#include "vector.h"

vec3 operator/(float f, vec3 v) {
    if (v.x == 0 || v.y == 0 || v.z == 0) {
        //std::cout << "Hay cero";
    }
    float tx = (v.x == 0) ? f/0.01 : f/v.x;
    float ty = (v.y == 0) ? f/0.01 : f/v.y;
    float tz = (v.z == 0) ? f/0.01: f/v.z;

    return vec3(tx, ty, tz);
}

vec3 operator*(float f, vec3 v) {
    return v * f;
}