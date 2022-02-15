#include <iostream>
#include <vector>
#include <iomanip>
#include "MaxHeap.h"

using namespace std;

#define INT_MIN -999999
#define INT_MAX 999999

MaxHeap::MaxHeap() {
   
}

MaxHeap::MaxHeap(int size) {

    this->capacity = capacity;
    this->size = size;
    this->heap = new int[size];
    for (int i = 0; i < size; i++) {
        heap[i] = i;
    }
}
//Inline Functions for optimization and decreased function overhead

int MaxHeap::getSize() { return size; }
int MaxHeap::getCapacity() { return capacity; }
bool MaxHeap::isEmpty() { if (size <= 0) { return true; }return false; }
int MaxHeap::parent(int i) { return (i - 1) / 2; }
int MaxHeap::leftChild(int i) { return 2 * i + 1; }
int MaxHeap::rightChild(int i) { return 2 * i + 2; }
int MaxHeap::get_SIZE() { return size; };


void MaxHeap::insert_PCB(PCB &new_PCB){
    size++;
    new_PCB.set_STATE(pcbSate::STATE::READY); //set new state to ready
    pcbHeap.emplace_back(&new_PCB); //inserts new PCB

    heapify(size -1);
}

/**
 * @brief MIN-HEAP FUNCTIONS
 * 
 */

void MaxHeap::buildHeap() 
{
 //from last non leaf 
	for (int i = size/2 -1; i >= 0; i--) { 
		heapify(i); 
	} 
} 

void MaxHeap::debugHelper(int left, int right, int cur_Largest){
    cout << "\n------DEBUG HELPER-------\n";
    cout << "Curr Size: " << size << endl;
    cout << "Curr Index Left: " << left << " and is: " << pcbHeap.at(left)->get_PRIORITY() << endl;
    cout << "Curr Index Right: " << right << " and is: " << pcbHeap.at(right)->get_PRIORITY() << endl;
    cout << "Curr Index largest: " << cur_Largest << " and is: " << pcbHeap.at(cur_Largest)->get_PRIORITY() << endl;
    
};
void MaxHeap::heapify(int i) {  //heapify and bubble up

    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;
    //  debugHelper(left, right, largest);

      //Must find the largest element in the heap
    if (left < size) {
        if (pcbHeap.at(left)->get_PRIORITY() > pcbHeap.at(i)->get_PRIORITY()) { //left is largest
            largest = left;
        }
    }
    if (right < size){
        if( pcbHeap.at(right)->get_PRIORITY() > pcbHeap.at(largest)->get_PRIORITY()) { //right is largest 
        largest = right;
    }
}
    if (largest != i) { //largest was not the parent
        
        swap_PCB(pcbHeap.at(i), pcbHeap.at(largest));

        heapify(largest);
    }
};


void MaxHeap::pop_top(){
    if(isEmpty()==true){
        cout << "Queue is empty" << endl;
    }
    else if(size ==1){
        PCB* ref_PCB = pcbHeap.at(0);
        ref_PCB->set_STATE(pcbSate::STATE::RUNNING);
        pcbHeap.pop_back();
        size--;
    }
    else{
        swap_PCB(pcbHeap.at(0), pcbHeap.at(size - 1));
        PCB* ref_PCB = pcbHeap.at(size-1);
        ref_PCB->set_STATE(pcbSate::STATE::RUNNING);
        pcbHeap.pop_back();
        size--;
        heapify(0);
    }
}

PCB* MaxHeap::peek_min(){
    if(isEmpty()==true){
        cout << "Queue is empty!" << endl;
    }
    return pcbHeap.at(0);
    
    
}
        
//Aux functions for the heap

//C-style swap for heap elements 
void MaxHeap::swap_PCB(PCB *a, PCB *b){

    int tempPID = a->get_PID();
    int tempPriority = a->get_PRIORITY();

    a->set_PRIORITY(b->get_PRIORITY());
    a->set_PID(b->get_PID());
    b->set_PRIORITY(tempPriority);
    b->set_PID(tempPID);

}
void MaxHeap::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
};



void MaxHeap::display()
{
    size = pcbHeap.size();
    unsigned int j = pcbHeap.size();
    if (pcbHeap.size()==0) {
        std::cout << "empty\n";
    }

    for (unsigned int i = 0; i < j; ++i) {

        cout << "Process ID:"<<setw(8) << pcbHeap[i]->PID <<setw(10)<< "Priority:"<<setw(8) << pcbHeap[i]->priority << setw(10) << "Current State:"<<setw(8) << pcbSate::enumList[ pcbHeap[i]->currentState] << "\n";

    }
}
