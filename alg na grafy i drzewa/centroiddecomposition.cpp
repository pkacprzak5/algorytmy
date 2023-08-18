#include <bits/stdc++.h>
using namespace std;
//centroid decompocostion ma złożonośc czasową O(n log n)
const int N = 100;
vector<set<int>> G(N+1); //lista sąsiedztwa
vector<int> P(N+1); // dla każdego wierzch trzyma ojca po cetroid decompositon
vector<int> S(N+1);//dla każdego wierzch trzyma rozmiar każdego poddrzewa, gdzie S[x] oznacza rozmiar poddrzewa, gdzie x jest korzeniem

int dfs(int v, int p){
    S[v] = 1;
    for(auto &u : G[v]){
        if(u!=p) S[v]+=dfs(u, v);
    }
    return S[v];
}

int centroid(int v, int p, int n){//n to rozmiar drzewa
    for(auto &u : G[v]){
        if(u!=p){
            if(S[u]>n/2) return centroid(u, v, n);
        }
    }
    return v;
}

void build(int v, int p){//v to wierzchołek od którego zaczynamy, p to ojciec v(na początku p = -1)
    int n = dfs(v, p);
    int c = centroid(v, p, n);
    if(p==-1) p = c;
    P[c] = p;

    vector<int> tmp(G[c].begin(), G[c].end());
    for(auto u : tmp){
        G[c].erase(u);
        G[u].erase(c);//usuwamy możliwe krawędzie między centroidem c, a innymi wierzchołkami
        build(u, c);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //wystarczy wprowadzić dane
    return 0;
}