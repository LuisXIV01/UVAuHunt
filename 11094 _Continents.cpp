#include <bits/stdc++.h>
using namespace std;
#define N 20
bool vis[N][N];
char adjlist[N][N];
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, tlin, tcol;
void dfs(int i, int j, int* cont, char c){
    vis[i][j] = true;
    for(int k=0; k<4; k++){
		x = (dx[k] + i);
		y = (dy[k] + j + tcol)%tcol;
		
        if(x >-1 and x < tlin and adjlist[x][y] == c and !vis[x][y]){
			//cout << "x = " << x << " y = " << y << '\n';
			(*cont)++;
            dfs(x,y, cont, c);
		}
    }
}
int main(){
    //freopen("output.txt", "w", stdout);
    //freopen("imput.txt", "r", stdin);
    int i, j, m, n, cont, maior;
    char ch;
    while(cin >> tlin){
		cin >> tcol;
		
		for(i=0; i < tlin; i++){
			for(j=0; j<tcol; j++){
				cin >> adjlist[i][j];
			}
		}
		cin >> m >> n;
		ch = adjlist[m][n];
		dfs(m, n, &cont, ch);
		cont =0;
		for(i=0, maior=cont=0; i<tlin; ++i){
			for(j=0; j<tcol; ++j){
				if(adjlist[i][j] == ch){
					if(!vis[i][j]){
						cont++;
						dfs(i, j, &cont, ch);
						if(cont > maior) maior = cont;
						cont =0;
					}
				}
				//cout << "aqui\n";
			}
		}
		cout << maior << '\n';
		for(i=0; i<tlin; ++i){
			for(j=0; j<tcol; ++j){
				vis[i][j] = false;
			}
		}
	}
}
