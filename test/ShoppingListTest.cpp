#include "gtest/gtest.h"
#include "../ShoppingList.h"

TEST(ShoppingList, Constructor) {
    ShoppingList lista("spesa");
    ASSERT_EQ("spesa", lista.getName());
}
