#include <stdio.h>

int main() {
    int pages[30], frames[10], pageFaults = 0, pagesSize, frameSize, counter = 0;

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
            }
        }

        if (!found) {
            frames[counter] = pages[i];
            counter = (counter + 1) % frameSize;
            pageFaults++;
            printf("Page %d caused a page fault.\n", pages[i]);
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);
    return 0;
}

