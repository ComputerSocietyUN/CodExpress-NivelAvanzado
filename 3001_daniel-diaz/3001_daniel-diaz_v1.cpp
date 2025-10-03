// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

tuple<long long, long long> bubble_sort(vector<long long> &a){
  int n = a.size();
  int comps = 0;
  int swaps = 0;
  
  for (int i =0 ;i < n; i++){
    for (int j = 0; j < n - i - 1; j++){
      if (a[j] > a[j + 1]){
        swap(a[j], a[j + 1]);
        swaps++;
      }
      comps++;
    }
  }

  return {comps, swaps};
}


tuple<string, long long, long long, double>  bubble_sort_wrapper(vector<long long> &a){
  /**
   * @brief 
   * Sorts a vector of long longs in non-descending order
   * Time complexity: O(n log n)
   * Space complexity: O(n log n)
   */
  const auto start{chrono::steady_clock::now()};
  auto [comps, swaps] = bubble_sort(a);

  const auto finish{chrono::steady_clock::now()};
  const chrono::duration<double> elapsed{finish - start};

  return {"Bubble sort", comps, swaps, elapsed.count()};
}

tuple<long long, long long> merge_sort(int l, int r, vector<long long> &a){
  if (l == r){
    return {0,0};
  } 

  int m = l + (r - l) / 2 ;


  auto [c1, s1] = merge_sort(l, m, a);
  auto [c2, s2] = merge_sort(m + 1, r, a);


  long long comps = c1 + c2;
  long long swaps = s1 + s2;

  vector<long long> left, right;
  
  for (int i = l ; i <= m; i++) left.push_back(a[i]);
  for (int i = m + 1 ; i <= r; i++) right.push_back(a[i]);

  int i =0, j =0 ;
  
  int ls = left.size();
  int rs = right.size();


  while (i < ls && j < rs){
    if (left[i] > right[j]){
      a[i + j + l] = right[j];

      j++;
      swaps++;
    }
    else{
      a[i + j + l] = left[i];
      i++;
    }

    comps++;
  }
  
  while (i < ls){
    a[i + j + l ] = left[i];

    i++;
  }
  while (j < rs){
    a[i + j + l ] = right[j];

    j++;
  }


  return {comps, swaps};

}


tuple<string, long long, long long, double>  merge_sort_wrapper(vector<long long> &a){
  /**
   * @brief 
   * Sorts a vector of long longs in non-descending order
   * Time complexity: O(n^2)
   * Space complexity: O(1)
   */
  const auto start{chrono::steady_clock::now()};

  auto [comps, swaps] = merge_sort(0, (int)a.size() - 1, a);

  const auto finish{chrono::steady_clock::now()};
  const chrono::duration<double> elapsed{finish - start};

  return {"Merge sort", comps, swaps, elapsed.count()};
}

void solve(){
  vector<long long> a;

  cout << "3001 -  Sort benchmark: " << endl;
  cout << "Mode A : Input N (size of array), and N elements - Type A in first line" << endl;
  cout << "Mode B : Input N (size of array), and seed - Type B in first line" << endl;
  string mode; cin >> mode;

  if (mode == "A"){
    int n; cin >> n;
    for (int i = 0;i < n ; i++){
      long long x; cin >> x;
      a.push_back(x);
    }
  }
  else{
    int n, seed; cin >> n >> seed;
    long long lim = 1e12;

    mt19937 gen(seed); // mersenne_twister_engine seeded seed from input
    uniform_int_distribution<long long> distrib(-lim, lim);

    for (int i =0;i < n; i++){
      a.push_back(distrib(gen));
    }
  }

  auto a_bubble = a;
  auto a_merge = a;

  auto [name1, comp1, swaps1, time1] = bubble_sort_wrapper(a_bubble);
  auto [name2, comp2, swaps2, time2] = merge_sort_wrapper(a_merge);
  time1 *= 1000.0;
  time2 *= 1000.0;


  // compare results
  sort(a.begin(), a.end());

  bool ok_bubble = a == a_bubble;
  bool ok_merge = a == a_merge;


  if (!ok_bubble){
    cout << "Failed bubble sort: Revise implementation" << endl;
  }
  if (!ok_merge){
    cout << "Failed merge sort: Revise implementation" << endl;
  }

  if (ok_bubble && ok_merge){
    cout << name1 << ", " << "comps=" << comp1 << ", swaps=" << swaps1 << ", ms=" << time1   << endl;
    cout << name2 << ", " << "comps=" << comp2 << ", swaps=" << swaps2 << ", ms=" << time2  << endl;
  }

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
B
10000 1
OUT:
Bubble sort, comps=49995000, swaps=25131616, ms=749.669
Merge sort, comps=120562, swaps=59096, ms=7.19629


TESTCASE 2 
IN:
B
10 1

OUT:
Bubble sort, comps=45, swaps=19, ms=0.000951
Merge sort, comps=22, swaps=9, ms=0.00549

TESTCASE 3 
IN:
A
10
10 9 8 7 6 5 4 3 2 1

OUT:
Bubble sort, comps=45, swaps=45, ms=0.001569
Merge sort, comps=15, swaps=15, ms=0.007354
**/