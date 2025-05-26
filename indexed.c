#include <stdio.h> 
 
int main() { 
    int diskSize, indexBlock, fileSize; 
    printf("Enter total disk size: "); 
    scanf("%d", &diskSize); 
 
    int disk[diskSize]; 
    for (int i = 0; i < diskSize; i++) 
        disk[i] = 0; 
 
    printf("Enter index block number: "); 
    scanf("%d", &indexBlock); 
    if (indexBlock >= diskSize) { 
        printf("Invalid index block.\n"); 
        return 0; 
    } 
 
    printf("Enter file size (number of blocks): "); 
    scanf("%d", &fileSize); 
 
    if (disk[indexBlock] == 1) { 
        printf("Index block already allocated.\n"); 
        return 0; 
    } 
 
    int blocks[fileSize]; 
    printf("Enter data block numbers:\n"); 
    for (int i = 0; i < fileSize; i++) { 

 
        scanf("%d", &blocks[i]); 
        if (blocks[i] >= diskSize) { 
            printf("Invalid block number %d.\n", blocks[i]); 
            return 0; 
        } 
    } 
 
    if (disk[indexBlock] == 1) { 
        printf("Index block already allocated.\n"); 
        return 0; 
    } 
 
    for (int i = 0; i < fileSize; i++) { 
        if (disk[blocks[i]] == 1) { 
            printf("Block %d already allocated. Cannot allocate file.\n", blocks[i]); 
            return 0; 
        } 
    } 
 
    disk[indexBlock] = 1; 
    for (int i = 0; i < fileSize; i++) 
        disk[blocks[i]] = 1; 
 
    printf("File allocated with index block %d and data blocks: ", indexBlock); 
    for (int i = 0; i < fileSize; i++) 
        printf("%d ", blocks[i]); 
    printf("\n"); 
 
    return 0; 
} 
