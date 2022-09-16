#pragma once

#include "vector.h"
#include <cassert>
#include <cmath>

class Esferav2{
private:
    float tetha, phi, radio;
    float step;
    bool sideway;
    vec3 center;
    
public:
    Esferav2(vec3 _center, float _step, float _radio, bool _sideway, float _tetha, float _phi){
        center = _center;
        step = _step;
        radio = _radio;
        sideway = _sideway;
        tetha = _tetha;
        phi = _phi;
    }

    Esferav2(vec3 pos, float _step, float _radio = 1, int op = 1, bool _sideway = true){
        sideway = _sideway;
        radio = _radio;
        step = _step;
        if(op == 0){
            phi = 90, tetha = 90;
            center = vec3(pos.x, pos.y - radio, pos.z);
        }else if(op == 1){
            phi = 0, tetha = 90;
            center = vec3(pos.x - radio, pos.y, pos.z);
        }else if(op == 2){
            phi = -90, tetha = 90;
            center = vec3(pos.x, pos.y + radio, pos.z);
        }else if(op == 3){
            phi = 180, tetha = 90;
            center = vec3(pos.x + radio, pos.y, pos.z);
        }else if(op == 4){
            sideway = false;
            phi = (rand() % 2) ? 0 : 90, tetha = 0;
            center = vec3(pos.x, pos.y, pos.z - radio);
        }else{
            sideway = false;
            phi = (rand() % 2) ? 0 : 90, tetha = 180;
            center = vec3(pos.x, pos.y, pos.z + radio);
        }
    }

    Esferav2(vec3 pos, float _step, float _radio, int op, bool _sideway, int x){
        sideway = _sideway;
        radio = _radio;
        step = _step;
        phi = rand() % 181,  tetha = rand() % 181;
        if(op == 0){
            center = vec3(pos.x, pos.y - radio, pos.z);
        }else if(op == 1){
            center = vec3(pos.x - radio, pos.y, pos.z);
        }else if(op == 2){
            center = vec3(pos.x, pos.y + radio, pos.z);
        }else if(op == 3){
            center = vec3(pos.x + radio, pos.y, pos.z);
        }else if(op == 4){
            sideway = false;
            center = vec3(pos.x, pos.y, pos.z - radio);
        }else{
            sideway = false;
            center = vec3(pos.x, pos.y, pos.z + radio);
        }
    }

    vec3 get_next_coordinate(){
        float tetha_rad = this->tetha * M_PI / 180.0f;
        float phi_rad = this->phi * M_PI / 180.0f;
        float x = center.x + radio * sin(tetha_rad) * cos(phi_rad);
        float y = center.y + radio * sin(tetha_rad) * sin(phi_rad);
        float z = center.z + radio * cos(tetha_rad);
        return vec3(x,y,z);
    }

    void reduce(float& angle){
        if(angle >= 360) angle -= 360;
        else if(angle <= -360) angle += 360;
    }

    vec3 calculate_next_coordinate(){
        if(sideway) {
            phi = phi + step;
            reduce(phi);
        }
        else {
            tetha = tetha + step;
            reduce(tetha);
        }

        return get_next_coordinate();
    }
};