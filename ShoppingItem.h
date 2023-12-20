#ifndef LISTONIC_SHOPPINGITEM_H
#define LISTONIC_SHOPPINGITEM_H

#include "string"
#include "iostream"
#include "exception"
#include "stdexcept"
#include "utility"

using namespace std;

class ShoppingItem {
private:
    string name;
    string category;
    int quantity;
    bool bought = false;

public:
    ShoppingItem(string n, string c, int q);

    const string &getName() const;

    const string &getCategory() const;

    int getQuantity() const;

    void setQuantity(int q);

    bool isBought() const;

    void setBought(bool b);

};

#endif //LISTONIC_SHOPPINGITEM_H