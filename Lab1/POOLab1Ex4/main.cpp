#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int s=b/2, i=3;
    cout<<a<<"/"<<b<<" = 1/2 ";
    while(s!=a){
        s+=b/i;
        cout<<"+ 1/"<<i<<" ";
        i++;
    }
    return 0;
}
