// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int V, E;
  cin >> V >> E;
  vector<vector<int>> g(V + 1);
  vector<int> parent(V + 1, - 1), in(V + 1, 0);
  vector<bool> vis(V +1 , 0);

  for (int i =0 ;i < E; i++){
    int u, v; cin >> u >> v;
    in[v]++;
    g[u].push_back(v);
  }

  bool cycle = 0 ;
  function<void(int)> dfs = [&](int u){
    if (cycle) return;
    vis[u] = 1;
    for (auto v: g[u]){
      if (cycle) return;
      if (vis[v]){
        cycle = 1;
        return;
      }
    }
  };

  // assumming values of V are from 1 to V and G is connected
  dfs(1);

  if (cycle){
    cout << "CYCLE" << endl;
    return;
  }


  queue<int> q;
  for (int i =1 ; i <= V; i++){
    if (in[i] == 0) q.push(i);
  }
  
  vector<int> topo;

  while (q.size()){
    int u = q.front();
    topo.push_back(u);
    q.pop();

    for (auto v: g[u]){
      in[v]--;
      if (in[v] ==0 ){
        q.push(v);
      }
    }
  }

  cout << "topo: " ;
  for (auto x: topo) cout << x << " "; 
  cout << endl;

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}

/**
TESTCASE 1 
IN:
5 4
1 2
2 3
3 4
4 5
1 5
OUT:
dist=4
1->2->3->4->5

TESTCASE 2 
IN:
6 7
1 2
1 3
2 4
3 4
4 5
5 6
2 6
1 6
OUT:
dist=2
1->2->6

TESTCASE 3 
IN:
4 2
1 2
3 4
1 4

OUT:
NO
**/