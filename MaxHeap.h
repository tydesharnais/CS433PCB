#include "PCB.h"
#include <vector>
#include <iostream>
#pragma once
#ifndef MAXHEAP_H
#define MAXHEAP_H
class MaxHeap {
	friend class PCB;
	friend class ReadyQueue;
	
public:
	int capacity; //For display optional 
	int size;  //Current size of Heap
	int* heap; //pointer for heap array
	std::vector<PCB*> pcbHeap;
	MaxHeap();
	MaxHeap(int size);
	int getSize();
	int getCapacity();
	void insert_PCB(PCB& new_PCB);
	void debugHelper(int left, int right, int cur_Largest);
	bool isEmpty();
	int parent(int i);
	int leftChild(int i);
	int rightChild(int i);
	void buildHeap();
	void heapify(int i);
	void pop_top();
	int get_SIZE();
	PCB* peek_min();
	void swap_PCB(PCB* a, PCB* b);
	void swap(int& a, int& b);
	void display();
};
#endif