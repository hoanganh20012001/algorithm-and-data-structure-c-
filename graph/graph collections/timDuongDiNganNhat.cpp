#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;
const int N = 1005;
typedef pair<int, int> ii;
/**
 * @param d: mảng lưu chữ đợ lớn từ 1 đỉnh tới các đỉnh còn lại
 * @param path: mảng lưu chữ các đỉnh mà nó đã đi qua
 */
int n, m, k, d[N], path[N];
vector<ii> adj[N];

void dijkstra(int st) {
    priority_queue <ii, vector<ii>, greater<ii>> q;

    for (int i = 1; i <= n; i++) {
        d[i] = oo;
    }
    d[st] = 0;
    path[st] = -1;
    q.push({0, st});

    while (!q.empty()) {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();

        if (du != d[u]) continue;

        for (auto x: adj[u]) {
            int v = x.second;
            int dv = x.first;

            if (du + dv < d[v]) {
                d[v] = du + dv;
                q.push({d[v], v});
                path[v] = u;
            }
        }
    }
}

void findPaht(int point) {
    int way[N], cnt = 0;
    while (point != -1) {
        /**
         *  find path
         */
        way[++cnt] = point;
        point = path[point];
    }
    for (int i = cnt; i >= 1; i--) {
        cout << way[i] << " ";
    }
    cout << endl;
}

void output() {
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;    
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});

        }
        dijkstra(k);
        int point = 9;
        cout << d[point] << endl;
        findPaht(point);

        for (int i = 0; i <= N; i++) {
            adj[i].clear();
        }
    }
}