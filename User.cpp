#include "User.h"

// Costruttore Utente
User::User(const string &n) : nome(n) {}

// Aggiungi lista utente
void User::addLista(ShoppingList *lista) {
    liste.push_back(lista);
    lista->addObserver(this);
    cout<<"Condivisione lista = "<<lista->getNome()<<" con utente '"<<nome<<"'"<<endl;
}

// Rimuovi lista utente
bool User::remLista(const string &n) {
    for(auto itr=liste.begin();itr!=liste.end();itr++){
        if((*itr)->getNome()==n) {
            cout<<"Rimozione lista = "<<(*itr)->getNome()<<" dall'utente "<<nome<<endl;
            (*itr)->removeObserver(this);
            liste.erase(itr);
            return true;
        }
    }
    cout<<"Lista non esistete"<<endl<<endl;
    return false;
}

// Visualizzazione liste utenti
void User::view() {
    cout<<"Utente "<<nome<<", visualizzazione liste ->"<<endl;
    for(auto lista:liste)
        lista->play();
}

// Aggiornamento cambiamenti di stato
void User::update() {
    cout << "Utente " << nome << " e' stato notificato di un cambiamento della lista." <<endl;
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
