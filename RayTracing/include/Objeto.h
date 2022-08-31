#pragma once

#include "Rayo.h"
#include <iostream>

class Objeto {
public:
    vec3 color;
    vec3 kd, ks;
    int n;
    Objeto(){}
    Objeto(vec3 _color): color(_color){};
    Objeto(vec3 _color, vec3 _kd, vec3 _ks): color(_color), kd(_kd), ks(_ks){};
    virtual bool interseccion(Rayo rayo, float &t, vec3 &normal) = 0;
};

class Esfera : public Objeto {
public:
    vec3 cen;
    float radio;
    Esfera(vec3 _cen, float _radio) {
        cen = _cen;
        radio = _radio;
    };
    Esfera(vec3 _cen, float _radio, vec3 _color) : Objeto(_color) {
        cen = _cen;
        radio = _radio;
    }

    Esfera(vec3 _cen, float _radio, vec3 _color, vec3 _kd, vec3 _ks) : Objeto(_color, _kd, _ks) {
        cen = _cen;
        radio = _radio;
    }
    
    bool interseccion(Rayo rayo, float &t, vec3 &normal) override;
};

class Plano : public Objeto {
public:
    vec3 normal;
    float d;
    Plano(vec3 _normal, float _d) { normal = _normal; d=_d; }
    bool interseccion(Rayo rayo, float &t, vec3 &normal) override;
};