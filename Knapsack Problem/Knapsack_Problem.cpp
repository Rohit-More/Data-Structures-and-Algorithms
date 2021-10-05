// Problem Statement

/*Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value 
in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and 
weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out 
the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You 
cannot break an item, either pick the complete item or don’t pick it (0-1 property).*/

/*sample Problem
value[] ={60,100,120}
weight[]={10,20,30}
W =50

Output
220
*/

/*Test Cases
3                 //number of items
15 30 45          //number of weight
60 120 150        //number of values
50                //Capacity of Knapsack


Output
180
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e3 + 2, MOD = 1e9 + 7;
int val[N], wt[N];
int dp[N][N];

int Knapsack(int n, int w)
{
    // when weight is less than zero
    if (w <= 0)
        return 0;

    // when item is less than zero
    if (n <= 0)
        return 0;

    //  store the values in dp when it is not compute
    if (dp[n][w] != -1)
        return dp[n][w];

    //storing the values in dp when it is already computed
    if (w < wt[n - 1])
        dp[n][w] = Knapsack(n - 1, w);

    // otherwise it stores first when item is not taken ,second item is taken ,third item values which is taken from input
    else
        dp[n][w] = max(Knapsack(n - 1, w), Knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);

    return dp[n][w];
}

signed main()
{
    // initlise with -1
    rep(i, 0, N)
    {
        rep(j, 0, N)
            dp[i][j] = -1;
    }
    // number of items
    int n;
    cin >> n;

    //Number of weights
    rep(i, 0, n)
    {
        cin >> wt[i];
    }

    // number of values as per weights
    rep(i, 0, n)
    {
        cin >> val[i];
    }

    // Capacity of Knapsack
    int w;
    cin >> w;

    // return the maximum values of items in knapsack of weight W
    cout << Knapsack(n, w) << endl;
}
