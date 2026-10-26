#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int e[10][10] = {0};
    int closure[10][10] = {0};

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter number of epsilon transitions: ");
    scanf("%d", &m);

    printf("Enter transitions (from to):\n");
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
    }

    for (i = 0; i < n; i++) {
        closure[i][i] = 1;
        for (j = 0; j < n; j++)
            closure[i][j] = closure[i][j] || e[i][j];
    }

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                closure[i][j] = closure[i][j] ||
                    (closure[i][k] && closure[k][j]);

    printf("\nEpsilon-closures:\n");
    for (i = 0; i < n; i++) {
        printf("E-closure(q%d) = { ", i);
        for (j = 0; j < n; j++)
            if (closure[i][j])
                printf("q%d ", j);
        printf("}\n");
    }

    return 0;
}