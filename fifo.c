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
 
    int frame[frames], index = 0, pageFaults = 0; 
    for (int i = 0; i < frames; i++) 
        frame[i] = -1; 
 
    for (int i = 0; i < pages; i++) { 
        int found = 0; 
        for (int j = 0; j < frames; j++) { 
            if (frame[j] == pageSeq[i]) { 
                found = 1; 
                break; 
 
 
            } 
        } 
        if (!found) { 
            frame[index] = pageSeq[i]; 
            index = (index + 1) % frames; 
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
