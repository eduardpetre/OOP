#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

class Data{
private:
    int zi, luna, an;
public:
    void citire(){
        cin>>zi>>luna>>an;
    }

    Data(){
        zi=0;
        luna=0;
        an=0;
    }

    Data(int _zi, int _luna, int _an) {
        zi = _zi;
        luna = _luna;
        an = _an;
    }

    int getZi(){
        return zi;
    }

    int getLuna(){
        return luna;
    }

    void afisare(){
        cout<<zi<<"/"<<luna<<"/"<<an;
    }

};

class Festivale{
private:
    Data start,end;
    string name;
public:
    void citire(){
        cin>>name;
        start.citire();
        end.citire();
    }

    Festivale(){
        start.Data();
        end.Data();
    }

    Festivale(Data _start, Data _end) {
        start = _start;
        end = _end;
    }

    int getZiend(){
        return end.getZi();
    }

    int getLunaend(){
        return end.getLuna();
    }

    int getZistart(){
        return start.getZi();
    }

    int getLunastart(){
        return start.getLuna();
    }

    void afisare(){
        cout<<name<<endl;
        start.afisare();
        cout<<"-";
        end.afisare();
        cout<<endl;
    }

};

int CompData(int luna1, int zi1, int luna2, int zi2){
    if(luna1>luna2) return -1;
    if(luna1<luna2) return 1;
    if(luna1==luna2)
        if (zi1>zi2) return -1;
            else if(zi1<zi2) return 1;
    return 0;
}

int main(){
    Festivale f[101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        f[i].citire();
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(CompData(f[i].getLunaend(),f[i].getZiend(),f[j].getLunaend(),f[j].getZiend())==-1)
                swap(f[i],f[j]);
    Festivale ult=f[0];
    ult.afisare();
    for (int i=1;i<n;i++)
        if(CompData(ult.getLunaend(),ult.getZiend(),f[i].getLunastart(),f[i].getZistart())==1) {
            f[i].afisare();
            ult=f[i];
        }
    return 0;
}