#include <bits/stdc++.h>
using namespace std;
//alg do znajdywania najkrótszej ścieżki w grafie ważonym, złożoność czasowa O(n*m)
//w porównaniu do alg Dijkstry, tutaj mogą być krawędzie o ujemnej wadze
const int N = 100;//liczba wierzchołków


vector<vector<pair<int, int>>> G(N+1);//trzyma graf, gdzie G[x]={y, z} oznacza, że z wierz. x do y jest krawędź o wadze z

int BF(int vs, int vk){
    vector<int> Odl(N+1, INT_MAX);
    Odl[vs] = 0;
    bool czyrelaks = true;
    for(int i =0; i<N  && czyrelaks; i++){
        czyrelaks = false;
        for(int j=1; j<N+1; j++){
            if(Odl[j]==INT_MAX) continue;
            for(auto [u, w]: G[j]){
                if(Odl[u]>Odl[j]+w){
                    czyrelaks = true;
                    Odl[u] = Odl[j]+w;
                }
            }
        }
    }
    return Odl[vk];
    //jeśli zwróci INT_MAX, to albo istnieje w grafie cykl o ujemnej wadze, albo nie istnieje ścieżka z vs do vk
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}