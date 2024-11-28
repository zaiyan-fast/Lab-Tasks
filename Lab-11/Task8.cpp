#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
    float price;
};

void addBook();
void viewBooks();
void searchBook();
void updateBook();
void deleteBook();
float calculateTotalInventoryValue();

int main() {
    int choice;

    do {
	    printf("\n--- Library Management System ---\n");
	    printf("1. Add New Book\n");
	    printf("2. View All Books\n");
	    printf("3. Search for a Book\n");
	    printf("4. Update Book Details\n");
	    printf("5. Delete a Book\n");
	    printf("6. Calculate Total Inventory Value\n");
	    printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: 
                printf("Total Inventory Value: %.2f\n", calculateTotalInventoryValue());
                break;
            case 0: 
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}

void addBook() {
    struct Book book;
    FILE *file = fopen("books.txt", "a");

    if (!file) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &book.id);

    struct Book temp;
    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &temp.id, temp.title, temp.author, &temp.quantity, &temp.price) != EOF) {
        if (temp.id == book.id) {
            printf("Error: Duplicate Book ID!\n");
            fclose(file);
            return;
        }
    }
    
    fseek(file, 0, SEEK_END);

    printf("Enter Title: ");
    scanf(" %[^\n]", book.title);
    
    printf("Enter Author: ");
    scanf(" %[^\n]", book.author);
    
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    
    printf("Enter Price: ");
    scanf("%f", &book.price);

    fprintf(file, "%d,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    
    fclose(file);
    printf("Book added successfully!\n");
}

void viewBooks() {
    struct Book book;
    FILE *file = fopen("books.txt", "r");

    if (!file) {
        perror("Unable to open file!");
        return;
    }

    printf("\n--- List of Books ---\n");
    
    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        printf("ID: %d | Title: %s | Author: %s | Quantity: %d | Price: $%.2f\n",
               book.id, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
}

void searchBook() {
    struct Book book;
    FILE *file = fopen("books.txt", "r");
    
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    char searchTerm[50];
    
    printf("Enter Book ID or Title to search: ");
    scanf(" %[^\n]", searchTerm);

    int found = 0;

    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (book.id == atoi(searchTerm) || strcasecmp(book.title, searchTerm) == 0) {
            found = 1;
            printf("\nFound Book:\nID: %d | Title: %s | Author: %s | Quantity: %d | Price: $%.2f\n",
                   book.id, book.title, book.author, book.quantity, book.price);
        }
    }

    if (!found) {
        printf("No matching records found.\n");
    }

    fclose(file);
}

void updateBook() {
    struct Book book;
    
   FILE *file = fopen("books.txt", "r+");

   if (!file) {
       perror("Unable to open file!");
       return;
   }

   int idToUpdate;

   printf("Enter Book ID to update: ");
   scanf("%d", &idToUpdate);

   int found = 0;

   while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.id, book.title,
                 book.author, &book.quantity,
                 &book.price) != EOF) {

       if (book.id == idToUpdate) {
           found = 1;
           fseek(file, -sizeof(book), SEEK_CUR);

           printf("Enter new Quantity: ");
           scanf("%d", &book.quantity);
           printf("Enter new Price: ");
           scanf("%f", &book.price);

           fprintf(file,"%d,%s,%s,%d,%f\n", 
                   book.id,
                   book.title,
                   book.author,
                   book.quantity,
                   book.price);

           break;
       }
   }

   if (!found) {
       printf("No matching records found.\n");
   } else {
       printf("Book updated successfully!\n");
   }

   fclose(file);
}

void deleteBook() {
   struct Book book;

   FILE *file = fopen("books.txt", "r");
   FILE *tempFile = fopen("temp.txt", "w");

   if (!file || !tempFile) {
       perror("Unable to open file!");
       return;
   }

   int idToDelete;

   printf("Enter Book ID to delete: ");
   scanf("%d", &idToDelete);

   int found = 0;

   while (fscanf(file,"%d,%99[^,],%99[^,],%d,%f\n",
                 &book.id,
                 book.title,
                 book.author,
                 &book.quantity,
                 &book.price) != EOF) {

       if (book.id == idToDelete) {
           found = 1;
           continue;
       }
       fprintf(tempFile,"%d,%s,%s,%d,%f\n",
               book.id,
               book.title,
               book.author,
               book.quantity,
               book.price);
   }

   if (!found) {
       printf("No matching records found.\n");
   } else {
       printf("Book deleted successfully!\n");
   }

   fclose(file);
   fclose(tempFile);

   remove("books.txt");
   rename("temp.txt","books.txt");
}

float calculateTotalInventoryValue() {
   struct Book book;
   
   FILE *file = fopen("books.txt","r");

   if (!file) {
       perror ("Unable to open file!");
       return 0;
   }

   float totalValue = 0.0;

   while(fscanf(file,"%d,%99[^,],%99[^,],%d,%f\n",
                &book.id,
                book.title,
                book.author,
                &book.quantity,
                &book.price)!=EOF){
       totalValue += (book.quantity * book.price);
   }

   fclose(file);
   
   return totalValue; 
}