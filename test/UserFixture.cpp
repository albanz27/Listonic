#include "gtest/gtest.h"
#include "../User.h"

class UserFixture : public ::testing::Test {
protected:
    User utente1{"alban"};
    User utente2{"marco"};
    void SetUp() override {
        // Inizializzo le liste
        ShoppingList lista1("spesa");
        ShoppingList lista2("grigliata");
        // Aggiungo la lista all'utente
        //utente1.addLista(&lista1);
    }
};


// addLista
/*
TEST_F(UserFixture, Test_addLista) {
    // Uso il getter per accedere alle liste dell'utente
    const list<ShoppingList*>& liste = utente.getListe();

    // Itera nelle liste e verifica che siano state inserite correttamente
    for (const auto& lista : liste)
        ASSERT_EQ("spesa", lista->getNome());

}

// remLista
TEST_F(UserFixture, Test_remLista) {
    // Rimuovo una lista dall'utente
    ASSERT_TRUE(utente.remLista("spesa"));

    // Controllo che la lista sia stata rimossa correttamente
    const list<ShoppingList*>& liste = utente.getListe();
    for (const auto& lista : liste) {
        ASSERT_NE("spesa", lista->getNome());
    }

    // Prova a rimuovere una lista non esistente
    ASSERT_FALSE(utente.remLista("nulla"));
}


*/