#include <iostream>
#include "string"
#include "ShoppingItem.h"
#include "ShoppingList.h"
#include "User.h"
#include "Observer.h"

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
   // string nomeOggetto, categoria;
    //int quantita;
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
    ShoppingItem oggetto3("mela","FRUTTA",5);
    ShoppingItem oggetto4("FARINA","IMPASTO",2);
    ShoppingItem oggetto5("UOVA","PROTEINE",4);
    /*  PROVA TASTIERA: INSERIMENTO OGGETTI NELLA LISTA
    string nomeLista;
    cout<<"Inserisci il nome della nuova lista"<<endl;
    cin>>nomeLista;
    ShoppingList lista(nomeLista);
     */
    ShoppingList lista("spesa");
    ShoppingList lista2("merenda");
    lista.addOggetto(oggetto);
    lista.addOggetto(oggetto2);
    lista.addOggetto(oggetto3);
    lista.addOggetto(oggetto4);
    lista2.addOggetto(oggetto2);
    lista2.addOggetto(oggetto5);

    lista.play();
    cout<<endl<<endl;
    lista2.play();
    cout<<endl<<endl;

    //lista.dimQuantita("tortellini",100);
    //lista2.aumQuantita("tortellini",10);

    User utente1("Alban");
    User utente2("Osman");

    utente1.addLista(&lista);
    utente1.addLista(&lista2);
    utente2.addLista(&lista);

    utente1.view();
    cout<<endl<<endl;
    utente2.view();
    cout<<endl<<endl;

    utente1.remLista("spesa");
    utente1.view();


    return 0;
}
