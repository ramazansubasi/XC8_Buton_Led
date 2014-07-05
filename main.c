/*
 * File:   main.c
 * Author: Ramazan Subasi (subram)
 *
 * Created on 04 Kasim 2013 Pazartesi, 22:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ 4000000      // Calisma Frekansi
#define Led PORTBbits.RB0       // RB0 Pini Led olarak Isimlendiriliyor
#define Button PORTAbits.RA0    // RA0 Pini Button Olarak Isimleniriliyor

int main() {
    ANSEL=0;                    // PORTA Dijital Giris/Cikis. Analog Iptal.
    TRISBbits.TRISB0=0;         // RB0 Pini Cikis Olarak Ayarlaniyor
    TRISAbits.TRISA0=1;         // RA0 Pini Giri? Olarak Ayarlan?yor
    Led=0;                      // Led(RB0) Sifirlaniyor
    for(;;){                    // Program Sonsuz Donguye Sokuluyor
    Led=Button;                 // Button'un durumunu Led'e Yukle
                                // Button=0 => Led=0, Button=1 => Led=1
    }                           // Dongu Sonu
}                               // Program Sonsel=0;