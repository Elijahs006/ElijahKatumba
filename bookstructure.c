#include <stdio.h>
#include <string.h>

// Define the Book structure
struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book book;
    FILE *file;
    int choice;
    
    printf("Book Management System\n");
    printf("1. Add book details\n");
    printf("2. Display saved books\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // To consume the newline character
    
    if (choice == 1) {
        // Input book details
        printf("Enter book title: ");
        fgets(book.title, sizeof(book.title), stdin);
        book.title[strcspn(book.title, "\n")] = '\0'; // Remove newline
        
        printf("Enter author name: ");
        fgets(book.author, sizeof(book.author), stdin);
        book.author[strcspn(book.author, "\n")] = '\0'; // Remove newline
        
        printf("Enter price: ");
        scanf("%f", &book.price);
        
        // Save to file
        file = fopen("books.dat", "ab"); // Open in append binary mode
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        fwrite(&book, sizeof(struct Book), 1, file);
        fclose(file);
        
        printf("Book details saved successfully!\n");
    }
    else if (choice == 2) {
        // Read and display saved books
        file = fopen("books.dat", "rb"); // Open in read binary mode
        if (file == NULL) {
            printf("No books found or error opening file!\n");
            return 1;
        }
        
        printf("\nSaved Books:\n");
        printf("--------------------------------------------------\n");
        printf("%-30s %-25s %s\n", "Title", "Author", "Price");
        printf("--------------------------------------------------\n");
        
        while (fread(&book, sizeof(struct Book), 1, file) == 1) {
            printf("%-30s %-25s $%.2f\n", book.title, book.author, book.price);
        }
        
        fclose(file);
    }
    else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}