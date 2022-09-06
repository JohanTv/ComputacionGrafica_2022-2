#pragma once

#include "Rayo.h"
#include <iostream>

class Objeto {
public:
    vec3 color;
    float kd, ks, idr, n;
    
    Objeto(){
        kd = ks = idr = 0;
        n = 4;
    }
    Objeto(vec3 _color) : color(_color){};
    Objeto(vec3 _color, float _kd, float _ks, int _n) : color(_color), kd(_kd), ks(_ks), n(_n), idr(0) {};
    virtual bool interseccion(Rayo rayo, float &t, vec3 &normal) = 0;

    void set(vec3 _color, float _kd, float _ks=0, float _n=0, float _idr=0) {
        color = _color; kd = _kd; ks = _ks; n = _n; idr = _idr;
    }
};

class Esfera : public Objeto {
public:
    vec3 cen;
    float radio;

    Esfera(vec3 _cen, float _radio) : cen(_cen), radio(_radio) {}
    Esfera(vec3 _cen, float _radio, vec3 _color, float _kd, float _ks, int _n) : 
            Objeto(_color, _kd, _ks, _n), cen(_cen), radio(_radio) {}
    
    bool interseccion(Rayo rayo, float &t, vec3 &normal) override;
};

class Plano : public Objeto {
public:
    vec3 normal;
    float d;

    Plano(vec3 _normal, float _d) : normal(_normal), d(_d) {}
    
    bool interseccion(Rayo rayo, float &t, vec3 &normal) override;
};