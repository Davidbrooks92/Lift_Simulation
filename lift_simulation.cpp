#include <iostream>
#include <mutex>
#include <condition_variable>
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

class Building;
class Button_Panel;
class Elevator;


class Buttons {
public:
    virtual void button_push(){

    };
};

class Elevator_Buttons: private Buttons{
public:

    explicit Elevator_Buttons(int x){
        current_floor = x;
    }
    void button_push(int  x, Elevator& elevator){
        destination = x;

    }

    int destination{};
    int current_floor{};
};

class Elevator_Button_Panel{
public:

    explicit Elevator_Button_Panel(int x):  button_0(0),
    button_1(1), button_2(2), button_3(3){
        current_floor = x;

    };
        Elevator_Buttons button_0;
        Elevator_Buttons button_1;
        Elevator_Buttons button_2;
        Elevator_Buttons button_3;
        void button_0_push(int x, Elevator& elevator){
            button_0.button_push(current_floor, elevator );
        }
        void button_1_push(int x, Elevator& elevator){
            button_1.button_push(current_floor, elevator);
        }
        void button_2_push(int x, Elevator& elevator){
            button_2.button_push(current_floor, elevator);
        }
        void button_3_push(int x, Elevator& elevator){
            button_3.button_push(current_floor, elevator);
        }
private:
    int current_floor;

};

class Elevator{
public:
    Elevator_Button_Panel e_button_panel;
    Elevator(int x): destination{},  e_button_panel(x){
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
    void button_0_push(Elevator& elevator){
         e_button_panel.button_0.button_push(0, elevator);
     }
    void button_1_push(Elevator& elevator){
        e_button_panel.button_1.button_push(1, elevator);
     }
    void button_2_push(Elevator& elevator){
        e_button_panel.button_2.button_push(2, elevator);
     }
    void button_3_push(Elevator& elevator){
        e_button_panel.button_3.button_push(3, elevator);
     }

private:
    int destination;
    int current_floor;
};

class Floor_Buttons: private Buttons {
public:

    explicit Floor_Buttons(){

    };
    void button_push(int x, Elevator& elevator){
        current_floor = x;
        elevator._request(current_floor);
    }
    int current_floor;
    };

class Button_Panel{
public:

    explicit Button_Panel(int x, Elevator& elevator):  down_button{}, up_button{} {
        current_floor = x;
    };


    void up_button_push(int x, Elevator& elevator){
        up_button.button_push(x, elevator);
    }

    void down_button_push(int x, Elevator& elevator){
        down_button.button_push(x, elevator);
    }
private:
    int current_floor;
    Floor_Buttons down_button;
    Floor_Buttons up_button;
};

class Floors {
public:
    Floors(int x, Elevator& elevator): buttonPanel(x, elevator){
        current_floor = x;
    };
    Button_Panel buttonPanel;
    int current_floor;
    void up_button_push(Elevator& elevator){
        buttonPanel.up_button_push(current_floor, elevator);
    }
    void down_button_push(Elevator& elevator){
        buttonPanel.down_button_push(current_floor, elevator);
    }
};

class Building {
public:

    explicit Building(Elevator& elevator): f1{0,elevator},
    f2{1,elevator}, f3{2,elevator}, f4{3,elevator} {

    }
    Floors f1;
    Floors f2;
    Floors f3;
    Floors f4;
    void down_button_push1(Elevator& elevator){
        f1.down_button_push(elevator);
    }
    void up_button_push1(Elevator& elevator){
        f1.up_button_push(elevator);
    }
    void down_button_push2(Elevator& elevator){
        f2.down_button_push(elevator);
    }
    void up_button_push2(Elevator& elevator){
        f2.up_button_push(elevator);
    }
    void down_button_push3(Elevator& elevator){
        f3.down_button_push(elevator);
    }
    void up_button_push3(Elevator& elevator){
        f3.up_button_push(elevator);
    }
    void down_button_push4(Elevator& elevator){
        f4.down_button_push(elevator);
    }
    void up_button_push4(Elevator elevator){
        f4.up_button_push(elevator);
    }

};


