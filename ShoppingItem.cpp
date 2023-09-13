#include "ShoppingItem.h"

// Costruttore oggetto
ShoppingItem::ShoppingItem(string nome, string categoria, int quantita) : nome(std::move(nome)), categoria(std::move(categoria)),quantita(quantita){}

// Visualizzazione oggetti
void ShoppingItem::view(){
    cout<<"Nome: "<<nome<<endl;
    cout<<"Categoria: "<<categoria<<endl;
    cout<<"Quantita': "<<quantita<<endl;
    cout<<"--------------------------------------------------"<<endl;
}

// GETTER -> Nome
const string &ShoppingItem::getNome() const {
    return nome;
}

// GETTER -> Categoria
const string &ShoppingItem::getCategoria() const {
    return categoria;
}

// GETTER -> Quantità
int ShoppingItem::getQuantita() const {
    return quantita;
}