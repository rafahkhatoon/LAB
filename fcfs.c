
#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    float avgwt = 0, avgtat = 0;
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    for(i = 0; i < n; i++) {
        if(time < at[i])
            time = at[i];

        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nP\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n",
        i+1, ct[i], tat[i], wt[i]);

    printf("Average WT = %.2f\n", avgwt/n);
    printf("Average TAT = %.2f\n", avgtat/n);

    return 0;
}
