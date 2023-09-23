#include "ShoppingItem.h"

// Costruttore oggetto
ShoppingItem::ShoppingItem(const string &nome, const string &categoria, int quantita) : nome(nome),
                                                                                        categoria(categoria),
                                                                                        quantita(quantita),
                                                                                        acquistato(false) {}

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

// SETTER -> Quantità
void ShoppingItem::setQuantita(int quantita) {
    ShoppingItem::quantita = quantita;
}



