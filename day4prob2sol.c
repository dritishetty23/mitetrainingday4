#include <stdio.h>

struct Fiction_t {
    char title[250];
    char author[125];
    float price;
};
typedef struct Fiction_t Fiction;

struct NonFiction_t {
    char title[250];
    char subject[500];
    float price;
};
typedef struct NonFiction_t NonFiction;

union BookType_t {
    Fiction fiction;
    NonFiction nonFiction;
};
typedef union BookType_t BookType;

typedef struct {
    BookType book;
    char type; // 'F' for Fiction, 'N' for NonFiction
} Book;

void addBooks(Book books[], int n);
void displayBooks(Book books[], int n);

int main() {
    int numBooks;
    printf("Enter number of books: ");
    scanf("%d", &numBooks);

    Book books[numBooks];
    addBooks(books, numBooks);
    displayBooks(books, numBooks);

    return 0;
}

void addBooks(Book books[], int n) {
    for (int i = 0; i < n; i++) {
        char type;
        printf("Book %d: (F)iction or (N)on-Fiction: ", i + 1);
        scanf(" %c", &type);
        books[i].type = type;

        if (type == 'F' || type == 'f') {
            printf("Enter title: ");
            scanf(" %[^\n]s", books[i].book.fiction.title);
            printf("Enter author: ");
            scanf(" %[^\n]s", books[i].book.fiction.author);
            printf("Enter price: ");
            scanf("%f", &books[i].book.fiction.price);
        } else if (type == 'N' || type == 'n') {
            printf("Enter title: ");
            scanf(" %[^\n]s", books[i].book.nonFiction.title);
            printf("Enter subject: ");
            scanf(" %[^\n]s", books[i].book.nonFiction.subject);
            printf("Enter price: ");
            scanf("%f", &books[i].book.nonFiction.price);
        } else {
            printf("Invalid type. Book skipped.\n");
            i--; // Decrement i to re-enter this book
        }
    }
}

void displayBooks(Book books[], int n) {
    for (int i = 0; i < n; i++) {
        if (books[i].type == 'F' || books[i].type == 'f') {
            printf("Fiction Book: %s, Author: %s, Price: %.2f\n",
                   books[i].book.fiction.title, books[i].book.fiction.author, books[i].book.fiction.price);
        } else if (books[i].type == 'N' || books[i].type == 'n') {
            printf("Non-Fiction Book: %s, Subject: %s, Price: %.2f\n",
                   books[i].book.nonFiction.title, books[i].book.nonFiction.subject, books[i].book.nonFiction.price);
        }
    }
}
