#include <bits/stdc++.h>
#define pq priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define INF 1000000000
#define int long long
using namespace std;
int size;
map<int, vector<pair<int,int>>> adjlist;
int dj(int m, vector<int> &pol){
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
	int max = v[pol[0]];
	for(int i = 1; i < (int)pol.size(); i++){
		if(max > v[pol[i]]) max = v[pol[i]];
	}
	return max;
}
signed main(){
	//freopen("output.txt","w", stdout);
	int N, M, B, P, U, V, T;
	while(cin >> N >> M >> B >> P){
		size = N;
		for(int i = 0; i < M; i ++){
			cin >> U >> V >> T;
			adjlist[U].push_back({T, V});
			adjlist[V].push_back({T, U});
		}
		
		vector<int> banks(B, 0);
		vector<int> pol(P, 0);
		for(int i = 0; i < B; i++)
			cin >> banks[i];
			
		if(P > 0){
			for(int i = 0; i < P; i++)
				cin >> pol[i];
			
			int max;
			vector<pair<int,int>> x;
			max = dj(banks[0], pol);
			x.push_back({banks[0],max});
			for(int i = 1; i < B; i++){
				int aux = dj(banks[i], pol);
				if(aux > max){
					x.clear();
					x.push_back({banks[i],aux});
					max = aux;
				}
				else{
					if(aux == max)
						x.push_back({banks[i],aux});
				}
			}
			sort(x.begin(), x.end());
			
			cout << x.size();
			if(x[0].second == INF) cout << " *\n";
			else cout << ' ' << x[0].second << '\n';
			
			int i;
			for(i = 0; i < (int)x.size() -1; i++)
				cout << x[i].first << ' ';
			cout << x[i].first << '\n';
			
			
			x.clear();
		}
		else{
			sort(banks.begin(),banks.end());
			int i;
			cout << B << " *\n";
			for(i = 0; i < B -1; i++)
				cout << banks[i] << ' ';
			cout << banks[i] << '\n';
		}
		adjlist.clear();
		banks.clear();
		pol.clear();
	}
}
