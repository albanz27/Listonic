//
// Created by alban on 11/09/2023.
//

#ifndef LISTONIC_SHOPPINGLIST_H
#define LISTONIC_SHOPPINGLIST_H

#include "string"
#include "list"
#include "ShoppingItem.h"
using namespace std;

class ShoppingList {
private:
    string nome;
    list<ShoppingItem> oggetti;

public:
    explicit ShoppingList(const string &n);

    void addOggetto(const ShoppingItem& oggetto);

    bool removeOggetto(const string &n);

    bool aumQuantita(const string &n, int q);

    bool dimQuantita(const string &n, int q);

    void play() const;

    const string &getNome() const;

    const list<ShoppingItem> &getOggetti() const;
};


#endif //LISTONIC_SHOPPINGLIST_H
