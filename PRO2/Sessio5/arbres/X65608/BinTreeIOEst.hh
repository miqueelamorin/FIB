#ifndef BINIOINT_HPP
#define BINIOINT_HPP

#include <iostream>
#include "Estudiant.hh"
#include "BinTree.hh"

void read_bintree_est(BinTree<Estudiant>& a);
// Pre: a �s buit; el canal estandar d?entrada cont� una seq��ncia
// de parells <int, double> que representa un arbre binari d?estudiants
// en preordre, on un parell amb l?int = ??marca?? representa
// un arbre buit
// Post: a cont� l?arbre que hi havia al canal estandar d?entrada

void write_bintree_est(const BinTree<Estudiant>& a); // (opcional)
// Pre: a = A
// Post: s?han escrit al canal estandar de sortida els elements
// d?a recorreguts en inordre, a = A

#endif
