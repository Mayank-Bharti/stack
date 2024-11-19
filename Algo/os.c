#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    
    // Initialize all allocations to -1 (meaning unallocated)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Loop through each process and find the best fit block for it
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        
        for (int j = 0; j < m; j++) {
            // Check if the current block can fit the process
            if (blockSize[j] >= processSize[i]) {
                // Find the smallest sufficient block
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // If a suitable block was found, allocate it to the process
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];  // Reduce the available memory in this block
        }
    }

    // Print the allocation results
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t\t%d\t\t\t\t", i, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSize[] = {21, 22, 230};
    int processSize[] = {12, 110, 13};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);

    return 0;
}
