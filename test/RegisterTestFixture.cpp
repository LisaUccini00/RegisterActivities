#include "lib/googletest/include/gtest/gtest.h"
#include "../Register.h"

class RegisterTextFixture: public ::testing::Test{
protected:
    Register *r = new Register;
};