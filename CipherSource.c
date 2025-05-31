#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "CipherHeader.h"

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

