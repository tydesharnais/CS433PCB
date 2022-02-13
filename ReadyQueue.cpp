#include <iostream>
#include <iomanip>
#include "ReadyQueue.h"


using namespace std;

void ReadyQueue::addPCB(PCB& ref_PCB) { heap.insert_PCB(ref_PCB); };
void ReadyQueue::removePCB() { heap.pop_top(); };
int ReadyQueue::size() { return heap.get_SIZE(); };
bool ReadyQueue::isEmpty() { return heap.isEmpty(); };
ReadyQueue::ReadyQueue()
{
}
//Displays results of the Queue 
void ReadyQueue::display(){
   // int colWidth = 20; 
    //int row = 40;
    string Names[4] = {"# Process", "PID", "PRIORITY", "STATE"};
    int counter =0;
    
    for (auto i : heap.pcbHeap) {
        while(counter < heap.size){
            PCB tmp;
            int id = tmp.get_PID();
            int pri = tmp.get_PRIORITY();
            pcbSate::STATE stat = tmp.get_STATE();
            cout << "PROCESS ID = " << id <<" PRIORITY = " << pri << " STATE = " << stat << endl;
            counter++;
        }
    }
    
    
}