
#include <stdio.h>

int main() {
    int n, i, time = 0, tq;
    int at[20], bt[20], rem[20], ct[20], tat[20], wt[20];
    int q[10000], front = 0, rear = 0, count = 0;
    int next = 0, p, exec;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(count < n) {
        while(next < n && at[next] <= time) {
            q[rear++] = next;
            next++;
        }

        if(front == rear) {
            time++;
            continue;
        }

        p = q[front++];

        if(rem[p] > tq)
            exec = tq;
        else
            exec = rem[p];

        rem[p] -= exec;
        time += exec;

        while(next < n && at[next] <= time) {
            q[rear++] = next;
            next++;
        }

        if(rem[p] > 0) {
            q[rear++] = p;
        }
        else {
            ct[p] = time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            count++;
            avgwt += wt[p];
            avgtat += tat[p];
        }
    }

    printf("\nP\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n",
        i+1, ct[i], tat[i], wt[i]);

    printf("Average WT = %.2f\n", avgwt/n);
    printf("Average TAT = %.2f\n", avgtat/n);

    return 0;
}
