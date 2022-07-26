#include <estados.h>
#include <entradas.h>
#include <salidas.h>

Estado_Mef logicaEstadoSiguiente(Estado_Mef estadoActual, Entradas entradas)
{
    static Estado_Mef estadoSiguiente = DESARMADO;

    switch (estadoActual){
        case ARMADO:
                    if(entradas.Llave == OFF){
                        if(entradas.Detector == OFF){
                            estadoSiguiente = estadoActual;
                        }else{
                            estadoSiguiente = DISPARADO;
                        }
                    }else{
                        estadoSiguiente = DESARMADO;
                    }
        break;
        case DESARMADO:
                    if(entradas.Llave == OFF){
                        estadoSiguiente = estadoActual;
                    }else{
                        if(entradas.Detector == OFF){
                            estadoSiguiente = ARMADO;
                        }else{
                            estadoSiguiente = DISPARADO;
                        }
                    }
        break;
        case DISPARADO:
                    if(entradas.Llave == OFF){
                        estadoSiguiente = estadoActual;
                    }else{
                        estadoSiguiente = DESARMADO;
                    }
        break;
        default:
        break;
    }
    return estadoSiguiente;
}

Estado_Mef memoriaEstado(Estado_Mef estadoSiguiente){
    static Estado_Mef estadoActual;
    estadoActual = estadoSiguiente;
    return estadoActual;
}

Salidas logicaDeSalida(Estado_Mef estadoActual, Entradas entradas){
    static Salidas salida;
    
    switch (estadoActual){
        case ARMADO:
                    salida.Led_V=OFF;
                    salida.Led_R=ON;
                    if(entradas.Detector == OFF){
                        salida.Sirena=OFF;
                    }else{
                        salida.Sirena=ON;
                    }
        break;
        case DESARMADO:
                    salida.Led_V=ON;
                    salida.Sirena=OFF;
                    if(entradas.Detector == OFF){
                        salida.Led_R=OFF;
                    }else{
                        salida.Led_R=ON;
                    }
        break;
        case DISPARADO:
                    salida.Led_V=OFF;
                    salida.Led_R=ON;
                    salida.Sirena=ON;
        break;
        default:
        break;
    }
    return salida;
}