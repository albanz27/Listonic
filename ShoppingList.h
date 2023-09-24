#ifndef LISTONIC_SHOPPINGLIST_H
#define LISTONIC_SHOPPINGLIST_H

#include "string"
#include "list"
#include "ShoppingItem.h"
#include "Subject.h"
using namespace std;

class ShoppingList: public Subject {
private:
    string nome;

public:
    // Costruttore lista
    explicit ShoppingList(const string &n);

    // Aggiunto oggetto
    void addObject(const ShoppingItem &oggetto);

    // Rimozione oggetto
    bool removeObject(const string &n);

    // Acquista oggetto
    bool stateObject(const string &n, bool a);

    // Modifica quantità
    bool modQuantity(const string &n, int q, bool dec);

    // Visualizzazione lista
    void show() const;

    // Aggiunge Observer
    void addObserver(Observer* observer) override;

    // Rimuove Observer
    void removeObserver(Observer* observer) override;

    // Notifica cambiamento
    void notify() override;


    // GETTER -> Nome
    const string &getNome() const;

    // SETTER -> Nome
    void setNome(const string &nome);

    list<ShoppingItem> oggetti;
};

#endif //LISTONIC_SHOPPINGLIST_H
