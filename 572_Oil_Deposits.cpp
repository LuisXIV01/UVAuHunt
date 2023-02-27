#include <bits/stdc++.h>
using namespace std;
#define N 100
bool vis[N][N];
char adjlist[N][N];
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, m, n;
void dfs(int i, int j){
    vis[i][j] = true;
    for(int k=0; k<8; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >-1 and x < m and y >-1 and y < n and adjlist[x][y] == '@' and !vis[x][y]){
			//cout << "x = " << x << " y = " << y << '\n';
            dfs(x,y);
		}
    }
}
int main(){
    //freopen("output.txt", "w", stdout);
    int i, j, resp, cont =1;
    cin >> m >> n;
    while(m != 0){
		resp=0;
		
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				cin >> adjlist[i][j];
			}
		}
		
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				if(adjlist[i][j] == '@'){
					if(!vis[i][j]){
						//cout << "[i = " << i << " j = " << j << "]\n";
						dfs(i,j);
						resp++;
					}
				}
				//cout << "aqui\n";
			}
		}
		cout << resp << '\n';
		cont++;
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				vis[i][j] = false;
			}
		}
		cin >> m >> n;
	}
}
