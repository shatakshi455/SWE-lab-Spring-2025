#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "operations.h"

TEST_CASE("Checking Operations", "[operations]")
{
Operations operations;
SECTION("Addition")
{
REQUIRE(operations.add(5, 3) == 8);
REQUIRE(operations.add(8, 3) == 11);
REQUIRE(operations.add(5, 3) != -8);

//5 more assertions for addition:
REQUIRE(operations.add(15, 3) == 18);
REQUIRE(operations.add(5, 10) == 15);
REQUIRE(operations.add(16, 0) == 16);
REQUIRE(operations.add(99, 75) == 174);
REQUIRE(operations.add(55, 3) == 58);

}

SECTION("Multiplication")
{
//10 assertions for addition:
REQUIRE(operations.multiply(15, 3) == 45);
REQUIRE(operations.multiply(5, 0) == 0);
REQUIRE(operations.multiply(20, 6) == 120);
REQUIRE(operations.multiply(15, 5) == 75);
REQUIRE(operations.multiply(5, 7) == 35);
REQUIRE(operations.multiply(23, 2) == 46);
REQUIRE(operations.multiply(7, 9) == 63);
REQUIRE(operations.multiply(5, 9) == 45);
REQUIRE(operations.multiply(2, 3) == 6);
REQUIRE(operations.multiply(3, 2) == 6);
}

}