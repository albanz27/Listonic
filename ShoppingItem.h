//
// Created by alban on 10/09/2023.
//

#ifndef LISTONIC_SHOPPINGITEM_H
#define LISTONIC_SHOPPINGITEM_H

#include "string"
#include <iostream>
#include <utility>

using namespace std;

class ShoppingItem {
private:
    string nome;
    string categoria;
    int quantita;

public:
    ShoppingItem(string  nome, string  categoria, int quantita);

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
