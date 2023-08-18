#include <bits/stdc++.h>
using namespace std;
//złożoność O(n log n)
const int N = 100;//przykładowa liczba wierzchołków

vector<vector<pair<int, int>>> G(N);//przechowuje graf ważony, pierwszy el w parze to wierzch do którego możemy dojść
//kosztem zapisanym w drugim el pary

int dijkstra(int vs, int vk){//zwraca koszt najkrótszej ścieżki w grafie ważonym od vs do vk
//WAŻNE --> graf nie może posiadać cyklu o ujemnej wadze krawędzi, ani nie może posiadać krawędzi o ujemnej wadze
    priority_queue<pair<int, int>> Q;//first to koszt dojścia z wierzchołka vs do wierz. o nr second
    Q.push({0, vs});
    int wyn = INT_MAX;//przechowuje wynik, jeśli na końcu zostanie ten sam, to znaczy że nie ma ścieżki od vs do vk
    while(!Q.empty()){
        auto [c, v] = Q.top();
        Q.pop();
        if(v==vk){
            wyn = c;
            break;
        }
        for(auto [u, o] : G[v]){
            Q.push({c+o, u});
        }
    }
    return wyn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}