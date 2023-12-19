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
    // Costruttore lista
    explicit ShoppingList(string listName);

    // Distruttore
    virtual ~ShoppingList()= default;

    // Aggiunto object
    void addObject(const ShoppingItem &object);

    // Rimozione oggetto
    bool removeObject(const string &n);

    // Acquista oggetto
    bool stateObject(const string &n, bool a);

    // Modifica quantità
    bool modQuantity(const string &n, int q, bool dec);

    int notBought();

    // Visualizzazione lista
    void show() const;

    // Aggiunge Observer
    void addObserver(Observer* observer) override;

    // Rimuove Observer
    void removeObserver(Observer* observer) override;

    // Notifica cambiamento
    void notify() override;


    // GETTER -> Nome
    const string &getName() const;

    // SETTER -> Nome
    void setName(const string &n);

    const list<ShoppingItem> &getObjects() const;


};

#endif //LISTONIC_SHOPPINGLIST_H
