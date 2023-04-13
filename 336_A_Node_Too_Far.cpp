#include <bits/stdc++.h>
#define pb push_back
using namespace std;
map<int,vector<int>> adj;
map<int, bool> vis;
void bfs(int o, int TTL){
	queue<int> q;
	vis[o] = true;
	for(int i = 0; i < adj[o].size(); i++)
		q.push(adj[o][i]);
		
	for(int i = 0; i < TTL; i++){
		int tam = q.size();
		while(tam--){
			vis[q.front()] = true;
			for(int i = 0; i < adj[q.front()].size(); i++)
				q.push(adj[q.front()][i]);
			
			q.pop();
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	int n, x, y, node, TTL, caso=1;
	while(cin >> n, n){
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
			vis[x] = false;
			vis[y] = false;
		}
		while(cin >> node >> TTL, node and TTL){
			bfs(node, TTL);
			int cont = 0;
			for(auto& [a, b] : vis){
				if(!b) cont++;
				b = false;
			}
			cout << "Case " << caso << ": " << cont << " nodes not reachable from node " << node <<" with TTL = " << TTL << ".\n";
			caso++;
		}
		adj.clear();
		vis.clear();
	}
}
