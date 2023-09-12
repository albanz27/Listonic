#include "gtest/gtest.h"

#include "../ShoppingItem.h"

TEST(ShoppingItem, DefaultConstructor) {
    ShoppingItem ogg("banana","frutto",2);
    ASSERT_EQ("banana",ogg.getNome());
    ASSERT_EQ("frutto",ogg.getCategoria());
    ASSERT_EQ(2,ogg.getQuantita());
}
