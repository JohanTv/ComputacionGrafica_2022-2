#pragma once

#include "vector.h"
#include "Objeto.h"

class Luz : public Esfera {
public:
    bool visible;
    
    Luz() : Esfera() {}
    Luz(vec3 _cen, vec3 _color, bool _visible = false, float _radio = 4) : Esfera(_cen, _radio), visible(_visible){
        color = _color;
        ks = -1, kd = 0, n = 0;
    }
};