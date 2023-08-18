#include <bits/stdc++.h>
using namespace std;
const int N = 100;//ilosc wierzchołków w grafie

vector<vector<int>> G(N+1);//przechowuje graf

void dfs(int v, vector<bool> &visited){
    //złożoność O(n)
    visited[v] = true;
    //tutaj można wykkonywać operacje na wierzchołku
    for(auto w : G[v]){
        if(!visited[w]) dfs(w, visited);
    }
}

void bfs(int v){
    //złożonośc O(n)
    vector<bool> visited(N, 0);
    queue<int> Q;
    Q.push(v);
    while(!Q.empty()){
        auto x = Q.front();
        Q.pop();
        //tutaj można wykonywać operacje na wierzchołku
        visited[x] = true;
        for(auto w : G[x]){
            if(!visited[w]) Q.push(w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}