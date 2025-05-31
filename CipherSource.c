
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

