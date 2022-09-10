#pragma once

#include "vector.h"
#include "objeto.h"

class Luz : public Esfera {
public:
//    Luz(){}
    Luz(vec3 _cen, vec3 _color, bool _visible = false):Esfera(_cen, 4), visible(_visible){
        color = _color;
        ks = kd = -1;
};
    bool visible;
};