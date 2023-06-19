#include<bits/stdc++.h>
using namespace std;

class IoBase{
public:
    virtual istream &read(istream &is) { // nu este nevoie de obiectul citit, pt ca avem this
        return is; // vom vedea ca in interfete deseori nu avem functionalitati
    }

    // metoda scriere
    virtual ostream &write(ostream &os) const { // nu este nevoie de obiectul citit, pt ca avem this
        return os; // vom vedea ca in interfete deseori nu avem functionalitati
    }

    // ...
    friend ostream &operator<<(ostream &os, const IoBase &base) {
        return base.write(os);
    }

    friend istream &operator>>(istream &is, IoBase &base) {
        return base.read(is);
    }
};

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    // empty vector:
    vec.clear();
    // read length:
    int n;
    cout << "n: ";
    cin >> n;
    // read items
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

struct dataCalendaristica{
    int zi, luna, an;
};

struct ora{
    int ora, minut;
};

class bilet: public IoBase{
protected:
    string statieplecare, statiesosire;
    dataCalendaristica dataPlecarii;
    ora oraPlecarii;
    int codTren, durataCalatoriei, distanta;
    double pret;
    int clasa;
    static unsigned int staticId;
    unsigned id;
    string serie;
public:
    bilet();

    bilet(const string &statieplecare, const string &statiesosire, const dataCalendaristica &dataPlecarii,
          const ora &oraPlecarii, int codTren, int durataCalatoriei, int distanta, int pret, int clasa,
          unsigned int id);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

    int getCodTren() const;

    int getDistanta() const;

    const string &getSerie() const;
};

unsigned int bilet::staticId=0;

bilet::bilet(): id(++staticId) {}

bilet::bilet(const string &statieplecare, const string &statiesosire, const dataCalendaristica &dataPlecarii,
             const ora &oraPlecarii, int codTren, int durataCalatoriei, int distanta, int pret, int clasa,
             unsigned int id) : statieplecare(statieplecare), statiesosire(statiesosire), dataPlecarii(dataPlecarii),
                                oraPlecarii(oraPlecarii), codTren(codTren), durataCalatoriei(durataCalatoriei),
                                distanta(distanta), pret(pret), clasa(clasa), id(id) {}

istream &bilet::read(istream &is) {
    cout<<"Codul trenului: ";
    is>>codTren;
    cout<<"Statia plecarii si cea a sosirii:\n";
    is>>statieplecare;
    cout<<"-\n";
    is>>statiesosire;
    cout<<"Data plecarii: ";
    is>>dataPlecarii.zi>>dataPlecarii.luna>>dataPlecarii.an;
    cout<<"Ora Plecarii: ";
    is>>oraPlecarii.ora>>oraPlecarii.minut;
    cout<<"Durata calatoriei: ";
    is>>durataCalatoriei;
    cout<<"Distanta: ";
    is>>distanta;
    cout<<"Bilet la clasa I sau clasa II?\n1. Clasa I\n2. Clasa II\nAlegeti 1 sau 2: ";
    is>>clasa;
    while(clasa!=1 && clasa!=2) {
        cout << "Clasa introdusa nu exista! Incercati din nou.";
        is >> clasa;
    }
    return is;
}

ostream &bilet::write(ostream &os) const {
    os<<"\nCodul trenului: "<<codTren;
    os<<"\nStatia plecarii si cea a sosirii: "<<statieplecare<<" - "<<statiesosire;
    os<<"\nData si ora plecarii: "<<dataPlecarii.zi<<"/"<<dataPlecarii.luna<<"/"<<dataPlecarii.an<<" "<<oraPlecarii.ora<<":"<<oraPlecarii.minut;
    os<<"\nDurata calatoriei: "<<durataCalatoriei<<" min";
    os<<"\nDistanta: "<<distanta<<" km";
    os<<"\nClasa: "<<clasa;
    return os;
}

int bilet::getCodTren() const {
    return codTren;
}

int bilet::getDistanta() const {
    return distanta;
}

const string &bilet::getSerie() const {
    return serie;
}


class biletIR: public bilet{
protected:
    int nrloc;
public:
    biletIR() {}

    biletIR(const string &statieplecare, const string &statiesosire, const dataCalendaristica &dataPlecarii,
            const ora &oraPlecarii, int codTren, int durataCalatoriei, int distanta, int pret, int clasa,
            unsigned int id, int nrloc) : bilet(statieplecare, statiesosire, dataPlecarii, oraPlecarii, codTren,
                                                durataCalatoriei, distanta, pret, clasa, id), nrloc(nrloc) {}

