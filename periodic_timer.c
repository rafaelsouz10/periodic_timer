#include <stdio.h>
#include "pico/stdlib.h"   // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.
#include "include/semaforo.h"       //Inclui toda configuração dos leds e funções de estado de semáforo

int estado_semaforo = 0;

// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna os estados do semáforo
    if (estado_semaforo == 0) {
        printf("SEMÁFORO VERMELHO\n");
        semaforo_vermelho();
        estado_semaforo = 1;
    } else if (estado_semaforo == 1) {
        printf("SEMÁFORO AMARELO\n");
        semaforo_amarelo();
        estado_semaforo = 2;
    } else {
        printf("SEMÁFORO VERDE\n");
        semaforo_verde();
        estado_semaforo = 0;
    }
}

int main() {

    stdio_init_all();

    setup_gpio_leds();  //Configuração incial dos leds

    // Estrutura de temporizador de repetição que estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        // Pausa de 1 segundos para reduzir o uso da CPU.
        sleep_ms(1000);
        printf("FIQUE SEMPRE ATENTO! RESPEITE O SEMÁFORO!\n");
    }
    return 0;
}