#include <bits/stdc++.h>
using namespace std;
#define N 25
bool vis[N][N];
char adjlist[N][N];
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, tlin, tcol;
void dfs(int i, int j, int* cont){
    vis[i][j] = true;
    for(int k=0; k<8; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >-1 and x < tlin and y >-1 and y < tcol and adjlist[x][y] == '1' and !vis[x][y]){
			//cout << "x = " << x << " y = " << y << '\n';
			(*cont)++;
            dfs(x,y, cont);
		}
    }
}
int main(){
    //freopen("output.txt", "w", stdout);
    //freopen("imput.txt", "r", stdin);
    int i, j, k, c, cont, maior;
    string text[26], te;
    cin >> c;
    getline(cin, te);
    cin.ignore();
    for(k = 0; k<c; k++){
		if(k) cout << '\n';
		
		getline(cin, text[0]);
		for(i=1; text[i-1].size() !=0; i++){
			getline(cin, text[i]);
		}
		tlin=i-1;
		tcol = text[0].size();
		for(i=0; i<tlin; ++i){
			for(j=0; j<tcol; ++j){
				adjlist[i][j] = text[i][j];
			}
		}
		for(i=0, maior=cont=0; i<tlin; ++i){
			for(j=0; j<tcol; ++j){
				if(adjlist[i][j] == '1'){
					if(!vis[i][j]){
						cont++;
						dfs(i, j, &cont);
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
