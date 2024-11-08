#include <stdio.h>

int findOptimal(int pages[], int frames[], int frameSize, int start, int pagesSize) {
    int pos = 0, farthest = start;

    for (int i = 0; i < frameSize; i++) {
        int j;

        for (j = start; j < pagesSize; j++) {
            if (frames[i] == pages[j] && j > farthest) {
                farthest = j;
                pos = i;
            }
        }

        if (j == pagesSize) {
            return i;
        }
    }

    return pos;
}

int main() {
    int pages[30], frames[10], pageFaults = 0, pagesSize, frameSize;

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
            int pos = findOptimal(pages, frames, frameSize, i + 1, pagesSize);
            frames[pos] = pages[i];
            pageFaults++;
            printf("Page %d caused a page fault.\n", pages[i]);
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);
    return 0;
}
