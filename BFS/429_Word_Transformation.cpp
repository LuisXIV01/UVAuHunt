#include <bits/stdc++.h>
using namespace std;
vector <string>  dictionary;
map <string, bool> vis;
void makeTree(string a){
	queue <string> q;
	
	while(!q.empty()){
		
	}
}
bool umaLetra(string a, string b){
	map <char, int> x;
	for(int i = 0; i < a.size(); i++){
		x[a[i]]++;
		x[b[i]]++;
	}
	return (x.size() == a.size()+1);
}
int main(){
	
	string a;
	int n;
	cin >> n;
	for(int i=0; i < n; i++){
		cin >> a;
		dictionary.push_back(a);
		vis[a] = false;
	}
	
}
if(!vis[dictionary[i]] and dictionary[i].size() == a.size() and umaLetra(dictionary[i], )
