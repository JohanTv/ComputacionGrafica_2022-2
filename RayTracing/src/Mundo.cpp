#include "Mundo.h"

void Mundo::reset(){
    for(int i = 0; i < objetos.size(); i++){
        delete objetos[i];
    }

    for(int i = 0; i < luces.size(); i++){
        delete luces[i];
    }

    objetos.clear();
    luces.clear();
}

void Mundo::solidify_lights(){
    for (auto it: luces){
        if(it->visible){
            objetos.emplace_back(it);
        }
    }
}

void Mundo::Escenario0(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3, 5, 30), 4, 60, 600, 400);
    camara.inicializar();

    luces = { new Luz({10,30,20}, {1,1,1}, true) };
    solidify_lights();

    const long SPHERENUM = 10;
    vec3 center, color;
    float radio;
    //srand(time(NULL));
    for(int i = 0; i < SPHERENUM; ++i){
        color = vec3(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);
        radio = rand() % 3 + 1;
        center = vec3(rand() % 20 - 10, rand() % 20 - 10, rand() % 20 - 10);
        auto pEsf = new Esfera(center, radio);
        pEsf->set(color, 0.9, 0.4, 4);
        objetos.emplace_back(pEsf);
    }

    Plano *pPlano = new Plano(vec3(0,1,0), 20);
    pPlano->set(vec3(0,0,1), 0.7, 0, 2);

    objetos.emplace_back(pPlano);
    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario1(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3, 5, 30), 4, 60, 600, 400);
    camara.backgroud_color = vec3{0,0,0};
    camara.inicializar();

    Luz *pLuz = new Luz({10,30,20}, {1,1,1}, true);
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 4);
    pEsf->set(vec3(1, 0, 0), 0.9, 0.1, 8);

    Esfera *pEsf2 = new Esfera(vec3(3,9,0), 4);
    pEsf2->set(vec3(1, 0, 0), 0.9, 0.1, 32);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0,0,1), 0.7, 0, 0);

    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pPlano );

    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario2(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,15,0), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz({10,30,20}, {1,1,1}, true);
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 5);
    pEsf->set(vec3(0,1,0), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,0,0), 0.9, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0,0,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7);

    objetos.emplace_back( pEsf );
    //objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    //objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario3(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,15,30), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz({10,30,20}, {1,1,1}, true);
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 5);
    pEsf->set(vec3(0,1,0), 0.9, 0.5, 8, 1.5);

//    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
//    pEsf2->set(vec3(1,0,0), 0.9, 1, 32);
//
//    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
//    pEsf3->set(vec3(1,1,0), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0,0,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7,0.5,8);

    objetos.emplace_back( pEsf );
//    objetos.emplace_back( pEsf2 );
//    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario4(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,15,30), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz({10,30,20}, {1,1,1}, true);
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,10,0), 5);
    pEsf->set(vec3(1,1,1), 0.9, 0.5, 8, 1.5);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7, 0.5, 8);

    objetos.emplace_back( pEsf );
    objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario5(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(10,30,80), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz({4,5,5}, {1,1,1}, true);
    luces.emplace_back(pLuz);
    solidify_lights();

    Esfera *pEsf = new Esfera(vec3(3,3,0), 3);
    pEsf->set(vec3(0.1,1,0.1), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,0.1,0.1), 0.1, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0.1), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0.1,0.1,1), 0.1);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7);

    Cilindro *pCil1 = new Cilindro(vec3(0,2,10), vec3(0,10,10), 6);
    pCil1->set(vec3(0.1,1,1), 0, 0.9, 8, 1.5);

    objetos.emplace_back( pEsf );
    //objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );
    objetos.emplace_back(pCil1);

    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario6(){ // STEPHANO
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,15,30), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz({10,30,20}, {1,1,1}, true);
    luces.emplace_back(pLuz);
    Cilindro *pCil1 = new Cilindro(vec3(1,4,1), vec3(2,4,1), 4);
    pCil1->set(vec3(0,1,0), 0.7, 0, 0, 0);
    Plano *pPlano = new Plano(vec3(0,1,0), 20);
    pPlano->set( vec3(0.66,0,1) , 0.7, 0.5, 8, 0);

    objetos.emplace_back( pCil1 );
    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario7(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,20,50), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(20, 5, 0), vec3(1, 1, 1), true, 2);
    luces.emplace_back(pLuz);
    solidify_lights();

    Esfera *pEsf = new Esfera(vec3(3,3,0), 3);
    pEsf->set(vec3(0.1,1,0.1), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,1,1), 0.5, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0.1), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),0);
    pPlano->set(vec3(0.1,0.1,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),-10);
    pPlano2->set(vec3(1,1,1), 0.2, 1, 8);

    Cilindro *pCil1 = new Cilindro(vec3(1,2,10), vec3(1,10,10), 6);
    pCil1->set(vec3(0.1,1,1), 0, 0.9, 8, 1.5);

//     objetos.emplace_back( pEsfLuz );
    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );
    objetos.emplace_back(pCil1);

    camara.renderizar(objetos, luces);
}

void Mundo::Proyecto1(){
        camara = Camara(vec3(0, 0, 0), vec3(0,1,0), vec3(3,20,50), 4, 60, 800, 600);
        camara.inicializar();

        Luz *pLuz = new Luz(vec3(30, 5, 20), vec3(1, 1, 1), true, 2);
        luces.emplace_back(pLuz);

        // Luciernagas
        Luz *luciernaga1 = new Luz(vec3(6, 11, 15), vec3(1, 1, 0), true, 1);
        luces.emplace_back(luciernaga1);
        // Luciernagas

        solidify_lights();
        Plano *pPlano = new Plano(vec3(0,1,0),0);
        pPlano->set(vec3(0.1,0.1,1), 0.7);

        Plano *pPlano2 = new Plano(vec3(1,0,0),-10);
        pPlano2->set(vec3(1,1,1), 0.2, 1, 8);

        Cilindro *pCil1 = new Cilindro(vec3(6,2,15), vec3(6,20,15), 10);
        pCil1->set(vec3(0.1,1,1), 0, 0.9, 8, 1.5);

        objetos.emplace_back( pPlano );
        objetos.emplace_back( pPlano2 );
        objetos.emplace_back(pCil1);

        camara.renderizar(objetos, luces);

        reset();
}
