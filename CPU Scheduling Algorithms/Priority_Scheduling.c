#include <stdio.h>

int main() {
    int n = 0, i = 0;
    printf("Priority_Scheduling");
    printf("\nEnter the number of processes : ");
    scanf("%d", &n);
    int AT[20] = {0};                           
    int BT[20] = {0};                           
    int P[20] = {0}, p_i = 0;                   
    int RT[20] = {0};                           
    int CT[20] = {0};                           
    int TAT[20] = {0};                          
    int WT[20] = {0};                           
    int time = 0;                               
    int count = 0;                              
    int remain = n;                            
    int processes_arrived = 0;                
    int smallest = 0;
    int smallest_pos = 0;

    for (i = 0; i < n; i++) {
    printf("Enter Arrival Time and Burst Time for Process Number %d :",i+1);
    scanf("%d",&AT[i]);
    scanf("%d",&BT[i]);
    RT[i]=BT[i];
    }

    printf("\nEnter Priority of processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    for (time = 0; remain != 0 && time < 40; time++) {

        for (i = 0; i < n; i++) {
            if (AT[i] == time) {
                processes_arrived += 1;
            }
        }

        smallest = 999999;
        smallest_pos = -1;

        for (i = 0; i < processes_arrived; i++) {
            if (RT[i] > 0) {
                if (smallest > P[i]) {
                    smallest = P[i];
                    smallest_pos = i;
                }
            }
        }

        count = smallest_pos;
        RT[count]-=1;

        if (RT[count] == 0) {
            remain--;
            CT[count] = time+1;
            TAT[count] = CT[count] - AT[count];
            WT[count] = TAT[count] - BT[count];
        }

    }

    printf("\nCompletion Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", CT[i]);
    }

    printf("\nTurn Around Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", TAT[i]);
    }

    printf("\nWaiting Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", WT[i]);
    }

    printf("\n\nAverage Turn Around Time : ");
    float sum_TAT = 0;
    float avg_TAT = 0;
    for (i = 0; i < n; i++) {
        sum_TAT+=TAT[i];
    }
    avg_TAT = sum_TAT/n;
    printf("%4f",avg_TAT);

    printf("\nAverage Waiting Time : ");
    float sum_WT = 0;
    float avg_WT = 0;
    for (i = 0; i < n; i++) {
        sum_WT+=WT[i];
    }
    avg_WT = sum_WT/n;
    printf("%4f",avg_WT);
    return 0;
}
