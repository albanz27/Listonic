#include "gtest/gtest.h"
#include "../ShoppingItem.h"

TEST(ShoppingItem, Constructor) {
    ShoppingItem ogg("banana","frutto",2);
    ASSERT_EQ("banana",ogg.getNome());
    ASSERT_EQ("frutto",ogg.getCategoria());
    ASSERT_EQ(2,ogg.getQuantita());
}

TEST(ShoppingItem, setAcquistato) {
    ShoppingItem ogg("banana","frutto",2);
    ogg.setAcquistato(true);
    ASSERT_TRUE(ogg.isAcquistato());
}