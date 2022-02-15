#include <iostream>
#include <iomanip>
#include "ReadyQueue.h"


using namespace std;
//inline functions to add, remove PCBs and check size and if heap is empty
void ReadyQueue::addPCB(PCB& ref_PCB) { heap.insert_PCB(ref_PCB); };
void ReadyQueue::removePCB() { heap.pop_top(); };
int ReadyQueue::size() { return heap.get_SIZE(); };
bool ReadyQueue::isEmpty() { return heap.isEmpty(); };
//basic constructor
ReadyQueue::ReadyQueue()
{
}
//Displays results of the Queue 
void ReadyQueue::display(){
   
    heap.display();
    
}