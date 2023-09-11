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

    void play() const {
        cout<<"Lista = "<<getNome()<<endl;
        for(auto oggetto:oggetti)
            oggetto.view();
    }

    const string &getNome() const;

    const list<ShoppingItem> &getOggetti() const;
};


#endif //LISTONIC_SHOPPINGLIST_H
