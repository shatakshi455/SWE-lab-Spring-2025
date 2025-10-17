#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "str.h"

TEST_CASE("first") {
    MyString A;
    MyString C("HEYYY");
    MyString K=C;
    REQUIRE(K==C);
    MyString D("HELLO");
    MyString E =C+D;
    MyString F("HEYYYHELLO");
    REQUIRE(E==F);
}

TEST_CASE("List Stream Output with <<", "[List]") {
    // Implement this code
    
    SECTION("Stream Output") {
        MyString A("HI");
        std::ostringstream oss;
        oss << A;
        REQUIRE(oss.str() == "HI");
    }
}