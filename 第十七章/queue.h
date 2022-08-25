#pragma once
#include <stdbool.h>

typedef int Item;

#define MAXQUEUE 10

typedef struct {
	Item item;
	struct node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int items;
}Queue;

void InitializeQueue(Queue* pq);

bool QueueIsFull(const Queue* pq);

bool QueueIsEmpty(const Queue* pq);

int QueueItemCount(const Queue* pq);

bool EnQueue(Item item, Queue* pq);

bool DeQueue(Item* pitem, Queue* pq);

void EmptyTheQueue(Queue* pq);
