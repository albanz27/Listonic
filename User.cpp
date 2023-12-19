#include "User.h"

// Costruttore Utente
User::User(const string &n) : userName(n) {}

// Aggiungi utente
void User::addList(ShoppingList *l) {
    lists.push_back(l);
    l->addObserver(this);
    cout << "Condivisione lista = " << l->getListName() << " con utente '" << userName << "'" << endl;
}

// Rimuovi lista utente
bool User::remList(const string &n) {
    for(auto itr=lists.begin(); itr != lists.end(); itr++){
        if((*itr)->getListName() == n) {
            cout << "Rimozione lista = " << (*itr)->getListName() << " dall'utente " << userName << endl;
            (*itr)->removeObserver(this);
            lists.erase(itr);
            return true;
        }
    }
    cout<<"Lista non esistete"<<endl<<endl;
    return false;
}

// Visualizzazione lists utenti
void User::view() {
    cout << "Utente " << userName << ", visualizzazione lists ->" << endl;
    for(auto list:lists)
        list->show();
}

// Aggiornamento cambiamenti di stato
void User::update(const string &o) {
    cout << "Notifica per utente " << getName() << endl;

    for(auto list:lists)
        if(list->getListName()==o)
            list->notBought();
}


// GETTER -> Nome
const string &User::getName() const {
    return userName;
}

const list<ShoppingList *> &User::getLists() const {
    return lists;
}


