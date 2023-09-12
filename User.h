#ifndef LISTONIC_USER_H
#define LISTONIC_USER_H

#include "string"
#include "list"
#include "ShoppingList.h"
#include "Observer.h"
using namespace std;

class User: public Observer{
private:
    string nome;
    list<ShoppingList*> liste;

public:
    // Costruttore Utente
    explicit User(const string &n);

    // Aggiungi lista all'utente
    void addLista(ShoppingList* lista);

    // Rimuovi lista all'utente
    bool remLista(const string &n);

    //visualizzazione liste utenti
    void view();

    // Aggiornamento cambiamenti di stato
    void update() ;//override

    // Getter --> nome
    const string &getNome() const;

    // Setter --> nome
    void setNome(const string &nome);

    // Getter --> liste
    const list<ShoppingList *> &getListe() const;

    // Setter --> liste
    void setListe(const list<ShoppingList *> &liste);

};

#endif //LISTONIC_USER_H
