#include <bits/stdc++.h> 
using namespace std; 
 
struct Item 
{ 
	float weight; 
	int profit; 
}; 
 
struct Node 
{ 
	
	int level, profit, bound; 
	float weight; 
}; 

 
bool cmp(Item a, Item b) 
{ 
	double r1 = (double)a.profit / a.weight; 
	double r2 = (double)b.profit / b.weight; 
	return r1 > r2; 
} 

 
int bound(Node u, int n, int W, Item arr[]) 
{ 
	 
	if (u.weight >= W) 
		return 0; 

    
	int profit_bound = u.profit; 

	 
	int j = u.level + 1; 
	int totweight = u.weight; 

	 
	while ((j < n) && (totweight + arr[j].weight <= W)) 
	{ 
		totweight += arr[j].weight; 
		profit_bound += arr[j].profit; 
		j++; 
	} 

	 
	if (j < n) 
		profit_bound += (W - totweight) * arr[j].profit / 
										arr[j].weight; 

	return profit_bound; 
} 

 
int knapsack(int W, Item arr[], int n) 
{ 
	sort(arr, arr + n, cmp); 

	queue<Node> Q; 
	Node u, v; 

	u.level = -1; 
	u.profit = u.weight = 0; 
	Q.push(u); 

	int maxProfit = 0; 
	while (!Q.empty()) 
	{ 
		
		u = Q.front(); 
		Q.pop(); 

		 
		if (u.level == -1) 
			v.level = 0; 

		 
		if (u.level == n-1) 
			continue; 

        
		v.level = u.level + 1; 

	 
		v.weight = u.weight + arr[v.level].weight; 
		v.profit = u.profit + arr[v.level].profit; 

		 
		if (v.weight <= W && v.profit > maxProfit) 
			maxProfit = v.profit; 

		 
		v.bound = bound(v, n, W, arr); 

		 
		if (v.bound > maxProfit) 
			Q.push(v); 

        
		v.weight = u.weight; 
		v.profit = u.profit; 
		v.bound = bound(v, n, W, arr); 
		if (v.bound > maxProfit) 
			Q.push(v); 
	} 

	return maxProfit; 
} 

 
int main() 
{ 
	int n, W; 
    cin >> n >> W;
	Item arr[n];
    
    for(int i = 1; i <= n; i++) {
       cin >> arr[i].profit >> arr[i].weight;
    }

	cout << "Maximum profit = " << knapsack(W, arr, n) << endl; 

	return 0; 
} 