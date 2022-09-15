#include "Camara.h"
#include <omp.h>
#define _INFINITY (std::numeric_limits<float>::max())

vec3 Camara::get_diffuse_reflection(vec3& N, vec3& L, vec3& color, float& kd){
    vec3 diffuse(0, 0, 0);
    float factor_difuso = N.punto(L);
    if(factor_difuso > 0){
        diffuse = factor_difuso * color * kd;
    }
    return diffuse;
}

vec3 Camara::get_specular_reflection(vec3& N, vec3& L, vec3& dir, vec3& color, float& ks, float n){
    vec3 specular(0, 0, 0);
    vec3 r = 2*L.punto(N)*N-L;
    vec3 v = -dir;
    r.normalize();
    v.normalize();
    float factor_especular = r.punto(v);
    if(factor_especular > 0){
        specular = pow(factor_especular, n) * color * ks;
    }
    return specular;
}

void Camara::fill_pixel(int x, int y, vec3 color){
    // pintar el pixel con el color
    (*pImg)(x,h-1-y,0) = (BYTE)(color.x * 255);
    (*pImg)(x,h-1-y,1) = (BYTE)(color.y * 255);
    (*pImg)(x,h-1-y,2) = (BYTE)(color.z * 255);
}

vec3 Camara::calculate_color(Rayo rayo, vector<Objeto*>& objects, vector<Luz*> &luces, int depth){
    if (depth > 7)
        return this->backgroud_color;

    vec3 color, normal, N;
    float t_tmp, mindist = _INFINITY;
    Objeto* closest_object = nullptr;

    for(auto& object : objects) {
        if (object->interseccion(rayo, t_tmp, normal)) {
            if(t_tmp < mindist){
                mindist = t_tmp;
                N = normal;
                closest_object = object;
            }
        }
    }

    if(!closest_object)
        return this->backgroud_color;

    if(closest_object->is_light())
        return closest_object->color;
    
    vec3 pi = rayo.ori + mindist * rayo.dir;
    vec3 bias = 0.001 * N;
    vec3 ambiente = vec3(0.1, 0.1, 0.1) * closest_object->kd;
    vec3 diffuse, specular = {0,0,0};
    vec3 color_reflexivo, color_refractivo;

    for(auto& luz : luces){
        vec3 L = luz->cen - pi;
        float dist_to_light = L.get_magnitude();
        L.normalize();
        Rayo rayo_sombra(pi + bias, L);

        bool shadow = false;
        for(auto& object : objects){
            if (!object->is_light() && object->interseccion(rayo_sombra, t_tmp, normal)){
                if(t_tmp <= dist_to_light) {
                    if(object->idr > 0) continue;
                    shadow = true;
                    break;
                }
            }
        }

        if(shadow) goto jumpto;

        diffuse = diffuse + get_diffuse_reflection(N, L, luz->color, closest_object->kd);
        specular = specular + get_specular_reflection(N, L, rayo.dir, luz->color, closest_object->ks, closest_object->n);

        jumpto:;
    }


    float kr = closest_object->kr;
    float kt = 0;
    bool outside = rayo.dir.punto(N) < 0;
    vec3 v = -rayo.dir;

    if(closest_object->idr > 0) {
        fresnel(rayo.dir, N, closest_object->idr, kr);
        if (kr < 1) {
            kt = 1 - kr;
            Rayo rayo_refractivo;
            rayo_refractivo.ori = outside ? pi - bias : pi + bias;
            rayo_refractivo.dir = refract(rayo.dir, N, closest_object->idr);
            rayo_refractivo.dir.normalize();
            color_refractivo = calculate_color(rayo_refractivo, objects, luces, depth + 1);
        }
    }

    if (kr > 0) {
        Rayo rayo_reflexivo;
        rayo_reflexivo.ori = outside ? pi + bias : pi - bias;
        rayo_reflexivo.dir = 2 * (v.punto(N)) * N - v;
        rayo_reflexivo.dir.normalize();
        color_reflexivo = calculate_color(rayo_reflexivo, objects, luces, depth + 3);
    }

    color = closest_object->color * (ambiente + diffuse + specular);
    color = color + color_reflexivo * kr + color_refractivo * kt;
    color.max_to_one();

    return color;
}

void Camara::renderizar(vector<Objeto*> &objects, vector<Luz*> &luces) {
    float x, y, z = 0;
    while(true) {
        pImg = new CImg<BYTE>(w, h, 1, 3);
        CImgDisplay dis_img((*pImg), "Imagen RayCasting en Perspectiva ");
        Rayo rayo(eye);
#pragma omp parallel for default(none)
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                rayo.dir = -f * ze + a * (y / h - 0.5) * ye + b * (x / w - 0.5) * xe;
                rayo.dir.normalize();
                vec3 color = calculate_color(rayo, objects, luces, 1);
                fill_pixel(x, y, color);
            }

            dis_img.render((*pImg));
            dis_img.paint();
        }

        if (!dis_img.is_closed()) {
            std::cout << "Add new x, y, and z >> ";
            std::cin >> x >> y >> z;
            if(dis_img.is_closed()) break;
            dis_img.close();
            eye = vec3(x, y, z);
            inicializar();
            continue;
        }
        break;
    }
}

void Camara::renderizar(vector<Objeto*> &objects, vector<Luz*> &luces, string filename) {
    pImg = new CImg<BYTE>(w, h, 1, 3);
    CImgDisplay dis_img((*pImg), "Imagen RayCasting en Perspectiva ");
    Rayo rayo(eye);

#pragma omp parallel for default(none)
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            rayo.dir = -f * ze + a * (y / h - 0.5) * ye + b * (x / w - 0.5) * xe;
            rayo.dir.normalize();
            vec3 color = calculate_color(rayo, objects, luces, 1);
            fill_pixel(x, y, color);
        }
    }

    dis_img.render((*pImg));
    dis_img.close();

    pImg->save(filename.c_str());
}

vec3 Camara::refract(vec3 I, vec3 N, float ior){
    float cosi = clamp(-1, 1, I.punto(N));
    float etai = 1, etat = ior;
    vec3 n = N;
    if (cosi < 0) { cosi = -cosi; } else { std::swap(etai, etat); n= -N; }
    float eta = etai / etat;
    float k = 1 - eta * eta * (1 - cosi * cosi);
    return k < 0 ? vec3(0,0,0) : eta * I + (eta * cosi - sqrtf(k)) * n;
}

void Camara::fresnel(vec3 I, vec3 N, float &ior, float &kr){
    float cosi = clamp(-1, 1, I.punto(N));
    float etai = 1, etat = ior;
    if (cosi > 0) { std::swap(etai, etat); }
    // Compute sini using Snell's law
    float sint = etai / etat * sqrtf(std::max(0.f, 1 - cosi * cosi));
    // Total internal reflection
    if (sint >= 1) {
        kr = 1;
    }
    else {
        float cost = sqrtf(std::max(0.f, 1 - sint * sint));
        cosi = fabsf(cosi);
        float Rs = ((etat * cosi) - (etai * cost)) / ((etat * cosi) + (etai * cost));
        float Rp = ((etai * cosi) - (etat * cost)) / ((etai * cosi) + (etat * cost));
        kr = (Rs * Rs + Rp * Rp) / 2;
    }
    // As a consequence of the conservation of energy, transmittance is given by:
    // kt = 1 - kr;
}