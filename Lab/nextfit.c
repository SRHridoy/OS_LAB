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
    j = 0;
    for (i = 0; i < pn; i++)
    {
        for (; j < mn; j++)
        {
            if (space[j] >= process[i])
            {
                space[j] -= process[i];
                allocate[i] = j;
                j++;
                break;
            }
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
3
5 10 20
3
10 20 30
*/