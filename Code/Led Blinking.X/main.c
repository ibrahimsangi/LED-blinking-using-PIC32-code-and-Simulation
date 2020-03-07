/* 
 * File:   main.c
 * Author: IBRAHIM LABS
 *
 * Website: http://ibrahimlabs.blogspot.com/
 *
 * Created on September 5, 2013, 8:48 AM
 */

#include <xc.h>
#include "Delay.h"

/*
 *
 */
#ifndef OVERRIDE_CONFIG_BITS

    #pragma config FPLLIDIV = DIV_2         // PLL Input Divider
    #pragma config FPLLODIV = DIV_1         // PLL Output Divider
    #pragma config FPBDIV   = DIV_1         // Peripheral Clock divisor
    #pragma config FWDTEN   = OFF           // Watchdog Timer
    #pragma config POSCMOD  = HS            // Primary Oscillator
    #pragma config FNOSC    = PRIPLL        // Oscillator Selection
    #pragma config FPLLMUL  = MUL_20        // PLL Multipler

#endif // OVERRIDE_CONFIG_BITS


int main() {

    TRISBbits.TRISB0 = 0;       /*  making this pin as output   */
    TRISBbits.TRISB1 = 0;       /*  making this pin as output   */
    TRISBbits.TRISB2 = 0;       /*  making this pin as output   */
    TRISBbits.TRISB3 = 0;       /*  making this pin as output   */
    TRISBbits.TRISB4 = 0;       /*  making this pin as output   */

    LATBbits.LATB0 = 1;         /*  writing 1 to this PINB0     */
    LATBbits.LATB1 = 1;         /*  writing 1 to this PINB0     */
    LATBbits.LATB2 = 1;         /*  writing 1 to this PINB0     */
    LATBbits.LATB3 = 1;         /*  writing 1 to this PINB0     */
    LATBbits.LATB4 = 1;         /*  writing 1 to this PINB0     */

    while( 1)
    {
        /*  Toggling the state of PINs*/
        LATBbits.LATB0 = LATBbits.LATB2 = LATBbits.LATB4 = 1;
        LATBbits.LATB1 = LATBbits.LATB3 = 0;
        
        GeneralDelay(0xFFFFF);

        LATBbits.LATB0 = LATBbits.LATB2 = LATBbits.LATB4 = 0;
        LATBbits.LATB1 = LATBbits.LATB3 = 1;

        GeneralDelay(0xFFFFF);
        
    }
    return 0;
}
