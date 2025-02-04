#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos dos LEDs e do botão
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13
#define BUTTON_PIN 4

// Variável para controlar o estado do sistema
volatile bool system_active = false;

// Funções de callback para o temporizador
int64_t turn_off_green_led(alarm_id_t id, void *user_data);
int64_t turn_off_red_led(alarm_id_t id, void *user_data);
int64_t turn_off_blue_led(alarm_id_t id, void *user_data);

// Função de callback para o botão
void button_callback(uint gpio, uint32_t events) {
    if (!system_active) {
        system_active = true;
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 1);

        // Inicia o temporizador para desligar o LED verde após 3 segundos
        add_alarm_in_ms(3000, turn_off_green_led, NULL, false);
    }
}

// Função de callback para desligar o LED verde
int64_t turn_off_green_led(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERDE, 0);

    // Inicia o temporizador para desligar o LED vermelho após 3 segundos
    add_alarm_in_ms(3000, turn_off_red_led, NULL, false);
    return false; // Não repetir o temporizador
}

// Função de callback para desligar o LED vermelho
int64_t turn_off_red_led(alarm_id_t id, void *user_data) {
    gpio_put(LED_AMARELO, 0);

    // Inicia o temporizador para desligar o LED azul após 3 segundos
    add_alarm_in_ms(3000, turn_off_blue_led, NULL, false);
    return false; // Não repetir o temporizador
}

// Função de callback para desligar o LED azul
int64_t turn_off_blue_led(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERMELHO, 0);
    system_active = false; // Permitir que o botão seja pressionado novamente
    return false; // Não repetir o temporizador
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa o pino do botão como entrada
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Configura a interrupção para o botão
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (true) {
        tight_loop_contents(); // Mantém o loop principal ativo
    }
}