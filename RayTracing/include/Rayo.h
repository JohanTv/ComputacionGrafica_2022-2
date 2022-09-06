#pragma once

#include "vector.h"

class Rayo {
public:
    vec3 ori, dir;

    Rayo(){}
    Rayo(vec3 _ori) : ori(_ori), dir(vec3(0, 0, 0)) {}
    Rayo(vec3 _ori, vec3 _dir) : ori(_ori), dir(_dir) {
        dir.normalize();
    }
};