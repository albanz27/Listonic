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

    // Aggiungi lista utente
    void addLista(ShoppingList* lista);

    // Rimuovi lista utente
    bool remLista(const string &n);

    // Visualizzazione liste utenti
    void view();

    // Aggiornamento cambiamenti di stato
    void update() override;

    // GETTER Nome
    const string &getNome() const;

    // SETTER Nome
    void setNome(const string &nome);


};

#endif //LISTONIC_USER_H
