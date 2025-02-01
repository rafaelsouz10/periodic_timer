## Sistema Temporizador periódico

---

## Descrição do Projeto

Projeto da atividade **EmbarcaTech**, sobre Clock e Temporizadores. O semáforo alterna entre os estados vermelho, amarelo e verde em intervalos de tempo definidos, simulando o funcionamento de um semáforo real. O projeto foi desenvolvido para funcionar tanto no simulador Wokwi quanto em hardware físico (BitDogLab).

![image](https://github.com/user-attachments/assets/3d6b3c84-f00a-474c-aa24-e2806f717aef)


A utilização do callback no projeto é um dos pontos centrais da atividade proposta pelo Embarcatech, pois ele permite a execução periódica de uma função (no caso, a alternância dos estados do semáforo) sem bloquear a execução do programa principal.

---

## Requisitos

- **Microcontrolador**: Raspberry Pi Pico ou Raspberry Pi Pico W (opcional)
- **Placa de Desenvolvimento:** BitDogLab (opcional).
- **Conta Criada no Wokwi Simulator**: [Wokwi](https://wokwi.com/).
- **Editor de Código**: Visual Studio Code (VS Code).
- **SDK do Raspberry Pi Pico** configurado no sistema.
- Ferramentas de build: **CMake** e **Ninja**.

---

## Instruções de Uso

### 1. Clone o Repositório

Clone o repositório para o seu computador:
```bash
git https://github.com/rafaelsouz10/periodic_timer.git
cd periodic_timer
code .
```
---

### 2. Instale as Dependências

Certifique-se de que o SDK do Raspberry Pi Pico está configurado corretamente no VS Code. As extensões recomendadas são:

- **C/C++** (Microsoft).
- **CMake Tools**.
- **Wokwi Simulator**.
- **Raspberry Pi Pico**.

---

### 3. Configure o VS Code

Abra o projeto no Visual Studio Code e siga as etapas abaixo:

1. Certifique-se de que as extensões mencionadas anteriormente estão instaladas.
2. No terminal do VS Code, compile o código clicando em "Compile Project" na interface da extensão do Raspberry Pi Pico.
3. O processo gerará o arquivo `.uf2` necessário para a execução no hardware real.

---

### 4. Teste no Simulador Wokwi Integrado ao VS Code

Após ter configurado o VS Code conforme descrito no item 3, siga os passos abaixo para simular o projeto:

1. Abra o arquivo `diagram.json` no Visual Studio Code.
2. Clique no botão "Play" disponível na interface.
3. Divirta-se interagindo com os componentes disponíveis no simulador integrado!

---

### 5. Teste no Hardware Real

#### Utilizando a Placa de Desenvolvimento BitDogLab com Raspberry Pi Pico W:

1. Conecte a placa ao computador no modo BOTSEEL:
   - Pressione o botão **BOOTSEL** (localizado na parte de trás da placa de desenvolvimento) e, em seguida, o botão **RESET** (localizado na frente da placa).
   - Após alguns segundos, solte o botão **RESET** e, logo depois, solte o botão **BOOTSEL**.
   - A placa entrará no modo de programação.

2. Compile o projeto no VS Code utilizando a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico):
   - Clique em **Compile Project**.

3. Execute o projeto clicando em **Run Project USB**, localizado abaixo do botão **Compile Project**.

---

### 6. Conexões e Esquemático

Abaixo está o mapeamento de conexões entre os componentes e a Raspberry Pi Pico W para os ambientes **Wokwi** (simulação) e **BitDogLab** (hardware físico):

   |  **Componentes do Wokwi**  |   **Pino Conectacos (GPIO)**    |
   |----------------------------|---------------------------------|
   | LED_RED                    | GPIO 6                          |
   | LED_YELLOW                 | GPIO 7                          |
   | LED_GREEN                  | GPIO 8                          |

   |  **Componentes do BitDogLab**  |   **Pino Conectacos (GPIO)**    |
   |--------------------------------|---------------------------------|
   | LED_RGB_R                      | GPIO 13                         |
   | LED_RGB_G                      | GPIO 12                         |
   | LED_RGB_B                      | GPIO 11                         |


**Observações**:

- No **Wokwi**, são utilizados LEDs individuais para cada cor do semáforo (vermelho, amarelo e verde).
- No **BitDogLab**, é utilizado um LED RGB, onde:
  - O **LED vermelho** é acionado para o estado vermelho do semáforo.
  - O **LED amarelo** é simulado acionando os canais vermelho e verde do LED RGB simultaneamente.
  - O **LED verde** é acionado para o estado verde do semáforo.

Essa abordagem demonstra a flexibilidade do projeto, que pode ser adaptado tanto para simulações com componentes discretos quanto para hardware físico com LEDs RGB.

---

### 7. Funcionamento do Sistema

#### Início no Estado Vermelho

O semáforo começa no estado vermelho porque a variável `estado_semaforo` é inicializada com o valor `0`, que corresponde ao estado vermelho.

---

#### Mudança de Estado no Callback

A lógica de alternância dos estados do semáforo é implementada diretamente na função `repeating_timer_callback`, atendendo ao requisito de que a mudança de estado dos LEDs seja feita no callback.

---

#### Impressão de Informações no Loop Principal

No loop principal (`while (true)`), uma mensagem é impressa a cada segundo usando `sleep_ms(1000)` e `printf`. Isso atende ao requisito de que a rotina principal deve exibir informações periodicamente.

```plaintext
FIQUE SEMPRE ATENTO! RESPEITE O SEMÁFORO!
