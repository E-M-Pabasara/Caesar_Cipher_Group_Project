#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "CipherHeader.h"

// Circular queue variables
char queue[QueueSize];
int front = 0;        // Index pointing to the front
int rear = -1;        // Index of the rear
int count = 0;

// Initialize the circular queue with characters A-Z
void SetupCircularQueue() {
    for (int i = 0; i < QueueSize; i++) {
        rear = (rear + 1) % QueueSize;    // Move rear index forward in circular fashion
        queue[rear] = 'A' + i;
        count++;
    }
}

// Find the index of a character in the queue
int getIndex(char ch) {
    for (int i = 0; i < QueueSize; i++) {
        if (queue[i] == ch)               // If character matches returns its index
            return i;
    }
    return -1; // Character not found
}