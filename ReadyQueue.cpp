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
   
    heap.display();

    
}