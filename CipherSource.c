#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "CipherHeader.h"

// Encrypt a Message using Caesar Cipher logic
void EncryptMessage(char* Message, int ShiftKey) {
    printf("-----------------------------------\n");
    printf("Encrypted Message is: ");
    for (int i = 0; Message[i]; i++) {
        char ch = Message[i];

        if (isalpha(ch)) {
            int Index = getIndex(toupper(ch));   // Convert to uppercase
            int NewIndex = (Index + ShiftKey + QueueSize) % QueueSize; // Shift forward
            char newChar = queue[NewIndex];

            // Preserve original case (uppercase or lowercase)
            printf("%c", islower(ch) ? tolower(newChar) : newChar);
        } else {
            printf("%c", ch);             // Print non-alphabetic characters as-is
        }
    }
    printf("\n");
}

// Decrypt a Message back to original form
void DecryptMessage(char* Message, int ShiftKey) {
    printf("-----------------------------------\n");
    printf("Original Message is: ");
    for (int i = 0; Message[i]; i++) {
        char ch = Message[i];

        if (isalpha(ch)) {
            int Index = getIndex(toupper(ch)); // Convert to uppercase
            int NewIndex = (Index - ShiftKey + QueueSize) % QueueSize; // Shift backward
            char newChar = queue[NewIndex];
            printf("%c", islower(ch) ? tolower(newChar) : newChar);
        } else {
            printf("%c", ch);             // Print non-alphabetic characters as it is
        }
    }
    printf("\n");
}




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

// Main function to the program
int main() {
    char choice;          // User choice for encryption or decryption
    char Message[500];    // Input Message
    int ShiftKey;         // Shift key

    SetupCircularQueue();

    // Allow user to choose encryption or decryption
    printf("Do You Want To Encryption (E/e) or Decryption (D/d) Message ?: ");
    scanf(" %c", &choice);
    getchar();

    if (choice == 'E' || choice == 'e') {
        // If user chooses encryption
        printf("Enter your Message: ");
        fgets(Message, sizeof(Message), stdin);
        Message[strcspn(Message, "\n")] = '\0';
        printf("Enter shift key : ");
        scanf("%d", &ShiftKey);           // Read shift key
        EncryptMessage(Message, ShiftKey);

    } else if (choice == 'D' || choice == 'd') {
        // If user chooses decryption
        printf("Encrypted Message: ");
        fgets(Message, sizeof(Message), stdin);
        Message[strcspn(Message, "\n")] = '\0';
        printf("Enter shift key : ");
        scanf("%d", &ShiftKey);      // Read shift key
        DecryptMessage(Message, ShiftKey);

    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