    istream &read(istream &is) override {
        bilet::read(is);
        cout<<"Numarul locului: ";
        is>>nrloc;
        pret=0.7;
        pret*=distanta;
        if(clasa==1)
            pret+=pret/5;
        cout<<"Pretul biletului este: ";
        cout<<pret<<" lei"<<endl;
        serie="IR" + to_string(clasa) + "-"+ to_string(id);
        cout<<"Seria biletului este: "<<serie<<endl;
        return is;
    }

    ostream &write(ostream &os) const override {
        bilet::write(os);
        os<<"\nNumarul locului: "<<nrloc;
        os<<"\nPret: "<<pret<<" lei";
        cout<<"\nSeria: "<<serie;
        return os;
    }

};

class biletR: public bilet{
public:
    biletR() {}

    biletR(const string &statieplecare, const string &statiesosire, const dataCalendaristica &dataPlecarii,
           const ora &oraPlecarii, int codTren, int durataCalatoriei, int distanta, int pret, int clasa,
           unsigned int id) : bilet(statieplecare, statiesosire, dataPlecarii, oraPlecarii, codTren, durataCalatoriei,
                                    distanta, pret, clasa, id) {}

    istream &read(istream &is) override {
        pret=0.39;
        pret*=distanta;
        if(clasa==1)
            pret+=pret/5;
        bilet::read(is);
        cout<<"Pretul biletului este: ";
        cout<<pret<<" lei"<<endl;
        serie="R" + to_string(clasa) + "-"+ to_string(id);
        cout<<"Seria biletului este: "<<serie<<endl;
        return is;
    }

    ostream &write(ostream &os) const override {
        bilet::write(os);
        os<<"\nPret: "<<pret<<" lei";
        cout<<"\nSeria: "<<serie;
        return os;
    }
};

class BaseMenu{
public:
    virtual void listOptions() {}
    virtual int chooseOption(int first, int last) {return 0;}
    virtual void mainLoop() {}
};

shared_ptr<bilet> citirebilet(){
    cout<<"Alegeti tipul trenului:\n1. Regio.\n2. Inter-Regio.\n";
    int optiune;
    cin>>optiune;
    shared_ptr<bilet> b;
    if (optiune==1)
        b= make_shared<biletR>();
    else if (optiune==2)
        b= make_shared<biletIR>();
    cin>>*b;
    return b;
}

class SimpleMenu: public BaseMenu{
private:
    vector<shared_ptr<bilet>> bilete;
public:
    void listOptions() override{
        cout << "1. Eliberarea unui nou bilet." << '\n';
        cout << "2. Listarea biletelor eliberate pentru un anumit tren, in funcite de codul acestuia." << '\n';
        cout << "3. Listarea biletelor elibarate pentru calatorii pe o distanta mai mare decat o valoare data." << '\n';
        cout << "4. Anularea unui bilet folosind seria biletului." << '\n';
        cout << "5. Listarea tuturor biletelor eliberate." << '\n';
        cout << "6. Iesire." << "\n";
    }

    int chooseOption(int first, int last) override {
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
        bilete.push_back(citirebilet());
    }

    void option2(){
        int cod;
        cout<<"Codul trenului: ";
        cin>>cod;
        for(int i=0;i<bilete.size();i++)
            if(bilete[i]->getCodTren()==cod)
                cout<<*bilete[i]<<endl<<endl;
    }

    void option3(){
        int distmin;
        cout<<"Distanta minima: ";
        cin>>distmin;
        for(int i=0;i<bilete.size();i++)
            if(bilete[i]->getDistanta()>distmin)
                cout<<*bilete[i]<<endl<<endl;
    }

    void option4(){
        string s;
        cout<<"\nSeria biletului ce urmeaza sa fie anulat: ";
        cin>>s;
        for(int i=0;i<bilete.size();i++)
            if(bilete[i]->getSerie()==s)
                bilete.erase(bilete.begin()+i);
        cout<<"\nBiletul a fost sters.";
    }

    void option5(){
        for(int i=0;i<bilete.size();i++)
            cout<<*bilete[i]<<endl;
    }

    void mainLoop() override {
        while(true){
            int option = chooseOption(0, 7);
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
            } else if (option==6) {
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