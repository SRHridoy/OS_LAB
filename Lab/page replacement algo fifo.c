#include <stdio.h>
int main()
{
    int i, j, k, l, p, f;
    scanf("%d", &f);
    int frame[f];
    memset(frame, -1, sizeof(frame));
    scanf("%d", &p);
    int page[p];
    for (i = 0; i < p; i++)
    {
        scanf("%d", &page[i]);
    }
    int pos = 0;
    int totalmiss = 0;
    for (i = 0; i < p; i++)
    {
        int miss = 1;
        for (j = 0; j < f; j++)
        {
            if (frame[j] == page[i])
            {
                miss = 0;
                break;
            }
        }
        if (miss)
        {
            printf("%d is replaced by %d\n", frame[pos], page[i]);
            frame[pos] = page[i];
            pos++;
            pos %= f;
            totalmiss++;
        }
        else
            printf("%d hit\n", page[i]);
    }
    char c = '%';
    printf("Total miss %d\n", totalmiss);
    printf("miss ratio %.2lf %c\n", totalmiss / (float)p * 100, c);
    printf("hit ratio %.2lf %c\n", (p - totalmiss) / (float)p * 100, c);

    return 0;
}




/* 
3
15
7 0 1 2 0 3 0 4 2 3 0 3 1 2 0

*/