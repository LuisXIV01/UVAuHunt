#include <bits/stdc++.h>
using namespace std;
#define N 100
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
		
        if(x >-1 and x < tlin and y >-1 and y < tcol and adjlist[x][y] == 'W' and !vis[x][y]){
			//cout << "x = " << x << " y = " << y << '\n';
			(*cont)++;
            dfs(x,y, cont);
		}
    }
}
int main(){
    //~ freopen("output.txt", "w", stdout);
    //~ freopen("input.txt", "r", stdin);
    int i, j, k, c, cont;
    string text, te, pq;
    cin >> c;
    getline(cin, te);
    cin.ignore();
    for(k = 0; k<c; k++){
		if(k) cout << '\n';
		
		getline(cin,text);
		tcol = text.size();
		for(i=0; text[0] =='L' or text[0] =='W'; i++){
			for(j=0; j<tcol; ++j){
				adjlist[i][j] = text[j];
			}
			getline(cin,text);
		}
		tlin=i;
		
		//~ for(i=0; i<tlin; ++i){
			//~ for(j=0; j<tcol; ++j){
				//~ cout << adjlist[i][j];
			//~ }
			//~ cout << '\n';
		//~ }
		//l = adjlist[0][0];
		//cout << l;
		while(text != "\0"){
			if(text[2] != ' '){
				i = text[0] - 48;
				j = text[2] - 48;
				if(text.size() == 4) j = j*10 + text[3] - 48;
			}
			else{
				i = text[0] - 48;
				i = i*10 + text[1] - 48;
				j = text[3] - 48;
				if(text.size() == 5) j = j*10 + text[4] - 48;
			}
			//cout << i-1 << " " << j-1 << adjlist[i-1][j-1] << ' ' << text << ' ';
			cont =0;
			cont++;
			if('W' == adjlist[i-1][j-1]){
				dfs(i-1, j-1, &cont);
			}
			
			for(i=0; i<tlin; ++i){
				for(j=0; j<tcol; ++j){
					vis[i][j] = false;
				}
			}
			cout << cont << '\n';
			//cout << " = " << text << '\n';
			getline(cin,text);
			//cin.ignore();
			
		}
		
		for(i=0; i<tlin; ++i){
			for(j=0; j<tcol; ++j){
				vis[i][j] = false;
			}
		}
	}
}
