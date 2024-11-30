#include <stdio.h>
#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

int probe(int H[], int key) {
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) {
        i++;
    }
    return (index + i) % SIZE;
}

int Insert(int H[], int key) {
    int index = hash(key);
    
    if (H[index] != 0) {
        index = probe(H, key);
    }
    
    H[index] = key;
    
    return key;
}

int Search(int H[], int key) {
    int index = hash(key);
    
    int i = 0;
    
    while (H[(index + i) % SIZE] != key) {
        i++;
    }
    
    return (index + i) % SIZE;
}

int main(int argc, const char * argv[]) {
    int HT[10] = {0};
    
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    
    printf("\nKey found at %d\n", Search(HT, 35));
    
    return 0;
}
