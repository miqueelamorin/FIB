#include <xc.h>
#include "config.h"

void configPIC(){
   ANSELA=0b00000011; 
   ANSELB=0x00;                  
   ANSELC=0x00;                  
   ANSELD=0x00;                  
   ANSELE=0xFF;
   
   TRISA=0xFF;
   TRISB=0x00; 
   TRISC=0b11001000;
   TRISD=0x00;		   
   TRISE=0xFF;
   
   PORTD=0x00;
   PORTB=0x00;    
}

void Config_TimersPWM(){
   IPEN = 0;
   GIE = 1;
   
   TMR2IP = 1;
   T2CON = 0b01111111;
   PR2 = 920;
   TMR2IF = 0;
   TMR2IE = 0;

   CCPTMRS0 = 0;
   CCP1CON = 0b00001100;
   CCPR1L = 0;
   
   TMR0IP = 1;
   T0CON = 0b10010001;
   TMR0 = 15536;
   TMR0IF = 0;
   TMR0IE = 0;
}


void Config_ADC(){
   ADCON0bits.ADON = 1;
   ADCON1bits.NVCFG = 0;
   ADCON1bits.PVCFG = 0;
   ADCON1bits.TRIGSEL = 0;
   ADCON2bits.ACQT = 1;
   ADCON2bits.ADCS = 2;
   ADCON2bits.ADFM = 0;
}

void ConfigTxConsole() {   
   TXSTA1bits.TX9 = 0;			//8 bits
   TXSTA1bits.TXEN = 1;			//Activar transmisio
   TXSTA1bits.SYNC = 0;			//Asincron
   TXSTA1bits.BRGH = 1;			//High baud rate
   BAUDCON1bits.BRG16 = 1;		//16 bit baud rate
   SPBRG1 = 16;				//Baud valor
   RCSTA1bits.SPEN = 1;			//Activar port USART
}

void ConfigRxConsole() { 
   RCSTA1bits.RX9 = 0;				//Reset bit recepcio
   RCSTA1bits.CREN = 1;				//Activar recepcio
   RC1IE = 1;				//Interrupcions recepcio
   PEIE = 1;					
   GIE = 1;
}

