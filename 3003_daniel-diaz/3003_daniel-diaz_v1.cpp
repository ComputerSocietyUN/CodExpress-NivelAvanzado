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
  vector<int> parent(V + 1, - 1), dis(V +1 , -1);

  for (int i =0 ;i < E; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s, t; cin >> s >> t;
  queue<int> q;
  q.push(s);
  parent[s] = 0;
  dis[s] = 0;
  
  // BFS
  while (q.size()){
    int u = q.front();
    q.pop();

    for (auto v: g[u]){
      if (parent[v] == -1){
        parent[v] = u;
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }

  if (parent[t] == -1){
    cout << no << endl;
    return;
  }

  vector<int> path;
  int x = t;
  while (x != 0){
    path.push_back(x);
    x = parent[x];
  }

  cout << "dist=" << dis[t] << endl;
  
  reverse(path.begin(), path.end());

  for (int i =0 ;i < path.size(); i++){
    if (i > 0){
      cout << "->";
    }
    cout << path[i];
  }
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