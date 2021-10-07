#include <stdio.h>

int main() {
    int n = 0, tq = 0, i = 0;
    printf("ROUND ROBIN");  
    printf("\nEnter the Time Quantum : ");
    scanf("%d", &tq);
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    int AT[20] = {0}, at_i = 0;                 
    int BT[20] = {0}, bt_i = 0;                 
    int P[20] = {0}, p_i = 0;                   
    int RT[20] = {0};                          
    int CT[20] = {0};                           
    int TAT[20] = {0};                          
    int WT[20] = {0};                           
    int RQ[100] = {-1}, rq_i = -1, rq_j = -1;   
    int time = 0;                               
    int prev_time = 0;                         
    int count = 0;                              
    int remain = n;   

    for (i = 0; i < n; i++) {
    printf("Enter Arrival Time and Burst Time for Process Number %d :",i+1);
    scanf("%d",&AT[i]);
    scanf("%d",&BT[i]);
    RT[i]=BT[i];
    }
    printf("\n");
    for (i = 0; i < 100; i++) {
        RQ[i]=-1;
    }
    RQ[0] = 0;
    rq_i = 0;
    rq_j = 0;


    for (time = 0, count = 0; remain != 0;) {
        prev_time = time;
        if (RT[count] <= tq && RT[count] > 0) {
            time += RT[count];
            RT[count] = 0;
        } else if (RT[count] > 0) {
            time += tq;
            RT[count] -= tq;
        }
        if (RT[count] == 0) {
            remain--;
            CT[count] = time;
            TAT[count] = CT[count] - AT[count];
            WT[count] = TAT[count] - BT[count];
        }
        for (i = 0; i < n; i++) {
            if (AT[i] <= time && AT[i] > prev_time) {
                rq_j += 1;
                RQ[rq_j] = i;
            }
        }
        if (RT[count] != 0) {
            rq_j += 1;
            RQ[rq_j] = count;
        }
        if (rq_i <= rq_j) {
            rq_i += 1;
            count = RQ[rq_i];
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