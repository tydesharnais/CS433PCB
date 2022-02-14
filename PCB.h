#include <string>
#pragma once

namespace pcbSate {
    //Enums for State of PCB
    enum STATE {
        NEW,
        READY,
        RUNNING,
        WAITING,
        TERMINATED
    };
    
    const std::string enumList[5] = { "NEW", "WAITING", "TERMINATED", "RUNNING", "READY" };
}
class PCB {
    friend class ReadyQueue;
    friend std::ostream& operator<<(std::ostream& os, const PCB& s);
public:
    pcbSate::STATE currentState;
    int PID;   //Process ID - static 
    int priority; //Number from 1 to 50
	PCB();
	PCB(int);
    PCB(int, int);
    int get_PID();
    void set_PID(int num);
    void set_PRIORITY(int num);
    int get_PRIORITY();
    pcbSate::STATE get_STATE();
    void set_STATE(pcbSate::STATE nS);
    
};