#include <bits/stdc++.h>
#include "util/IoBase.h"
#include "util/functions.h"

using namespace std;

class Fruit: public IoBase{
protected:
    string fruct, soi;
public:
    Fruit(string f, string s): fruct(f), soi(s) {}
    Fruit(): fruct(""), soi("") {}

    ostream &write(ostream &os) const override {
        IoBase::write(os);
        os<<fruct<<' '<<soi;
        return os;
    }
    istream &read(istream &is) override

    {
        IoBase::read(is);
        is>>fruct>>soi;
        return is;
    }
};

class Juice: public Fruit{
public:
    Juice(string f, string s): Fruit(f, s) {}
    Juice(): Fruit(){}
    ostream &write(ostream &os) const override {
        IoBase::write(os);
        os<<fruct<<' '<<soi;
        return os;
    }
    virtual int quantity(){
        return 0;
    }
};

class simpleJuice: public Juice{
private:
    int cant;
    Fruit f;
public:
    simpleJuice(int c, Fruit f1): cant(c), f(f1) {}
    simpleJuice(): cant(0), f(){}
    ostream &write(ostream &os) const override {
        IoBase::write(os);
        os<<cant<<endl<<f<<endl;
        return os;
    }

    istream &read(istream &is) override
    {
        IoBase::read(is);
        is>>cant>>f;
        return is;
    }

    int quantity() override {
        return cant;
    }
};

class MixedJuice: public Juice{
private:
    int cant;
    vector<Fruit> f;
public:
    MixedJuice(int c, vector<Fruit> f1): cant(c), f(f1) {}
    MixedJuice(): cant(0), f(){}

    ostream &write(ostream &os) const override {
        IoBase::write(os);
        os<<cant<<' '<<endl;
        for(int i=0; i<f.size(); i++)
            os<<f[i]<<endl;
        return os;
    }

    istream &read(istream &is) override
    {
        IoBase::read(is);
        cout<<"Cantitate: ";
        is>>cant;
        int n;
        cout<<"cate fructe: ";
        cin>>n;
        Fruit fruct;
        for(int i=0; i<n; i++) {
            is >> fruct;
            f.push_back(fruct);
        }
        return is;
    }

    int quantity() override {
        return cant;
    }
};


class IcedJuice: public Juice{
private:
    int cantsuc, cantgheata;
    vector<Fruit> f;
public:
    IcedJuice(int c, vector<Fruit> f1, int cg): cantsuc(c), f(f1), cantgheata(cg){}
    IcedJuice(): cantsuc(0), f(), cantgheata(0){}

    ostream &write(ostream &os) const override {
        IoBase::write(os);
        os<<cantsuc<<' '<<endl;
        for(int i=0; i<f.size(); i++)
            os<<f[i]<<endl;
        os<<cantgheata;
        return os;
    }

    istream &read(istream &is) override
    {
        IoBase::read(is);
        cout<<"Cantitate: ";
        is>>cantsuc;
        int n;
        cout<<"cate fructe: ";
        cin>>n;
        Fruit fruct;
        for(int i=0; i<n; i++) {
            is >> fruct;
            f.push_back(fruct);
        }
        is>>cantgheata;
        return is;
    }

    int quantity() override {
        return cantsuc + cantgheata;
    }
};


int main(){
    vector<shared_ptr<Juice> > stock = {
            make_shared<simpleJuice> (
                    simpleJuice(550, Fruit("Apple", "Granny Smith"))
            ),
            make_shared<MixedJuice>(
                    MixedJuice(
                            560,
                            {
                                    Fruit("Apple", "Granny Smith"),
                                    Fruit("Banana", "Musa balbisiana"),
                            }
                    )
            ),
            make_shared<IcedJuice>(
                    IcedJuice(
                            560,
                            {
                                    Fruit("Apple", "Granny Smith"),
                                    Fruit("Banana", "Musa balbisiana"),
                            },
                            150
                    )
            ),
    };
    for (auto juice : stock) {
        cout << *juice << endl;
    }
    cout<<endl;
    for (auto juice : stock) {
        cout << juice->quantity() << ' ';
    }
}