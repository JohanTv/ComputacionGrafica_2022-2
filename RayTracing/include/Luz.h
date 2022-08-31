#pragma once

#include "vector.h"

class Luz {
public:
    Luz(){}
    Luz(vec3 _pos, vec3 _color):pos(_pos), color(_color){};
    vec3 pos;
    vec3 color;
};