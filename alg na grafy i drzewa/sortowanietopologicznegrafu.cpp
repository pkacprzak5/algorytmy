#include <bits/stdc++.h>
using namespace std;
//dotyczy DAG, czyli skierowanego acyklicznego grafu
vector<int> S;//przechowuje wierzchołki grafu posortowane topologicznie

void dfs(int v, vector<bool> &visited, vector<vector<int>> G){
    visited[v]=true;
    for(auto &w : G[v]){
        if(!visited[w]) dfs(w, visited, G);
    }
    S.push_back(v);
}
void toposort(vector<vector<int>> &G){
    vector<bool> visited(G.size(), 0);
    for(int i = 1; i<G.size(); i++){
        if(!visited[i]) dfs(i, visited, G);
    }
    reverse(S.begin(), S.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    return 0;
}