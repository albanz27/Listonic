#include "ShoppingList.h"

// Costruttore lista
ShoppingList::ShoppingList(const string &n) : nome(n) {}

// Aggiunto oggetto
void ShoppingList::addOggetto(const ShoppingItem &oggetto) {
    oggetti.push_back(oggetto);
    cout<<"Inserimento di '"<<oggetto.getNome()<<"' nella lista: "<<nome<<endl;
    notify();
    cout<<endl;
}

// Rimozione oggetto
bool ShoppingList::removeOggetto(const string &n) {
    for(auto itr=oggetti.begin();itr!=oggetti.end();itr++){
        if(itr->getNome()==n) {
            cout<<"Rimozione = "<<itr->getNome()<<" dalla lista '"<<nome<<"'"<<endl;
            oggetti.erase(itr);
            notify();
            cout<<endl;
            return true;
        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

// Aumento quantità
bool ShoppingList::aumQuantita(const string &n, int q) {
    for(auto itr=oggetti.begin();itr!=oggetti.end();itr++){
        if(itr->getNome()==n) {
             cout<<"Aumento = "<<itr->getNome()<<" (da '"<<itr->getQuantita()<<"' passa a '"<<itr->getQuantita()+q<<"')"<<endl;
             itr->setQuantita(itr->getQuantita()+q);
             notify();
             cout<<endl;
             return true;
        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

// Diminuzione quantità
bool ShoppingList::dimQuantita(const string &n, int q) {
    for(auto itr=oggetti.begin();itr!=oggetti.end();itr++){
        if(itr->getNome()==n) {
            if(itr->getQuantita()<=q) {
                cout<<"Rimozione = "<<itr->getNome()<<endl;
                oggetti.erase(itr);
                notify();
                cout<<endl;
                return true;
            }
            else{
                cout<<"Diminuzione = "<<itr->getNome()<<" (da '"<<itr->getQuantita()<<"' passa a '"<<itr->getQuantita()-q<<"')"<<endl;
                itr->setQuantita(itr->getQuantita()-q);
                notify();
                cout<<endl;
                return true;
            }
        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

// Visualizzazione lista
void ShoppingList::show() const{
    cout<<" | LISTA = "<<getNome()<<" | "<<endl;
    for(auto oggetto:oggetti)
        oggetto.view();
}

// GETTER -> Nome
const string &ShoppingList::getNome() const {
    return nome;
}

// SETTER -> Nome
void ShoppingList::setNome(const string &nome) {
    ShoppingList::nome = nome;
}

// GETTER -> Lista di oggetti
const list<ShoppingItem> &ShoppingList::getOggetti() const {
    return oggetti;
}

// SETTER -> Lista di oggetti
void ShoppingList::setOggetti(const list<ShoppingItem> &oggetti) {
    ShoppingList::oggetti = oggetti;
}