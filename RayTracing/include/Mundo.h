#pragma once

#include <vector>
#include "Objeto.h"
#include "Luz.h"
#include "Camara.h"

using namespace std;

class Mundo {
public:
    vector<Objeto*> objetos;
    vector<Luz*> luces;
    Camara camara;

    void Escenario0();
    void Escenario1();
    void Escenario2();
    void Escenario3();
    void Escenario4();
    void Escenario5();
    void Escenario6();

    void Proyecto1();

    void reset();
};