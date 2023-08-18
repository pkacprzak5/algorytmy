#include <bits/stdc++.h>
using namespace std;
const long long MOD = 2000000033;
const long long X = 1696969;

vector<long long> P;

void pot(int n){//wylicza kolejne potęgi X%MOD
    P.push_back(1);
    for(int i =0; i<n; i++){
        P.push_back((P.back()*X)%MOD);
    }
}

vector<long long> hsh(string s){//zwraca vector z hashami prefiksów słowa s
    vector<long long> W(1);
    W[0] = 0;
    for(auto &c : s){
        W.push_back((W.back()*X+c)%MOD);
    }
    return W;
}

long long phsh(int p, int q, vector<long long> &W){//zwraca hash podsłowa w przedziale [p, q)
    return (W[q]+(MOD-P[q-p])*W[p])%MOD;//zwraca hash podsłowa, może to być wykorzystane do wyszukiwania wzorca w tekście, w złożoności O(n)
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    pot(s.size()+1);
    auto W = hsh(s);//vector trzymający hashe prefiksów słowa s
    if(phsh(0, 3, W)==phsh(3, 6, W)) cout << "TAK\n";
    else cout << "NIE\n";
    return 0;
}