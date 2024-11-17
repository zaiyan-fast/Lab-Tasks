#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char ISBN[13];
    int year;
    int isAvailable;
} Book;

int bookCount = 0;
Book library[20];

void addBook(Book newBook) {
    library[bookCount] = newBook;
    bookCount++;
}

int searchBook(const char* title) {
    for (int i = 0; i < bookCount; i++) {
        if (!strcmp(library[i].title, title)) {
            return i;
        }
    }
    return -1;
}

void availability(int i, int isAvailable) {
    if (i >= 0 && i < bookCount) {
        library[i].isAvailable = isAvailable;
    }
}

int main() {
    Book book1 = {"ABC", "XYZ", "123456789123", 2005, 10};
    Book book2 = {"STU", "PQR", "123456789124", 2006, 11};

    addBook(book1);
    addBook(book2);

    int search = searchBook("ABC");
    if (search != -1) {
        printf("Book found: %s by %s", library[search].title, library[search].author);
        availability(search, 0);
    } else {
        printf("Book not found\n");
    }

    return 0;
}
