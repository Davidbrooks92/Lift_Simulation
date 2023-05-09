#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <string>
#include "lift_simulation.hpp"

using std::string;
using std::mutex;
using std::condition_variable;
using std::queue;
using std::unique_lock;
using std::cout;
using std::endl;
using std::thread;

int destination;
int current_floor;

void Buttons::button_push(int  x, Elevator& elevator){
    destination = x;
    elevator.send_(4,3);
}
void Elevator_Button_Panel::button_0_push(int x, Elevator& elevator){
    button_0.button_push(current_floor, elevator );
}
void Elevator_Button_Panel::button_1_push(int x, Elevator& elevator){
    button_1.button_push(current_floor, elevator);
}
void Elevator_Button_Panel::button_2_push(int x, Elevator& elevator){
    button_2.button_push(current_floor, elevator);
}
void Elevator_Button_Panel::button_3_push(int x, Elevator& elevator){
    button_3.button_push(current_floor, elevator);
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
void Elevator::_request(int i) {
    if (current_floor < i) {
        for (current_floor; current_floor < i; current_floor--) {
            cout << "Elevator is on floor: " + std::to_string(current_floor);
        }
    } else if (current_floor > i) {
        for (current_floor; current_floor > i; current_floor++) {
            cout << "Elevator is on floor: " + std::to_string(current_floor) + " \n";
        }
    } else {
        cout << "Elevator has reached it's destination\n";
    }
}
void Button_Panel::up_button_push(int x, Elevator& elevator){
    up_button.button_push(x, elevator);
    elevator._request(current_floor);
}
void Button_Panel::down_button_push(int x, Elevator& elevator){
    down_button.button_push(x, elevator);
    elevator._request(current_floor);
}
void Floors::up_button_push(Elevator& elevator){
    buttonPanel.up_button_push(current_floor, elevator);
}
void Floors::down_button_push(Elevator& elevator){
    buttonPanel.down_button_push(current_floor, elevator);
}
void Building::down_button_push1(Elevator& elevator){
    f1.down_button_push(elevator);
    elevator.send_(destination, current_floor);
}
void Building::up_button_push1(Elevator& elevator){
    f1.up_button_push(elevator);
    elevator.send_(destination, current_floor);
}
void Building::down_button_push2(Elevator& elevator){
    f2.down_button_push(elevator);
    elevator.send_(destination, current_floor);
}
void Building::up_button_push2(Elevator& elevator){
    f2.up_button_push(elevator);
    elevator.send_(destination, current_floor);
}
void Building::down_button_push3(Elevator& elevator){
    f3.down_button_push(elevator);
    elevator.send_(destination, current_floor);
}
void Building::up_button_push3(Elevator& elevator){
    f3.up_button_push(elevator);
    elevator.send_(destination, current_floor);
}
void Building::down_button_push4(Elevator& elevator){
    f4.down_button_push(elevator);
    elevator.send_(destination, current_floor);
}
void Building::up_button_push4(Elevator& elevator){
    f4.up_button_push(elevator);
    elevator.send_(destination, current_floor);
}


