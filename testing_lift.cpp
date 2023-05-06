#include "lift_simulation.hpp"
#include "lift_simulation.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Initialisation test"){

}

TEST_CASE("Building"){
    Building building(Elevator &elevator);
    Elevator elevator(0, elevator);
    Floors f1(0, elevator);
    Floors f2(1, elevator);
    Floors f3(2, elevator);
    Floors f4(3, elevator);
    REQUIRE(f1.current_floor == 0);
    REQUIRE(f2.current_floor == 1);
    REQUIRE(f3.current_floor == 2);
    REQUIRE(f4.current_floor == 3);
}

TEST_CASE("start"){
    Elevator elevator(0, elevator);
    Building building(elevator);
    building.down_button_push();
    building.up_button_push();
}