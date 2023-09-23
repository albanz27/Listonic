#include "ShoppingList.h"

// Costruttore lista
ShoppingList::ShoppingList(const string &n) : nome(n) {}

// Aggiunto oggetto
void ShoppingList::addObject(const ShoppingItem &oggetto) {
    oggetti.push_back(oggetto);
    cout<<"Inserimento di '"<<oggetto.getNome()<<"' nella lista: "<<nome<<endl;
    notify();
    cout<<endl;
}

// Rimozione oggetto
bool ShoppingList::removeObject(const string &n) {
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

// Acquista oggetto
bool ShoppingList::stateObject(const string &n, bool a) {
    for (auto itr = oggetti.begin(); itr != oggetti.end(); itr++) {
        if (itr->getNome() == n) {
            itr->setAcquistato(a);
            notify();
            if (a)
                cout << "Oggetto " << itr->getNome() << " e' contrassegnato come acquistato" << endl;
            else
                cout << "Oggetto " << itr->getNome() << " e' contrassegnato come non acquistato" << endl;
            cout << endl;
            return true;
        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

// Modifica quantità
bool ShoppingList::modQuantity(const string &n, int q, bool dec) {
    for(auto & itr : oggetti){
        if(itr.getNome()==n) {
            // se dec è vero allora aumenta quantità altrimenti diminuisce
            if(dec){
                cout<<"Aumento = "<<itr.getNome()<<" (da '"<<itr.getQuantita()<<"' passa a '"<<itr.getQuantita()+q<<"')"<<endl;
                itr.setQuantita(itr.getQuantita()+q);
                notify();
                cout<<endl;
                return true;
            }
            else{
                if(itr.getQuantita()>q){
                    cout<<"Diminuzione = "<<itr.getNome()<<" (da '"<<itr.getQuantita()<<"' passa a '"<<itr.getQuantita()-q<<"')"<<endl;
                    itr.setQuantita(itr.getQuantita()-q);
                    notify();
                    cout<<endl;
                    return true;
                }
                else
                    cout<<"la quantita' inserita e' troppo grande"<<endl;
            }

        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

// Visualizzazione lista
void ShoppingList::show() const{
    cout<<" | LISTA = "<<getNome()<<" | "<<endl;
    /*for(auto oggetto:oggetti)
        oggetto.view();*/
}

// GETTER -> Nome
const string &ShoppingList::getNome() const {
    return nome;
}

// SETTER -> Nome
void ShoppingList::setNome(const string &nome) {
    ShoppingList::nome = nome;
}

// Aggiunge Observer
void ShoppingList::addObserver(Observer *observer) {
    observers.push_back(observer);
}

// Rimuove Observer
void ShoppingList::removeObserver(Observer *observer) {
    observers.remove(observer);
}

// Notifica cambiamento
void ShoppingList::notify() {
    for (Observer* observer : observers) {
        observer->update();
    }
}


