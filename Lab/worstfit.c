#include <stdio.h>
int main()
{
    int mn, pn, i, j, k, l;
    scanf("%d", &mn);
    int space[mn];
    for (i = 0; i < mn; i++)
    {
        scanf("%d", &space[i]);
    }
    scanf("%d", &pn);
    int process[pn];
    int allocate[pn];
    for (i = 0; i < pn; i++)
    {
        scanf("%d", &process[i]);
        allocate[i] = -1;
    }

    for (i = 0; i < pn; i++)
    {
        int p = -1;
        int mx = 0;
        for (j = 0; j < mn; j++)
        {
            if (space[j] >= process[i] && mx < space[j])
            {
                mx = space[j];
                p = j;
            }
        }
        if (p != -1)
        {
            allocate[i] = p;
            space[p] -= process[i];
        }
    }
    for (i = 0; i < pn; i++)
    {
        if (allocate[i] == -1)
            printf("P%d not allocated\n", i + 1);
        else
            printf("P%d allocated to %d\n", i + 1, allocate[i] + 1);
    }
    return 0;
}


/*
5
100 500 200 300 600
4
212 417 112 426
*/