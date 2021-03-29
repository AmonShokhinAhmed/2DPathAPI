#include "pathfinder.h"
#include <catch2/catch.hpp>

TEST_CASE("Creating a Pathfinder instance and trying the TestFunction", "[testfunction]") {
    GIVEN("A Pathfinder instance is created") {
        PathAPI::PathFinder pathfinder;
        WHEN("the user calls the TestFunction") {
            THEN("the function has to return 0") {
                REQUIRE(pathfinder.TestFunction() == 0);
            }
        }
    }
}
