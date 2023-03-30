#include <bits/stdc++.h>
using namespace std;
#define N 50
bool vis[N][N];
char adjlist[N][N];
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, m, n;
vector<int> vec;

void dfs(int i, int j){
  vis[i][j] = true;
  
	for(int k=0; k<4; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
		if(x >-1 and x < m and y >-1 and y < n and !vis[x][y] and (adjlist[x][y] == 'X' or adjlist[x][y] == '*')){
			if(adjlist[x][y] == 'X'){
				cout << "x = " << x << " y = " << y << '\n';
				bool md = true;
				for(int k=0; k<4; k++){
					int g = dx[k] + x;
					int h = dy[k] + y;
					if(adjlist[g][h] == 'X') md = false;
				}
				if(md){
					vec.back()++;
					cout << "conta mais 1\n";
				}
			}
         dfs(x,y);
		}
		
	}	
        
}
int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt","r", stdin);
    int i, j, cont =0;
    cin >> n >> m;
    while(m and n){
		if(cont) cout << '\n';
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				cin >> adjlist[i][j];
			}
		}
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				cout << adjlist[i][j];
			}
			cout << '\n';
		}
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				if(adjlist[i][j] == 'X'){
					if(!vis[i][j]){
						//cout << "Fora x = " << x << " y = " << y << '\n';
						vec.push_back(1);
						dfs(i,j);
						
					}
				}
				//cout << "aqui\n";
			}
		}
		sort(vec.begin(), vec.end());
		cout << "Throw " << cont+1 << '\n';
		for(i=0; i<vec.size()-1; i++)
			cout << vec[i] << ' ';
		cout << vec[i] << '\n';
		cont++;
		while(!vec.empty())
			vec.pop_back();
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				vis[i][j] = false;
			}
		}
		cin >> n >> m;
	}
}
