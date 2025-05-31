#ifndef CIPHER_H
#define CIPHER_H

#define QueueSize 26 // Number of letters in the English alphabet (A-Z)

// Function declarations
void SetupCircularQueue();
int getIndex(char ch);
void EncryptMessage(char* Message, int ShiftKey);
void DecryptMessage(char* Message, int ShiftKey);

#endif

