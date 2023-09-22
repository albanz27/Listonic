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
        // Assert_ne controlla che i due parametri sono diversi
        ASSERT_NE("Banana", oggetto.getNome());
    }

    // Provo a rimuovere un oggetto non esistente
    ASSERT_FALSE(lista.removeOggetto("nulla"));
}

// aumOggetto
TEST_F(ShoppingListFixture, Test_aumOggetto) {
    // Aumento la quantià di un oggetto
    ASSERT_TRUE(lista.aumQuantita("Banana", 3));

    // Controllo se la quantità è stata aumentata
    const list<ShoppingItem>& oggetti = lista.getOggetti();
    for (const auto& oggetto : oggetti) {
        if (oggetto.getNome() == "Banana") {
            ASSERT_EQ(5, oggetto.getQuantita());
        }
    }

    // Provo ad aumentare la quantità di un oggetto non esistente
    ASSERT_FALSE(lista.aumQuantita("nulla", 3));
}

// dimOggetto
TEST_F(ShoppingListFixture, Test_dimOggetto) {
    // Diminuisco la quantità di un oggetto
    ASSERT_TRUE(lista.dimQuantita("Banana", 1));

    // Controllo se la quantità è diminuita
    const list<ShoppingItem>& oggetti = lista.getOggetti();
    for (const auto& oggetto : oggetti) {
        if (oggetto.getNome() == "Banana") {
            ASSERT_EQ(1, oggetto.getQuantita());
        }
    }

    // Provo a diminuire la quantità di un oggetto non esistente
    ASSERT_FALSE(lista.dimQuantita("nulla", 1));
}
