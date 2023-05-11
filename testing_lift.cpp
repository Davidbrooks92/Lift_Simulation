#include "lift_simulation.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
using  std::cout;
using  std::flush;
TEST_CASE("Initialisation test"){
    printf("Initialisation Succeeded \n");
}

TEST_CASE("construct an elevator"){
    printf("Initialisation Succeeded \n");
    Elevator ev1{0};
    printf("Elevator Build Succeeded \n");
}

TEST_CASE("Construct a building") {
    printf("Initialisation Succeeded \n");
    Elevator ev1(0);
    printf("Elevator Build Succeeded \n");
    Building building(ev1);
    printf("Building Build Succeeded \n");
}

TEST_CASE("test2"){
    printf("Initialisation Succeeded \n");
    Elevator ev1(0);
    printf("Elevator Build Succeeded \n");
    Building building(ev1);
    printf("Building Build Succeeded \n");
    cout << "Elevator Values: " << flush << "Destination and Current Floor"<<std::endl;
    building.f4.buttonPanel.downbutton.push(3, ev1);
    printf("Floor 4 Button Push Build Succeeded \n");
}

TEST_CASE("test3"){
    printf("Initialisation Succeeded \n");
    Elevator ev1(0);
    printf("Elevator Build Succeeded \n");
    Building building(ev1);
    printf("Building Build Succeeded \n");
    cout << "Elevator Values: " << flush << "Destination and Current Floor"<<std::endl;
    building.f4.buttonPanel.go_down(3, ev1);
    printf("Floor 4 Button Push Build Succeeded \n");
    building.elevator.e_button_panel.button_0.e_push(0,ev1.current_floor, ev1);
}
