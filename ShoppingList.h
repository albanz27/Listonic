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
    list<ShoppingItem> oggetti;

public:
    // Costruttore di default
    ShoppingList();
    // Costruttore lista
    explicit ShoppingList(const string &n);

    // Aggiunto oggetto
    void addOggetto(const ShoppingItem &oggetto);

    // Rimozione oggetto
    bool removeOggetto(const string &n);

    // Aumento quantità
    bool aumQuantita(const string &n, int q);

    // Diminuzione quantità
    bool dimQuantita(const string &n, int q);

    // Visualizzazione lista
    void play() const;

    // GETTERE -> Nome
    const string &getNome() const;

    void setNome(const string &nome);

    const list <ShoppingItem> &getOggetti() const;

    void setOggetti(const list <ShoppingItem> &oggetti);

};

#endif //LISTONIC_SHOPPINGLIST_H
