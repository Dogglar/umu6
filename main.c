#include <stdio.h>
#include "libpower.h"

int main(int argc, char *argv[]){

  float resistance = 1398.0;
  float voltage = 50;
  float ampere = 0.063;

  printf("Input resistance is: %.4f Ω\n",resistance);
  printf("Input voltage is:    %.4f V\n",voltage);
  printf("Input current is:    %.4f A\n",ampere);

    float r_power;
    r_power =  calc_power_r(voltage,resistance);
    float i_power;
    i_power = calc_power_i(voltage,ampere);

    printf("Results -----------------------------\n");
    printf("Resistive power was: %.4f W\n",r_power);
    printf("Current power was:   %.4f W\n",i_power);

    return 0;
}
