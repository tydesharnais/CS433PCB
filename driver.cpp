#include <iostream>
#include <string>
#include <stdlib.h> //srand, rand
#include <time.h>
#include <map>
#include "ReadyQueue.cpp"

using namespace std;

int main(){
    ReadyQueue q1;
    
    
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