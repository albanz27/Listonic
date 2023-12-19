#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListFixture : public ::testing::Test {
protected:
    ShoppingList list1{"spesa"};
    ShoppingItem object1{"Banana", "FRUTTA", 2};
    ShoppingItem object2{"Gocciole", "BISCOTTI", 5};
    ShoppingItem object3{"Insalata", "VERDURE", 1};

    void SetUp() override {
        list1.addObject(object1);
        list1.addObject(object2);
        list1.addObject(object3);
    }
};

TEST_F(ShoppingListFixture, Test_addObject){
    ShoppingItem object4{"Bistecca", "Carne", 5};
    list1.addObject(object4);
    int size=list1.getObjects().size();
    // numero di oggetti nella lista
    ASSERT_EQ(size,4);

    // somma della quantità di tutti gli oggetti segnati come non acquistati
    ASSERT_EQ(list1.notBought(),13);
}

// removeObject
TEST_F(ShoppingListFixture, Test_removeObject) {
    // Rimuovo un oggetto dalla lista
    ASSERT_TRUE(list1.removeObject("Banana"));

    // Rimuovo un oggetto non esistente
    ASSERT_FALSE(list1.removeObject("NON ESISTENTE"));
}

// stateObject
TEST_F(ShoppingListFixture, Test_stateObject) {
    // Segno le Gocciole come acquistate
    ASSERT_TRUE(list1.stateObject("Gocciole", true));
    // Segno le Banane come objects da acquistare
    ASSERT_TRUE(list1.stateObject("Banana", false));
    // Cambio stato ad un oggetto non esistente
    ASSERT_FALSE(list1.stateObject("Uova", true));
}

TEST_F(ShoppingListFixture, Test_modQuantity) {
    // aumenta la quantità di 10
    ASSERT_TRUE(list1.modQuantity("Banana",10,1));

    // diminuisce la quantità di 4
    ASSERT_TRUE(list1.modQuantity("Gocciole",4,0));

    // la quantità dell'oggetto è minore della quantità che si vuole decrementare
    ASSERT_FALSE(list1.modQuantity("Insalata",10,0));

    // modifico quantità di un oggetto non esistente
    ASSERT_FALSE(list1.modQuantity("Mela",10,0));


}

TEST_F(ShoppingListFixture, Test_notBought) {
    // somma degli oggetti non acquistati
    ASSERT_EQ(list1.notBought(),8);
}

TEST_F(ShoppingListFixture, Test_subject) {
}