#include <bits/stdc++.h>
using namespace std;
#define N 9
bool vis[N][N], vez1, ok;
char adjlist[N][N], let;
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y;
map<char, int> color;

void dfs(int i, int j){
    vis[i][j] = true;
    for(int k=0; k<4; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		if(x >-1 and x < N and y >-1 and y < N and !vis[x][y]){
			if(adjlist[x][y] != '.'){
				color[adjlist[x][y]]++;
				dfs(x,y);
			}
		}
    }
}
void dfsMeio(int i, int j){
    vis[i][j] = true;
    for(int k=0; k<4; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		if(x >-1 and x < N and y >-1 and y < N and !vis[x][y]){
			if(adjlist[x][y] == '.'){
				color[adjlist[x][y]]++;
				dfsMeio(x,y);
			}
			else{
				if(!vez1){ // primeira vez aqui
					let = adjlist[x][y];
					vez1 = true;
				}
				else{
					if(let != adjlist[x][y]){
						ok = true;
					}
				}
			}
		}
    }
}
int main(){
    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    int i, j, k, t;
    cin >> t;
    for(k = 0; k<t; k++){
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				cin >> adjlist[i][j];
			}
		}
		//~ for(i=0; i<N; ++i){
			//~ for(j=0; j<N; ++j){
				//~ cout << adjlist[i][j];
			//~ }
			//~ cout << '\n';
		//~ }
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				if(adjlist[i][j] != '.' and !vis[i][j]){
					color[adjlist[i][j]]++;
					dfs(i,j);
				}
			}
		}
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				vis[i][j] = false;
			}
		}
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				if(adjlist[i][j] == '.' and !vis[i][j]){
					let = '.';
					vez1 = ok = false;
					color['.'] =1;
					dfsMeio(i,j);
					if(!ok){
						color[let] += color['.'];
					}
				}
			}
		}
		cout << "Black " << color['X'] << " White " << color['O'] << '\n';
		color.clear();
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				vis[i][j] = false;
			}
		}
	}
}
