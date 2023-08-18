#include <bits/stdc++.h>
using namespace std;
//zarówno aktualizacja jak i zapytanie w czasie O(log n)

//implementacja drzewa typu punkt-przedział, gdzie aktualizujemy wartość w punkcie, a pytamy o przedział(np o max na przedziale)
const int N = 1<<10;//przykładowy rozmiar drzewa

vector<int> TREE(2*N);

int query(int l, int r){//zapytanie o max wartość na przedziale [l, r] (zamiast max może być min, suma, itd.)
    l+=N;
    r+=N;
    int val = max(TREE[l], TREE[r]);
    while(r/2!=l/2){
        if(l%2==0){
            val = max(val, TREE[l+1]);
        }
        if(r%2==1){
            val = max(val, TREE[r-1]);
        }
        l/=2;
        r/=2;
    }
    return val;
}

void update(int v, int val){//aktualizacja wartości w punkcie
    v+=N;
    TREE[v] = val;//zamiana wartości, może być +, -, itd.
    v/=2;
    while(v>0){
        TREE[v] = max(TREE[2*v], TREE[2*v+1]);
        v/=2;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}