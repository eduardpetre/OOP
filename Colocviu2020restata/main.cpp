#include<bits/stdc++.h>

#include <utility>
using namespace std;

class IoBase{
public:
    virtual istream &read(istream &is) {
        return is;
    }
    virtual ostream &write(ostream &os) const {
        return os;
    }
    friend ostream &operator<<(ostream &os, const IoBase &base) {
        return base.write(os);
    }
    friend istream &operator>>(istream &is, IoBase &base) {
        return base.read(is);
    }
};

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    vec.clear();
    int n;
    cout << "n: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        T var;
        cin >> var;
        vec.push_back(var);
    }
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[ ";
    for(auto& var : vec) {
        os << var << " ; ";
    }
    os << ']';
    return os;
}

class comanda: public IoBase{
protected:
    static unsigned int staticId;
    unsigned id;
    string nume, adresa;
    int pret, timp;
    vector<string> produse;
    vector<int> cantitate;
public:
    comanda();

    comanda(unsigned int id, string nume, string adresa, int pret, int timp, vector<string> &produse, vector<int> &cantitate);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

    unsigned int getId();

    string getNume();

    int getPret();
};

unsigned int comanda::staticId=0;

comanda::comanda(): id(++staticId) {}

comanda::comanda(unsigned int id, string nume, string adresa, int pret, int timp, vector<string> &produse, vector<int> &cantitate) :
            id(id), nume(nume), adresa(adresa), pret(pret), timp(timp), produse(produse), cantitate(cantitate) {}

istream &comanda::read(istream &is) {
    is.get();
    cout<< "Nume client:";
    getline(is, nume);
    cout<< "Adresa:";
    getline(is, adresa);
//    cout<<"Timp livrare:";
//    is>>timp;
//    cout<<"Numar produse:";
//    int n;
//    is>>n;
//    string s;
//    int nr;
//    for(int i=0;i<n;i++){
//        cout<<"Produsul cu numarul "<<i+1<<":";
//        is>>s;
//        produse.push_back(s);
//        cout<<"Cantitate:";
//        is>>nr;
//        cantitate.push_back(nr);
//        cout<<endl;
//    }
//    cout<<"Pret final: ";
//    is>>pret;
    return is;
}

ostream &comanda::write(ostream &os) const {
    os<<"\n"<<id<<". "<<"Nume client: "<<nume;
    os<<"\nAdresa: "<<adresa;
//    os<<"\nTimp livrare: "<<timp<<" min";
//    os<<"Produse: ";
//    for(int i=0;i<produse.size();i++){
//        os<<produse[i]<<" -> x"<<cantitate[i];
//    }
//    os<<"\nPret final: "<<pret<<" lei";
    return os;
}

unsigned int comanda::getId() {
    return id;
}

string comanda::getNume() {
    return nume;
}

int comanda::getPret() {
    return pret;
}

class comandaMancare: public comanda{
protected:
    string numeLocal;
public:
    comandaMancare();

    comandaMancare(string numeLocal);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;
};

comandaMancare::comandaMancare(){}
comandaMancare::comandaMancare(string numeLocal): numeLocal(numeLocal) {}

istream &comandaMancare::read(istream &is) {
//    cout<< "Nume client:";
//    is.get();
//    getline(is, nume);
//    cout<< "Adresa:";
//    is.get();
//    getline(is, adresa);
    comanda::read(is);
    cout<<"Local:";
    getline(is, numeLocal);
    cout<<"Timp livrare:";
    is>>timp;
    cout<<"Numar produse:";
    int n;
    is>>n;
    string s;
    int nr;
    for(int i=0;i<n;i++){
        cout<<"Produsul cu numarul "<<i+1<<":";
        is.get();
        getline(is,s);
        produse.push_back(s);
        cout<<"Cantitate:";
        is>>nr;
        cantitate.push_back(nr);
        cout<<endl;
    }
//    cout<<"Pret final: ";
//    is>>pret;
    return is;
}

