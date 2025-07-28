#include<stdio.h>

int queue1[1000];
int process[1000+1], arr[1000+1], burst[1000+1];
int vis[1000+1];

void sort(int n) {
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;

                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;
            }
        }
    }
}

int main() {
    int timequan, n, i;
    int queuepoint = 0;
    int queuepoindex = -1;
    int starttime = 0;

    printf("Enter time quantum : ");
    scanf("%d", &timequan);
    printf("Enter number of process : ");
    scanf("%d", &n);
    printf("Enter process no, arrival time, burst time \n");
    
    int comp[n+1], b[n+1];
    for (i = 1; i <= n; i++) {
        vis[i] = 0;
        scanf("%d%d%d", &process[i], &arr[i], &burst[i]);
        b[i] = burst[i];
    }

    sort(n);
    int count = n;
    while (count > 0) {
        for (i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                if (starttime >= arr[i] && burst[i] > 0) {
                    vis[i] = -1;
                    queuepoindex++;
                    queue1[queuepoindex] = i;
                }
            }
        }
        if (queuepoint > queuepoindex) {
            starttime++;
            continue;
        }
        int take = queue1[queuepoint];
        queuepoint++;

        if (burst[take] <= timequan && burst[take] > 0) {
            starttime += burst[take];
            comp[take] = starttime;
            burst[take] = 0;
            count--;
        } else {
            burst[take] -= timequan;
            starttime += timequan;

            for (i = 1; i <= n; i++) {
                if (vis[i] == 0) {
                    if (starttime >= arr[i] && burst[i] > 0) {
                        vis[i] = -1;
                        queuepoindex++;
                        queue1[queuepoindex] = i;
                    }
                }
            }
            queuepoindex++;
            queue1[queuepoindex] = take;
        }
    }

    int turn[n+1], wt[n+1];
    double avet = 0, avew = 0;
    for (i = 1; i <= n; i++) {
        turn[i] = comp[i] - arr[i];
        avet += (double)turn[i];
        wt[i] = turn[i] - b[i];
        avew += (double)wt[i];
    }

    printf("\nprocess\t\tturn arount time\t\twaiting time\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t\t\t%d\t\t\t%d\n", process[i], turn[i], wt[i]);
    }

    avet /= n;
    avew /= n;
    printf("Average turn around time : %.2f\n", avet);
    printf("Average waiting time : %.2f\n", avew);

    return 0;
}
