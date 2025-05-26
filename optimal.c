
#include <stdio.h> 
 
int findOptimal(int pageSeq[], int frame[], int frames, int current, int pages) { 
    int res = -1, farthest = current; 
    for (int i = 0; i < frames; i++) { 
        int j; 
        for (j = current; j < pages; j++) { 
            if (frame[i] == pageSeq[j]) 
                break; 
        } 
        if (j == pages) 
            return i; 
        if (j > farthest) { 
            farthest = j; 
            res = i; 
        } 
    } 
    return (res == -1) ? 0 : res; 
} 
 
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
    for (int i = 0; i < frames; i++) 
        frame[i] = -1; 
 
    int pageFaults = 0, count = 0; 
 
    for (int i = 0; i < pages; i++) { 
        int found = 0; 
        for (int j = 0; j < frames; j++) { 
            if (frame[j] == pageSeq[i]) { 
                found = 1; 
                break; 
            } 
        } 
        if (!found) { 
            if (count < frames) { 
                frame[count++] = pageSeq[i]; 
            } else { 
                int idx = findOptimal(pageSeq, frame, frames, i + 1, pages); 
                frame[idx] = pageSeq[i]; 
            } 
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