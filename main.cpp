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
    Elevator& elevator1;
    explicit Elevator_Buttons(int x, Elevator& elevator1): elevator1{elevator1}{
        destination = x;
    };

    int destination;
    int current_floor;
    int button_push(){

    }
};
class Elevator_Button_Panel{
public:

    explicit Elevator_Button_Panel(int x, Elevator &elevator1) : button_0(0, elevator1) , button_1(1, elevator1), button_2(2, elevator1),
                                                                                     button_3(3, elevator1){
        current_floor = x;
    }

    int current_floor;
    Elevator_Buttons button_0;
    Elevator_Buttons button_1;
    Elevator_Buttons button_2;
    Elevator_Buttons button_3;

    void button0_push(){

           }
    void button1_push(){

    }
    void button2_push(){
        button_2.button_push();
    }
    void button3_push(){
        button_3.button_push();
    }
private:
};

class Elevator {
public:

    Elevator(int x, Elevator& elevator1) : e_button_panel(destination, elevator1){
    };
    int destination{};
    int current_floor{};
    Elevator_Button_Panel e_button_panel;

      void _send(int dest) {
        if (dest < current_floor) {
            for (dest; dest < current_floor; dest--) {
                cout << "Elevator is on floor: " + std::to_string(current_floor);
            }
        } else if (dest > current_floor) {
            for (dest; dest > current_floor; dest++) {
                cout << "Elevator is on floor: " + std::to_string(current_floor);
            }
        } else {
            cout << "Elevator has reached it's dest";
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
            cout << "Elevator has reached it's destination";
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
    explicit Button_Panel(int x, Elevator& elevator1): up_button(x, elevator1), down_button(x, elevator1){
        current_floor = x;
    };
    int current_floor;
    void down_button_push(){
        down_button.push(current_floor);
    }
    void up_button_push(){
        up_button.push(current_floor);
    }
    Floor_Buttons down_button;
    Floor_Buttons up_button;
};

class Floors {
public:
    Floors(int x, Elevator& elevator1): buttonPanel(x, elevator1){
        current_floor = x;
    };
    int current_floor;
    Button_Panel buttonPanel;
};

class Building {
public:
    Building() =default;
    Elevator elevator1 = Elevator(0,elevator1);
    Floors f1 = Floors(0, elevator1);
    Floors f2 = Floors(1, elevator1);
    Floors f3 = Floors(2, elevator1);
    Floors f4 = Floors(3, elevator1);
    void test(){

    }
};

int main(){
    auto b1 = Building();

    b1.f1.buttonPanel.down_button_push();
};