#include "ShoppingItem.h"

#include <utility>

// Costruttore oggetto
ShoppingItem::ShoppingItem(string n, string c, int q) : name(std::move(n)),category(std::move(c)),quantity(q){
    if(q>=0)
        quantity=q;
    else
        throw out_of_range("La quantita' dell'oggetto non e' positiva");
}

// GETTER -> Nome
const string &ShoppingItem::getName() const {
    return name;
}

// GETTER -> Categoria
const string &ShoppingItem::getCategory() const {
    return category;
}

// GETTER -> Quantità
int ShoppingItem::getQuantity() const {
    return quantity;
}

// SETTER -> Quantità
void ShoppingItem::setQuantity(int q) {
    if(q>=0)
        quantity = q;
    else
        throw std::out_of_range("La quantita' dell'oggetto non e' positiva");
}

bool ShoppingItem::isBought() const {
    return bought;
}

void ShoppingItem::setBought(bool b) {
    bought = b;
}



