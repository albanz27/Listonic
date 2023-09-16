#include "gtest/gtest.h"
#include "../ShoppingList.h"

class ShoppingListFixture : public ::testing::Test {
protected:
    ShoppingList lista;
    void SetUp() override {
        lista.setNome("spesa");
    }};

// addOggetto
TEST_F(ShoppingListFixture, Test_addOggetto){
    // Inizializzo l'oggetto con il costruttore di ShopppingItem
    ShoppingItem oggetto1("Banana", "FRUTTA", 2);

    // Aggiungo l'oggetto alla lista
    lista.addOggetto(oggetto1);

    // Uso il getter per accedere alla lista
    const list<ShoppingItem>& oggetti = lista.getOggetti();

    // Itero nella lista e controllo che sia stato inserito correttamente
    for (const auto& oggetto : oggetti) {
        // Add assertions for the properties of 'oggetto' (ShoppingItem)
        ASSERT_EQ("Banana", oggetto.getNome());
        ASSERT_EQ("FRUTTA", oggetto.getCategoria());
        ASSERT_EQ(2, oggetto.getQuantita());
    }
}

