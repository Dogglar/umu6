# umu6

Skapa er egen branch när ni börjar


## Beskriving av libpower
libpower består av en c fil och en header fil. Dessa två används för att skapa ett delat bibliotek som kan räkna ut effektutvecklingen. Antingen genom ett motstånd som spänning genom resistans **(U^2/R)** eller som spänning multiplicerat med ström **(A*V)**.

## Kompilering och testning av libpower

## Beskrivning av libcomponent
*libcomponent* består av en c fil och en header fil. Dessa två används för att skapa ett delat bibliotek. Biblioteket innehåller funktionalitet för att beräkna antal resistorer samt resistorvärden från E12 serien som krävs att ersätta resistansvärde givet av användaren. 

## Kompilering och testning av libcomponent
libcomponent använder sig av standard biblioteket **Math** (-lm) som bör länkas in på ställen där den används. Testning av biblioteket och kodens funktionalitet utfördes i branchen **"libcomponent"** som också innehåller ett färdigtkompilerat testprogram med source-koden. 
 


