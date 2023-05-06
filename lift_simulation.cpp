#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>
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

class Building;
class Button_Panel;
class Elevator;


class Buttons {
public:
    virtual void button_push() =0;
};

class Elevator_Buttons: private Buttons{
public:
    Elevator &elevator;
    explicit Elevator_Buttons(int x, Elevator &elevator): elevator{elevator}{
        destination = x;
    }
    void button_push(){

    }


private:
    int destination;
    int current_floor;
};

class Elevator_Button_Panel{
public:
    explicit Elevator_Button_Panel(int x, Elevator &elevator): button_0(1, elevator),
    button_1(2, elevator), button_2(3, elevator), button_3(4, elevator){
        current_floor = x;

    };
        Elevator_Buttons button_0;
        Elevator_Buttons button_1;
        Elevator_Buttons button_2;
        Elevator_Buttons button_3;
private:
    int current_floor;

};

class Elevator{
public:
    Elevator_Button_Panel e_button_panel;

    Elevator(int x, Elevator &elevator): e_button_panel(x, elevator){
        current_floor = x;

    };

     void send_(int x, int y) {
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
      void _request(int i) {
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
private:
    int destination;
    int current_floor;
};

class Floor_Buttons: private Buttons {
public:
    Elevator& elevator;
    explicit Floor_Buttons(int x,Elevator &elevator): elevator{elevator}{
        current_floor = x;
    };
    void button_push(){
        elevator._request(current_floor);
    }
private:
    int current_floor;
    };

class Button_Panel{
public:
    explicit Button_Panel(int x, Elevator& elevator): up_button(x, elevator), down_button(x, elevator){};
    Floor_Buttons down_button;
    Floor_Buttons up_button;

    void up_button_push(){
        up_button.button_push();
    }

    void down_button_push(){
        down_button.button_push();
    }
};

class Floors {
public:
    Floors(int x, Elevator& elevator): buttonPanel(x, elevator){
        current_floor = x;
    };
    Button_Panel buttonPanel;
    int current_floor;
    void up_button_push(){
        buttonPanel.up_button_push();
    }
    void down_button_push(){
        buttonPanel.down_button_push();
    }
};

class Building {
public:

    explicit Building(Elevator &elevator): f1{0,elevator},
    f2{1,elevator}, f3{2,elevator}, f4{3,elevator} {
    }
    Floors f1;
    Floors f2;
    Floors f3;
    Floors f4;
    void down_button_push(){
        f1.down_button_push();
    }
    void up_button_push(){
        f1.up_button_push();
    }

};


