#include "RP6ControlLib.h"
#include "functions.h"

uint16_t analogeWaardes[6];
int main(void)
{
    portInit(); // na een koude start moeten de poorten goed geinit worden.
    DDRC |= IO_PC2; // set pin 2 als uitgang door met off te masken.
    //DDRC = 0xFF; // zet alle kanalen van poort c als uitgang
    //DDRC &= ~IO_PC2;    //zet kanaal 2 als ingang


    int beweging;
	initRP6Control();		// Initialize extension board processor
	initLCD();				// Initialize the LC-Display (LCD)

	startStopwatch1();
	startStopwatch2();

	for(;;)
	{
	    uint8_t key = getPressedKeyNumber();  // check welke toets is ingedrukt.


            //DDRC = 0b00000100;
            //PORTC |= IO_PC2;  // set de poort hoog
            //mSleep(500);

            //PORTC &= ~IO_PC2; // set de poort laag
            //sound(180,80,25);
            //sound(220,80,25);
            //mSleep(500);



        //runningLight();
        //runLCDText();
        //readAnalogValues(&analogeWaardes);
//        analogeWaardes[0] = readADC(ADC_2);
//        analogeWaardes[1] = readADC(ADC_3);
//        analogeWaardes[2] = readADC(ADC_4);
//        analogeWaardes[3] = readADC(ADC_5);
//        writeString("anlaoge waarde van 2 = : ");
//        writeInteger(analogeWaardes[0],DEC);
//        writeString("anlaoge waarde van 3= : ");
//        writeInteger(analogeWaardes[1],DEC);
//        writeString("\n");
//        writeString("anlaoge waarde van 4= : ");
//        writeInteger(analogeWaardes[2],DEC);
//        writeString("\n");
//        writeString("anlaoge waarde van 5= : ");
//        writeInteger(analogeWaardes[3],DEC);
//        writeString("\n");
printScharpSensorsValuesRight();


    }
	return 0;
}
