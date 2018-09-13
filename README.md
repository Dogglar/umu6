## Beskrivning av libresistance
*libresistance* består av en c fil och en header fil.
Biblioteket innehåller funktionalitet för att beräkna det totala motståndet i en krets som innehåller flera motstånd, motstånden kan vara kopplade parallellt eller i serie.  
*float calc_resistance(int count, char conn, float array)*  
count: antalet motstånd  
conn: S för serie, P för parallellt  
array: en array med värdena på motstånden (lika många som värdet i count)

## Kompilering och testning av libresistance

