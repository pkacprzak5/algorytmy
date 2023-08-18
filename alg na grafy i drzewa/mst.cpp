#include <bits/stdc++.h>
using namespace std;
//alg Kruskala do wyznaczania MST

int F(int v, vector<int> &P){//znajduje reprezentanta zbioru w którym jest wierzchołek v
    if(P[v]!=v) P[v] = F(P[v], P);
    return P[v];
}

bool U(int x, int y, vector<int> &P, vector<int> &R){//łączy 2 wierzchołki w jeden zbiór
//zwraca prawdę, jeśli udało się połączyć, fałsz jeśli wierzchołki były już w jednym zbiorze
    x = F(x, P);
    y = F(y, P);
    if(x==y) return false;
    if(R[x]<R[y]) swap(x, y);
    P[y] = x;
    R[x]+=(R[x]==R[y]);//zwiększamy głębokość o 1, gdy wierz x i y były na tej samej głębości
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n , m;
    cin >> n >> m;//n to l. wierzchołków, m to liczba krawędzi
    vector<array<int, 3>> G;//przechowuje krawędzie ważone grafu w formacie<waga krawędzi, wierzch., wierzch.>
    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;//a i b to wierzchołki, c to waga krawędzi łącząca te wierzchołki
        G.push_back({c, a, b});
    }
    vector<int> P(n+1), R(n+1, 0);//R[x] to wysokość drzewa, gdzie x jest korzeniem, a P[x] przechowuje "ojca" x
    //jeśli P[x] = x, to x jest korzeniem i reprezentantem zbioru
    iota(P.begin(), P.end(), 0);
    //alg Kruskala:
    sort(G.begin(), G.end());
    for(auto &[c, x, y]: G){ //po zakończeniu tej pętli wszystkie wierzchołki będa połączone w MST
        U(x, y, P, R); 
    }
    return 0;
}