#include "gtest/gtest.h"
#include "../ShoppingList.h"

TEST(ShoppingList, Constructor) {
    ShoppingList lista("spesa");
    ASSERT_EQ("spesa",lista.getNome());
}

TEST(ShoppingList, addObject) {
    ShoppingItem oggetto("Banana","FRUTTA",2);
    ShoppingList lista("spesa");
    lista.addObject(oggetto);

    bool found = false;
    for (const ShoppingItem& ogg : lista.oggetti) {
        if (ogg.getNome() == "Banana") {
            found = true;
        }
    }
    ASSERT_TRUE(found);
}