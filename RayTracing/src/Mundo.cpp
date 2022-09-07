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

void Mundo::Escenario0(){
    camara.center=vec3(0,0,0);
    camara.up=vec3(0,1,0);
    camara.eye=vec3(3,5,30);
    camara._near=4;
    camara.fov = 60;
    camara.w = 600;
    camara.h = 400;
    camara.backgroud_color = vec3(1, 1, 1);
    camara.inicializar();

    luces = { new Luz({10,30,20}, {1,1,1}) };
    const long SPHERENUM = 10;
    vec3 center, color;
    float radio;
    //srand(time(NULL));
    for(int i = 0; i < SPHERENUM; ++i){
        color = vec3(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);
        radio = rand() % 3 + 1;
        center = vec3(rand() % 20 - 10, rand() % 20 - 10, rand() % 20 - 10);
        auto pEsf = new Esfera(center, radio, color, 0.9, 0.4, 4);
        objetos.emplace_back(pEsf);
    }

    Plano *pPlano = new Plano(vec3(0,1,0), 20);
    pPlano->color = vec3(0,0,1);
    pPlano->kd = 0.7;
    pPlano->ks = 0;

    objetos.emplace_back(pPlano);
    camara.renderizar(objetos, luces, true);
    reset();
}

void Mundo::Escenario1(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3, 5, 30), 4, 60, 600, 400);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 4);
    pEsf->color = vec3(1,0,0);
    pEsf->kd = 0.9;
    pEsf->ks = 0.1;
    pEsf->n = 8;

    Esfera *pEsf2 = new Esfera(vec3(3,9,0), 4);
    pEsf2->color = vec3(1,0,0);
    pEsf2->kd = 0.9;
    pEsf2->ks = 0.1;
    pEsf2->n = 32;

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->color=vec3(0,0,1);
    pPlano->kd = 0.7;
    pPlano->ks = 0;

    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pPlano );

    camara.renderizar(objetos, luces, true);
    reset();
}

void Mundo::Escenario2(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,15,0), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
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

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
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

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,10,0), 5);
    pEsf->set(vec3(1,1,1), 0.9, 0.5, 8, 1.5);

    // Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    // pEsf2->set(vec3(1,0,0), 0.9, 1, 32);

    // Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    // pEsf3->set(vec3(1,1,0), 0.9);

    // Plano *pPlano = new Plano(vec3(0,1,0),2);
    // pPlano->set(vec3(0,0,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7, 0.5, 8);

    objetos.emplace_back( pEsf );
    // objetos.emplace_back( pEsf2 );
    // objetos.emplace_back( pEsf3 );
    // objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Escenario5(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,15,40), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 3);
    pEsf->set(vec3(0.1,1,0.1), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,0.1,0.1), 0.1, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0.1), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0.1,0.1,1), 0.7);

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

    Luz *pLuz = new Luz({10,30,20}, {1,1,1});
    luces.emplace_back(pLuz);
    Cilindro *pCil1 = new Cilindro(vec3(1,4,1), vec3(2,4,1), 4);
    pCil1->set(vec3(0,1,0), 0.7, 0, 0, 0);
    Plano *pPlano = new Plano(vec3(0,1,0), 20);
    pPlano->set( vec3(0.66,0,1) , 0.7, 0.5, 8, 0);

    objetos.emplace_back( pCil1 );
    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Proyecto1(){
    camara = Camara(vec3(0,0,0), vec3(0,1,0), vec3(3,15,30), 4, 60, 800, 600);
    camara.inicializar();

    Cilindro *pCil1 = new Cilindro(vec3(0,2,10), vec3(0,10,10), 6);
    pCil1->set(vec3(0.1,1,1), 0, 0.9, 8, 0);


    reset();
}