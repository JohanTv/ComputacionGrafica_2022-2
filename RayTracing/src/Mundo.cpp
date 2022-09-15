#include "Mundo.h"
#include "Esferav2.h"

void Mundo::reset(){
    for(int i = 0; i < objetos.size(); i++){
        if(objetos[i]->is_light()) continue;
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

    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );
    objetos.emplace_back(pCil1);

    camara.renderizar(objetos, luces);
    reset();
}

void Mundo::Proyecto1(){
    camara = Camara(vec3(0, 0, 0), vec3(0,1,0), vec3(3,30,50), 4, 60, 800, 600);
    camara.inicializar();
    // 3 50 30
    // -5 50 -5
     Luz *pLuz = new Luz(vec3(6, 30, 15), vec3(0.3, 0.3, 0.3), true, 2);
     luces.emplace_back(pLuz);

    // Luciernagas
    vector<Luz*> luciernagas;
    Luz *luciernaga1 = new Luz(vec3(6, 11, 15), vec3(1, 1, 0.01), true, 1);
    Luz *luciernaga2 = new Luz(vec3(10, 5, 20), vec3(1, 1, 0.01), true, 1);
    Luz *luciernaga3 = new Luz(vec3(4, 15, 20), vec3(1, 1, 0.01), true, 1);
    Luz *luciernaga4 = new Luz(vec3(4, 5, 20), vec3(1, 1, 0), true, 1);
    luces.emplace_back(luciernaga1);
    luces.emplace_back(luciernaga2);
    luces.emplace_back(luciernaga3);
    luciernagas = {luciernaga1, luciernaga2, luciernaga3};
    // Luciernagas
    solidify_lights();
    Esfera *pEsf = new Esfera(vec3(25,15,-5), 5);
    pEsf->set(vec3(0.1,1,0.1), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(30,5,10), 5);
    pEsf2->set(vec3(1,0.1,0.1), 0.1, 0.9, 16, 0, 1.3);
//        Esfera *pEsf = new Esfera(vec3(3,3,0), 3);
//        pEsf->set(vec3(0.1,1,0.1), 0.9, 0.5, 8, 1.5);
    Esfera *pEsf3 = new Esfera(vec3(19,15,0), 2);
    pEsf3->set(vec3(1,0.1,0.1), 0.1, 0.9, 16, 0, 1.3);

    Plano *pPlano = new Plano(vec3(0,1,0),0);
    pPlano->set(vec3(0.1,0.1,1), 0.5);

    Plano *pPlano2 = new Plano(vec3(1,0,0),-10);
    pPlano2->set(vec3(0.5,0.5,0.5), 0, 0, 8,  0, 1.2);

    Cilindro *jarra = new Cilindro(vec3(6,2,15), vec3(6,20,15), 10);
    jarra->set(vec3(0.01,0.01,1), 0, 0.9, 8, 1.5);

    Cilindro *tapa = new Cilindro(vec3(6,19.9,15), vec3(6,22,15), 5);
    tapa->set(vec3(0.7,0.7,0.7), 0.5, 0.9, 8, 0, 0);

    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );
    objetos.emplace_back(jarra);
    objetos.emplace_back(tapa);
    objetos.emplace_back(pEsf);
    objetos.emplace_back(pEsf2);
    objetos.emplace_back(pEsf3);

    int op = 1;
    cout << "[1] Generar una imagen" << endl;
    cout << "[2] Generar video" << endl;
    cout << "Inserte opcion >> ";
    cin >> op;
    if(op == 1) camara.renderizar(objetos, luces);
    else if(op == 2) generar_video(luciernagas);

    reset();
}

void Mundo::generar_video(vector<Luz*> luciernagas){
    int video_time = 2; // en segundos
    int fps = 10; // frames por segundos
    float loop_time = 1;
    int total_frames = fps * video_time;
    float step = 360.0 / (fps / loop_time);
    //vector<Luz*> luciernagas = luces;
    vector<Esferav2*> change_pos;
    srand(time(NULL));
    for(auto& luciernaga : luciernagas){
        change_pos.push_back(new Esferav2(luciernaga->cen, step, 0.8, rand() % 6, rand() % 2));
    }
 
    for(int i = 0; i < total_frames; i++){
        string filename = "imagen_" + to_string(i) + ".bmp";
        camara.renderizar(objetos, luces, filename);

        for(int j = 0; j < luciernagas.size(); j++){
            luciernagas[j]->cen = change_pos[j]->calculate_next_coordinate();
        }
    }

    for(int i = 0; i < change_pos.size(); i++){
        delete change_pos[i];
    }

    change_pos.clear();
}