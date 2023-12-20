#include "ShoppingItem.h"

ShoppingItem::ShoppingItem(string n, string c, int q) : name(std::move(n)),category(std::move(c)),quantity(q){
    if(q>=0)
        quantity=q;
    else
        throw out_of_range("La quantita' dell'oggetto non e' positiva");
}

const string &ShoppingItem::getName() const {
    return name;
}

const string &ShoppingItem::getCategory() const {
    return category;
}

int ShoppingItem::getQuantity() const {
    return quantity;
}

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