#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// enum for faction color
typedef enum color { Red, Green, Blue }COLOR;

// node struct for the queue
struct Node {
	char userName[11];
	int level;
	COLOR faction;
	struct Node* next;
};

// prototype functions
struct Node* front;
struct Node* rear;
void enqueue(struct Node* temp);
struct Node* dequeue();
void initQueue();
bool isQueueEmpty();
void randomUsername();
void printQueue(void);