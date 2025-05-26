 
#include <stdio.h> 
struct Task { 
    int id; 
    int execution_time; 
    int period; 
    int deadline; 
    int remaining_time; 
    int next_release; 
}; 
 
int main() { 
    int n, hyper_period = 1; 
    printf("Enter number of tasks: "); 
    scanf("%d", &n); 
    struct Task t[n]; 
    for (int i = 0; i < n; i++) { 
        printf("Enter Execution Time and Period for Task %d: ", i + 1); 
        scanf("%d%d", &t[i].execution_time, &t[i].period); 
        t[i].id = i + 1; 
        t[i].deadline = t[i].period; 
        t[i].remaining_time = 0; 
        t[i].next_release = 0; 
        hyper_period *= t[i].period; 
    } 

 
 
    printf("\nTime\tTask\n"); 
    for (int time = 0; time < hyper_period; time++) { 
        for (int i = 0; i < n; i++) 
            if (time == t[i].next_release) { 
                t[i].remaining_time = t[i].execution_time; 
                t[i].next_release += t[i].period; 
            } 
 
        int current = -1, min_period = 1e9; 
        for (int i = 0; i < n; i++) 
            if (t[i].remaining_time > 0 && t[i].period < min_period) { 
                min_period = t[i].period; 
                current = i; 
            } 
 
        if (current != -1) { 
            printf("%d\tT%d\n", time, t[current].id); 
            t[current].remaining_time--; 
        } else { 
            printf("%d\tIdle\n", time); 
        } 
    } 
 
    return 0; 
} 
 
