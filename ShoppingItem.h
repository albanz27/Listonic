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
    bool acquistato;

public:
    // Costruttore oggetto
    ShoppingItem(const string &nome, const string &categoria, int quantita);

    // GETTER -> Nome
    const string &getNome() const;

    // GETTER -> Categoria
    const string &getCategoria() const;

    // GETTER -> Quantità
    int getQuantita() const;

    // SETTER -> Quantità
    void setQuantita(int quantita);

};

#endif //LISTONIC_SHOPPINGITEM_H