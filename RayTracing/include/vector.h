#pragma once

#include <cmath>
#include <algorithm>
#include <iostream>

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

using namespace std;

class vec3 {
public:
    float x, y, z;
    vec3(): x(0), y(0), z(0) {}
    vec3(float t) : x(t), y(t), z(t) {}
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    vec3 operator+(vec3 v) { return vec3(x + v.x, y + v.y, z + v.z); }
    vec3 operator-(vec3 v) { return vec3(x - v.x, y - v.y, z - v.z); }
    vec3 operator-() { return vec3(-x, -y, -z); }
    vec3 operator*(vec3 v) { return vec3(x * v.x, y * v.y, z * v.z); }
    vec3 operator*(float f) { return vec3(x * f, y * f, z * f); }
    vec3 operator/(vec3 v) { return vec3( x/v.x, y/v.y, z/v.z); }
    vec3 operator/(float f) { return vec3( x/f, y/f, z/f); }
    bool operator>(vec3 v) { return x > v.x && y > v.y && z > v.z; }
    
    vec3 cruz(vec3 v) {
        return vec3(y*v.z - z*v.y,
                    z*v.x - x*v.z,
                    x*v.y - y*v.x);
    }
    
    float punto(vec3 v){
        return x*v.x + y*v.y + z*v.z;
    }
    
    void normalize(){
        double m = get_magnitude();
        if(m == 0.f) return;
        x = x/m;
        y = y/m;
        z = z/m;
    }
    
    float get_magnitude() {
        return sqrt(x*x + y*y + z*z);
    }
    // para los colores
    void max_to_one(){
        float maxValue = std::max({x ,y, z});
        if(maxValue > 1){
            x /= maxValue;
            y /= maxValue;
            z /= maxValue;
        }
    }

    friend ostream& operator<<(ostream& out, vec3 v){
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
        return out;
    }
};

vec3 operator/(float f, vec3 v);
vec3 operator*(float f, vec3 v);

vec3 abs(vec3 &v);
vec3 sign(vec3 &v);
vec3 step(vec3 v1, vec3 v2);