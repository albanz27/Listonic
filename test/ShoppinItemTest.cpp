#include "gtest/gtest.h"
#include "../ShoppingItem.h"

TEST(ShoppingItem, Constructor) {
    ShoppingItem item("banana","frutto",2);
    ASSERT_EQ("banana", item.getName());
    ASSERT_EQ("frutto", item.getCategory());
    ASSERT_EQ(2, item.getQuantity());
}

TEST(ShoppingItemSuite, isBought) {
    ShoppingItem item("banana", "frutto", 2);
    item.setBought(true);
    ASSERT_TRUE(item.isBought());
}

TEST(ShoppingItemSuite, setQuantity) {
    ShoppingItem item("banana", "frutto", 2);
    ASSERT_THROW(item.setQuantity(-2),out_of_range);
}