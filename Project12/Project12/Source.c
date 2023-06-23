#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "queue.h"
#include <time.h>

int main(int argc, char* argv[])
{
	//mapping all the enum values to colors
	char* map[3] = { "Red", "Green", "Blue" };
	srand(time(NULL));

	initQueue();     // initialising the queue
	int number = atoi(argv[1]);   // getting the number from command line
	for (int i = 0; i < number; i++)
	{
		enqueue(rear);   // pushing/enqueuing to the queue
	}

	for (int i = 0; i < number; i++)
	{
		struct Node* del = dequeue();    // storing the front element in del
		printf("%s - ", del->userName);   //printing all the corresponding values of the node
		printf("%d - ", del->level);
		printf("%s\n", map[del->faction - 1]);
		free(del);   //freeing the memory of del after use
	}
	return 0;
}