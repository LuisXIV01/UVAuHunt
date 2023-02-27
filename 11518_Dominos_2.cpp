#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<int> adjlist[10005];
void dfs(int u){
    vis[u] = true;
    for(int v: adjlist[u]){
        if(!vis[v]){
            dfs(v);
		}
    }
}
int main(){
    //freopen("output.txt", "w", stdout);
    int i, N, j, n, m, l, x, y, z, resp;
    
    cin >> N;
    
    for(i=0; i < N; i++){
		resp = 0;
		cin >> n >> m >> l;
        
        for(j=0; j<m; j++){
			cin >> x >> y;
			adjlist[x-1].push_back(y-1);
		}
		for(j=0; j<l; j++){
			cin >> z;
			if(!vis[z-1])
				dfs(z-1);
		}
		for(j=0; j<n; j++){
			if(vis[j])
				resp++;
		}
        cout << resp << endl;
		for(j=0;j<=n;j++){
			adjlist[j].clear();
			vis[j] = false;
		}
    }
}
