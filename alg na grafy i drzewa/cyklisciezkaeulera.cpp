#include <bits/stdc++.h>
using namespace std;
//ścieżka Eulera to taka ścieżka, która przechodzi przez każdą krawędź grafu dokładnie raz
//cykl Eulera to ścieżka Eulera która jest cyklem
//algorytm znajduje ścieżkę Eulera w grafie skierowanym w czasie O(m), gdzie m to liczba krawędzi
//ścieżka Eulera istnieje wtedy i tylko wtedy, gdy jest 0 lub 2 wierzch o nieparzystej ilości ścieżek wychodzących od nich
//cykl Eulera isteniej wtedy i tylko wtedy, gdy wszystkie wierzchołki maja patrzystą liczbę krawędzi wychodzących od nich

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, bool>>> G(n+1);//<nr wierz do którego prowadzi krawędź, jeśli false, to usunięta>
    vector<int> R(n+1, 0);//trzema ile krawędzi wychodzi z wierz
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back({b, true});
        R[a]++;
    }
    int liczniknp = 0;//zmienna która trzyma ile jest wierz z nieparzystą ilością krawędzi wychodzących
    vector<int> NP;//tu trzymamy nr wierzch z nieparzystą ilością krawędzi wychodzących
    for(int i = 0; i<n+1; i++){
        if(G[i].size()%2==1){
            liczniknp++;
            NP.push_back(i);
        }
    }
    if(liczniknp==2){
        G[NP[0]].push_back({NP[1], true});
    }else if(liczniknp>0){cout << "Nie ma śceiżki ani cyklu Eulera w grafie\n"; return 0;}
    vector<int> ans;//przechowuje ścieżke/cykl eulera
    stack<int> S;
    S.push(1);//1 to wierzchołek startowy ścieżki
    while(!S.empty()){
        auto x = S.top();
        if(R[x]==0){
            ans.push_back(x);
            S.pop();
        }else{
            for(int i = 0; i<G[x].size(); i++){
                if(G[x][i].second){
                    R[x]--;
                    G[x][i].second = false;
                    S.push(G[x][i].first);
                }
            }
        }
    }
    
    return 0;
}
