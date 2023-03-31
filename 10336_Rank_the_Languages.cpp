#include <bits/stdc++.h>
using namespace std;
#define N 100
#define f first
#define s second
bool vis[N][N];
char adjlist[N][N], letra;
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, m, n;
void dfs(int i, int j){
    vis[i][j] = true;
    for(int k=0; k<4; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >-1 and x < m and y >-1 and y < n and adjlist[x][y] == letra and !vis[x][y]){
			//cout << x << " " << y << adjlist[x][y] << '\n';
            dfs(x,y);
		}
    }
}
bool sortPair(const pair <int, char> &x, const pair <int, char> &y){
	if(x.second > y.second) return true;
	if(x.second < y.second) return false;
	return x.first < y.first;
	
}
	
int main(){
	//freopen("input.txt","r", stdin);
	//freopen("output.txt","w",stdout);
	int q, g;
	vector<pair<char,int>> lin;
	cin >> q;
	for(int i=1; i<=q; i++){
		cin >> m >> n;
		
		for(int j =0; j<m; j++)
			for(int k=0; k<n; k++)
				cin >> adjlist[j][k];
		//~ for(int j =0; j<m; j++){
			//~ for(int k=0; k<n; k++)
				//~ cout << adjlist[j][k];
			//~ cout << '\n';
		//~ }
		for(int j =0; j<m; j++){
			for(int k=0; k<n; k++){
				if(!vis[j][k]){
					letra = adjlist[j][k];
					//cout << j << ' ' << k << '\n' << adjlist[j][k] << '\n';
					dfs(j,k);
					
					int l;
					g = lin.size();
					for(l=0; l<g and adjlist[j][k] != lin[l].f; l++);
					
					if(l < g){
						(lin[l].s)++;
						//cout << "if " << g << ' ' << l << '\n' << lin[l].f << '\n';
					}
					else{
						lin.push_back(make_pair(adjlist[j][k],1));
						//cout << "else " << g << ' ' << l << '\n' << lin[l].f << '\n';
					}
				}
			}
		}
		sort(lin.begin(), lin.end(), sortPair);
		cout << "World #" << i << '\n';
		g = lin.size();
		for(int j=0; j<g; j++)
			cout << lin[j].f << ": " << lin[j].s << '\n';
		
		while(!lin.empty())
				lin.pop_back();
		for(int j=0; j<m; ++j)
			for(int k=0; k<n; ++k)
				vis[j][k] = false;
	}
}
