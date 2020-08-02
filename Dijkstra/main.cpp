#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1<<29;
int N, M, adj[1002][1002], dist[1002]; bool flag[1002];
void dijkstra(int s){
    fill(dist, dist+1002, INF);
    dist[s] = 0;
    for(int i=1; i<=N; i++){
        int d=INF, u=0;
        for(int j=1; j<=N; j++)
            if(!flag[j] && dist[j]< d){
                d=dist[j]; u=j;
            }
        flag[u] = 1;
        for(int j=1; j<=N; j++)
            if(!flag[j])
                dist[j]=min(dist[j], dist[u]+adj[u][j]);
    }
}
int main(){
    cin >> N >> M;
    fill_n(&adj[0][0], 1002*1002, INF);
    for(int i=0, u, v, w; i<M; i++){
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = min(adj[u][v], w);
    }
    dijkstra(1);
    for(int i=2; i<=N; i++)
        if(flag[i]) cout << dist[i] << " ";
        else cout << -1 << endl;
}