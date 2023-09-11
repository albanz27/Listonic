//
// Created by alban on 11/09/2023.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(const string &n) : nome(n) {}

void ShoppingList::addOggetto(const ShoppingItem &oggetto) {
    oggetti.push_back(oggetto);
    //notifyObservers();
}

bool ShoppingList::removeOggetto(const string &n) {
    for(auto itr=oggetti.begin();itr!=oggetti.end();itr++){
        if(itr->getNome()==n) {
            cout<<"Rimozione = "<<itr->getNome()<<endl;
            oggetti.erase(itr);
            //notifyObservers();
            return true;
        }
    }
    return false;
}

const string &ShoppingList::getNome() const {
    return nome;
}

const list<ShoppingItem> &ShoppingList::getOggetti() const {
    return oggetti;
}
