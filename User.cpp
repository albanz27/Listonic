#include "User.h"

User::User(const string &n) : userName(n) {}

void User::addList(ShoppingList *l) {
    lists.push_back(l);
    l->addObserver(this);
    cout << "Condivisione lista = " << l->getListName() << " con utente '" << userName << "'" << endl;
}

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

void User::view() {
    cout << "Utente " << userName << ", visualizzazione lista ->" << endl;
    for(auto list:lists)
        list->show();
}

void User::update(const string &o) {
    cout << "Notifica per utente " << getName() << endl;
    for(auto list:lists)
        if(list->getListName()==o)
            list->notBought();
}

const string &User::getName() const {
    return userName;
}

const list<ShoppingList *> &User::getLists() const {
    return lists;
}
