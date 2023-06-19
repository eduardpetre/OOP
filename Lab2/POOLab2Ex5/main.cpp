#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

class Client{
private:
    string id;
    int suma;
public:
    void citeste(){
        cin>>id;
        cin>>suma;
    }

    Client(){
        id="";
    }

    Client(string _id, int _suma) {
        id = _id;
        suma = _suma;
    }

    int getSuma(){
        return suma;
    }
};

class Banca{
private:
    Client c[101];
    int n;
public:
    void citeste(){
        cin>>n;
        for(int i=0;i<n;i++)
            c[i].citeste();
    }

    Banca(){
        n=0;
    }

    Banca(int _n) {
        n = _n;
    }

    int getSumaTotala(){
        int s=0;
        for(int i=0;i<n;i++)
            s+=c[i].getSuma();
        return s;
    }

    int get1000(){
        int nr=0;
        for(int i=0;i<n;i++)
            if(c[i].getSuma()>=1000) nr++;
        return nr;
    }

    int get100(){
        int nr=0;
        for(int i=0;i<n;i++)
            if(c[i].getSuma()>100) nr++;
        return nr*100/n;
    }
};


int main() {
    Banca b;
    b.citeste();
    cout<<b.getSumaTotala()<<" "<<b.get1000()<<" "<<b.get100();
    return 0;
}
