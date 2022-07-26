/**
 * @file loop.c
 * @author Fernando A. Miranda Bonomi (fmirandabonomi@herrera.unt.edu.ar)
 * @brief Implementación del lazo principal sencilla para probar el 
 *      funcionamiento básico del entorno y el hardware. Simplemente hace 
 *      parpadear el LED conectado al pin 13 del puero C del bluepill.
 */
#include <main.h>
#include <stm32f1xx.h>
#include <timer_systick.h>

typedef enum EstadoLed{ENCENDIDO,APAGADO}EstadoLed;
typedef enum EstadoBoton{ON,OFF}EstadoBoton;

inline static void estadoLed(EstadoLed estado)
{
    if (estado == ENCENDIDO)
        GPIOC->BSRR |= GPIO_BSRR_BR13;
    else
        GPIOC->BSRR |= GPIO_BSRR_BS13;
}

inline static EstadoBoton estadoBoton(void)
{
    if(GPIOC->IDR & GPIO_ODR_ODR14_Msk)
        return ON;
    else
        return OFF;
}

inline static EstadoLed nuevoEstado(EstadoLed estadoActual)
{
    if (estadoActual == ENCENDIDO)
        return APAGADO;
    return ENCENDIDO;
}




void loop(void)
{
    static EstadoLed led = APAGADO;
    static EstadoBoton boton = OFF; 
    boton = estadoBoton();
    if(boton == ON)
    {
        estadoLed(led);
        TimerSysTick_esperaMilisegundos(200);
        led = nuevoEstado(led);
    }
    else
    {
        led = APAGADO;
        estadoLed(led);
    }
}
