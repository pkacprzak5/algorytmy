#include <bits/stdc++.h>
using namespace std;
//program wyznacza długość najdłuższego właściwego prefikso-sufiksu w słowie, który jest krótszy niż całe słowo

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> P(s.size()+1);//P[x] to najdłuższy właściwy prefikso-sufiks prefiksu o długości x
    int t = P[0] = -1;
    for(int i =0; i<s.size(); i++){
        while(t!=-1 && s[t] != s[i]){
            t = P[t];
        }
        P[i+1] = ++t;
    }
    cout << P[s.size()] << "\n";//wyświetla najdłuższy właściwy prefikso-sufiks słowa s
    return 0;
}