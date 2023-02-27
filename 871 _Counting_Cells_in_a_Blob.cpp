#include <bits/stdc++.h>
using namespace std;
#define N 25
bool vis[N][N];
char adjlist[N][N];
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, t;
void dfs(int i, int j, int* cont){
    vis[i][j] = true;
    for(int k=0; k<8; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >-1 and x < t and y >-1 and y < t and adjlist[x][y] == '1' and !vis[x][y]){
			//cout << "x = " << x << " y = " << y << '\n';
			(*cont)++;
            dfs(x,y, cont);
		}
    }
}
int main(){
    freopen("output.txt", "w", stdout);
    int i, j, k, c, pos, cont, maior;
    string text;
    cin >> c;
    for(k = 0; k<c; k++){
		cin.ignore();
		if(k) cout << '\n';
		cin >> text;
		t = text.size();
		for(i=0; i<t; i++){
			adjlist[0][i] = text[i];
		}
		for(i=1, pos=0; i<t; ++i){
			for(j=0; j<t; ++j, pos++){
				cin >> adjlist[i][j];
			}
		}
		for(i=0, maior=cont=1; i<t; ++i){
			for(j=0; j<t; ++j){
				if(adjlist[i][j] == '1'){
					if(!vis[i][j]){
						dfs(i, j, &cont);
						if(cont > maior) maior = cont;
						cont =1;
					}
				}
				//cout << "aqui\n";
			}
		}
		cout << maior << '\n';
		for(i=0; i<t; ++i){
			for(j=0; j<t; ++j){
				vis[i][j] = false;
			}
		}
	}
}
