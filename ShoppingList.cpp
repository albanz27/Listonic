#include "ShoppingList.h"

ShoppingList::ShoppingList(string listName) : listName(std::move(listName)) {}

void ShoppingList::addObject(const ShoppingItem &object) {
    ShoppingList::objects.push_back(object);
    cout << "Inserimento di '" << object.getName() << "' nella lista: " << listName << endl;
    notify();
    cout<<endl;
}

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

bool ShoppingList::stateObject(const string &n, bool a) {
    for (auto & object : objects) {
        if (object.getName() == n) {
            object.setBought(a);
            if (a)
                cout << "Oggetto " << object.getName() << " e' contrassegnato come acquistato" << endl;
            else
                cout << "Oggetto " << object.getName() << " e' contrassegnato come NON acquistato" << endl;
            notify();
            return true;
        }
    }
    cout<<"Oggetto non esistente"<<endl<<endl;
    return false;
}

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

void ShoppingList::show() const{
    cout << " | LISTA = " << getListName() << " | " << endl;
    for(const auto& object:objects){
        cout << " name = '" << object.getName() << "'" << endl;
        cout << " category = '" << object.getCategory() << "'" << endl;
        cout << " quantity' = '" << object.getQuantity() << "'" << endl;
        cout<<" stato = '";
        if(object.isBought())
            cout<<" ACQUISTATO' ";
        else
            cout<<" NON ACQUISTATO' ";
        cout<<endl<<endl;
    }
}

const string &ShoppingList::getListName() const {
    return listName;
}

void ShoppingList::addObserver(Observer *observer) {
    observers.push_back(observer);
}

void ShoppingList::removeObserver(Observer *observer) {
    observers.remove(observer);
}

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
    for (auto &object: objects) {
        if (!object.isBought()) {
            cout << object.getName() << ", quantita' da acquistare: " << object.getQuantity() << endl;
            res += object.getQuantity(); //numero di oggetti da acquistare
        }
    }

    cout<<"Numero totale di oggetti da acquistare "<<res<<endl;
    return res;
}

const list<Observer *> &ShoppingList::getObservers() const {
    return observers;
}
