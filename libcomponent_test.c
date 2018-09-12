#include <stdio.h>

#include "libcomponent.h"


int main ()
{
   float afMatchedResistance[3];
   float fOrigResistance = 0;
   int   iResistorsUsed = 0;
   printf( "Please enter the resistance value!\n" );
   scanf( "%f", &fOrigResistance );

   iResistorsUsed = e_resistance( fOrigResistance, afMatchedResistance );
   
   for ( int i = 0 ; i < iResistorsUsed ; i++ )
   {
       printf( "Resistor%i:%f\n", (i+1), afMatchedResistance[i] ); 
   }

   return 0;

}
