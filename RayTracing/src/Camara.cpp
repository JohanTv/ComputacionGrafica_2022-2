#include "Camara.h"

const long SPHERENUM = 10;

#define _INFINITY (std::numeric_limits<float>::max())

vec3 Camara::get_diffuse_reflection(vec3& N, vec3& L, vec3& color, vec3& kd){
    vec3 diffuse(0, 0, 0);
    float factor_difuso = N.punto(L);
    if(factor_difuso > 0){
        diffuse = factor_difuso * color * kd;
    }
    return diffuse;
}

vec3 Camara::get_specular_reflection(vec3& N, vec3& L, vec3& dir, vec3& color, vec3& ks, int n){
    vec3 specular(0, 0, 0);
    vec3 r = 2*L.punto(N)*N-L;
    vec3 v = vec3{0,0,0} - dir;
    r.normalize();
    v.normalize();
    float factor_especular = r.punto(v);
    if(factor_especular > 0){
        specular = pow(factor_especular, 4) * color * ks;
    }
    return specular;
}

void Camara::fill_pixel(int x, int y, vec3 color){
    // pintar el pixel con el color
    (*pImg)(x,h-1-y,0) = (BYTE)(color.x * 255);
    (*pImg)(x,h-1-y,1) = (BYTE)(color.y * 255);
    (*pImg)(x,h-1-y,2) = (BYTE)(color.z * 255);
}

vec3 Camara::calculate_color(Rayo rayo, vector<Objeto*>& objetos, vector<Luz*> &luces, int depth){
    if (depth > 7)
        return vec3(1,1,1);

    Luz luz = *(luces[0]);
    vec3 color(1, 1, 1);
    vec3 normal, N, L, pi;
    float t_tmp, fs = 1;
    float mindist = _INFINITY;
    Objeto* closest_object = nullptr;

    for(auto& esfera : objetos) {
        if (esfera->interseccion(rayo, t_tmp, normal)) {
            if(t_tmp < mindist){
                mindist = t_tmp;
                pi = rayo.ori + t_tmp * rayo.dir;
                N = normal;
                L = luz.pos - pi;
                closest_object = esfera;
            }
        }
    }

    if(!closest_object)
        return color;

    L.normalize();
    Rayo rayo_sombra(pi + N * 0.01, L);

    for(auto& esfera : objetos){
        if (esfera->interseccion(rayo_sombra, t_tmp, normal)){
            fs = 0;
            break;
        }
    }
    
    if(fs == 0)
        return vec3(0, 0, 0);

    vec3 diffuse = get_diffuse_reflection(N, L, luz.color, closest_object->kd);
    vec3 specular = get_specular_reflection(N, L, rayo.dir, luz.color, closest_object->ks, closest_object->n);
    
    color = closest_object->color * (diffuse + specular);
    color.max_to_one();

    if(depth != -1 && closest_object->ks > vec3(0, 0, 0)){
        vec3 v = vec3{0,0,0} - rayo.dir;
        v.normalize();

        Rayo rayo_reflexivo;
        rayo_reflexivo.ori = pi + N * 0.01;
        rayo_reflexivo.dir = 2 * (v.punto(N)) * N - v;
        vec3 color_reflexivo = calculate_color(rayo_reflexivo, objetos, luces, depth + 1);
        color = color + color_reflexivo;
        color.max_to_one();
    }
    return color;
}


void Camara::renderizar(){
    pImg = new CImg<BYTE>(w, h, 1, 10);
    CImgDisplay dis_img((*pImg), "Imagen RayCasting en Perspectiva ");
    
    vector<Luz*> luces = { new Luz({10,30,20}, {1,1,1}) };
    std::vector<Objeto*> esferas;
    for(int i = 0; i < SPHERENUM; ++i){
        auto esfera = new Esfera(vec3(this->h, this->w), rand()%3 + 1, vec3(rand()%255/255.0,rand()%255/255.0,rand()%255/255.0), vec3(0.9, 0.9, 0.9), vec3(0.9, 0.9, 0.9));
        esferas.emplace_back(esfera);
    }

    Plano *pPlano = new Plano(vec3(0,1,0), 20);
    pPlano->color = vec3(0,0,1);
    pPlano->kd = vec3(0.7, 0.7, 0.7);
    pPlano->ks = vec3(0, 0, 0);

    esferas.emplace_back(pPlano);

    Rayo rayo;
    rayo.ori = eye;

    for (int x=0; x < w; x++){
        for (int y=0; y < h; y++){
            rayo.dir = -f*ze + a*(y/h -0.5)*ye + b*(x/w-0.5)*xe;
            vec3 color = calculate_color(rayo, esferas, luces);
            fill_pixel(x, y, color);    
        }

        dis_img.render((*pImg));
        dis_img.paint();
    }

    while (!dis_img.is_closed()) {
        dis_img.wait();
    }
}

void Camara::renderizar(vector<Objeto*> &objetos, vector<Luz*> &luces) {
    pImg = new CImg<BYTE>(w, h, 1, 10);
    CImgDisplay dis_img((*pImg), "Imagen RayCasting en Perspectiva ");

    Rayo rayo;
    rayo.ori = eye;

    for (int x=0; x < w; x++){
        for (int y=0; y < h; y++){
            rayo.dir = -f*ze + a*(y/h -0.5)*ye + b*(x/w-0.5)*xe;
            vec3 color = calculate_color(rayo, objetos, luces, 1);
            fill_pixel(x, y, color);    
        }

        dis_img.render((*pImg));
        dis_img.paint();
    }

    while (!dis_img.is_closed()) {
        dis_img.wait();
    }
}