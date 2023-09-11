#include <bits/stdc++.h>
#define pq priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define INF 1000000000
using namespace std;
int size;
map<int, vector<pair<int,int>>> adjlist;
long int dj(int m, int n){
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
	long int N, e, s, q, a, b, c;
	cin >> N;
	for(int i=1; i <= N; i++){
		cin >> size >> q >> s >> e;
		for(int i = 0; i < q; i++){
			cin >> a >> b >> c;
			adjlist[a].push_back({c,b});
			adjlist[b].push_back({c,a});
		}
		
		int cont = dj(s,e);
		if(cont == INF) printf("Case #%d: unreachable",i);
		else printf("Case #%d: %i",i, cont);
		cout << '\n';
		adjlist.clear();
	}
	
}
