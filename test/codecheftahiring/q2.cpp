#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <stack>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <sstream>
using namespace std;
 
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define MAX_N 10001
 
vector < int > graph[MAX_N], rev_graph[MAX_N];
 
bool visited[MAX_N] = {0};
bool visited2[MAX_N] = {0};
 
int indegree[MAX_N] = {0};
int represent_node[MAX_N] = {0};
 
void dfs(int node, stack < int > &s) {
    visited[node] = true;
 
    for (int x: graph[node])
        if (!visited[x])
            dfs(x, s);
 
    s.push(node);
}
 
int dfs2(int node, int representative) {
    visited2[node] = true;
    represent_node[node] = representative;
 
    for (int x: graph[node])
        if (!visited2[x])
            dfs2(x, representative);
}
 
int main() {
    FIO;
    int t, n, m, k, i, j, ans=0;
    cin >> t;
    while (t--) {
        cin >> n >> m;
 
        while (m--) {
            cin >> j >> k;
            graph[j].push_back(k);
            rev_graph[k].push_back(j);
        }
 
        stack < int > s;
 
        for (i = 1; i <= n; i++)
            if (!visited[i])
                dfs(i, s);
 
        while (s.size() > 0) {
            j = s.top();
            if (!visited2[j]){
                ans++;
                dfs2(j, j);
            }
            s.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}