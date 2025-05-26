#include <stdio.h> 
int main() { 
    int b, p; 
    printf("Enter number of memory blocks: "); 
    scanf("%d", &b); 
    int blockSize[b], blockAllocated[b]; 
    printf("Enter sizes of memory blocks:\n"); 
    for (int i = 0; i < b; i++) { 
        scanf("%d", &blockSize[i]); 
        blockAllocated[i] = 0; 
    } 
 
    printf("Enter number of processes: "); 
    scanf("%d", &p); 
    int processSize[p], allocation[p]; 
    printf("Enter sizes of processes:\n"); 
    for (int i = 0; i < p; i++) { 
        scanf("%d", &processSize[i]); 
        allocation[i] = -1; 
    } 
 
    for (int i = 0; i < p; i++) { 
        int worstIdx = -1; 
        for (int j = 0; j < b; j++) { 
            if (!blockAllocated[j] && blockSize[j] >= processSize[i]) { 

 
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) 
                    worstIdx = j; 
            } 
        } 
        if (worstIdx != -1) { 
            allocation[i] = worstIdx; 
            blockAllocated[worstIdx] = 1; 
        } 
    } 
 
    printf("\nProcess No.\tProcess Size\tBlock No.\n"); 
    for (int i = 0; i < p; i++) { 
        printf("%d\t\t%d\t\t", i + 1, processSize[i]); 
        if (allocation[i] != -1) 
            printf("%d\n", allocation[i] + 1); 
        else 
            printf("Not Allocated\n"); 
    } 
 
    return 0; 
} 
 
