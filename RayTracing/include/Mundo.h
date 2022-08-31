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

    void Escenario1();
};