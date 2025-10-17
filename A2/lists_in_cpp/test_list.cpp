#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"

TEST_CASE("List Basic Operations", "[List]") {
    List list;

    SECTION("Append Elements") {
        list.append(1);
        REQUIRE(list.getSize() == 1);
        list.append(2);
        REQUIRE(list.getSize() == 2);
        REQUIRE(list[1]==2);
        list.append(5);
        REQUIRE(list.getSize() == 3);
        REQUIRE(list[2]==5);
        list.append(10);
        REQUIRE(list.getSize() == 4);
    }

    SECTION("Access Elements with []") {
       // Implement this code
       list.append(0);
       REQUIRE(list[0] == 0);
       list.append(1);
       REQUIRE(list[1] == 1);
       list.append(2);
       REQUIRE(list[2] == 2);
       list.append(3);
       REQUIRE(list[3] == 3);
       list.append(4);
       REQUIRE(list[4] == 4);
       list.append(5);
       REQUIRE(list[5] == 5);
       
    }

    SECTION("Out of Range Access Throws Exception") {
        list.append(5);
        REQUIRE_THROWS_AS(list[1], std::out_of_range);
        list.append(6);
        REQUIRE_THROWS_AS(list[10], std::out_of_range);
        list.append(7);
        REQUIRE_THROWS_AS(list[11], std::out_of_range);
        list.append(8);
        REQUIRE_THROWS_AS(list[100], std::out_of_range);
        list.append(5);
        REQUIRE_THROWS_AS(list[101], std::out_of_range);
        list.append(4);
        REQUIRE_THROWS_AS(list[99], std::out_of_range);
    }
}

TEST_CASE("List Concatenation with + Operator", "[List]") {
    List L1, L2;
    SECTION("Concatenate Two Lists") {
       L1.append(0);
       L1.append(1);
       L1.append(2);
       L2.append(3);
       L2.append(4);
       List list = L1+L2;
       REQUIRE(list[0] == 0);
       REQUIRE(list[1] == 1);
       REQUIRE(list[2] == 2);
       REQUIRE(list[3] == 3);
       REQUIRE(list[4] == 4);
    }
}

TEST_CASE("List Stream Output with <<", "[List]") {
    // Implement this code
    List list;
    
    SECTION("Stream Output") {
        list.append(5);
        list.append(10);
        list.append(15);
        std::ostringstream oss;
        oss << list;

        REQUIRE(oss.str() == "[5, 10, 15]");
        
        list.append(10);
        list.append(15);
        std::ostringstream oss2;
        oss2 << list;

        REQUIRE(oss2.str() == "[5, 10, 15, 10, 15]");
    }
}