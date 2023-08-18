#include <bits/stdc++.h>
using namespace std;


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
    int n = 100;//ilość wierzchołków
    vector<int> P(n+1), R(n+1, 0);//R[x] to wysokość drzewa, gdzie x jest korzeniem, a P[x] przechowuje "ojca" x
    //jeśli P[x] = x, to x jest korzeniem i reprezentantem zbioru
    iota(P.begin(), P.end(), 0);
    //aby łączyc kolejne wierzchołki, należy korzystać z funckji U
    //można wykonywać też inne operacje i wykorzystywać do nich właśnie ten alg
    return 0;
}