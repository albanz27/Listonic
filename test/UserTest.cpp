#include "gtest/gtest.h"
#include "../User.h"

TEST(User, Constructor) {
    User utente("alban");
    ASSERT_EQ("alban", utente.getName());
}