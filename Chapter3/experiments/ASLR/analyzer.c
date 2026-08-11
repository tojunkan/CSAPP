#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
#define PAGE_SHIFT 12  // 4KB page size, 2^12 = 4096

// cmp function for qsort
int cmp_ull(const void *a, const void *b) {
    unsigned long long va = *(unsigned long long*)a;
    unsigned long long vb = *(unsigned long long*)b;
    return (va > vb) - (va < vb);
}

int main() {
    FILE *fp = fopen("addresses.txt", "r");
    if (!fp) {
        perror("failed to open file.");
        return 1;
    }

    unsigned long long addrs[MAX];
    int count = 0;
    char line[64];

    // 1. read all addresses to the array
    while (count < MAX && fgets(line, sizeof(line), fp)) {
        // sscanf is safer than fscanf
        if (sscanf(line, "run at: %llx", &addrs[count]) == 1) {
            count++;
        }
    }
    fclose(fp);

    if (count == 0) {
        printf("didn't get valid address!\n");
        return 1;
    }

    printf("read %d addresses successfully.\n", count);

    // 2. extract page base address, masking off lower 12 bits.
    unsigned long long pages[MAX];
    for (int i = 0; i < count; i++) {
        pages[i] = addrs[i] >> PAGE_SHIFT;  // divided by 4096 to get page frame.
    }

    // 3. sort and get unique values.
    qsort(pages, count, sizeof(unsigned long long), cmp_ull);

    int unique_pages = 1;
    for (int i = 1; i < count; i++) {
        if (pages[i] != pages[i-1]) unique_pages++;
    }

    // 4. print conclusions.
    printf("totally ran %d times.\n", count);
    printf("minimum: 0x%016llx\n", addrs[count - 1]);
    printf("maximum: 0x%016llx\n", addrs[0]);
    printf("unique stack base addresses: %d\n", unique_pages);
    printf("ratio: %.2f%%\n", (float)unique_pages / count * 100);

    // 5. print first 10 raw address and stack base address
    printf("\nfirst 10 samples:\n");
    for (int i = 0; i < (count < 10 ? count : 10); i++) {
        printf("address: 0x%016llx, page base address 0x%010llx\n", addrs[i], addrs[i] >> PAGE_SHIFT);
    }

    return 0;
}
