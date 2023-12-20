#ifndef LISTONIC_USER_H
#define LISTONIC_USER_H

#include "string"
#include "list"
#include "ShoppingList.h"
#include "Observer.h"
using namespace std;

class User: public Observer{
private:
    string userName;
    list<ShoppingList*> lists;

public:
    explicit User(const string &n);

    void addList(ShoppingList* l);

    bool remList(const string &n);

    void view();

    void update(const string &o) override;

    const string &getName() const;

    const list<ShoppingList *> &getLists() const;

};

#endif //LISTONIC_USER_H
