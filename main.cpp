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

class Motor {
public:
    Motor motor();
    void move_up(){

    };
    int move_down(int x){

    };
    void stop(){

    };
private:


};

class Buttons {

};

class Floor_Buttons: private Buttons{

};

class Elevator_Buttons: private Buttons{
public:
    Elevator_Buttons(int x){
        destination = x;
    };
private:
    int send_elevator(int destination) : current_floor {
        if(destination < current_floor){
            int x = current_floor - destination;
            motor.move_down(x);
        } else if(destination > current_floor){
            motor.move_up();
        }
    };
    int destination;
};
class Stop_Button: private Elevator_Buttons{
private:
    void stop_elevator();
};

class Elevator {
public:
    Elevator(){}
private:
    int current_floor;
    Elevator_Buttons zero_button;
    Elevator_Buttons one_button;
    Elevator_Buttons two_button;
    Elevator_Buttons three_button;
    Elevator_Buttons stop_button;
    Motor motor;
    int destination;
    int button_push(Elevator_Buttons x){
        if(x = zero_button)
        zero_button.send_elevator(destination): current_floor;
    };
    void operator+(Elevator_Buttons stop_button){
        motor.stop();
    };



};


class Floors {
public:
    explicit Floors(){
    }

    private:
    bool doors = false;
};


class Building {

public:
    explicit Building() {
        int x;
        std::cout << "Enter how many floors the building has";
        std::cin >> x;
        num_floors = x;
        Floors floor[x];
    }
private:
    int num_floors;
    Elevator elevator;
};







int main(){
Building building();
};