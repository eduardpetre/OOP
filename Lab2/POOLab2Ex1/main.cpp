#include<iostream>
using namespace std;

class Bilet{
private:
    string nume;
    bool clasa;
public:
    void citire(){
        getline(cin>>ws, nume);
        cin>>clasa;
        }

    Bilet(){
        nume="";
    }

    Bilet(string _nume, bool _clasa){
        nume=_nume;
        clasa=_clasa;
    }

    bool getClasa(){
        return clasa;
    }
};

void statisticaZboruri(int n, Bilet bilete[]){
    int nr=0;
    bool tipclasa;
    for(int i=0;i<n;i++){
        tipclasa=bilete[i].getClasa();
        if(tipclasa==true) nr++;
    }
    cout<<nr;
}

int main(){
    int n;
    cin>>n;
    Bilet bilete[101];
    for (int i=0;i<n;i++)
        bilete[i].citire();
    statisticaZboruri(n, bilete);
    return 0;
}