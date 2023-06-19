#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct data{
    int zi, luna, an;
};

struct eveniment{
    data start, final;
}v[101];

void citire(eveniment x){
    cin>>x.start.zi>>x.start.luna>>x.start.an>>x.final.zi>>x.final.luna>>x.final.an;
    cout<<x.start.zi<<"/"<<x.start.luna<<"/"<<x.start.an<<" - "<<x.final.zi<<"/"<<x.final.luna<<"/"<<x.final.an<<endl;
}

void afisare(eveniment x){
    cout<<x.start.zi<<"/"<<x.start.luna<<"/"<<x.start.an<<" - "<<x.final.zi<<"/"<<x.final.luna<<"/"<<x.final.an<<endl;
}

int comp(data x, data y){
    if (x.an > y.an)
        return 0;
    else if (x.an < y.an)
        return 1;
    else if (x.luna > y.luna)
        return 0;
    else if (x.luna < y.luna)
        return 1;
    else if (x.zi > y.zi)
    return 0;
    else if (x.zi < y.zi)
        return 1;
    return 1;
}

bool cmp(data s, data f){
    if (comp(s,f)==1)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        citire(v[i]);
    sort(v,v+n,cmp);
    for (int i=0;i<n;i++)
        afisare(v[i]);
    return 0;
}

// 10-12 11-12 13-19 13-14 17-19 15-16
//10-12 13-14 15-16 17-19