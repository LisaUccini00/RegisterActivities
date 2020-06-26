#include "lib/googletest-master/googletest/include/gtest/gtest.h"
#include "../Register.h"

class RegisterTextFixture: public ::testint::Test{
protected:
    Register *r = new Register;
};