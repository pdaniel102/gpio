/*!
\file   Blink.c
\date   2020-11-13
\author Fulvio Vivas <fulvio.vivas@unicauca.edu.co>
\brief  Example blink.

\par Copyright
Information contained herein is proprietary to and constitutes valuable
confidential trade secrets of unicauca, and
is subject to restrictions on use and disclosure.

\par
Copyright (c) unicauca 2020. All rights reserved.

\par
The copyright notices above do not evidence any actual or
intended publication of this material.
******************************************************************************
*/
#include <xc.h>
#include <pic18f4550.h>  /*Header file PIC18f4550 definitions*/
#include "fuses.h"
#include "pinout.h"

void secuencial_Efecto1(void);
void secuencial_Efecto2(void);
void secuencial_Efecto3(void);
void secuencial_Efecto4(void);
void secuencial_Efecto5(void);
void secuencial_Efecto6(void);

unsigned char efecto = 1;
unsigned long velocidad = 1;

int main(void) {
    TRISD = 0; //Puerto D en modo de Salida
    LATD = 0;  //0V en puerto D
    TRISBbits.TRISB7 = 1; //Puerto B-7 en modo de Entrada
    TRISBbits.TRISB6 = 1; //lo coloque en 1 porque pienso que es de entrada
    INTCON2bits.RBPU = 0;
    while (1) {
        
        switch (efecto) {
            case 1: secuencial_Efecto1();
                break;
            case 2: secuencial_Efecto2();
                break;
            case 3: secuencial_Efecto3();
                break;
            case 4: secuencial_Efecto4();
                break;
            case 5: secuencial_Efecto5();
                break;
            case 6: secuencial_Efecto6();
                break;    
        }
    }
    return 1;
}

void secuencial_Efecto1(void) {
    for (int i = 0; i < 8; i++) {
        LATD = 1 << i;
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
        //Efecto
        if (!PORTBbits.RB7) {//Aqui evalua si se esta pulsando el efecto, la cuestion para un cambio en tiempo real es evaluar durante la llama de las funciones que reaizan los efectos
            __delay_ms(50);
            if(++efecto==7){efecto=1;}
            return;
        }
    }
}

void secuencial_Efecto2(void) {
    for (int i = 0, j = 7; i < 8; i++, j--) {
        LATD = (1 << i) + (1 << j);
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
        //Efecto
        if (!PORTBbits.RB7) {
            __delay_ms(50);
            if(++efecto==7){efecto=1;}
            return;
        }
    }
}

void secuencial_Efecto3(void) {
    for (int i = 0; i < 9; i++) {
        LATD = (1 << i) - 1;
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
        //Efecto
        if (!PORTBbits.RB7) {
            __delay_ms(50);
            if(++efecto==7){efecto=1;}
            return;
        }
    }
}

void secuencial_Efecto4(void) {
    volatile unsigned int m=0,n=0;
    for (int i = 0; i < 5; i++) {
        LATD = m+n;
        m += (1 << i) & 0x0f;
        n += (1 << (7-i)) & 0xf0;
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
        //Efecto
        if (!PORTBbits.RB7) {
            __delay_ms(50);
            if(++efecto==7){efecto=1;}
            return;
        }
    }
}

void secuencial_Efecto5(void) { //Efecto de "trencito"
   for (int i = 0; i < 6; i++) {
       LATD = (1 << i) + (1 << i + 1) + (1 << i + 2);
        
        if(velocidad==1){__delay_ms(50);}
     else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
          __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
       //Efecto
        if (!PORTBbits.RB7) {
            __delay_ms(50);
            if(++efecto==7){efecto=1;}
            return;
        }
    }
    
    for (int j = 6; j > 0; j--) {
        LATD = (1 << j-1) + (1 << j ) + (1 << j + 1);
        
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
        //Efecto
        if (!PORTBbits.RB7) {
            __delay_ms(50);
            if(++efecto==7){efecto=1;}
            return;
        }
    }
    
}

void secuencial_Efecto6(void) { //"Efecto alternado"
    for (int i = 0; i < 2; i++) {
        if(i == 0){
            LATD = (1 << 0) + (1 << 2) + (1 << 4)+ (1 << 6);
        }else{
            LATD = (1 << 1) + (1 << 3) + (1 << 5)+ (1 << 7);
        }
        
        if(velocidad==1){__delay_ms(50);}
        else if(velocidad==2){__delay_ms(100);}
        else if(velocidad==3){__delay_ms(200);}
        else if(velocidad==4){__delay_ms(400);}
        //velocidad
        if (!PORTBbits.RB6) {
            __delay_ms(50);
            if(++velocidad==5){velocidad=1;}
        }
        //Efecto
        if (!PORTBbits.RB7) {
            __delay_ms(50);
            if(++efecto==7){efecto=1;}
            return;
        }
    }
}