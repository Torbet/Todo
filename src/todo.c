#include <stdio.h>
#include <time.h>
#include <string.h>

void addItem(char *item) {
    FILE *f;
    f = fopen("tmp/items", "a");
    if (f) {
        fprintf(f, "%s\n", item);
    }
}

int getCount() {
    int c;
    FILE *f;
    f = fopen("tmp/count", "r");
    if (f) {
      c = fgetc(f);
      return(c - '0');
    }
    else {
        return(0);
    }
}

void addCount() {
    int c = getCount();
    FILE *f;
    f = fopen("tmp/count", "w");
    if (f) {
        fprintf(f, "%d", c+1);
    }
}

void clearCount() {
    FILE *f;
    f = fopen("tmp/count", "w");
    if (f) {
        fprintf(f, "%c", '0');
    }
}

void readCache() {
    char c;
    FILE *f;
    f = fopen("tmp/items", "r");
    if (f) {
        while ((c = getc(f)) != EOF)
            // stop printing first line
            putchar(c);
        fclose(f);
    }
}

void addItem(char *item) {
    FILE *f;
    f = fopen("tmp/items", "a");
    if (f) {
        fprintf(f, "%s\n", item);
    }
}

void clearItems() {
    FILE *f;
    f = fopen("tmp/items", "w");
    fclose(f);
}

int main(int argn, char **args) {
    if(argn>1) {
        // adding todo
        if(strcmp(args[1], "add") == 0) {
            if(args[2]) {
                if(getCount()<3) {
                    addItem(args[2]);
                    addCount();
                }
                else {printf("Already Got Enough To Do!");}
            }
            else {printf("Enter When Ur Gonna Do!");}
        }

        if(strcmp(args[1], "clear") == 0) {
            clearItems();
            clearCount();
        }
    }
    else {
        readCache();
        time_t now = time(0);
        printf("%ld", now);
    }
}
