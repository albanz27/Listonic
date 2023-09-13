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
    utente1.addLista(&lista1);
    utente1.addLista(&lista2);
    utente1.addLista(&lista3);

    // LISTE DI MARCO
    utente2.addLista(&lista2);

    // LISTE DI GIACOMO
    utente3.addLista(&lista1);

    cout<<endl;

    // OGGETTI LISTA 1: spesa
    lista1.addOggetto(oggetto);
    lista1.addOggetto(oggetto2);
    lista1.addOggetto(oggetto7);

    // OGGETTI LISTA 2: dolci
    lista2.addOggetto(oggetto3);
    lista2.addOggetto(oggetto4);
    lista2.addOggetto(oggetto7);

    // OGGETTI LISTA 3: grigliata
    lista3.addOggetto(oggetto5);
    lista3.addOggetto(oggetto6);

    // visualizzazione tutte le liste di ciascun utente
    utente1.view();
    cout<<endl<<endl;
    utente2.view();
    cout<<endl<<endl;
    utente3.view();
    cout<<endl<<endl;

    // rimozione oggetto
    lista1.removeOggetto("Latte");
    // aumento quantità
    lista1.aumQuantita("Banana",20);
    // diminuzione quantità
    lista1.dimQuantita("Orata",1);
    lista2.dimQuantita("Farina",4);

    // visualizzazione tutte le liste di ciascun utente
    utente1.view();
    cout<<endl<<endl;
    utente2.view();
    cout<<endl<<endl;
    utente3.view();
    cout<<endl<<endl;

    // rimozione lista grigliata utente Alban
    utente1.remLista("grigliata");
    utente1.view();

    // Prova automazione
/*    bool fine = false;
    do {
        // SELEZIONE UTENTE
        string op1="";
        do {
            cout<<"DIGITA il NOME dell'utente da selezionare oppure DIGITA CREA per creare nuovo utente: "<<endl;
            cout<<"Alban  -  Marco"<<endl;
            cin>>op1;
            if(op1!="Alban" && op1!="ALBAN" && op1!="alban" && op1!="Marco" && op1!="MARCO" && op1!="marco" && op1!="crea" && op1!="CREA" && op1!="Crea")
                cout<<"ERRORE"<<endl<<endl;
        } while ( op1!="Alban" && op1!="ALBAN" && op1!="alban" && op1!="Marco" && op1!="MARCO" && op1!="marco" && op1!="crea" && op1!="CREA" && op1!="Crea");

        // CREAZIONE UTENTE
        if(op1=="CREA" || op1=="Crea" || op1=="crea"){
            string nUtente;
            cout<<"INSERISCI nuovo nome utente"<<endl;
            cin>>nUtente;
            User utente3(nUtente);
        }

        // SELEZIONE LISTA
        string op2="";
        do {
            cout<<"DIGITA il NOME della lista da selezionare oppure CREA per creare una nuova lista: "<<endl;
            cout<<"spesa  -  dolci"<<endl;
            cin>>op2;
            if( op2!="spesa" && op2!="dolci" && op2!="crea" && op2!="CREA" && op2!="Crea" )
                cout<<"ERRORE"<<endl<<endl;
        } while ( op2!="spesa" && op2!="dolci" && op2!="crea" && op2!="CREA" && op2!="Crea" );

        // CREAZIONE LISTA
        if(op1=="CREA" || op1=="Crea" || op1=="crea"){
            string nLista;
            cout<<"INSERISCI nuovo nome lista"<<endl;
            cin>>nLista;
            ShoppingList lista3(nLista);
        }

        fine = true;
    } while (fine == false);

    FINE AUTOMAZIONE
    */

    return 0;
}
