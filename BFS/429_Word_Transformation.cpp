#include <bits/stdc++.h>
using namespace std;
map <string, pair<int, bool>> dic;
bool umaLetra(string a, string b){
	
	int carac=0;
	
	for(int i = 0; i <(int)a.size(); i++){
		if(a[i]!=b[i]) carac++;
	}
	return (carac==1);
	
}
void makeTree(string a, string b){
	queue <string> q;
	q.push(a);
	dic[a].second = true;
	//cout << q.front() << ' ' << b << '\n';
	while(!q.empty() and q.front() != b){
		for (auto k = dic.begin(); k != dic.end(); ++k){
			if(!(k->second.second) and (k->first).size() == (q.front()).size() and umaLetra(k->first, q.front())){
				k->second.second = true;
				k->second.first = dic[q.front()].first + 1;
				q.push(k->first);
			}
		}
		q.pop();
	}
}
int main(){
	
	string a, b, c;
	int n;
	//~ freopen("12","w",stdout);
	//~ freopen("input.txt", "r", stdin);
	cin >> n;
	getline(cin.ignore(),a);
	
	for(int i=0; i < n; i++){
		cin >> a;
		while(a != "*"){
			dic[a] = {0,false};
			cin >> a;
		}
		cin.ignore();
		while(getline(cin,b) and (int)b.size() > 0){
			stringstream ss;
			ss << b;
			ss >> b >> c;
			makeTree(b, c);
			cout << b << ' ' << c << ' ' << dic[c].first << '\n';
			for (auto k = dic.begin(); k != dic.end(); ++k){
				k->second.first = 0;
				k->second.second = false;
			}
		}
		dic.clear();
		if(n>0) cout<<endl;
	}
}
