#include <bits/stdc++.h>
using namespace std;
//alg o złożoności O(n^3), wyznacza najkrótszą odległość z każdego wierzch. do każdego
//trzymamy graf w macierzy
const int N = 100; //rozmiar grafu
vector<vector<int>> D(N+1, vector<int>(N+1, INT_MAX));
//vector trzyma dane w następujący sposób:
//D[x][y]=z oznacza że ścieżka z x do y ma wagę z

void FW(){
    for(int i = 1; i<N+1; i++){
        for(int j = 1; j<N+1; j++){
            if(D[i][j]==INT_MAX) continue;
            for(int k = 1; k<N+1; k++){
                if(D[i][k]==INT_MAX) continue;
                D[j][k] = min(D[j][k], D[i][k]+D[i][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //tutaj wystarczy wczytanie danych do macierzy
    return 0;
}