
#include <stdio.h>

int findLRU(int time[], int n) {
    int pos = 0;

    for (int i = 1; i < n; i++) {
        if (time[i] < time[pos]) {
            pos = i;
        }
    }

    return pos;
}

int main() {
    int pages[30], frames[10], time[10], pageFaults = 0, pagesSize, frameSize, counter = 0;

    printf("Enter number of pages and frames: ");
    scanf("%d %d", &pagesSize, &frameSize);

    for (int i = 0; i < pagesSize; i++) {
        scanf("%d", &pages[i]);
    }
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < pagesSize; i++) {
        int found = 0;

        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = ++counter;
            }
        }

        if (!found) {
            int pos = findLRU(time, frameSize);
            frames[pos] = pages[i];
            time[pos] = ++counter;
            pageFaults++;
            printf("Page %d caused a page fault.\n", pages[i]);
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);
    return 0;
}

