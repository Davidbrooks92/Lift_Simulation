#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <string>
#include "lift_simulation.hpp"

using std::string;
using std::queue;
using std::unique_lock;
using std::cout;
using std::endl;



void Elevator_Buttons::e_push(int x , int y, Elevator& elevator){
    elevator.send_(x, y);
}
void Floor_Buttons::push(int current_floor, Elevator& elevator){

    elevator._request(current_floor, elevator);
}
void Elevator_Buttons::push(int current_floor, Elevator& elevator){

    elevator._request(current_floor, elevator);
}

void Button_Panel::go_up(int current_floor, Elevator& elevator) {
    upbutton.push(current_floor, elevator);
}
void Button_Panel::go_down( int current_floor, Elevator& elevator) {

    downbutton.push(current_floor, elevator);
}

void Elevator_Button_Panel::button_0_push(int destination,int current_floor, Elevator& elevator) {
    button_0.e_push(destination, current_floor, elevator);
}
void Elevator_Button_Panel::button_1_push(int destination,int current_floor, Elevator& elevator) {
    button_1.e_push(destination, current_floor, elevator);
}
void Elevator_Button_Panel::button_2_push(int destination,int current_floor, Elevator& elevator) {
    button_2.e_push(destination, current_floor, elevator);
}
void Elevator_Button_Panel::button_3_push(int destination,int current_floor, Elevator& elevator) {
    button_3.e_push(destination, current_floor, elevator);
}

void Elevator::send_(int x, int y) {
    if (x < y) {
        for (x; x < y; x--) {
            cout << "Elevator is on floor: " + std::to_string(y);
        }
    } else if (x > y) {
        for (x; x > y; x++) {
            cout << "Elevator is on floor: " + std::to_string(y);
        }
    } else {
        cout << "Elevator has reached it's destination";
    }
}
void Elevator::_request(int i, Elevator& elevator) {
    cout << i << " " << elevator.current_floor << endl;
    if (elevator.current_floor < i) {

        for (elevator.current_floor; elevator.current_floor < i; elevator.current_floor++) {
            cout << "Elevator is on floor:" + std::to_string(elevator.current_floor) + " \n";
        }
        cout << "Elevator has reached it's destination on floor: " + std::to_string(elevator.current_floor) + " \n";
    } else if (elevator.current_floor > i) {
        for (elevator.current_floor; elevator.current_floor > i; elevator.current_floor--) {
            cout << "Elevator is on floor:" + std::to_string(elevator.current_floor) + " \n";
        }
        cout << "Elevator has reached it's destination on floor: " + std::to_string(elevator.current_floor) + " \n";
    }
}

