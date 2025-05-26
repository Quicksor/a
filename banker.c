#include <stdio.h> 
int main() { 
    int n, m; 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    printf("Enter number of resources: "); 
    scanf("%d", &m); 
 
    int alloc[n][m], max[n][m], need[n][m], avail[m]; 
    printf("Enter Allocation Matrix:\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf("%d", &alloc[i][j]); 
 
    printf("Enter Maximum Matrix:\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf("%d", &max[i][j]); 
 
    printf("Enter Available Resources:\n"); 
    for (int i = 0; i < m; i++) 
        scanf("%d", &avail[i]); 
 
    for (int i = 0; i < n; i++) 

 
        for (int j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
 
    int finish[n], safe[n], index = 0; 
    for (int i = 0; i < n; i++) 
        finish[i] = 0; 
 
    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            if (!finish[i]) { 
                int flag = 1; 
                for (int j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]) { 
                        flag = 0; 
                        break; 
                    } 
                } 
                if (flag) { 
                    for (int j = 0; j < m; j++) 
                        avail[j] += alloc[i][j]; 
                    safe[index++] = i; 
                    finish[i] = 1; 
                } 
            } 
        } 
    } 
 
    int is_safe = 1; 
    for (int i = 0; i < n; i++) { 
        if (!finish[i]) { 

 
            is_safe = 0; 
            break; 
        } 
    } 
 
    if (is_safe) { 
        printf("System is in a safe state.\nSafe sequence: "); 
        for (int i = 0; i < n; i++) 
            printf("P%d ", safe[i]); 
        printf("\n"); 
    } else { 
        printf("System is not in a safe state.\n"); 
    } 
 
    return 0; 
} 