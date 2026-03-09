#include <stdio.h>

void display() {
    printf("Hello\n");
}

int add(int a, int b) {
    return a + b;
}

int main() {
    display();
    printf("%d\n", add(2,3));
}
