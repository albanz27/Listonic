#include "gtest/gtest.h"
#include "../User.h"

class UserFixture : public ::testing::Test {
protected:
    User user1{"alban"};
    ShoppingList list1{"spesa"};
    ShoppingList list2{"festa"};

    void SetUp() override {
        user1.addList(&list1);
    }
};

TEST_F(UserFixture, addList) {
    user1.addList(&list2);

    // controllo numero liste in user1
    ASSERT_EQ(user1.getLists().size(),2);

    // controllo se "festa" e' presente
    auto it = std::find_if(user1.getLists().begin(), user1.getLists().end(),[](const ShoppingList* list) {
        return list->getListName() == "festa";
    });
    ASSERT_TRUE(it != user1.getLists().end());
}

// remList
TEST_F(UserFixture, Test_remLista) {
    // rimuovo una lista dall'utente
    ASSERT_TRUE(user1.remList("spesa"));

    // numero liste
    ASSERT_EQ(user1.getLists().size(),0);

    // controllo se è stata rimossa correttamente
    auto it = std::find_if(user1.getLists().begin(), user1.getLists().end(),[](const ShoppingList* list) {
        return list->getListName() == "spesa";
    });
    ASSERT_FALSE(it != user1.getLists().end());

    // Prova a rimuovere una lista non esistente
    ASSERT_FALSE(user1.remList("NON ESISTENTE"));
}
