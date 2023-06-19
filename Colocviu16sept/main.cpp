#include<bits/stdc++.h>
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

class produse: public IoBase{
private:
    static int staticId;
protected:
    const int id = ++staticId;
    int pret,cantitate;
public:
    produse();

    produse(int pret, int cantitate);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

    unsigned int getId();

    int getPret();

    int getCantitate();
};

int produse::staticId=0;

produse::produse(){}

produse::produse(int pret, int cantitate): pret(pret), cantitate(cantitate) {}

istream &produse::read(istream &is) {
    cout<< "Pretul produsului:";
    is>>pret;
    cout<<"Cantitate:";
    is>>cantitate;
    return is;
}

ostream &produse::write(ostream &os) const {
    os<<"\nPret: "<<pret;
    os<<"\nCantitate: "<<cantitate;
    return os;
}

unsigned int produse::getId() {
    return id;
}

int produse::getPret() {
    return pret;
}

int produse::getCantitate() {
    return cantitate;
}


class carte: public produse{
protected:
    string  titlul;
    vector<string> autori;
    string editura;
public:
    carte();

    carte(string titlul, vector<string> autori, string editura);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

    string &getTitlul();
};

carte::carte(){}

carte::carte(string titlul, vector<string> autori, string editura): titlul(titlul), autori(autori), editura(editura) {}

istream &carte::read(istream &is) {
    is.get();
    cout<<"Titlul cartii:";
    getline(is, titlul);
    cout<<"Numarul de autori:";
    int n;
    is>>n;
    string s;
    is.get();
    for(int i=0;i<n;i++){
        cout<<"Autorul "<<i+1<<" :";
        getline(is, s);
        autori.push_back(s);
    }
    cout<<"Editura:";
    getline(is, editura);
    produse::read(is);
    return is;
}

ostream &carte::write(ostream &os) const {
    os<<"Titlul cartii: "<<titlul;
    os<<"\nAutori: ";
    os<<autori;
    os<<"\nEditura: "<<editura;
    produse::write(os);
    return os;
}

string &carte::getTitlul() {
    return titlul;
}


class dvd: virtual public produse{
protected:
    int minute;
public:
    dvd();

    dvd(int minute);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;
};

dvd::dvd(){}

dvd::dvd(int minute): minute(minute){}

istream &dvd::read(istream &is) {
    cout<<"Numar minute:";
    is>>minute;
    produse::read(is);
    return is;
}

ostream &dvd::write(ostream &os) const {
    os<<"\nNumar minute: "<<minute;
    produse::write(os);
    return os;
}


class dvdMuzica: public dvd{
protected:
    string album;
    vector<string> interpreti;
public:
    dvdMuzica();

    dvdMuzica(string album, vector<string> interpreti);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

};

dvdMuzica::dvdMuzica() {}

dvdMuzica::dvdMuzica(string album, vector<string> interpreti): album(album), interpreti(interpreti) {}

istream &dvdMuzica::read(istream &is) {
    is.get();
    cout<<"Album:";
    getline(is, album);
    cout<<"Numar interpreti:";
    int n;
    is>>n;
    string s;
    is.get();
    for(int i=0;i<n;i++){
        cout<<"Interpret "<<i+1<<":";
        getline(is, s);
        interpreti.push_back(s);
    }
    dvd::read(is);
    return is;
}

ostream &dvdMuzica::write(ostream &os) const {
    os<<"Album: "<<album;
    os<<"\nInterpreti: ";
    for(int i=0;i<interpreti.size();i++)
        os<<interpreti[i]<<"; ";
    dvd::write(os);
    return os;
}


class dvdFilm: public dvd{
protected:
    string nume, gen;
public:
    dvdFilm();

    dvdFilm(string nume, string gen);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

};

dvdFilm::dvdFilm() {}

dvdFilm::dvdFilm(string nume, string gen): nume(nume), gen(gen) {}

istream &dvdFilm::read(istream &is) {
    is.get();
    cout<<"Nume:";
    getline(is, nume);
//    is.get();
    cout<<"Gen:";
    getline(is, gen);
    dvd::read(is);
    return is;
}

ostream &dvdFilm::write(ostream &os) const {
    os<<"Nume: "<<nume;
    os<<"\nGen: "<<gen;
    dvd::write(os);
    return os;
}


class obiecteColectie: virtual public produse{
protected:
    string denumire;
public:
    obiecteColectie();

    obiecteColectie(string denumire);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

};

obiecteColectie::obiecteColectie() {}

obiecteColectie::obiecteColectie(string denumire): denumire(denumire) {}

