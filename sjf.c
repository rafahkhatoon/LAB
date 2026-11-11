
#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    int done[20] = {0}, min, pos;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    while(count < n) {
        min = 9999;
        pos = -1;

        for(i = 0; i < n; i++) {
            if(done[i] == 0 && at[i] <= time &&
               bt[i] < min) {
                min = bt[i];
                pos = i;
            }
        }

        if(pos == -1) {
            time++;
        }
        else {
            time += bt[pos];
            ct[pos] = time;
            tat[pos] = ct[pos] - at[pos];
            wt[pos] = tat[pos] - bt[pos];

            done[pos] = 1;
            count++;

            avgwt += wt[pos];
            avgtat += tat[pos];
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