ostream &comandaMancare::write(ostream &os) const {
//    os<<"\nNume client: "<<nume;
//    os<<"\nAdresa: "<<adresa;
    comanda::write(os);
    os<<"\nLocal: "<<numeLocal;
    os<<"\nTimp livrare: "<<timp<<" min";
    os<<"\nProduse: ";
    for(int i=0;i<produse.size();i++){
        os<<produse[i]<<" -> x"<<cantitate[i]<<", ";
    }
//    os<<"\nPret final: "<<pret<<" lei";
    return os;
}

class comandaFastFood: public comandaMancare{
protected:
    int discount;
public:
    comandaFastFood();

    comandaFastFood(int discount);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

};

comandaFastFood::comandaFastFood() {}

comandaFastFood::comandaFastFood(int discount): discount(discount) {}

istream &comandaFastFood::read(istream &is) {
//    cout<< "Nume client:";
//    is.get();
//    getline(is, nume);
//    cout<< "Adresa:";
//    is.get();
//    getline(is, adresa);
//    cout<<"Local:";
//    is.get();
//    getline(is, numeLocal);
//    cout<<"Timp livrare:";
//    is>>timp;
//    cout<<"Numar produse:";
//    int n;
//    is>>n;
//    string s;
//    int nr;
//    for(int i=0;i<n;i++){
//        cout<<"Produsul cu numarul "<<i+1<<":";
//        is>>s;
//        produse.push_back(s);
//        cout<<"Cantitate:";
//        is>>nr;
//        cantitate.push_back(nr);
//        cout<<endl;
//    }
    comandaMancare::read(is);
    cout<<"Discount:";
    is>>discount;
    cout<<"Pret final: ";
    is>>pret;
    return is;
}

ostream &comandaFastFood::write(ostream &os) const {
//    os<<"\nNume client: "<<nume;
//    os<<"\nAdresa: "<<adresa;
//    os<<"\nLocal: "<<numeLocal;
//    os<<"\nTimp livrare: "<<timp<<" min";
//    os<<"Produse: ";
//    for(int i=0;i<produse.size();i++){
//        os<<produse[i]<<" -> x"<<cantitate[i];
//    }
    comandaMancare::write(os);
    os<<"\nDiscount: "<<discount<<" lei";
    os<<"\nPret final: "<<pret<<" lei";
    return os;
}


class comandaRestaurant: public comandaMancare{
protected:
    bool tacamuri;
public:
    comandaRestaurant();

    comandaRestaurant(bool tacamuri);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;
};

comandaRestaurant::comandaRestaurant() {}

comandaRestaurant::comandaRestaurant(bool tacamuri): tacamuri(tacamuri) {}

istream &comandaRestaurant::read(istream &is) {
    comandaMancare::read(is);
    cout<<"Tacamuri?\n1. Da\n2. Nu\n";
    int opt;
    is>>opt;
    while(opt!=1 && opt!=2){
        cout<<"Optiunea nu exista! Incercati din nou.";
        is>>opt;
    }
    if(opt==1)
        tacamuri= true;
    else if(opt==2)
        tacamuri= false;
    cout<<"Pret final: ";
    is>>pret;
    return is;
}

ostream &comandaRestaurant::write(ostream &os) const {
    comandaMancare::write(os);
    os<<"\nTacamuri: ";
    if(tacamuri)
        os<<"Da";
    else
        os<<"Nu";
    os<<"\nPret final: "<<pret<<" lei";
    return os;
}

class comandaMedicamente: public comanda{
protected:
    vector<int> antibiotic;
public:
    comandaMedicamente();

    comandaMedicamente(vector<int>antibiotic);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

    vector<int> &getAntibiotic();
};

comandaMedicamente::comandaMedicamente() {}

comandaMedicamente::comandaMedicamente(vector<int> antibiotic): antibiotic(antibiotic) {}

