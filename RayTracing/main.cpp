#include <iostream>
#include <map>
#include <functional>
#include "Mundo.h"

using namespace std;

Mundo mundo;

map<int, function<void()>> escenarios = { 
    {0, [](){ mundo.Escenario0(); }}, {1 , [](){ mundo.Escenario1(); }}, {2 , [](){ mundo.Escenario2(); }},
    {3 , [](){ mundo.Escenario3(); }}, {4 , [](){ mundo.Escenario4(); }}, {5 , [](){ mundo.Escenario5(); }},
    {6 , [](){ mundo.Escenario6(); }}, {7 , [](){ mundo.Escenario7(); }} 
    };

map<int, function<void()>> proyectos = {
    {1, [](){ mundo.Proyecto1(); }}
};


void ver(bool _proyectos){
    auto mymap = _proyectos ? proyectos : escenarios;
    int op = -1;
    while(true){
        cout << "Inserte opcion >> "; cin >> op;
        if(mymap.find(op) != mymap.end()){
            mymap[op]();
        }
        if(op == -1) break;
    }
}

void menu(){
    int op = -1;
    cout << "[1] Ver escenarios" << endl;
    cout << "[2] Ver proyectos" << endl;
    cout << "Inserte opcion >> "; cin >> op;
    if(op == 1) ver(false);
    else if(op == 2) ver(true);
}

int main() {
//    menu();
    mundo.Proyecto1();
    return 0;
}