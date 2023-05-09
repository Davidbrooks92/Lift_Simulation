#ifndef UNTITLED_LIFT_SIMULATION_HPP
#define UNTITLED_LIFT_SIMULATION_HPP

#endif //UNTITLED_LIFT_SIMULATION_HPP
class Elevator;

class Buttons {
public:
    virtual void button_push(int x, Elevator&);
};

class Floor_Buttons: public Buttons {
public:
    int current_floor;
    //void button_push(int x, Elevator& elevator);
};

class Button_Panel{
public:

    explicit Button_Panel(int x, Elevator& elevator):  down_button{}, up_button{} {
        current_floor = x;
    };
    void up_button_push(int x, Elevator& elevator);
    void down_button_push(int x, Elevator& elevator);
private:
    int current_floor;
    Floor_Buttons down_button;
    Floor_Buttons up_button;
};

class Floors {
public:
    Floors(int x, Elevator &elevator) : buttonPanel(x, elevator) {
        current_floor = x;
    };
    Button_Panel buttonPanel;
    int current_floor;
    void up_button_push(Elevator& elevator);
    void down_button_push(Elevator& elevator);
};

class Building {
public:

    explicit Building(Elevator& elevator): f1{0,elevator},
                                           f2{1,elevator},
                                           f3{2,elevator},
                                           f4{3,elevator}
                                           {}
    void down_button_push1(Elevator& elevator);
    void up_button_push1(Elevator& elevator);
    void down_button_push2(Elevator& elevator);
    void up_button_push2(Elevator& elevator);
    void down_button_push3(Elevator& elevator);
    void up_button_push3(Elevator& elevator);
    void down_button_push4(Elevator& elevator);
    void up_button_push4(Elevator& elevator);

    Floors f1;
    Floors f2;
    Floors f3;
    Floors f4;
};

class Elevator_Buttons: public Buttons{
public:
    int destination{};
    int current_floor{};
};

class Elevator_Button_Panel{
public:
    Elevator_Buttons button_0;
    Elevator_Buttons button_1;
    Elevator_Buttons button_2;
    Elevator_Buttons button_3;
    void button_0_push(int x, Elevator&);
    void button_1_push(int x, Elevator&);
    void button_2_push(int x, Elevator&);
    void button_3_push(int x, Elevator&);
private:
    int current_floor;


};

class Elevator{
public:
    Elevator_Button_Panel e_button_panel;
    Elevator(int x): destination{}, e_button_panel(){
        current_floor = x;
    };
    void send_(int x, int y);
    void _request(int i);
private:
    int destination;
    int current_floor;
};