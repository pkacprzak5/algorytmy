#include <bits/stdc++.h>
using namespace std;
//używamy algorytmu Kosaraju do wyznaczenia silnie spójnych składowych (dotyczy grarfów skierowanych)

void dfs(int v, vector<bool> &visited, vector<vector<int>> &G, stack<int> &S){
    visited[v] = true;
    for(auto &w : G[v]){
        if(!visited[w]) dfs(w, visited, G, S);
    }
    S.push(v);
}

void rdfs(int v, vector<int> &P, int p, vector<vector<int>> &G, vector<bool> &visited){
    visited[v] = true;
    P[v] = p;
    for(auto &w : G[v]){
        if(!visited[w]) rdfs(w, P, p, G, visited);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;//n to liczba wierzchołków, a m to liczba krawędzi
    vector<vector<int>> G(n+1);
    vector<vector<int>> rG(n+1);
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b; // oznacza, że jest ścieżka z a do b
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    stack<int> S;
    vector<bool> visited(n+1, 0);
    for(int i = 1; i<n+1; i++){
        if(!visited[i]) dfs(i, visited, G, S);
    }
    vector<int> P(n+1);//przechowuje nr silnie spójniej składowej w której jest ten wierzch.
    vector<bool> rvisited(n+1, 0);
    int i = 1;
    while(!S.empty()){
        auto x = S.top();
        S.pop();
        if(!rvisited[x]){
            rdfs(x, P, i, rG, rvisited);
            i++;
        }
    }
    if(i>1) i--;//bo ostatnim krokiem było zwiększenie i bez powstania kolejnej spójnej
    cout << i << "\n";//wyświetla liczbę silnie spójnych składowych
    return 0;
}