#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>
#include <queue>
#include <string>

using std::string;
using std::mutex;
using std::condition_variable;
using std::queue;
using std::unique_lock;
using std::cout;
using std::endl;
using std::thread;

class Button_Panel;
class Elevator;



class Buttons {
public:
    virtual int button_push() =0;
};
class Elevator_Buttons{
public:
    explicit Elevator_Buttons(int x){
        destination = x;
    };

    static void send_elevator(int destination, int current_floor)  {
        if(destination < current_floor){
            int x = current_floor - destination;

        } else if(destination > current_floor){

        }
    };
    int destination;
    int current_floor{};
};
class Elevator_Button_Panel{
public:
    explicit Elevator_Button_Panel(){
        Elevator_Buttons button_0(0);
        Elevator_Buttons button_1(1);
        Elevator_Buttons button_2(2);
        Elevator_Buttons button_3(3);
    }
};

class Elevator {
public:
    Elevator() = default;
    int destination;
    int current_floor;
    Elevator_Button_Panel e_button_panel;

     static void _send(int destination, int current_floor) {
        if (destination < current_floor) {
            for (destination; destination < current_floor; destination--) {
                cout << "Elevator is on floor: " + std::to_string(current_floor);
            }
        } else if (destination > current_floor) {
            for (destination; destination > current_floor; destination++) {
                cout << "Elevator is on floor: " + std::to_string(current_floor);
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
            cout << "Elevator has reached it's i";
        }
    }

};




class Floor_Buttons {
public:
    Elevator& elevator;
    explicit Floor_Buttons(int x,Elevator &elevator1): elevator{elevator1}{
        current_floor = x;
    };
    void push(int x) {
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
};

class Floors {
public:
    Floors(int x, Elevator& elevator){
        current_floor = x;
        Button_Panel buttonPanel(current_floor, elevator);
    };
    int current_floor;
};

class Building {
public:
    Building() {
        Elevator elevator;
        auto f1 = Floors(0, elevator);
        auto f2 = Floors(1, elevator);
        auto f3 = Floors(2, elevator);
        auto f4 = Floors(3, elevator);
    }
};







int main(){
    Building building;
    Button_Panel:buttonPanel;
};