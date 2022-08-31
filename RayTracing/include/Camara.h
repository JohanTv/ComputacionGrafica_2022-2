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
    vec3 get_diffuse_reflection(vec3& N, vec3& L, vec3& color, vec3& kd);
    vec3 get_specular_reflection(vec3& N, vec3& L, vec3& pi, vec3& color, vec3& ks, int n);
    void fill_pixel(int x, int y, vec3 color);
    vec3 calculate_color(Rayo rayo, vector<Objeto*>& objetos, vector<Luz*>& luces, int depth = -1);
public:
    float fov, w, h, _near;
    vec3 eye, center, up;
    float f, a, b;
    vec3 xe, ye, ze;
    CImg<BYTE> *pImg;

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