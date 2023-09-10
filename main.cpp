#include <iostream>
#include "string"
#include "ShoppingItem.h"

using namespace std;

int main() {
    string nome, categoria;
    int quantita;
    cout<<"Inserisci il nome dell'oggetto desiderato "<<endl;
    cin>>nome;
    cout<<"Inserisci la categoria di "<<nome<<endl;
    cin>>categoria;
    cout<<"Inserisci la quantita' di "<<nome<<endl;
    cin>>quantita;
    ShoppingItem oggetto(nome,categoria,quantita);
    oggetto.view();

    return 0;
}
