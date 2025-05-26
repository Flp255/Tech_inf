//
// Created by Student on 19.05.2025.
//

#include "Queue.h"

#define QUEUE_SIZE 5


static int queue_table[QUEUE_SIZE];
static int front = -1;
static int rear = -1;

int isQueueEmpty(void)
{
    return (front == -1) ? 1 : 0;
}

int isQueueFull(void)
{

    return ((rear + 1) % QUEUE_SIZE == front) ? 1 : 0;
}

void Enqueue(int val)
{
    if (!isQueueFull())
    {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % QUEUE_SIZE;
        queue_table[rear] = val;
    }

}

int Dequeue(void) {
    if (!isQueueEmpty()) {
        int val = queue_table[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % QUEUE_SIZE;
        }
        return val;
    }
    return -1;
}
int Peek(void)
{
    if (!isQueueEmpty())
    {
        return queue_table[front];
    }
    return -1;
}
