#include <bits/stdc++.h>
#define pb push_back
using namespace std;
char matr[1000][1000];
bool vis[1000][1000];
int M, N;
void bfs(int o, int TTL){
	queue<int> q;
	vis[o] = true;
	for(int i = 0; i < adj[o].size(); i++)
		q.push(adj[o][i]);
		
	for(int i = 0; i < TTL; i++){
		int tam = q.size();
		while(tam--){
			vis[q.front()] = true;
			for(int i = 0; i < adj[q.front()].size(); i++){
				if(!vis[adj[q.front()][i]]){
					q.push(adj[q.front()][i]);
				}
			}
			q.pop();
		}
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int ;
	cin >> M >> N;
	while(M != 0 and N != 0){
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				matr[i][j] = 0;
			
		cin >> r;
		for(int i = 0; i < r; i++){
			cin >> m >> x;
			for(int i = 0; i < x; i++){
				cin >> n;
				matr[m][n] = 1;
			}
		}
	}
}
