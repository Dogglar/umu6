#include <stdio.h>
#include "libpower.h"

int main(int argc, char *argv[]){

    float r_power;
    r_power =  calc_power_r(120,10000);
    float i_power;
    i_power = calc_power_i(230,2);

    printf("Resistive power was: %.4fW\n",r_power);
    printf("Current power was: %.4fW\n",i_power);

    return 0;
}
