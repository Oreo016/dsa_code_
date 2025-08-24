#include <stdio.h>
#include <stdlib.h>

// Function to compute the lexicographic index of a permutation
int permutation_index(const size_t *p, int n) {
    int idx = 0;

    // Precompute factorials up to (n-1)!
    int factorials[n];
    factorials[0] = 1;
    for (int i = 1; i < n; i++) {
        factorials[i] = factorials[i - 1] * i;
    }

    // Compute Lehmer code and convert to index
    for (int i = 0; i < n; i++) {
        int smaller = 0;
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[i]) smaller++;
        }
        idx += smaller * factorials[n - 1 - i];
    }

    return idx;
}

int main() {
    int n;
    scanf("%d", &n);
    size_t p[n];
    for (int i = 0; i < n; i++) {
        scanf("%zu", &p[i]);
    }
    int ans = permutation_index(p, n);
    printf("%d\n", ans);
    return 0;
}

