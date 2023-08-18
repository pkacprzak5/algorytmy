#include <bits/stdc++.h>
using namespace std;
//alg do wyznaczenia LCA dwóch wierzch w drzewie, preprocesing w czasie O(n log n),
//odpowiadanie na zapytania o LCA w czasie stałym

void dfs(int v, int p, vector<vector<int>> &G, vector<pair<int, int>> &R, vector<int> &K){
//dfs wykorzystywany aby przejść drzewo od korzenia i zapisywać "głębokość" każdego wierzchołka
    for(auto g : G[v]){
        R.push_back({p, g});
        dfs(g, p+1, G, R, K);
    }
    R.push_back({p, v});
    K[v]=R.size()-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, z;//n to liczba wierzch, a z to liczba zapytań o LCA
    cin >> n >> k >> z;
    vector<vector<int>> G(n+1);
    for(int i = 0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<vector<pair<int, int>>> R(1);//tu przechowujemy poziomy kolejnych wierzchołków
    vector<int> K(n+1);//zapisujemy tu ostatnie wystąpnienie danego wierzchołka
    dfs(k, 0, G, R[0], K);
    int N = R[0].size();
    for(int i = 1; (1<<i)<N; i++){
        R.emplace_back(N-(1<<i)+1);
        for(int j = 0; j<N-(1<<i)+1; j++){
            R[i][j] = min(R[i-1][j], R[i-1][j+(1<<(i-1))]);
        }
    }
    while(z--){
        int a, b;
        cin >> a >> b;//wierzchołki między którymi należy policzyć LCA
        a = K[a];
        b = K[b];
        if(a>b) swap(a, b);
        int i = __lg(b-a+1);
        cout << min(R[i][a], R[i][b-(1<<i)+1]).second << "\n";
    }
    return 0;
}