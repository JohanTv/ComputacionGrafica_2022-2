#pragma once

#include <cmath>
#include <vector>

#include "CImg.h"
#include "Luz.h"
#include "Rayo.h"
#include "Objeto.h"

using namespace cimg_library;
using namespace std;
typedef unsigned char BYTE;

class Camara {
private:
    vec3 get_diffuse_reflection(vec3& N, vec3& L, vec3& color, float& kd);
    vec3 get_specular_reflection(vec3& N, vec3& L, vec3& pi, vec3& color, float& ks, int n = 4);
    void fill_pixel(int x, int y, vec3 color);
    vec3 calculate_color(Rayo rayo, vector<Objeto*>& objetos, vector<Luz*>& luces, int depth = -1);
    void fresnel(vec3 I, vec3 N, float& ior, float &kr );
    vec3 refract(vec3 I, vec3 N, float ior);
    float clamp(float lower, float upper, float n) {
        return max(lower, min(n, upper));
    }

public:
    float fov, w, h, _near;
    vec3 eye, center, up;
    float f, a, b;
    vec3 xe, ye, ze;
    CImg<BYTE> *pImg;
    vec3 backgroud_color;

    Camara(){}
    Camara(vec3 _center, vec3 _up, vec3 _eye, float _near_, float _fov, float _w, float _h, vec3 _background_color = vec3(1, 1, 1))
        : fov(_fov), w(_w), h(_h), _near(_near_), eye(_eye), center(_center), up(_up), backgroud_color(_background_color) {}

    void inicializar() {
        f = _near;
        a = 2 * f * tan(fov*M_PI/180/2);
        b = w / h * a;
        ze = eye-center;
        ze.normalize();
        xe = up.cruz(ze);
        xe.normalize();
        ye = ze.cruz(xe);
    }
    
    void renderizar();
    void renderizar(vector<Objeto*> &objetos, vector<Luz*> &luces);
};