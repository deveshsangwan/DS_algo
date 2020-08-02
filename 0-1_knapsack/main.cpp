#include<bits/stdc++.h>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
   int dp[n + 1][maxWeight + 1];
    for(int i = 0; i <= maxWeight; i++){
        dp[0][i] = 0;
    }
     for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    
    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= maxWeight; w++){
                dp[i][w] = dp[i - 1][w];
            if(weights[i - 1] <= w){
                dp[i][w] = max(dp[i][w], (values[i - 1] + dp[i - 1][w - weights[i - 1]]));
            }
        }
    }
   
    return dp[n][maxWeight];
 
}
int main(){

    int t;
    while(t--){
        int maxWeight;
        int n; 
        cin >> maxWeight >> n;
        int* weights = new int[n];
        int* values = new int[n];

        for(int i = 0; i < n; i++){
        cin >> weights[i] >> values[i];
        }


        cout << knapsack(weights, values, n, maxWeight);
    }

}