#include <bits/stdc++.h>
using namespace std;
int iJ, jJ;
queue<pair<int,int>> posF;
queue<pair<int,int>> q;
char madj[1005][1005];

void fire(){
	pair<int,int> pos;
	while(!q.empty()){
		pos.push(q.top());
		p.push();
		if()
	}
}

int main(){
	int i, j, m, n;
	while(cin >> m >> n){
		for(i=0; i < m; i++){
			for(j=0; j < n; j++){
				cin >> madj[i][j];
				if(madj[i][j] == 'J'){
					iJ = i;
					jJ = j;
				}
				else{
					if(madj[i][j] == 'F'){
						posF.push({i,j});
					}
				}
			}
		}
		q.push({iJ,jJ});
		while(!posF.empty()){
			q.push(posF.top());
			posF.pop();
		}
		
	}
}
