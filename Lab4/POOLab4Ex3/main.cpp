#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class InterestPoint{
private:
    int nr, x, y;
public:
    InterestPoint(int nr, int x, int y) : nr(nr), x(x), y(y) {}

    InterestPoint() {}

    friend ostream &operator<<(ostream &os, const InterestPoint &point) {
        os << "Numare de vizitatori: " << point.nr
        << "\nCoordonate:\nx: " << point.x
        << " y: " << point.y;
        return os;
    }

    friend istream &operator>>(istream &is, InterestPoint &point){
        cout<<"Numar de vizitatori: ";
        is>>point.nr;
        cout<<"\nCoordonate:\n"<<"x: ";
        is>>point.x;
        cout<<"y: ";
        is>>point.y;
        return is;
    }

    int getNr() const {
        return nr;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

class BikeTrail{
private:
    string nume, oras;
    int n;
    vector<InterestPoint> c;
public:
    BikeTrail() {}

    BikeTrail(const string &nume, const string &oras, int n, const vector<InterestPoint> &c) : nume(nume), oras(oras),
                                                                                               n(n), c(c) {}

    friend ostream &operator<<(ostream &os, const BikeTrail &trail) {
        os << "Nume: " << trail.nume
        << "\nOras: " << trail.oras
        << "\nNumar puncte de interes: " << trail.n
        << "\nPuncte de interes:\n";
        for(int i=0;i<trail.n;i++)
            os<<trail.c[i]<<endl;
        return os;
    }

    friend istream &operator>>(istream &is, BikeTrail &trail){
        cout<<"Nume: ";
        is>>trail.nume;
        cout<<"Oras: ";
        is>>trail.oras;
        cout<<"Numar de puncte de interes ale orasului: ";
        is>>trail.n;
        cout<<"Centrele de interes: ";
        for(int i=0;i<trail.n;i++)
            is>>trail.c[i];
    }

    const vector<InterestPoint> &getC() const {
        return c;
    }

};

double dist(InterestPoint a, InterestPoint b){
    return sqrt( (a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY()));
}


int main() {
    BikeTrail p;
    p = BikeTrail("Traseu#1", "Constanta", 5, {{102, 0, 0}, {404, 0, 0}, {3, 1, 1}, {22, 3, 2}, {1001, 5, 0}});
    cout<<p<<endl;

//    d)
    double dmax=0, d1, d2;
    InterestPoint x, y, z;
    vector<InterestPoint> t=p.getC();
    for(int i=0;i<t.size();i++)
        for(int j=0;j<t.size();j++){
            if(i!=j){
                d1 = dist(t[i],t[j]);
                for(int k=0;k<t.size();k++){
                    if(k!=i && k!=j) {
                        d2 = dist(t[j],t[k]);
                        if(d1+d2>dmax){
                            dmax=d1+d2;
                            x=t[i];
                            y=t[j];
                            z=t[k];
                            cout<<i<<j<<k<<endl;
                        }
                    }
                }
            }
        }

    cout<<x<<endl<<y<<endl<<z<<endl<< "Distanta maxima este: "<<dmax<<endl;
    int nr = x.getNr()+y.getNr()+z.getNr();
    cout<<"Numarul total de vizitatori: "<<nr<<endl;

    // e)
    InterestPoint A,B,C;
    for(int i=0; i<t.size(); ++i) {
        if (t[i].getNr() > A.getNr())
        {
            C = B;
            B = A;
            A = t[i];
        }
        else if(t[i].getNr() > B.getNr())
        {
            C = B;
            B = t[i];
        }
        else if(t[i].getNr() > C.getNr())
            C = t[i];
    }
    cout<<A<<endl<<B<<endl<<C<<endl;
    double AB, BC, CA;
    AB = dist(A, B);
    BC = dist(B, C);
    CA = dist(A, C);
    double D1, D2, D3, dfinal;
    D1 = AB + BC;
    D2 = BC + CA;
    D3 = AB + CA;
    dfinal = min(D1, D2) + min(D2, D3);
    cout<<AB<<" "<<BC<<" "<<CA<<endl<<dfinal;
    return 0;
}

/*
Traseu#1
Constanta
5
102  0 0
404  10 10
3    1 1
22   3 2
1001 5 0
*/

//. 0 1 2 3 4 5 6 7 8 9 10
//0 x         x
//1   x
//2       x
//3
//4
//5
//6
//7
//8
//9
//10                     x
