#include <iostream>
#include <algorithm>
using namespace std;

struct fractie{
    int a,b;
};

//functie care ne spune cand doua elemente sunt in ordine gresita (da true atunci)
bool cmp(fractie f1, fractie f2) {
    if (f1.a*f2.b<f1.b*f2.a)
        return true;
    else
        return false;
}
int main() {
    int n, v[100];
    cin >> n;
    for (int i=0; i<n; i++)
        cin>>v[i];
    fractie w[100];
    int k=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (v[i]>v[j]) {
                w[k].a = v[i];
                w[k].b = v[j];
                k++;
            }
    sort(w, w + k, cmp);

    for (int i=0;i<k-1;i++)
        for (int j=i+1;j<k;j++)
            if (w[i].a*w[j].b!=w[i].b*w[j].a) {
                cout << w[i].a << "/" << w[i].b << " ";
                break;
            }
            else
                break;
    cout << w[k-1].a << "/" << w[k-1].b << " ";
    return 0;
}
