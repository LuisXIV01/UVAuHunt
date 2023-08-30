#include <bits/stdc++.h>
#define pq priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>>
#define INF 1000000000
using namespace std;
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
vector<vector<int>> matAdj;
int dj(int m, int n){
	pq q;
	q.push({matAdj[0][0], {0,0}});
	vector<vector<int>> v(m, vector<int>(n, INF));
	v[0][0] = matAdj[0][0];
	
	while(!q.empty()){
		int carga = q.top().first;
		int xx = q.top().second.first;
		int yy = q.top().second.second;
		q.pop();
		if(v[xx][yy] < carga) continue;
		
		for(int i = 0; i < 4; i++){
			int x = xx + dx[i];
			int y = yy + dy[i];
			
			if(x >= 0 and x < m and y >= 0 and y < n and v[x][y] > matAdj[x][y] + carga){
				v[x][y] = carga + matAdj[x][y];
				q.push({v[x][y],{x,y}});
			}
		}
	}
	return v[m-1][n-1];
}
int main(){
	int N, m, n;
	cin >> N;
	while(N--){
		cin >> m >> n;
		matAdj.assign(m, vector<int>(n));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> matAdj[i][j];
				
			}
		}
		cout << dj(m,n) << '\n';
	}
}
