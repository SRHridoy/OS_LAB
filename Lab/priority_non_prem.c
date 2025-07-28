// less value high priority

#include<stdio.h>

int process[1000], priority[1000], arr[1000], burst[1000];

void sort(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter process number, priority, arrival time, burst time\n");
    
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &process[i], &priority[i], &arr[i], &burst[i]);
    }

    sort(n);

    int vis[n + 1], com[n], turn[n], wt[n];
    for (i = 0; i < n; i++) vis[i] = 0;

    com[0] = arr[0] + burst[0];
    vis[0] = -1;
    int prev = com[0];

    for (i = 1; i < n; i++) {
        int mx = 1000000, pos = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j] == -1) continue;
            if (prev >= arr[j]) {
                if (priority[j] < mx) {
                    mx = priority[j];
                    pos = j;
                }
            }
        }

        if (pos != -1) {
            com[pos] = prev + burst[pos];
            vis[pos] = -1;
            prev = com[pos];
        } else {
            for (int j = 0; j < n; j++) {
                if (vis[j] == 0) {
                    com[j] = arr[j] + burst[j];
                    prev = com[j];
                    break;
                }
            }
        }
    }

    double avet = 0.0, avew = 0.0;
    for (i = 0; i < n; i++) {
        turn[i] = com[i] - arr[i];
        avet += turn[i];
        wt[i] = turn[i] - burst[i];
        avew += wt[i];
    }

    printf("process\t\tturnaround time\t\twaiting time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t\t%d\t\t\t%d\n", process[i], turn[i], wt[i]);
    }

    avet /= n;
    avew /= n;
    printf("Average turn around time: %.2lf\n", avet);
    printf("Average waiting time: %.2lf\n", avew);

    return 0;
}
