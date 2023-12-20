#ifndef LISTONIC_SHOPPINGLIST_H
#define LISTONIC_SHOPPINGLIST_H

#include "string"
#include "list"
#include "memory"
#include "ShoppingItem.h"
#include "Subject.h"
using namespace std;

class ShoppingList: public Subject {
private:
    string listName;
    list<Observer*> observers;
    list<ShoppingItem> objects;

public:
    explicit ShoppingList(string listName);

    virtual ~ShoppingList()= default;

    void addObject(const ShoppingItem &object);

    bool removeObject(const string &n);

    bool stateObject(const string &n, bool a);

    bool modQuantity(const string &n, int q, bool dec);

    int notBought();

    void show() const;

    void addObserver(Observer* observer) override;

    void removeObserver(Observer* observer) override;

    void notify() override;

    const string &getListName() const;

    const list<ShoppingItem> &getObjects() const;

    const list<Observer *> &getObservers() const;

};

#endif //LISTONIC_SHOPPINGLIST_H