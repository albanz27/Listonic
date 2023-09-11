#include <iostream>
#include "string"
#include "ShoppingItem.h"
#include "ShoppingList.h"

using namespace std;

int main() {
    string nomeOggetto, categoria;
    int quantita;
    /* PROVA TASTIERA: INSERIMENTO OGGETTI
    cout<<"Inserisci il nome dell'oggetto desiderato "<<endl;
    cin>>nomeOggetto;
    cout<<"Inserisci la categoria di "<<nome<<endl;
    cin>>categoria;
    cout<<"Inserisci la quantita' di "<<nome<<endl;
    cin>>quantita;
    ShoppingItem oggetto(nome,categoria,quantita);
     */
    ShoppingItem oggetto("BANANA","FRUTTA",2);
    ShoppingItem oggetto2("tortellini","pasta",10);
    //oggetto.view();

    /*
    string nomeLista;
    cout<<"Inserisci il nome della nuova lista"<<endl;
    cin>>nomeLista;
    ShoppingList lista(nomeLista);
     */
    ShoppingList lista("spesa");
    lista.addOggetto(oggetto);
    lista.addOggetto(oggetto2);
    lista.play();
    cout<<endl<<endl;
    lista.dimQuantita("BANANA",1);
    lista.play();
    cout<<endl<<endl;

    lista.aumQuantita("tortellini",10);
    lista.play();
    cout<<endl<<endl;

    return 0;
}
