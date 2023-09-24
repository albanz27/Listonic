#include "gtest/gtest.h"
#include "../User.h"

TEST(User, Constructor) {
    User utente("alban");
    ASSERT_EQ("alban",utente.getNome());
}

TEST(User, addLista) {
    ShoppingList lista1("spesa");
    User utente1("alban");
    utente1.addLista(&lista1);

    bool found = false;
    for (const ShoppingList* lista : utente1.liste) {
        if (lista->getNome() == "spesa") {
            found = true;
        }
    }
    ASSERT_TRUE(found);
}