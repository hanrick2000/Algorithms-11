#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll MAXX = 1e15;
const ll MOD = 1e9 + 7;
 
#define P pair
#define F first
#define S second
#define vec vector
 
struct class_cmp {
    bool operator()(const P<ll, ll> &lhs, const P<ll, ll> &rhs) const {
        return lhs.F > rhs.F && lhs.S > rhs.S;
    }
};
 
bool cmp(pair<ll, ll> &lhs, pair<ll, ll> &rhs) {
    return lhs.F > rhs.F || lhs.S > rhs.S;
}
 
ll n, m;
vec<vec<ll>> adj;
vec<bool> visited;
vec<bool> path;
vector<ll> s;
bool flag;
 
void dfs(ll u) {
    if(path[u]) {
        flag = true;
        return;
    }
    if(visited[u]) return;
 
    visited[u] = true;
 
    path[u] = true;
    for (auto &v : adj[u]) {
        if(flag) return;
        dfs(v);
        if(flag) return;
    }
    path[u] = false;
 
    s.push_back(u);
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
 
    adj.resize(n + 5);
    visited.resize(n + 5);
    path.resize(n + 5);
 
    ll u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
        if(flag) break;
    }
 
    if(!flag) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            cout << s[i] << " ";
        }
        cout << "\n";
    }else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}