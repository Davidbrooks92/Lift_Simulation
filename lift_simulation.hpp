#ifndef UNTITLED_LIFT_SIMULATION_HPP
#define UNTITLED_LIFT_SIMULATION_HPP

#include <iostream>
class Elevator;

class Buttons {
    Elevator& ev;
public:
    Buttons(Elevator&ev2) : ev{ev2} {}
    virtual void push(int , Elevator&) =0;
};

class Floor_Buttons: public virtual Buttons {
public:
    Floor_Buttons(int x, Elevator& elevator) : Buttons(elevator){

    }
    int current_floor{};
    void push(int, Elevator&);
};

class Button_Panel{
    int current_floor;
public:
    Floor_Buttons upbutton;
    Floor_Buttons downbutton;

    explicit Button_Panel(int x, Elevator& elevator) : upbutton(x, elevator), downbutton(x, elevator) {
        current_floor = x;
    };
    void go_up(int, Elevator&);
    void go_down(int, Elevator&);

};

class Floors {
    int current_floor;
public:
    Button_Panel buttonPanel;
    Floors(int x, Elevator &elevator) : buttonPanel(x, elevator) {
        current_floor = x;
    };


};

class Building {
public:
    Elevator& elevator;
    Floors f1;
    Floors f2;
    Floors f3;
    Floors f4;

    explicit Building(Elevator& ev1): elevator{ev1},
    f1{0,elevator},f2{1,elevator},f3{2,elevator},f4{3,elevator} {}

};

class Elevator_Buttons: public Buttons{
public:
    Elevator_Buttons(int x, Elevator& elevator) : Buttons(elevator) {

    }
    void e_push(int, int, Elevator&);
    void push(int, Elevator&);

};

class Elevator_Button_Panel{
public:
    Elevator_Buttons button_0;
    Elevator_Buttons button_1;
    Elevator_Buttons button_2;
    Elevator_Buttons button_3;

    Elevator_Button_Panel(Elevator& elevator):
    button_0(0, elevator),
    button_1(1, elevator),
    button_2(2, elevator),
    button_3(3,elevator) {

    };
    void button_0_push(int x,int y, Elevator&);
    void button_1_push(int x,int y, Elevator&);
    void button_2_push(int x,int y, Elevator&);
    void button_3_push(int x,int y, Elevator&);
private:
    int current_floor;


};

class Elevator{
public:
    int destination;
    int current_floor;
    Elevator_Button_Panel e_button_panel;
    //Building building;


    Elevator(int x = 0): current_floor{x}, destination{0},
    e_button_panel(*this) {


    };
    void send_(int x, int y);
    void _request(int i, Elevator& elevator);

};

#endif //UNTITLED_LIFT_SIMULATION_HPP
