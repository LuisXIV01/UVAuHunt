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
				//cout << "oi\n";
				bool md = true;
				for(int k=0; k<4; k++){
					int g = dx[k] + x;
					int h = dy[k] + y;
					if(adjlist[g][h] == 'X') md = false;
				}
				if(md){
					vec.back()++;
					//cout << "oi ";
				}
			}
         dfs(x,y);
		}
		
	}	
        
}
int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt","r", stdin);
    int i, j, cont =1;
    cin >> m >> n;
    while(m and n){
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				cin >> adjlist[i][j];
			}
		}
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				if(adjlist[i][j] == 'X'){
					if(!vis[i][j]){
						//cout << "oi ";
						vec.push_back(0);
						dfs(i,j);
						
					}
				}
				//cout << "aqui\n";
			}
		}
		sort(vec.begin(), vec.end());
		cout << cont << '\n';
		for(i=0; i<vec.size(); i++)
			cout << vec[i] << ' ';
		cont++;
		while(!vec.empty())
			vec.pop_back();
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				vis[i][j] = false;
			}
		}
		cin >> m >> n;
	}
}
