//
// Created by alban on 10/09/2023.
//

#include "ShoppingItem.h"

ShoppingItem::ShoppingItem(string nome, string categoria, int quantita) : nome(std::move(nome)), categoria(std::move(categoria)),quantita(quantita){}


void ShoppingItem::view(){
    cout<<"Nome: "<<nome<<endl;
    cout<<"Categoria: "<<categoria<<endl;
    cout<<"Quantita': "<<quantita<<endl;
    cout<<"<--------------------------------------------------------->"<<endl;

}

void ShoppingItem::setQuantita(int quantita) {
    ShoppingItem::quantita = quantita;
}

