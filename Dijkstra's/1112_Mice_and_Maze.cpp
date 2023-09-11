#include <bits/stdc++.h>
#define pq priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define INF 1000000000
using namespace std;
int size;
map<int, vector<pair<int,int>>> adjlist;
int dj(int m, int n){
	pq q;
	
	vector<int> v(size +5, INF);
	v[m] = 0;
	q.push({v[m], m});
	int xx = m;
	while(!q.empty()){
		int carga = q.top().first;
		xx = q.top().second;
		q.pop();
		if(v[xx] < carga) continue;
		
		for(auto p: adjlist[xx]){
			if(v[p.second] > p.first + carga){
				v[p.second] = carga + p.first;
				q.push({v[p.second],p.second});
				//xx = p.second;
			}
		}
	}
	return v[n];
}
int main(){
	//freopen("output.txt","w", stdout);
	int N, z, t, q, a, b, c;
	bool ok=false;
	cin >> N;
	while(N--){
		if(ok) cout << '\n';
		cin >> size >> z >> t >> q;
		for(int i = 0; i < q; i++){
			cin >> a >> b >> c;
			adjlist[a].push_back({c,b});
		}
		
		int cont=0;
		for(int i=1; i <= size; i++){
			//cout << dj(i,z) << '\n';
			if(dj(i,z) <= t){
				cont++;
			}
		}
		cout << cont << '\n';
		adjlist.clear();
		ok=true;
	}
	
}
