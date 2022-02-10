﻿/*
Assignment: 1 - Priority Queue of Processes

Name: Tyler Desharnais, James Donaldson
Date: 14 Feb 2022

Summary: We are initializing a priority queue through the use of the heap
data structure. We will also be using a Process control block to manage the 
pritorty of each entry into the queue. We balanced the heap to have the highest priorities 
at the top to create a system for easy removal based on priority.

*/

#include <iostream>
#include <string>
#include <stdlib.h> //srand, rand
#include <time.h>
#include <map>
#include "ReadyQueue.cpp"
#include "PCB.cpp"


using namespace std;

void test1(ReadyQueue& q1)
{
    std::cout << "// TEST 1\n";

    // START OF TEST 1 
    q1.size(20);

    // 1) Add processes 14, 1, 28, 39 and 18 to 𝑞1. 
    q1.addPCB(14);
    q1.addPCB(1);
    q1.addPCB(28);
    q1.addPCB(39);
    q1.addPCB(18);
    //Display the content of 𝑞1
    q1.display(); 

    // 2) remove the process with the highest priority from q1
    q1.removePCB();
    //Display the content of 𝑞1
    q1.display();

    // 3) Add processes 48, 10, 31, 19 to 𝑞1.
    q1.addPCB(48);
    q1.addPCB(10);
    q1.addPCB(31);
    q1.addPCB(19);
    //Display the content of 𝑞1
    q1.display();

    // 4) remove the process with the highest priority from q1 and display q1
    q1.removePCB();
    q1.display();

    // 5) Add processes 29, 41, 18, 46 to 𝑞1. Display the content of 𝑞1
    q1.addPCB(29);
    q1.addPCB(41);
    q1.addPCB(18);
    q1.addPCB(46);
    q1.display();
    

    // (6) One by one remove the process with the highest priority from the queue q1 and display it after each removal.
    while (!q1.isEmpty()) {
        q1.removePCB();
        q1.display();
    }
    // END OF TEST 1
}
void test2(ReadyQueue& q2) {

    srand(time(NULL));//established for the random generator
    PCB p1;//initialize the PCB class to enter into queue

    //loop to add 100 elements to the queue
    for (int i = 0; i < 100; i++) {
        int random = rand () % 50;
        q2.addPCB(p1.(i + 1,random));
        
    }
    //
    int heapNum = 101;
    //for loop to run through the process of adding or removing 
    //from the queue a million times.
    start = clock();// store the clock time at the begining of the loop
    for (int i = 0; i < 1000000; i++) {
        int pick = rand() % 2;
        //if pick is 0 we will remove from queue if not empty
        if (pick == 0) {
            //if to check if queue is empty
            if(!q2.isEmpty()) q2.removePCB();
        }
        //else statment if pick is 1 to add to queue and asign random priority
        else {
            //random int to pick priority
            int random2 = rand() % 50;
            //add to queue the new pcb
            q2.addPCB(p1.(heapNum, random));
            //increment for the next pcb
            heapNum++;
        }
    }
    end = clock() - start; // subtract the start time from the end time.
    q2.display();//display final queue
    //print statment to show total time it took in miliseconds
    cout << "Test 2 is finished and took " << end / 1000 << " ms.\n";
}
int main(){

    ReadyQueue q1;//initialize the queue to pass into the test
    
    test1(q1);//call test 1
    test2(q1);//call test2
    /*
    //m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "3"), 100) );
    PCB blocks[10];
    int count = 1;

    for(int i=0; i < 10; i++){
       // cout << i <<":\n" <<endl;
        blocks[i] = PCB(count, 1+(rand()%50));
        q1.addPCB(blocks[i]);
      //  heap.printHeapLevels();
        count++;
    }
    q1.display();
    */
    /*
    for(int i=0; i < 10; i++){
        cout << blocks[i] << endl;   
    }
    heap.printHeapLevels();
    */
   /*
    while(!q1.isEmpty()){
       // cout << "Removing ID" << heap.peek_min()->get_PID() << "Priority: " << heap.peek_min()->get_PRIORITY() << endl;
        q1.removePCB(); 
       // heap.printHeapLevels();
    }
    */
    /*
    for(int i=0; i < 10; i++){
        cout << blocks[i] << endl;   
    }
    */





    return 0;
}