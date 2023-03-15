#include <bits/stdc++.h>
using namespace std;
#define N 50
bool vis[N][N], caminho;
char adjlist[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int x, y, M, n;
void dfs(int i, int j, int* cont){
    vis[i][j] = true;
    for(int k=0; k<4; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		if(adjlist[x][y] == 'T') return;
	}
    for(int k=0; k<4; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
		if(x >-1 and x < M and y >-1 and y < n and adjlist[x][y] != 'T' and adjlist[x][y] != '#' and !vis[x][y]){
			//cout << "x = " << x << " y = " << y << '\n';
			if(adjlist[x][y] == 'G'){
				(*cont)++; 
				caminho=true;
			}
            dfs(x,y, cont);
		}
    }
}
int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int i, j, cont;
    
    while(cin >> n >> M){
		
		for(i=0; i<M; ++i){
			for(j=0; j<n; ++j){
				cin >> adjlist[i][j];
			}
		}
		for(i=0, cont=0; i<M; ++i){
			for(j=0; j<n; ++j){
				if(adjlist[i][j] == 'P'){
					if(!vis[i][j]){
						dfs(i, j, &cont);
					}
				}
				//cout << "aqui\n";
			}
		}
		cout << cont << '\n';
		for(i=0; i<M; ++i){
			for(j=0; j<n; ++j){
				vis[i][j] = false;
			}
		}
	}
}
