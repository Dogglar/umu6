/**@file libcomponent.c*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

#include "libcomponent.h"

/* Defines ********************************************************************/ 

#define NUM_OF_ELEMENTS_ARR_E12       13 

/* Variables ******************************************************************/ 

float afE12Series[] = { 1.0f, 1.2f, 1.5f, 1.8f, 
                        2.2f, 2.7f, 3.3f, 3.9f,
                        4.7f, 5.6f, 6.8f, 8.2f, 10.0f};

/* Functions ******************************************************************/

float matchResistanceE12( float , bool );

/**
 ******************************************************************************* 
 * \fn        e_resistance
 *
 * \brief     Function finds the serial resistance representation (3 values as max)
 *            of the in parameter resistance
 *
 * \param[in] Original resistance value
 * \param[in] Passed by reference array that will be filled with resistance values 
 * 
 * \retval    Integer value corresponding to how many resistors were used to
 *            get the desired original resistance. 
 ******************************************************************************/
int e_resistance ( float orig_resistance, float *res_array)
{
    float fRestResistance = 0 ;
    int   iNumOfResistorsUsed = 0;

    /* Error handling */
    if ( res_array == NULL )
    {
    return -1; 
    }  
   
    memset( res_array, 0, 3*sizeof(float) ); 
    fRestResistance = orig_resistance; 

    for ( int i = 0 ; i < 3 ; i++ )
    {
        res_array[i] = matchResistanceE12( fRestResistance, false ); 
 
        if ( !(res_array[i] == 0) )
        {
            iNumOfResistorsUsed++;
        }

        fRestResistance -= res_array[i];
        /* Check if we are done */ 
        if ( fRestResistance <= 0 || res_array[0] == 0 )
        {
            break; 
        }
    }

    return iNumOfResistorsUsed;
}

/**
 ********************************************************************************
 * \fn        matchResistanceE12
 * 
 * \brief     Function returns the closest resistance value match from E12 series
 *            to in parameter.
 *
 * \param[in] Resistance value to match
 * \param[in] Flag that allows over-shoot of the matched resistance value i.e
 *            the returned value can be higher than the original though closer            
 *            to the original 
 *
 * \retval    Matched resistance value from E12 series
 *******************************************************************************/
float matchResistanceE12( float resistance, bool allowOverShoot)
{
    int iResistanceValueCopy = ( int ) resistance; 
    int iDigitCount = 0;
    int i = 0;
    float fResDelta = 0;
    float fResErrorAbs1 = 0; 
    float fResErrorAbs2 = 0; 

    /* Handle the case when the resistance value is bellow minimum allwed */
    if ( resistance < afE12Series[0] )
    {
        return 0.0;
    }
 
    /* Count the number of digits to the left of the decimal point in the resistance value */ 
    while ( iResistanceValueCopy != 0 )
    {
        iResistanceValueCopy /= 10;
        iDigitCount++;
    }
   
    const int iNumOfZeroes = ((iDigitCount - 1) < 0) ? (0) : (iDigitCount - 1);
 
    /* Find array index that corresponds to the resistance value with the least delta from 
       the original resistance */ 
    while( i < NUM_OF_ELEMENTS_ARR_E12 ) 
    {
       fResDelta = ( resistance - afE12Series[i] * pow(10, (iNumOfZeroes)) );
        
       if ( fabs( fResDelta ) < 0 + 0.001  )
       { 
          /* Zero delta has been found -> 
             The exact value matched E12 series */ 
          break;

       }
       else if( fResDelta < 0 )
       { 
         if ( i != 0 )
         {
             fResErrorAbs1 = fabs( (resistance - afE12Series[i] * pow(10, (iNumOfZeroes))) );
             fResErrorAbs2 = fabs( (resistance - afE12Series[i-1] * pow(10, (iNumOfZeroes))) );

             /* Decide the closest value */
             if( (fResErrorAbs2 < fResErrorAbs1) || !(allowOverShoot) )
             {
             i--; 
             }
         }

          break;
       }
             i++;
    }

    return ( afE12Series[i] * pow(10, (iNumOfZeroes)) ); 
}