istream &comandaMedicamente::read(istream &is) {
    comanda::read(is);
    cout<<"Timp livrare:";
    is>>timp;
    cout<<"Numar produse:";
    int n;
    is>>n;
    string s;
    int nr, opt;
    for(int i=0;i<n;i++){
        cout<<"Produsul cu numarul "<<i+1<<":";
        is.get();
        getline(is,s);
        produse.push_back(s);
        cout<<"Antibiotic:\n1. Da\n2. Nu\n";
        is>>opt;
        while(opt!=1 && opt!=2){
            cout<<"Optiunea nu exista. Incercati din nou.";
            is>>opt;
        }
        if(opt==1)
            antibiotic.push_back(1);
        else if (opt==2)
            antibiotic.push_back(0);
        cout<<"Cantitate:";
        is>>nr;
        cantitate.push_back(nr);
        cout<<endl;
    }
    cout<<"Pret final: ";
    is>>pret;
    return is;
}

ostream &comandaMedicamente::write(ostream &os) const {
    comanda::write(os);
    os<<"\nTimp livrare: "<<timp<<" min";
    os<<"\nProduse: ";
    for(int i=0;i<produse.size();i++){
        os<<produse[i]<<" ("<<antibiotic[i]<<")"<<" -> x"<<cantitate[i]<<", ";
    }
    os<<"\nPret final: "<<pret<<" lei";
    return os;
}

vector<int> &comandaMedicamente::getAntibiotic(){
    return antibiotic;
}


class comandaTigari: public comanda{
protected:
        vector<int> clasic;
public:
    comandaTigari();

    comandaTigari(vector<int> clasic);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;
};

comandaTigari::comandaTigari() {}

comandaTigari::comandaTigari(vector<int> clasic): clasic(clasic) {}

istream &comandaTigari::read(istream &is) {
    comanda::read(is);
    cout<<"Timp livrare:";
    is>>timp;
    cout<<"Numar produse:";
    int n;
    is>>n;
    string s;
    int nr, opt;
    for(int i=0;i<n;i++){
        cout<<"Produsul cu numarul "<<i+1<<":";
        is.get();
        getline(is,s);
        produse.push_back(s);
        cout<<"Tigari clasice:\n1. Da\n2. Nu\n";
        is>>opt;
        while(opt!=1 && opt!=2){
            cout<<"Optiunea nu exista. Incercati din nou.";
            is>>opt;
        }
        if(opt==1)
            clasic.push_back(1);
        else if (opt==2)
            clasic.push_back(0);
        cout<<"Cantitate:";
        is>>nr;
        cantitate.push_back(nr);
        cout<<endl;
    }
    cout<<"Pret final: ";
    is>>pret;
    return is;
}

ostream &comandaTigari::write(ostream &os) const {
    comanda::write(os);
    os<<"\nTimp livrare: "<<timp<<" min";
    os<<"\nProduse: ";
    for(int i=0;i<produse.size();i++){
        os<<produse[i]<<" ("<<clasic[i]<<")"<<" -> x"<<cantitate[i]<<", ";
    }
    os<<"\nPret final: "<<pret<<" lei";
    return os;
}



shared_ptr<comanda> citirec(){
    cout<<"\n1. Comanda Fast-Food.\n2. Comanda restaurant.\n3. Comanda medicamente.\n4. Comanda tigari.\n";
    cout<<"Alege tipul de comanda: ";
    int optiune;
    cin>>optiune;
    shared_ptr<comanda> c;
    if (optiune==1)
        c= make_shared<comandaFastFood>();
    else if (optiune==2)
        c= make_shared<comandaRestaurant>();
    else if (optiune==3)
        c= make_shared<comandaMedicamente>();
    else if (optiune==4)
        c= make_shared<comandaTigari>();
    cin>>*c;
    return c;
}

class SimpleMenu {
private:
    vector<shared_ptr<comanda>> comenzi;
public:
    void listOptions() {
        cout << "1. Citire comenzi." << '\n';
        cout << "2. Adaugare comanda." << '\n';
        cout << "3. Afiseaza comenzile." << '\n';
        cout << "4. Stergere comanda dupa ID." << '\n';
        cout << "5. Cautare comanda dupa ID." << '\n';
        cout << "6. Cautare comanda dupa numele clientului." << "\n";
        cout << "7. Ordonare comenzi dupa pret in mod descrescator." << '\n';
        cout << "8. Gestionare comenzi." << '\n';
        cout << "9. Iesire." << '\n';
    }

