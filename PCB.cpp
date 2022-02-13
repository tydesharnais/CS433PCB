#include "PCB.h"
using namespace std;

//CONSTRUCTORS//
PCB::PCB() {
    this->currentState = pcbSate::NEW;
}
PCB::PCB(int priority) {
    this->PID = priority;
    this->priority = priority;
    this->currentState = pcbSate::NEW;
};

//Overloaded Constructor id PID is given 

PCB::PCB(int PID, int priority) {
    this->PID = PID;
    this->priority = priority;
    this->currentState = pcbSate::STATE::NEW;
};

int PCB::get_PID() { return PID; };
void PCB::set_PID(int num) { PID = num; };
void PCB::set_PRIORITY(int num) { priority = num; };
pcbSate::STATE PCB::get_STATE() { return currentState; };
int PCB::get_PRIORITY() { return priority; };
void PCB::set_STATE(pcbSate::STATE nS) { currentState = nS; };
/*
std::ostream& operator<<(std::ostream& os, const PCB &s) {
    
    os << "PROCESS ID: " << s.PID << "\t PROIRTY: " << s.priority << "\t CURRENT_STATE: " << s.currentState << std::endl;
}*/


/*
std::string STATE::state_HELPER(){
    string state_Handler;
    switch(currentState){
        case PCB::STATE::NEW:
            return "NEW";
            break;
        case PCB::STATE::READY:
            return "READY";
            break;
        case PCB::STATE::RUNNING:
            return "RUNNING";
            break;
        case PCB::STATE::WAITING:
            return "WAITING";
            break;
        case PCB::STATE::TERMINATED:
            return "TERMINATED";
            break;
    }
}*/
