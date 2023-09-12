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
    /*ShoppingItem oggetto("BANANA","FRUTTA",2);
    ShoppingItem oggetto2("tortellini","pasta",10);
    ShoppingItem oggetto3("mela","FRUTTA",5);
    ShoppingItem oggetto4("FARINA","IMPASTO",2);
    ShoppingItem oggetto5("UOVA","PROTEINE",4);*/
    /*  PROVA TASTIERA: INSERIMENTO OGGETTI NELLA LISTA
    string nomeLista;
    cout<<"Inserisci il nome della nuova lista"<<endl;
    cin>>nomeLista;
    ShoppingList lista(nomeLista);
     */
   /* ShoppingList lista("spesa");
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
    cout<<endl<<endl;*/

    //lista.dimQuantita("tortellini",100);
    //lista2.aumQuantita("tortellini",10);
    /*
    User utente1("Alban");
    User utente2("Osman");

    utente1.addLista(&lista);
    utente1.addLista(&lista2);
    utente2.addLista(&lista);

    utente1.view();
    cout<<endl<<endl;
    utente2.view();
    cout<<endl<<endl;

    lista.dimQuantita("tortellini",100);

    utente1.remLista("spesa");
    utente1.view();
    */

    // INIZIO DEL COUT <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    // UTENTI
    User utente1("Alban");
    User utente2("Marco");

    // LISTE
    ShoppingList lista1("spesa");
    ShoppingList lista2("dolci");

    // OGGETTI
    ShoppingItem oggetto("Banana","FRUTTA",2);
    ShoppingItem oggetto2("Paprika","SPEZIE",4);
    ShoppingItem oggetto3("Orata","Pesce",1);

    bool fine = false;
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

    return 0;
}
