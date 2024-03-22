#include "Cubeta.hh"
#include <iostream>

Cubeta::Cubeta(){}

Cubeta::Cubeta(const Cubeta& c){
    ropacolor = c.ropacolor;
    ropablanca = c.ropablanca;
}

void Cubeta::anadir_prenda(const Prenda& p){
    if (p.consul_color()) ropacolor.push(p);
    else ropablanca.push(p);
}

void Cubeta::completar_lavadora(Lavadora& lav){
    if (lav.consultar_color()) completar_lavadora_pila_it(ropacolor, lav);
    else completar_lavadora_pila_it(ropablanca, lav);   
}

void Cubeta::completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l){
    while (not p.empty() and l.consultar_peso() + p.top().consul_peso() <= l.consultar_peso_maximo()){
        l.anadir_prenda(p.top());
        p.pop();
    }
}

void Cubeta::completar_lavadora_pila_rec(stack<Prenda>& p, Lavadora& l){
    if (not p.empty() and l.consultar_peso() + p.top().consul_peso() <= l.consultar_peso_maximo()){
        p.pop();
        l.anadir_prenda(p.top());
        completar_lavadora_pila_rec(p, l);
    }
}

void Cubeta::escribir() const
{
    cout << "Ropa de color de la cubeta:" << endl;
    escribir_pila_prenda(ropacolor);
    cout << "Ropa blanca de la cubeta:" << endl;
    escribir_pila_prenda(ropablanca);
}

void Cubeta::escribir_pila_prenda(const stack<Prenda>& p){
    stack<Prenda> cub = p;
    while (not cub.empty()){
        cub.top().escribir();
        cub.pop();
    }
}

