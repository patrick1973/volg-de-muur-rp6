#ifndef PCF8574AP_H_INCLUDED
#define PCF8574AP_H_INCLUDED

// Het adres wordt gemaat door de eerste 3 IC pins.
// 0 1 1 1 A2 A1 A0 r/w omdat er gebruik gemaakt wordt van een IC PCF8574AP zit de R/w in het adres.
// zie data sheet. pagina 9

#define IO_EXPANDER_0_ADDRESS 0x70  //2#01110000
#define IO_EXPANDER_1_ADDRESS 0x72  //2#01110010
#define IO_EXPANDER_2_ADDRESS 0x76  //2#01110110



#endif // PCF8574AP_H_INCLUDED
