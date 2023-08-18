#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> adjlist;
map<string, string> parent;
map<string, int> nivel;
map<string, bool> vis;
stack<string> caminho;
void bfs(string a){
	queue<string> q;
	q.push(a);
	nivel[a] = 0;
	string s;
	while(!q.empty()){
		s = q.front();
		q.pop();
		for(auto z: adjlist[s]){
			if(!vis[z]){
				vis[z] = true;
				q.push(z);
				parent[z] = s;
				nivel[z] = nivel[s]+1;
			}
			else{
				if(nivel[s] < nivel[parent[z]]){
					parent[z] = s;
					nivel[z] = nivel[s] +1;
				}
			}
		}
	}		
}

int main(){
	int n;
	string a, b;
	
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			adjlist[a].push_back(b);
			adjlist[b].push_back(a);
		}
		cin >> a >> b;
		bfs(a);
		caminho.push(b);
		for(int i = 0; i < nivel[b]; i++){
			caminho.push(parent[caminho.top()]);
		}
		while(!caminho.empty()){
			cout << caminho.top() << ' ';
			caminho.pop();
		}
	}
}
