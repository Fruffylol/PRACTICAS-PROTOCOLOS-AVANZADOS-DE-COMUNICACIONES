#include <msp430.h> 


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    // 1.-Función Rx Tx
    P4SEL |= BIT5 | BIT4; //Activamos la funcion Rx y Tx en "P4.5 --> Rx" y "P4.4 --> Tx"
    // 2.-Habiliatmos el Rs en la USCI
    UCA1CTL0 |= UCPEN | UCPAR | UCSPB;
    UCA1CTL1 |= UCSWRST; //Habilidto el reset en la USCI
    // 3.- Conectamos el funete de reloj al modulo USCI
    UCA1CTL1 |= UCSSEL__SMCLK; //Conectamos la fuente SMCLK a la USCI
    //4.- Se configura la velocidad de transmision y recepcion en el la USC (9600bps)
    UCA1BR0 =54; //19200 EJERCICIO 3; // 9 115200 EJ1 PARTE UNO;  //109 9600 EJERCICIO 2;
    UCA1MCTL = UCBRS_2;
    UCA1CTL1 &= ~UCSWRST;//Se desconecta el resset
    UCA1IE |= UCRXIE; //Habilito la interrupcion en la recepcion
    __bis_SR_register(GIE);

}

#pragma vector=USCI_A1_VECTOR
__interrupt void UART (void)
{
    UCA1TXBUF = UCA1RXBUF; //Eco para mostrar en la pantalla
}