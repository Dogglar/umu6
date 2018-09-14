#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"

int main () 
{

    float fVSource = 0;
    float afE12Resistors[3];
    float * pfResistors = NULL;
    float fResultingResistance = 0;
    float fCalculatedPower = 0;
    char cResistorCoupling = 'S';
    char c;
    int iNumOfResistors = 0;

    printf( "Ange spänningskälla i V: " );
    if ( scanf( "%f", &fVSource ) != 1 )
    {   
        /* ERROR HANDLING:
           scanf output */
        printf("\033[0;31m"); // change color to red
        printf ("Ogiltigt värde på spänningkällan\n" );
        printf("\033[0m"); // reset to default color
        return -1;
    }
    while( ( c = getchar() != '\n' && c != EOF ) ); 

    printf( "Ange koppling[S | P]: " );
    if ( scanf( "%1c", &cResistorCoupling ) != 1)
    {
        /* ERROR HANDLING: 
           scanf output */
        printf("\033[0;31m"); // change color to red
        printf ("Ogiltig kopplingstyp\n" );
        printf("\033[0m"); // reset to default color
        return -1;
    }
    while( ( c = getchar() != '\n' && c != EOF ) ); 
 
    printf( "Antal komponenter: " );

    if( scanf( "%d", &iNumOfResistors ) != 1 ) 
    {
        /* ERROR HANDLING: 
           scanf output */
        printf("\033[0;31m"); // change color to red
        printf ("Ogiltigt antal komponenter\n" );
        printf("\033[0m"); // reset to default color
        return -1;
    }
    while( ( c = getchar() != '\n' && c != EOF ) ); 

    /* Allocate array for numOfResistors float values */
    pfResistors = (float *) malloc( sizeof(float) * iNumOfResistors );
    /* Fill the array with resistor values */
    for ( int i = 0 ; i < iNumOfResistors ; i++ )
    {
        printf( "Komponent %d i ohm: ", i + 1 );
        if ( scanf( "%f", &pfResistors[i] ) != 1 )
        { 
        /* ERROR HANDLING: 
           scanf output */
        printf("\033[0;31m"); // change color to red
        printf ("Ogiltigt komponentvärde\n" );
        printf("\033[0m"); // reset to default color
        return -1;
        }
        while( ( c = getchar() != '\n' && c != EOF ) ); 
    }
    
    fResultingResistance = calc_resistance( iNumOfResistors, cResistorCoupling, pfResistors );
    
    /* ERROR HANDLING:
       calc_resistance */
    if ( (int)fResultingResistance == -1 )
    {
    printf("\033[0;31m"); // change color to red
    printf ("calc_resistance returned an error code\n" );
    printf("\033[0m"); // reset to default color
    return -1;
    }
  
    free( pfResistors );

    printf( "Ersättningsresistans: %0.1f ohm\n", fResultingResistance );
    
    fCalculatedPower = calc_power_r ( fVSource, fResultingResistance );
   
    /* ERROR HANDLING:
       calc_power */
    if ( (int) fCalculatedPower == -1 )
    {
    printf("\033[0;31m"); // change color to red
    printf ("calc_power returned an error code\n" );
    printf("\033[0m"); // reset to default color
    return -1;
    }

    printf( "Effekt: %0.2f W\n", fCalculatedPower );
    
    switch (cResistorCoupling)
    { 
        case 'S':
        case 's':
            printf( "Ersättningsresistanser i E12-serien kopplade i serie: " );
            break;
        case 'P':
        case 'p':
            printf( "Ersättningsresistanser i E12-serien kopplade paralellt: " );
            break;
    }  
     
    iNumOfResistors = e_resistance( fResultingResistance, afE12Resistors );
    
    /* ERROR HANDLING:
       e_resistance */
    if ( (int) iNumOfResistors == -1 )
    {
    printf("\033[0;31m"); // change color to red
    printf ("e_resistance returned an error code\n" );
    printf("\033[0m"); // reset to default color
    return -1;
    }
    
    for( int i = 0; i < iNumOfResistors ; i++ )
    {
        if ( i == iNumOfResistors - 1)
        {
            printf( "%0.0f", afE12Resistors[i] ); 
        }
        else
        {
            printf( "%0.0f, ", afE12Resistors[i] );
        }

    } 
    printf( "\n" );
    
    return 1;
}