    int chooseOption(int first, int last) {
        int option = -1;
        while(option < first || option > last){
            cout << '\n';
            cout << "Pentru a rula comanda, alegeti un numar intre "
                 << first << " si " << last << '\n';
            listOptions();
            cout << "Alegere: ";
            cin >> option;
        }
        return option;
    }


    void option1(){
        cout<<"Nr comenzi:";
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            comenzi.push_back(citirec());
    }

    void option2(){
        comenzi.push_back(citirec());
    }

    void option3(){
        for(int i=0;i<comenzi.size();i++)
            cout<<*comenzi[i]<<endl;
    }

    void option4(){
        cout<<"Id-ul comenzii: ";
        int nr;
        cin>>nr;
        while(nr<0 && nr>comenzi.size()-1){
            cout<<"Id-ul introdus nu exista. Incercati din nou.\n";
            cin>>nr;
        }
        for(auto x: comenzi)
            if(x->getId()==nr)
                comenzi.erase(comenzi.begin()+nr-1);
        cout<<"Comanda cu id-ul "<<nr<<" a fost sters cu succes!\n";
    }

    void option5(){
        cout<<"Id-ul comenzii: ";
        int nr;
        cin>>nr;
        while(nr<0 && nr>comenzi.size()-1){
            cout<<"Id-ul introdus nu exista. Incercati din nou.\n";
            cin>>nr;
        }
        for(auto x: comenzi)
            if(x->getId()==nr)
                cout<<*comenzi[nr-1]<<endl;
    }

    void option6(){
        cout<<"Numele clientului: ";
        string s;
        getline(cin,s);
        for(auto x:comenzi){
            if(x->getNume()==s)
                cout<<*x<<endl;
        }
    }

    void option7(){
        for(int i=0;i<comenzi.size()-1;i++)
            for(int j=i+1;j<comenzi.size();j++)
                if(comenzi[i]->getPret()<comenzi[j]->getPret())
                    swap(comenzi[i],comenzi[j]);
    for(auto x: comenzi)
        cout<<*x<<endl;
    }

    void option8(){
        int FF=0,R=0,M=0,T=0,A=0;
        for (auto x: comenzi){
            auto* ff=dynamic_cast<comandaFastFood *>(x.get());
            auto* r=dynamic_cast<comandaRestaurant *>(x.get());
            auto* m=dynamic_cast<comandaMedicamente *>(x.get());
            auto* t=dynamic_cast<comandaTigari *>(x.get());
            if (ff!=nullptr)
                FF++;
            else if (r!=nullptr)
                R++;
            else if (m!=nullptr) {
                M++;
                for(auto k:m->getAntibiotic())
                    if(k==1) {
                        A++;
                        break;
                    }
            }
            else if (t!=nullptr)
                T++;
        }
        cout<<"In acest moment sunt "<<FF<<" comenzi de mancare de tip Fast-Food, "<<R<<" comenzi de mancare de tip restaurant, "<<M<<" comenzi de medicamente, dintre care "<<A<<" antibiotice, si "<<T<<" comenzi de tigari.";
    }

    void mainLoop() {
        while(true){
            int option = chooseOption(1, 9);
            if (option == 1) {
                option1();
            } else if (option == 2) {
                option2();
            } else if (option == 3) {
                option3();
            } else if (option == 4) {
                option4();
            } else if (option == 5) {
                option5();
            } else if (option == 6) {
                option6();
            } else if (option == 7) {
                option7();
            } else if (option == 8) {
                option8();
            } else if (option == 9) {
                break;
            }

        }
        cout << '\n'
             << "---------------------------------"
             << '\n'
             << "Programul s-a incheiat cu success";
    }
};


int main(){
    SimpleMenu menu;
    menu.mainLoop();
    return 0;
}