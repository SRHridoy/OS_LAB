#include <stdio.h>
int main()
{
    int i, j, k, l, p, f;
    scanf("%d", &f);
    int frame[f];
    scanf("%d", &p);

    int page[p];
    for (i = 0; i < p; i++)
    {
        scanf("%d", &page[i]);
    }

    int totalmiss = 0;
    memset(frame, -1, sizeof(frame));

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
            int mxdis = 0;
            int pos = 0;
            for (j = 0; j < f; j++)
            {
                if (frame[j] == -1)
                {
                    pos = j;
                    break;
                };
                int dis = 1000;
                for (k = i + 1; k < p; k++)
                {
                    if (page[k] == frame[j])
                    {
                        dis = k;
                        break;
                    }
                }
                if (frame[j] != -1 && dis > mxdis)
                {
                    pos = j;
                    mxdis = dis;
                }
            }
            printf("%d is replaced by %d\n", frame[pos], page[i]);
            frame[pos] = page[i];
            totalmiss++;
        }
        else
            printf("%d hit\n", page[i]);
        // to see the current frame
        // for (k = 0; k < f; k++)
        // {
        //     printf("%d ", frame[k]);
        // }
        // printf("\n");
    }
    char c = '%';
    printf("Total miss %d\n", totalmiss);
    printf("miss ratio %.2lf %c\n", totalmiss / (float)p * 100, c);
    printf("hit ratio %.2lf %c\n", (p - totalmiss) / (float)p * 100, c);

    return 0;
}

/* 
4
19
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/