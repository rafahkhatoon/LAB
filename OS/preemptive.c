
#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0;
    int at[20], bt[20], pr[20], rem[20];
    int ct[20], tat[20], wt[20];
    int min, pos;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority of P%d: ", i+1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        rem[i] = bt[i];
    }

    while(count < n) {
        min = 9999;
        pos = -1;

        for(i = 0; i < n; i++) {
            if(rem[i] > 0 && at[i] <= time &&
               pr[i] < min) {
                min = pr[i];
                pos = i;
            }
        }

        if(pos == -1) {
            time++;
        }
        else {
            rem[pos]--;
            time++;

            if(rem[pos] == 0) {
                ct[pos] = time;
                tat[pos] = ct[pos] - at[pos];
                wt[pos] = tat[pos] - bt[pos];

                count++;
                avgwt += wt[pos];
                avgtat += tat[pos];
            }
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
