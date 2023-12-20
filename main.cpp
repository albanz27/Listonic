#include <iostream>
#include "string"
#include "ShoppingItem.h"
#include "ShoppingList.h"
#include "User.h"

using namespace std;

/*
 *  Classi che rappresentano una lista della spesa (es. Listonic):
 *  un utente deve avere diverse liste della spesa dove segnare
 *  oggetti da acquistare che appartengono a diverse categorie
 *  ed eventualmente con quantità da acquistare.
 *  Si usa Observer per aggiornare il numero di oggetti da acquistare
 *  in una lista e quali questi siano.
 *  Si possono avere più utenti che condividono la stessa lista
 */

int main() {
    // UTENTI
    User utente1("Alban");
    User utente2("Marco");
    User utente3("Giacomo");

    // LISTE
    ShoppingList lista1("spesa");
    ShoppingList lista2("dolci");
    ShoppingList lista3("grigliata");

    // OGGETTI
    ShoppingItem oggetto("Banana","FRUTTA",2);
    ShoppingItem oggetto2("Orata","PESCE",3);
    ShoppingItem oggetto3("Uova","UOVA",10);
    ShoppingItem oggetto4("Farina","FARINA",3);
    ShoppingItem oggetto5("Spiedino","CARNE",8);
    ShoppingItem oggetto6("Bistecca","CARNE",6);
    ShoppingItem oggetto7("Latte","LATTE",2);

    // LISTE DI ALBAN
    utente1.addList(&lista1);
    utente1.addList(&lista2);
    utente1.addList(&lista3);

    // LISTE DI MARCO
    utente2.addList(&lista2);

    // LISTE DI GIACOMO
    utente3.addList(&lista1);

    cout<<endl;

    // OGGETTI LISTA 1: spesa
    lista1.addObject(oggetto);
    lista1.addObject(oggetto2);
    lista1.addObject(oggetto7);

    // OGGETTI LISTA 2: dolci
    lista2.addObject(oggetto3);
    lista2.addObject(oggetto4);
    lista2.addObject(oggetto7);

    // OGGETTI LISTA 3: grigliata
    lista3.addObject(oggetto5);
    lista3.addObject(oggetto6);

    // visualizzazione tutte le lists di ciascun utente
    /*
    user1.view();
    cout<<endl<<endl;
    utente2.view();
    cout<<endl<<endl;
    utente3.view();
    cout<<endl<<endl;
    */

    cout<<"---------------------------------------------------------------------------------------"<<endl<<endl<<endl;

    // rimozione oggetto
    lista1.removeObject("Latte");
    // rimozione oggetto non esistente
    lista1.removeObject("limone");
    // aumento quantità
    lista1.modQuantity("Banana", 20, true);
    // diminuzione quantità
    lista1.modQuantity("Orata",1, false);
    lista2.modQuantity("Farina",4, false);
    lista1.stateObject("Banana", true);

    // visualizzazione tutte le lists di ciascun utente
    /*
    user1.view();
    cout<<endl<<endl;
    utente2.view();
    cout<<endl<<endl;
    utente3.view();
    cout<<endl<<endl;
    */

    // rimozione lista grigliata utente Alban
    utente1.remList("grigliata");
    utente1.view();

    return 0;
}
