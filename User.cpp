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
            //(*itr)->removeObserver(this);
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
        lista->show();
}

// Aggiornamento cambiamenti di stato
void User::update() {
    cout<<"Notifica per utente "<<getNome()<<endl;
    // stampa oggetti da acquistare numerati
    for (auto lista : liste) {
        int conta = 0;
        if(!lista->oggetti.empty())
            cout <<"Lista: " << lista->getNome() <<" oggetti da acquistare"<< endl;
        for (const auto& oggetto : lista->oggetti) {
            if (!oggetto.isAcquistato()) {
                conta++;
                cout << conta<<") " << oggetto.getNome() << endl;
            }
        }
    }
    // stampa oggetti acquistati numerati
    for (auto lista : liste) {
        int conta = 0;
        for (const auto& oggetto : lista->oggetti) {
            if (oggetto.isAcquistato()) {
                if(conta==0)
                    cout <<"Lista: " << lista->getNome() <<" oggetti acquistati"<< endl;
                conta++;
                cout << conta<<") " << oggetto.getNome() << endl;
            }
        }
    }
    cout<<endl;
}


// GETTER -> Nome
const string &User::getNome() const {
    return nome;
}

// SETTER -> Nome
void User::setNome(const string &nome) {
    User::nome = nome;
}
