//
// Created by alban on 12/09/2023.
//

#include "User.h"

User::User(const string &n) : nome(n) {}

void User::addLista(ShoppingList *lista) {
    liste.push_back(lista);
    lista->addObserver(this);
}

bool User::remLista(const string &n) {
    for(auto itr=liste.begin();itr!=liste.end();itr++){
        if((*itr)->getNome()==n) {
            cout<<"Rimozione = "<<(*itr)->getNome()<<endl;
            (*itr)->removeObserver(this);
            liste.erase(itr);
            return true;
        }
    }
    return false;
}


void User::view() {
    cout<<"Utente "<<nome<<", visualizzazione liste ->"<<endl;
    for(auto lista:liste)
        lista->play();
}

void User::update() {
    cout << "Utente " << nome << " è stato notificato di un cambiamento della lista." <<endl;
}

const string &User::getNome() const {
    return nome;
}

void User::setNome(const string &nome) {
    User::nome = nome;
}

const list<ShoppingList *> &User::getListe() const {
    return liste;
}

void User::setListe(const list<ShoppingList *> &liste) {
    User::liste = liste;
}


