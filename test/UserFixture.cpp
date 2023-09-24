#include "gtest/gtest.h"
#include "../User.h"

class UserFixture : public ::testing::Test {
protected:
    User utente1{"alban"};
    ShoppingList lista1{"spesa"};

    void SetUp() override {
        utente1.addLista(&lista1);
    }

    void TearDown() override {
        while (!utente1.liste.empty()) {
            const string nLista = utente1.liste.front()->getNome();
            utente1.remLista(nLista);
        }
    }
};

// addLista
TEST_F(UserFixture, addLista) {

    utente1.addLista(&lista1);

    // controllo se è stata aggiunta correttamente
    bool found = false;
    for (const ShoppingList* lista : utente1.liste) {
        if (lista->getNome() == "spesa") {
            found = true;
        }
    }
    ASSERT_TRUE(found);
}

// remLista
TEST_F(UserFixture, Test_remLista) {
    // Rimuovo una lista dall'utente
    ASSERT_TRUE(utente1.remLista("spesa"));

    // controllo se è stata rimossa correttamente
    bool found = false;
    for (const ShoppingList* lista : utente1.liste) {
        if (lista->getNome() == "spesa") {
            found = true;
        }
    }
    ASSERT_FALSE(found);

    // Prova a rimuovere una lista non esistente
    ASSERT_FALSE(utente1.remLista("NON ESISTENTE"));
}


