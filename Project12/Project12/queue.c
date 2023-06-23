#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "queue.h"

//global string to store random string
char result[11];
void randomUsername()
{
	const char* base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";  // base for all the alphanumerics
	for (int i = 0; i < 10; i++)
		result[i] = base[(rand() % 60) + 1];  // taking a random number and getting that alphanumeric from the base
	result[10] = '\0'; //setting last index to '\0' to let the compiler know when to stop
}

int getRandomLevel()
{
	return (rand() % 60) + 1;  //getting random number between 1 and 60 for level
}

int getRandomFaction()
{
	return (rand() % 3) + 1;   // getting random number between 1 and 3 for faction color
}

void initQueue()
{
	front = NULL;
	rear = NULL;  // initialising both front and rear of queue to NULL
}

bool isQueueEmpty()
{
	return front == NULL; //checking if the queue is empty by checking if the front is NULL or not
}
// function to enqueue a node to a queue
void enqueue(struct Node* temp)
{
	temp = (struct Node*)malloc(sizeof(struct Node)); // allocating space for the new node
	if (temp == NULL)  //checking if memory has been allocated
	{
		printf("Memory allocation error\n");
		return;
	}
	randomUsername(); //storing a random username in the global variable result
	strncpy(temp->userName, result, 11);   //copying data members 
	temp->level = getRandomLevel();
	temp->faction = getRandomFaction();
	temp->next = NULL;
	if (isQueueEmpty())   //if queue is empty, set front and rear to temp
		front = rear = temp;
	else
	{
		rear->next = temp;   // else add temp to next of rear and set its value to temp
		rear = temp;
	}
}

//function to dequeue a element from a queue
struct Node* dequeue()
{
	if (isQueueEmpty())  
		return NULL;
	//getting the front element of the queue and returning it and moving the front pointer to the right
	struct Node* temp = front;
	front = front->next;
	return temp;
}
