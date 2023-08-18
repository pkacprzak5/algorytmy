#include <bits/stdc++.h>
using namespace std;
//akutalizacje i zapytania w czasie O(log n)
//drzewo przedział-przedział (+, min), można zmienić na (-, max), itd.

const int N = 1 << 10;
vector<int> D(2*N);//przechowuje obecne wartości
vector<int> R(2*N);//służy do opóxnionego aktualizowania wart

int p, k; //przedział o który pytamy/aktualizujemy

void push(int v, int l, int r, int dl){ //służy do przepychania informacji w głąb drzewa i aktualizowania go
    //nie używamy dl, ponieważ chcemy min na przedziale, dl używamy w przypadku zapytania o sumę na przedziale
    R[2*v]+= R[v];
    R[2*v+1]+= R[v];

    D[2*v]+=R[v];//*dl jeśli chcemy pytać o sumę na przedziale
    D[2*v+1]+=R[v];//*dl jeśli chcemy pytać o sumę na przedziale

    R[v] = 0;
}

void update(int v, int a, int b, int val){
    if(k<a || p>b){//wierzchołek nie zawiera szukanego przedziału
        return;
    }else if(p<=a && k>=b){//przedział zawiera przedział obsługiwany przez wierzchołek w całości
        D[v]+=val;//*(b-a+1), jeśli chcemy pytac o sumę na przedziale
        R[v]+=val;
    }else{
        int l = 2*v, r = 2*v+1, mid = (a+b)/2;
        push(v, l, r, (b-a+1));

        update(l, a, mid, val);
        update(r, mid+1, b, val);

        D[v]=min(D[l],D[r]);//D[v]=D[l]+D[r], jeśli chcemy pytać o sumę na przedziale
    }
}

int query(int v, int a, int b){
    if(k<a || p>b){//wierzchołek nie zawiera szukanego przedziału
        return INT_MAX;//szukamy minimum, więc jeśli wierzch nie zawiera przedziału to zwracamy INT_MAX
    }else if(p<=a && k>=b){//przedział zawiera przedział obsługiwany przez wierzchołek w całości
        return D[v];
    }else{
        int l = 2*v, r = 2*v+1, mid = (a+b)/2;
        push(v, l, r, (b-a+1)/2);

        return min(query(l, a, mid), query(r, mid+1, b));
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 5;
    while(t--){
        string s;
        cin >> s;
        if(s=="U"){
            cin >> p >> k;
            int val;
            cin >> val;
            update(1, 0, N-1, val);
        }else{
            cin >> p >> k;
            cout << query(1, 0, N-1) << "\n";
        }
    }

    return 0;
}