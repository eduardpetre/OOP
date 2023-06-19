#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

class Tablou{
private:
    string mesaj;
    int inaltime, latime, pret, nr;
public:
    void citire(){
        getline(cin>>ws, mesaj);
        cin>>inaltime>>latime>>pret;
    }

    Tablou(){
        mesaj="";
    }

    Tablou(string _mesaj, int _inaltime, int _latime, int _pret) {
        mesaj = _mesaj;
        inaltime = _inaltime;
        latime = _latime;
        pret = _pret;
    }

    int getnrcuvMesaj(){
        nr=1;
        for (int i=0;i<mesaj.length();i++)
            if (mesaj[i]==' ') nr++;
        return nr;
    }

    void getMesaj(){
        cout<<mesaj<<endl;
    }

    void getDimensiuni(){
        cout<<inaltime<<" "<<latime<<" "<<pret<<endl;
    }
};
int cuvintemax(string s){
    int nr=1;
    for(int i=0;i<s.length();i++)
        if(s[i]==' ')nr++;
    return nr;
}
int main(){
    int n,maxi=0,p=0;
    cin>>n;
    Tablou tablouri[101];
    for (int i=0;i<n;i++) {
        tablouri[i].citire();
        if (tablouri[i].getnrcuvMesaj()>maxi) {
            maxi = tablouri[i].getnrcuvMesaj() ;
            p = i;
        }
    }
    tablouri[p].getMesaj();
    tablouri[p].getDimensiuni();
    cout<<maxi;
    return 0;
}