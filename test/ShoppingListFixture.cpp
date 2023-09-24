#include "gtest/gtest.h"
#include "../ShoppingList.h"

class ShoppingListFixture : public ::testing::Test {
protected:
    ShoppingList lista1{"spesa"};

    void SetUp() override {
        // Inizializzo l'oggetto ShopppingItem
        ShoppingItem oggetto1("Banana", "FRUTTA", 2);
        ShoppingItem oggetto2("Gocciole", "BISCOTTI", 5);
        // Aggiungo l'oggetto alla lista
        lista1.addObject(oggetto1);
        lista1.addObject(oggetto2);
    }

    void TearDown() override {
        while (!lista1.oggetti.empty()) {
            const string nOggetto = lista1.oggetti.front().getNome();
            lista1.removeObject(nOggetto);
        }
    }

};

// removeObject
TEST_F(ShoppingListFixture, Test_removeOggetto) {
    // Rimuovo un oggetto dalla lista
    ASSERT_TRUE(lista1.removeObject("Banana"));

    // Rimuovo un oggetto non esistente
    ASSERT_FALSE(lista1.removeObject("NON ESISTENTE"));
}

// stateObject
TEST_F(ShoppingListFixture, Test_stateObject) {
    // Segno le Gocciole come acquistate
    ASSERT_TRUE(lista1.stateObject("Gocciole", true));
    // Segno le Banane come oggetti da acquistare
    ASSERT_TRUE(lista1.stateObject("Banana", false));

    // Cambio stato ad un oggetto non esistente
    ASSERT_FALSE(lista1.stateObject("Uova", true));
}

// modQuantity
TEST_F(ShoppingListFixture, Test_modQuantity) {
    // aggiungo +10 Banane
    ASSERT_TRUE(lista1.modQuantity("Banana",10, true));
    // controlla se la quantità dell'oggetto è aumentata = 12
    for (const auto& oggetto : lista1.oggetti) {
        if (oggetto.getNome() == "Banana") {
            ASSERT_EQ(12, oggetto.getQuantita());
        }
    }

    // diminuisco le Gocciole di -3
    ASSERT_TRUE(lista1.modQuantity("Gocciole",3, false));
    // controlla se la quantità dell'oggetto è diminuita a = 2
    for (const auto& oggetto : lista1.oggetti) {
        if (oggetto.getNome() == "Gocciole") {
            ASSERT_EQ(2, oggetto.getQuantita());
        }
    }

    // diminuisco ulteriormente le gocciole di -5 (sono '2')
    ASSERT_FALSE(lista1.modQuantity("Gocciole",5, false));

    // modifico la quantità di un oggetto non esistente
    ASSERT_FALSE(lista1.modQuantity("OGGETTO NON ESISTENTE",3, true));
}
