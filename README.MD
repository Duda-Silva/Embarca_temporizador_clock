# Projeto: Temporizador de um Disparo (One Shot)

## 📌 Descrição
Este projeto visa criar um sistema de temporização para o acionamento de LEDs utilizando a função `add_alarm_in_ms()` do Pico SDK. O sistema é ativado a partir do clique em um botão (pushbutton) e simula os seguintes componentes:
1. Microcontrolador Raspberry Pi Pico W.
2. 03 LEDs (azul, vermelho e verde).
3. 03 Resistores de 330 Ω.
4. Botão (Pushbutton).

## 🎯 Objetivos
✔ Acionar três LEDs simultaneamente ao pressionar um botão.
✔ Desligar os LEDs em sequência com um atraso de 3 segundos entre cada estado.
✔ Implementar a mudança de estado dos LEDs em funções de callback do temporizador.
✔ Garantir que o botão só possa alterar o estado dos LEDs quando o último LED for desligado.

## 🎮 Funcionalidades
- Pressionar o botão aciona os três LEDs simultaneamente.
- Os LEDs desligam em sequência com um atraso de 3 segundos entre cada estado.
- O botão só pode ser pressionado novamente após o último LED ser desligado.

## 🛠 Tecnologia Utilizada
### 🔹 Programas
- Linguagem de Programação: C
- IDE: Visual Studio Code
- SDK: Pico SDK
- Simulador: Wokwi
- Controle de Versão: Git
- Plataforma de Hospedagem: GitHub

### 🔹 Ferragens
- Microcontrolador: Raspberry Pi Pico W
- LEDs: Azul, Vermelho e Verde
- Resistores: 330 Ω
- Botão: Pushbutton

## 📝 Como Executar o Projeto
1. Clonar o repositório:
   ```sh
   git clone https://github.com/seu-usuario/temporizador-one-shot.git
   cd Embarca_temporizador_cloch
    code .  //para abrir o VS code 
   Compile o projeto (Compile Project)
   Simulação wokwi  - clique no arquivo diagram.json para se conduzido a simulação, ter play para iniciar a simulação no wokwi.
