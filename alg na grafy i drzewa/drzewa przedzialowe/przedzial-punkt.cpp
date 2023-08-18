#include <bits/stdc++.h>
using namespace std;
//zarówno aktualizacja jak i zapytanie w czasie O(log n)

const int N = 1<<10;//przykładowy rozmiar drzewa

vector<int> TREE(2*N);

int query(int v){//zapytanie o wartość w pkt
    v+=N;
    int val = TREE[v];
    while(v>0){
        val+=TREE[v];
        v/=2;
    }
    return val;
}

void update(int l, int r, int val){//aktualizacja wartości na przedziale [l, r] o val(może być +, -, itd.)
    l+=N;
    r+=N;
    TREE[r]+=val;
    if(l!=r) TREE[l]+=val;
    while(l/2!=r/2){
        if(l%2==0){
            TREE[l+1]+=val;
        }
        if(r%2==1){
            TREE[r-1]+=val;
        }
        r/=2;
        l/=2;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}