#include <stdio.h>

#define MAX_BOOKS 5

// The array of available book IDs
int availableBooks[MAX_BOOKS] = {101, 102, 103, 104, 105};
int bookCount = MAX_BOOKS;

// THESE are the Function prototypes
int checkAvailability(int book_id);
void borrowBook(int book_id);
void displayAvailableBooks();

int main() {
    int choice, book_id;
    printf("\nBOOK ID:\n");
    printf("101. HISTORY\n");
    printf("102. ENGLISH\n");
    printf("103. MATH\n");
    printf("104. SCIENCE\n");
    printf("105. PROGRAMING\n");

    while (1)
     {
        printf("\nLibrary Menu:\n");
        printf("1. Check Availability\n");
        printf("2. Borrow Book\n");
        printf("3. Display Available Books\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("Enter Book ID to check availability: ");
                scanf("%d", &book_id);
                if (checkAvailability(book_id)) {
                    printf("Book ID %d is available.\n", book_id);
                } else {
                    printf("Book ID %d is not available.\n", book_id);
                }
                break;

            case 2:
                printf("Enter Book ID to borrow: ");
                scanf("%d", &book_id);
                borrowBook(book_id);
                break;

            case 3:
                displayAvailableBooks();
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid input. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

int checkAvailability(int book_id) {      // bookCount= 5
    for (int i = 0; i < bookCount; i++) {   //for loop: (innitialisation; condition; iteration)
        if (availableBooks[i] == book_id) {
            return 1; // Book is available
        }
    }
    return 0; // Book is not available
}

void borrowBook(int book_id) {
    for (int i = 0; i < bookCount; i++) {
        if (availableBooks[i] == book_id) {
            // Mark the book as unavailable by shifting the array
            for (int j = i; j < bookCount - 1; j++) {
                availableBooks[j] = availableBooks[j + 1];
            }
            bookCount--; // Decrease the count of available books
            printf("Book ID %d has been borrowed.\n", book_id);
            return;
        }
    }
    printf("Book ID %d is not available for checkout.\n", book_id);
}

void displayAvailableBooks() {
    if (bookCount > 0) {
        printf("Available Books: ");
        for (int i = 0; i < bookCount; i++) {
            printf("%d ", availableBooks[i]);
        }
        printf("\n");
    } else {
        printf("No books are currently available.\n");
    }
}
/
