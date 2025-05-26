#include <stdio.h> 
 
int main() { 
    int frames, pages; 
    printf("Enter number of frames: "); 
    scanf("%d", &frames); 
    printf("Enter number of pages: "); 
    scanf("%d", &pages); 
 
    int pageSeq[pages]; 
    printf("Enter page reference string:\n"); 
    for (int i = 0; i < pages; i++) 
        scanf("%d", &pageSeq[i]); 
 
    int frame[frames]; 
    int time[frames]; 
    int pageFaults = 0, counter = 0; 
 
    for (int i = 0; i < frames; i++) { 
        frame[i] = -1; 
        time[i] = 0; 
    } 
 
    for (int i = 0; i < pages; i++) { 
        int found = 0; 
        for (int j = 0; j < frames; j++) { 
            if (frame[j] == pageSeq[i]) { 
                found = 1; 

 
                counter++; 
                time[j] = counter; 
                break; 
            } 
        } 
        if (!found) { 
            int lru_index = 0, min_time = time[0]; 
            for (int j = 1; j < frames; j++) { 
                if (time[j] < min_time) { 
                    min_time = time[j]; 
                    lru_index = j; 
                } 
            } 
            frame[lru_index] = pageSeq[i]; 
            counter++; 
            time[lru_index] = counter; 
            pageFaults++; 
        } 
 
        printf("Page %d: ", pageSeq[i]); 
        for (int j = 0; j < frames; j++) { 
            if (frame[j] != -1) 
                printf("%d ", frame[j]); 
            else 
                printf("- "); 
        } 
        printf("\n"); 
    } 
 
    printf("Total Page Faults = %d\n", pageFaults); 

 
 
    return 0; 
} 