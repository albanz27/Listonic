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
    // Costruttore oggetto
    ShoppingItem(string nome, string categoria, int quantita);

    // Visualizzazione oggetti
    void view();

    // GETTER -> Nome
    const string &getNome() const;

    // GETTER -> Categoria
    const string &getCategoria() const;

    // GETTER -> Quantità
    int getQuantita() const;

};

#endif //LISTONIC_SHOPPINGITEM_H