istream &obiecteColectie::read(istream &is) {
    is.get();
    cout<<"Denumire:";
    getline(is, denumire);
    produse::read(is);
    return is;
}

ostream &obiecteColectie::write(ostream &os) const {
    os<<"Denumire: "<<denumire;
    produse::write(os);
    return os;
}


class figurine: public obiecteColectie{
protected:
    string categorie, brand, material;
public:
    figurine();

    figurine(string categorie, string brand, string material);

    figurine(const string &denumire, const string &categorie, const string &brand, const string &material);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;
};

figurine::figurine() {}

figurine::figurine(string categorie, string brand, string material): categorie(categorie), brand(brand), material(material) {}

figurine::figurine(const string &denumire, const string &categorie, const string &brand, const string &material)
        : obiecteColectie(denumire), categorie(categorie), brand(brand), material(material) {}


istream &figurine::read(istream &is) {
    obiecteColectie::read(is);
    is.get();
    cout<<"Categorie:";
    getline(is, categorie);
//    is.get();
    cout<<"Brand:";
    getline(is, brand);
//    is.get();
    cout<<"Material:";
    getline(is, material);
    return is;
}

ostream &figurine::write(ostream &os) const {
    obiecteColectie::write(os);
    os<<"\nCategorie: "<<categorie;
    os<<"\nBrand: "<<brand;
    os<<"\nMaterial: "<<material;
    return os;
}


class postere: public obiecteColectie{
protected:
    string format;
public:
    postere();

    postere(string format);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;
};

postere::postere() {}

postere::postere(string format): format(format) {}

istream &postere::read(istream &is) {
    obiecteColectie::read(is);
    is.get();
    cout<<"Format:";
    getline(is, format);
    return is;
}

ostream &postere::write(ostream &os) const {
    obiecteColectie::write(os);
    os<<"\nFormat: "<<format;
    return os;
}
shared_ptr<produse> citireP(){
    cout<<"\n1. Carte.\n2. DVD muzica.\n3. DVD film.\n4. Figurina.\n5. Poster\n";
    cout<<"Alege tipul de produs: ";
    int optiune;
    cin>>optiune;
    shared_ptr<produse> p;
    if (optiune==1)
        p= make_shared<carte>();
    else if (optiune==2)
        p= make_shared<dvdMuzica>();
    else if (optiune==3)
        p= make_shared<dvdFilm>();
    else if (optiune==4)
        p= make_shared<figurine>();
    else if (optiune==5)
        p= make_shared<postere>();
    cin>>*p;
    return p;
}

class SimpleMenu {
private:
    vector<shared_ptr<produse>> p ;
public:
    void listOptions() {
        cout << "1. Citire a n produse. " << '\n';
        cout << "2. Afisarea produselor." << '\n';
        cout << "3. Editarea unui produs." << '\n';
        cout << "4. Ordonarea crescatoare a produselor dupa pret." << '\n';
        cout << "5. Cautarea unei carti dupa titlu." << '\n';
        cout << "6. Afisarea produsului cu cea mai mare cantitate disponibila." << "\n";
        cout << "7. Iesire." << '\n';
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
        cout<<"Numarul de produse:";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            p.push_back(citireP());
        }
    }

    void option2(){
        for(int i=0;i<p.size();i++){
            cout<<p[i]->getId()<<". "<<*p[i]<<endl<<endl;
        }
    }

    void option3(){

    }

    void option4(){
        for(int i=0;i<p.size()-1;i++)
            for(int j=i+1;j<p.size();j++)
                if(p[i]->getPret()>p[j]->getPret())
                    swap(p[i],p[j]);
        cout<<"Produsele au fost ordonate crescator cu succes."<<endl<<endl;
        option2();
    }

    void option5(){
        cin.get();
        cout<<"Titlul cartii cautate:";
        string s;
        getline(cin, s);
        for(int i=0;i<p.size();i++) {
            auto *c = dynamic_cast<carte *>(p[i].get());
            if (c != nullptr)
                if (c->getTitlul() == s) {
                    cout << "Cartea a fost gasita!" << endl << endl;
                    cout << *c << endl;
                    break;
                }
        }
    }

    void option6(){
        int maxi=0;
        int maxipoz=-1;
        for(int i=0;i<p.size();i++)
            if(p[i]->getCantitate()>maxi){
                maxi=p[i]->getCantitate();
                maxipoz=i;
            }
        cout<<"Produsul cu cea mai mare cantitate disponibila este\n"<<*p[maxipoz]<<endl;
    }

    void mainLoop() {
        while(true){
            int option = chooseOption(1, 7);
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