#ifndef LISTONIC_SHOPPINGITEM_H
#define LISTONIC_SHOPPINGITEM_H

#include "string"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <utility>

using namespace std;

class ShoppingItem {
private:
    string name;
    string category;
    int quantity;
    bool bought = false;

public:
    // Costruttore oggetto
    ShoppingItem(string n, string c, int q);

    // GETTER -> Nome
    const string &getName() const;

    // GETTER -> Categoria
    const string &getCategory() const;

    // GETTER -> Quantità
    int getQuantity() const;

    // SETTER -> Quantità
    void setQuantity(int q);

    bool isBought() const;

    void setBought(bool acquistato);

};

#endif //LISTONIC_SHOPPINGITEM_H