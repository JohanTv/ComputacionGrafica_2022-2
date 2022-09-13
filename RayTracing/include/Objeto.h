#pragma once

#include "Rayo.h"

class Objeto {
public:
    vec3 color;
    float kd, ks, idr, n;
    
    Objeto(){ set_default_setting(); }
    Objeto(vec3 _color) : color(_color){ set_default_setting(); };
    
    virtual bool interseccion(Rayo rayo, float &t, vec3 &normal) = 0;

    void set(vec3 _color, float _kd, float _ks=0, float _n=0, float _idr=0) {
        color = _color; kd = _kd; ks = _ks; n = _n; idr = _idr;
    }

    bool is_light(){ return this->ks == -1; }
    void set_default_setting(){
        kd = ks = idr = 0;
        n = 4;
    }
};

class Esfera : public Objeto {
public:
    vec3 cen;
    float radio;

    Esfera(): Objeto(), cen(vec3(0.0f, 0.0f, 0.0f)), radio(1) {} 
    Esfera(vec3 _cen, float _radio) : Objeto(), cen(_cen), radio(_radio) {}
    
    bool interseccion(Rayo rayo, float &t, vec3 &normal) override;
};

class Plano : public Objeto {
public:
    vec3 normal;
    float d;

    Plano(vec3 _normal, float _d) : Objeto(), normal(_normal), d(_d) {}
    
    bool interseccion(Rayo rayo, float &t, vec3 &normal) override;
};

class Cilindro : public Objeto {
public:
    vec3 pa, pb;
    float ra;

    Cilindro(vec3 _pa, vec3 _pb, float _ra): Objeto(), pa(_pa), pb(_pb), ra(_ra){}
    
    bool interseccion(Rayo rayo, float &t, vec3 &normal) override;
};