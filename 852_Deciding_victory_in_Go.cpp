#include <bits/stdc++.h>
using namespace std;
#define N 9
bool vis[N][N], ver, ok;
char adjlist[N][N], let;
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, black, white, meio;
void dfs(int i, int j, char l){
    vis[i][j] = true;
    for(int k=0; k<4; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		if(x >-1 and x < N and y >-1 and y < N and adjlist[x][y] == 'X' and !vis[x][y] and !ok){
			let = 'X';
			ok = true;
		}
		else{
			if(x >-1 and x < N and y >-1 and y < N and adjlist[x][y] == 'O' and !vis[x][y] and !ok){
				let = 'O';
				ok = true;
			}
			else{
				if(x >-1 and x < N and y >-1 and y < N and adjlist[x][y] != l and !vis[x][y] and adjlist[x][y] != let and ok) ver = false;
			}
		}
		
        if(x >-1 and x < N and y >-1 and y < N and adjlist[x][y] == l and !vis[x][y]){
			if(l == 'X') black++;
			else{
				if(l == 'O') white++;
				else meio++;
			}
            dfs(x,y, l);
		}
		
    }
}
int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int i, j, k, t;
    cin >> t;
    for(k = 0; k<t; k++){
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				cin >> adjlist[i][j];
			}
		}
		black = white = 0;
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				meio = 0;
				ver = true;
				ok = false;
				if(adjlist[i][j] == 'X'){
					if(!vis[i][j]){
						dfs(i,j,'X');
					}
				}
				else{
					if(adjlist[i][j] == 'O'){
						if(!vis[i][j]){
							dfs(i,j,'O');
						}
					}
					else{
						if(!vis[i][j]){
							dfs(i,j,'.');
						}
						if(ver and let == 'X') black += meio;
						else{
							if(ver and let == 'O') white += meio;
						}
					}
				}
				//cout << "aqui\n";
			}
		}
		cout << "Black " << black << " White " << white << '\n';
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				vis[i][j] = false;
			}
		}
	}
}
