#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, kol = 0, r[1000][1000], go[1000];
map<string, int> mp;
vector<int> adj[1000];
int used[1000][1000];
bool was[1000];

bool TL() {
    return clock() > 1990;
}

void dfs(int v) {
    was[v] = 1;
    for (auto u : adj[v])  if (!was[u]) {
        dfs(u);
    }
}

void dfs2(int v, int cnt) {
    if (v == mp["Minsk"] && cnt == n) {
        cout << "Yes";
        exit(0);
    }

    if (TL()) {
        cout << "No";
        exit(0);
    }

    for (auto u : adj[v]) if (used[v][u] != r[v][u]) {
        cnt++;
        used[v][u]++;
        dfs2(u, cnt);
        cnt--;
        used[v][u]--;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        if (mp[s1] == 0) mp[s1] = ++kol;
        if (mp[s2] == 0) mp[s2] = ++kol;

        adj[mp[s1]].push_back(mp[s2]);
        r[mp[s1]][mp[s2]]++;
        go[mp[s2]]++;
    }

    bool pr = 0;
    for (int i = 1; i <= kol; i++) if(!was[i] && pr) {
            cout << "No";
            exit(0);
        } else if (!was[i]) {
            dfs(i);
            pr = 1;
        }

    for (int i = 1; i <= kol; i++) if (go[i] != adj[i].size()){
            cout << "No";
            exit(0);
        }

    for (int i = 1; i <= kol; i++)
        for (int j = 1; j <= kol; j++) used[i][j] = 0;

    dfs2(mp["Minsk"], 0);
    cout << "No";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q = 1;
    //cin >> q;
    while(q--) solve();

    return 0;
}

/*#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define ll long long

using namespace std;

ll n, x, dp[5001][5001], mod = 1e9 + 7;

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q = 1;
    //cin >> q;
    while(q--) solve();

    return 0;
}*/

