#include <stdio.h> 
 
int main() { 
    int diskSize, start, length; 
    printf("Enter total disk size: "); 
    scanf("%d", &diskSize); 
 
    int disk[diskSize]; 
    for (int i = 0; i < diskSize; i++) 
        disk[i] = 0; 
 
    printf("Enter starting block and length of file: "); 
    scanf("%d%d", &start, &length); 
 
    if (start + length > diskSize) { 
        printf("Error: Not enough space.\n"); 
        return 0; 
    } 
 
    for (int i = start; i < start + length; i++) { 
        if (disk[i] == 1) { 
            printf("Block %d already allocated. Cannot allocate file.\n", i); 
            return 0; 
        } 
 
 
    } 
 
    for (int i = start; i < start + length; i++) 
        disk[i] = 1; 
 
    printf("File allocated from block %d to %d\n", start, start + length - 1); 
 
    return 0; 
}