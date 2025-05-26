#include <stdio.h> 
 
int main() { 
    int diskSize, fileSize; 
    printf("Enter total disk size: "); 
    scanf("%d", &diskSize); 
 
    int disk[diskSize]; 
    for (int i = 0; i < diskSize; i++) 
        disk[i] = 0; 
 
    printf("Enter file size (number of blocks): "); 
    scanf("%d", &fileSize); 
 
    int blocks[fileSize]; 
    printf("Enter block numbers in sequence:\n"); 
    for (int i = 0; i < fileSize; i++) { 
        scanf("%d", &blocks[i]); 
        if (blocks[i] >= diskSize) { 
            printf("Invalid block number %d.\n", blocks[i]); 
            return 0; 
        } 
    } 
 
    for (int i = 0; i < fileSize; i++) { 
        if (disk[blocks[i]] == 1) { 
            printf("Block %d already allocated. Cannot allocate file.\n", blocks[i]); 
            return 0; 
        } 
 
 
    } 
 
    for (int i = 0; i < fileSize; i++) 
        disk[blocks[i]] = 1; 
 
    printf("File allocated in linked manner with blocks: "); 
    for (int i = 0; i < fileSize; i++) 
        printf("%d ", blocks[i]); 
    printf("\n"); 
 
    return 0; 
}