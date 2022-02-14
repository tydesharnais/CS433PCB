#include "MaxHeap.h"
#pragma once
#ifndef READYQUEUE_H
#define READYQUEUE_H
class ReadyQueue {
	friend class PCB;
	friend class MaxHeap;
public:
	MaxHeap heap;
	ReadyQueue();
	void display();
	void addPCB(PCB& ref_PCB);
	void removePCB();
	int size();
	bool isEmpty();

};
#endif