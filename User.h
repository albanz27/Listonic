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
    // Costruttore Utente
    explicit User(const string &n);

    // Aggiungi utente
    void addList(ShoppingList* l);

    // Rimuovi lista utente
    bool remList(const string &n);

    // Visualizzazione lists utenti
    void view();

    // Aggiornamento cambiamenti di stato
    void update(const string &o) override;

    // GETTER Nome
    const string &getName() const;

    const list<ShoppingList *> &getLists() const;

};

#endif //LISTONIC_USER_H
