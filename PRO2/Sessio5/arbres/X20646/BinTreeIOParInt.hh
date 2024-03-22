#ifndef BINIOINT_HPP
#define BINIOINT_HPP

#include <iostream>
#include "ParInt.hh"
#include "BinTree.hh"

void read_bintree_parint(BinTree<ParInt>& a);
// Pre: a �s buit; el canal estandar d?entrada cont� un nombre
// parell d?enters, que representa un arbre binari en preordre,
// on el parell 0 0 representa un arbre buit
// Post: a cont� l?arbre que hi havia al canal estandar d?entrada

void write_bintree_parint(const BinTree<ParInt>& a); // (opcional)
// Pre: a = A
// Post: s?han escrit al canal estandar de sortida els elements
// d?a recorrreguts en inordre, a = A

#endif
