#include <msp430.h>

char cadena[] = "Hola como";
volatile char i =0;
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  //Configuracion de la UART
  P3SEL |= BIT3+BIT4;                       // P3.3,4 = USCI_A0 TXD/RXD
  UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
  UCA0CTL1 |= UCSSEL_1;                     // SMCLK
  UCA0BR0 = 3;                              // 1MHz 115200
  UCA0BR1 = 0;                              // 1MHz 115200
  UCA0MCTL |= 0x06;            // Modulation UCBRSx=1, UCBRFx=0
  UCA0CTL0 &= 0x0;
  UCA0CTL1 &= ~UCSWRST;
  // **Initialize USCI state machine**
  //Configuracion del Boton P2.1
  P2DIR &= ~BIT1; //Configuro P2.1 como entrada
  P2REN |= BIT1; //Activa la resistencia P2.1
  P2OUT |= BIT1; //Conecto a Vcc la resistencia/Envio un logico P2.1

  while(1){
      i =0;
      if ((!(P2IN & BIT1))){ //Si presiono se activa
          while(cadena[i] != '\0'){
              UCA0TXBUF = cadena[i];
              while(UCA0STAT & UCBUSY);
              i++;;
              __delay_cycles(100000);
          }
      }else{

      }
  }
}