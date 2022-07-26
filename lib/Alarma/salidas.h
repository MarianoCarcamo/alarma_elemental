#ifndef SALIDAS_H
#define SALIDAS_H
#include "estados.h"

typedef struct Salidas{
    Estado_on_off Led_R;
    Estado_on_off Led_V;
    Estado_on_off Sirena;
} Salidas;

#endif