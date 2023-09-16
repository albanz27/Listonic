#include "gtest/gtest.h"
#include "../ShoppingList.h"

class ShoppingListFixture : public ::testing::Test {
protected:
    ShoppingList lista;
    void SetUp() override {
        lista.setNome("spesa");
        // Inizializzo l'oggetto con il costruttore di ShopppingItem
        ShoppingItem oggetto1("Banana", "FRUTTA", 2);
        // Aggiungo l'oggetto alla lista
        lista.addOggetto(oggetto1);
    }};

// addOggetto
TEST_F(ShoppingListFixture, Test_addOggetto){
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

// removeOggetto
TEST_F(ShoppingListFixture, Test_removeOggetto) {
    // Rimuovo un oggetto dalla lista
    ASSERT_TRUE(lista.removeOggetto("Banana"));

    // Controllo se è stato rimosso dalla lista
    const list<ShoppingItem>& oggetti = lista.getOggetti();
    for (const auto& oggetto : oggetti) {
        ASSERT_NE("Banana", oggetto.getNome());
    }

    // Provo a rimuovere un oggetto non esistente
    ASSERT_FALSE(lista.removeOggetto("NonExistingItem"));
}