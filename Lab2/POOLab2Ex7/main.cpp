#include <iostream>
#include <cstring>
using namespace std;

class IntervalOrar{
private:
    int orastart, minutstart, oraend, minutend;
public:
    void citire(){
        cin>>orastart>>minutstart>>oraend>>minutend;
    }

    IntervalOrar(){
        orastart=oraend=minutstart=minutend=0;
    }

    IntervalOrar(int _orastart, int _minutstart, int _oraend, int _minutend) {
        orastart=_orastart;
        minutstart=_minutstart;
        oraend=_oraend;
        minutend=_minutend;
    }

    void getInterval() {
        cout<<orastart<<":"<<minutstart<<"-"<<oraend<<":"<<minutend<<endl;
    }

    int getOrastart(){
        return orastart;
    }

    int getMinutstart(){
            return minutstart;
    }

    int getOraend(){
            return oraend;
    }

    int getMinutend(){
            return minutend;
    }

};

class Camin{
private:
    IntervalOrar interval[101];
    string name;
    int n, nrcamere, orar[24]={0};
public:
    void citire() {
        cin >> name >> nrcamere;
        for (int i = 0; i < n; i++)
            interval[i].citire();
    }
    Camin(){
        name="";
        nrcamere=0;
        n=0;
    };
    void setNrIntervale(int k){
        n = k;
    }
    int getNrIntervale(){
        return n;
    }
    void getCamin(){
        cout<<name<<" "<<nrcamere<<endl;
        for (int i=0; i<n; i++) {
            interval[i].getInterval();
        }
        cout<<endl;
    }


};

int main(){
    int n,k,mini=24,ore[24]={0};
    cin>>n;
    Camin camine[101];
    for (int i=0;i<n;i++) {
        cin>>k;
        camine[i].setNrIntervale(k);
        camine[i].citire();
    }

    for (int i=0;i<n;i++) {
        camine[i].getCamin();
    }

    return 0;
}
