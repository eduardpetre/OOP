#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int cmp(int x, int y){
    return x<y;
}

int main() {
    int n,v1[1001],v2[1001];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v1[i];
    for(int i=0;i<n;i++)
        cin>>v2[i];
    sort(v1, v1+n, cmp);
    sort(v2, v2+n, cmp);
    int s=0;
    for(int i=0;i<n;i++)
        s+=v1[i]*v2[i];
    cout<<s;
    return 0;
}
// s= v[0]*v[n]+v[1]+v[n+1]+...+v[n-1]*v[2n-1]

//1 2 3 4
//5 6 7 8
// s = 5 + 12 + 21 + 32 = 70

//1 2 3 4
//8 7 6 5
//s = 8 + 14 + 18 + 20 = 60

// Pentru a obtine cea mai mica suma vom ordona unul dintre vectori crescator, iar celalalt descrescator.