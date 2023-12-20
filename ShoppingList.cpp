#include "ShoppingList.h"

// Costruttore lista
ShoppingList::ShoppingList(string listName) : listName(std::move(listName)) {}


// Aggiunto object
void ShoppingList::addObject(const ShoppingItem &object) {
    ShoppingList::objects.push_back(object);
    cout << "Inserimento di '" << object.getName() << "' nella lista: " << listName << endl;
    notify();
    cout<<endl;
}

// Rimozione oggetto
bool ShoppingList::removeObject(const string &n) {
    for(auto itr=objects.begin(); itr != objects.end(); itr++){
        if(itr->getName() == n) {
            cout << "Rimozione = " << itr->getName() << " dalla lista '" << listName << "'" << endl;
            objects.erase(itr);
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
    for (auto itr = objects.begin(); itr != objects.end(); itr++) {
        if (itr->getName() == n) {
            itr->setBought(a);
            if (a)
                cout << "Oggetto " << itr->getName() << " e' contrassegnato come acquistato" << endl;
            else
                cout << "Oggetto " << itr->getName() << " e' contrassegnato come NON acquistato" << endl;
            notify();
            return true;
        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

// Modifica quantità
bool ShoppingList::modQuantity(const string &n, int q, bool dec) {
    for(auto & itr : objects){
        if(itr.getName() == n) {
            // se dec è vero allora aumenta quantità altrimenti diminuisce
            if(dec){
                cout << "Aumento = " << itr.getName() << " (da '" << itr.getQuantity() << "' passa a '" <<
                                                                                                        itr.getQuantity() + q << "')" << endl;
                itr.setQuantity(itr.getQuantity() + q);
                notify();
                cout<<endl;
                return true;
            }
            else{
                if(itr.getQuantity() > q){
                    cout << "Diminuzione = " << itr.getName() << " (da '" << itr.getQuantity() << "' passa a '" <<
                                                                                                                itr.getQuantity() - q << "')" << endl;
                    itr.setQuantity(itr.getQuantity() - q);
                    notify();
                    cout<<endl;
                    return true;
                }
                else {
                    cout << "la quantity' inserita e' troppo grande" << endl << endl;
                    return false;
                }
            }

        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

// Visualizzazione lista
void ShoppingList::show() const{
    cout << " | LISTA = " << getListName() << " | " << endl;
    for(const auto& oggetto:objects){
        cout << " name = '" << oggetto.getName() << "'" << endl;
        cout << " category = '" << oggetto.getCategory() << "'" << endl;
        cout << " quantity' = '" << oggetto.getQuantity() << "'" << endl;
        cout<<" stato = '";
        if(oggetto.isBought())
            cout<<" ACQUISTATO' ";
        else
            cout<<" NON ACQUISTATO' ";
        cout<<endl<<endl;
    }
}

// GETTER -> Nome
const string &ShoppingList::getListName() const {
    return listName;
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
        observer->update(listName);
    }
}

const list<ShoppingItem> &ShoppingList::getObjects() const {
    return objects;
}

int ShoppingList::notBought() {
    int res=0;
    for(auto &itr: objects){
        if(!itr.isBought()){
            cout<<itr.getName()<<", quantita' da acquistare: "<<itr.getQuantity()<<endl;
            res+= itr.getQuantity(); //numero di oggetti da acquistare
        }
    }
    cout<<"Numero totale di oggetti da acquistare "<<res<<endl;
    return res;
}

const list<Observer *> &ShoppingList::getObservers() const {
    return observers;
}





