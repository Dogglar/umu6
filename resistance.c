#include <stdio.h>
#include "resistance.h"

float calc_resistance(int count, char conn, float *array){

    float value = 0;
    /*  kollar
        att array inte är en nollpekare,
        att count inte är mindre än 1
        att conn är ett S eller P
    */
    if(!array || count <1 || !(conn == 80 || conn == 83)){
        return -1;
    }
    else if(conn == 83) return calc_serial_resistans(count, array);
    else return calc_parallel_resistans(count, array);

}

float calc_serial_resistans(int count, float *array){
    float value = 0;
    for (int i = 0; i < count; i++){
        value += array[i];
    }
    return value;
}

float calc_parallel_resistans(int count, float *array){
    float value = 0;
    for (int i = 0; i < count; i++){
        // kolla om något värde är noll
        // isf blir den totala resistansen 0
        if(array[i] == 0){
            return 0;
        }
        else value += 1/array[i];
    }
    return 1/value;
}
