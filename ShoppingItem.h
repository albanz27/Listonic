//
// Created by alban on 10/09/2023.
//

#ifndef LISTONIC_SHOPPINGITEM_H
#define LISTONIC_SHOPPINGITEM_H

#include "string"
#include <iostream>

using namespace std;

class ShoppingItem {
private:
    string nome;
    string categoria;
    int quantita;

public:
    ShoppingItem(const string& nome, const string& categoria, int quantita) : nome(nome), categoria(categoria),quantita(quantita){}

    void view();


    const string &getNome() const {
        return nome;
    }

    const string &getCategoria() const {
        return categoria;
    }

    int getQuantita() const {
        return quantita;
    }
};


#endif //LISTONIC_SHOPPINGITEM_H
