#ifndef SEMAFORO_H
#define SEMAFORO_H

//Definição dos GPIOs
//Wokwi
#define LED_RED 6
#define LED_YELLOW 7
#define LED_GREEN 8

//BitDogLab
#define LED_RGB_R 13
#define LED_RGB_G 12
#define LED_RGB_B 11

//Configuração inicial dos leds
void setup_gpio_leds(){
  //Wokwi
  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);
  gpio_init(LED_YELLOW);
  gpio_set_dir(LED_YELLOW, GPIO_OUT);
  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);

  //BitDogLab
  gpio_init(LED_RGB_R);
  gpio_set_dir(LED_RGB_R, GPIO_OUT);
  gpio_init(LED_RGB_G);
  gpio_set_dir(LED_RGB_G, GPIO_OUT);
  gpio_init(LED_RGB_B);
  gpio_set_dir(LED_RGB_B, GPIO_OUT);
}

void semaforo_vermelho(){
  //Acende o led vermelho do Wokwi
  gpio_put(LED_RED, true);
  gpio_put(LED_YELLOW, false);
  gpio_put(LED_GREEN, false);

  //Acende o led vermelho da BitDogLab
  gpio_put(LED_RGB_R, true);
  gpio_put(LED_RGB_G, false);
  gpio_put(LED_RGB_B, false);
}

void semaforo_amarelo(){
  //Acende o led amarelo do Wokwi
  gpio_put(LED_YELLOW, true);
  gpio_put(LED_GREEN, false);
  gpio_put(LED_RED, false);

  //Acende o led vermelho do Wokwi (A cor amarela no sistema RGB R=255, G=255 e B=0. )
  gpio_put(LED_RGB_R, true);
  gpio_put(LED_RGB_G, true);
  gpio_put(LED_RGB_B, false);
}

void semaforo_verde(){
  //Acende o led verde do Wokwi
  gpio_put(LED_GREEN, true);
  gpio_put(LED_YELLOW, false);
  gpio_put(LED_RED, false);

  //Acende o led vermelho do Wokwi
  gpio_put(LED_RGB_G, true);
  gpio_put(LED_RGB_B, false);
  gpio_put(LED_RGB_R, false);
}

#endif