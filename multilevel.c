#include <stdio.h> 
#include <string.h> 
 
struct Process { 
    int pid; 
    int arrival_time; 
    int burst_time; 
    int completion_time; 
    int waiting_time; 
    int turnaround_time; 
}; 
 
void sort_by_arrival(struct Process p[], int n) { 
    struct Process temp; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (p[i].arrival_time > p[j].arrival_time) { 
                temp = p[i]; 
                p[i] = p[j]; 
                p[j] = temp; 
            } 

 
} 
 
void calculate_fcfs(struct Process p[], int n, int start_time) { 
    int current_time = start_time; 
    for (int i = 0; i < n; i++) { 
        if (current_time < p[i].arrival_time) 
            current_time = p[i].arrival_time; 
        p[i].completion_time = current_time + p[i].burst_time; 
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time; 
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time; 
        current_time = p[i].completion_time; 
    } 
} 
 
void print_processes(struct Process p[], int n) { 
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n"); 
    for (int i = 0; i < n; i++) 
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, 
p[i].completion_time, p[i].turnaround_time, p[i].waiting_time); 
} 
 
int main() { 
    int n_sys, n_user; 
    printf("Enter number of system processes: "); 
    scanf("%d", &n_sys); 
    struct Process sys[n_sys]; 
    for (int i = 0; i < n_sys; i++) { 
        printf("Enter PID, Arrival Time and Burst Time for System Process %d: ", i + 1); 
        scanf("%d%d%d", &sys[i].pid, &sys[i].arrival_time, &sys[i].burst_time); 
    } 
 
 
 
    printf("Enter number of user processes: "); 
    scanf("%d", &n_user); 
    struct Process user[n_user]; 
    for (int i = 0; i < n_user; i++) { 
        printf("Enter PID, Arrival Time and Burst Time for User Process %d: ", i + 1); 
        scanf("%d%d%d", &user[i].pid, &user[i].arrival_time, &user[i].burst_time); 
    } 
 
    sort_by_arrival(sys, n_sys); 
    sort_by_arrival(user, n_user); 
 
    calculate_fcfs(sys, n_sys, 0); 
    int last_sys_completion = n_sys > 0 ? sys[n_sys - 1].completion_time : 0; 
    calculate_fcfs(user, n_user, last_sys_completion); 
 
    printf("\nSystem Processes:\n"); 
    print_processes(sys, n_sys); 
    printf("\nUser Processes:\n"); 
    print_processes(user, n_user); 
 
    return 0; 
}