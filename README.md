# umu6

Skapa er egen branch när ni börjar


## Beskriving av libpower
libpower består av en c fil och en header fil. Dessa två används för att skapa ett delat bibliotek som kan räkna ut effektutvecklingen. Antingen genom ett motstånd som spänning genom resistans **(U^2/R)** eller som spänning multiplicerat med ström **(A*V)**.

## Kompilering och testning av libpower

## Beskrivning av libcomponent
*libcomponent* består av en c fil och en header fil. Dessa två används för att skapa ett delat bibliotek. Biblioteket innehåller funktionalitet för att beräkna antal resistorer samt resistorvärden från E12 serien som krävs att ersätta resistansvärde givet av användaren.

**Bibliotekets funktioner:**
*int e_resistance( float orig_resistance, float \**res_array )*
- orig\_resistance - ersättningsresistansen.
- \*res\_array - pekare till en array med 3 resistorer som ska fyllas med värden ur E12-serien.
- count - antalet resistorer ur E12-serien som behövdes för att ersätta orig\_resistance. 

## Kompilering och testning av libcomponent
libcomponent använder sig av standard biblioteket **Math** (-lm) som bör länkas in på ställen där den används. Testning av biblioteket och kodens funktionalitet utfördes i branchen **"libcomponent"** som också innehåller ett färdigtkompilerat testprogram med source-koden. 

## Beskrivning av libresistance
*libresistance* består av en c fil och en header fil.
Biblioteket innehåller funktionalitet för att beräkna det totala motståndet i en krets som innehåller flera motstånd, motstånden kan vara kopplade parallellt eller i serie.  
*float calc_resistance(int count, char conn, float array)*  
count: antalet motstånd  
conn: S för serie, P för parallellt  
array: en array med värdena på motstånden (lika många som värdet i count)
 


