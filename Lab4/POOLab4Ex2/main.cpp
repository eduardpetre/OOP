#include <bits/stdc++.h>
using namespace std;

class ConstructionProduct{
private:
    string nume, um;
    int cantitate;
    float pret;
public:
    ConstructionProduct(const string &nume, const string &um, int cantitate, float pret) : nume(nume), um(um),
                                                                                           cantitate(cantitate),
                                                                                           pret(pret) {}

    ConstructionProduct() {}

    friend ostream &operator<<(ostream &os, const ConstructionProduct &product) {
        os << " nume: " << product.nume
           << " um: " << product.um
           << " cantitate: " << product.cantitate
           << " pret: " << product.pret;
        return os;
    }

    friend istream &operator>>(istream &is, ConstructionProduct &product){
        cout<< "name: ";
        is>>product.nume;
        cout<< "unitate de masura: ";
        is>>product.um;
        cout<< "cantitate: ";
        is>>product.cantitate;
        cout<< "pret per "<< product.um <<": ";
        is>>product.pret;
        return is;
    }

    const string &getNume() const {
        return nume;
    }

    const string &getUm() const {
        return um;
    }

    int getCantitate() const {
        return cantitate;
    }

    float getPret() const {
        return pret;
    }

    void operator++(int) {
        cantitate++;
    }

    void operator+=(int crestere) {
        cantitate+=crestere;
    }
};

void chitanta(vector<ConstructionProduct> x) {
    cout << "Chitanta renovare:\n";
    for (int i = 0; i < x.size(); i++) {
        cout << i + 1 << ". " << x[i].getNume() << " (" << x[i].getUm() << ") x " << x[i].getCantitate() << endl;
        cout<< x[i].getCantitate() << " x " << x[i].getPret() << " = " << x[i].getCantitate() * x[i].getPret()
             << " RON";
        cout<<endl;
    }
}

int main() {
    vector<ConstructionProduct> p;
    p = {ConstructionProduct("Cuie", "buc", 10, 0.20),
         ConstructionProduct("Lavabila", "galeata", 3, 37.12),
         ConstructionProduct("Pal", "buc", 5, 12)};
    chitanta(p);
    p[2]++;
    chitanta(p);
    p[2]+=4;
    chitanta(p);
    return 0;
}
