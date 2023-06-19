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

class jucarie: public IoBase{
protected:
        string nume, tip;
        int dimensiune;
public:
    jucarie() {}
    jucarie(const string &nume, const string &tip, int dimensiune) : nume(nume), tip(tip), dimensiune(dimensiune) {}

    istream &read(istream &is) override {
        cout<<"\nNume: ";
        is>>nume;
        cout<<"\nTip: ";
        is>>tip;
        cout<<"\nDimensiune: ";
        is>>dimensiune;
        return is;
    }

    ostream &write(ostream &os) const override {
        os<<"Nume: "<<nume<<"; "<<"Tip: "<<tip<<"; "<<"Dimensiune: "<<dimensiune;
        return os;
    }

    const string &getNume() const {
        return nume;
    }

    void setNume(const string &nume) {
        jucarie::nume = nume;
    }

    const string &getTip() const {
        return tip;
    }

    void setTip(const string &tip) {
        jucarie::tip = tip;
    }

    int getDimensiune() const {
        return dimensiune;
    }

    void setDimensiune(int dimensiune) {
        jucarie::dimensiune = dimensiune;
    }

};

class jucarieClasica: public jucarie{
private:
    string material, culoare;
public:
    jucarieClasica() {}

    jucarieClasica(const string &material, const string &culoare) : material(material), culoare(culoare) {}

    istream &read(istream &is) override {
        jucarie::read(is);
        cout<<"\nMaterial: ";
        is>>material;
        cout<<"\nCuloare: ";
        is>>culoare;
        return is;
    }

    ostream &write(ostream &os) const override {
        jucarie::write(os);
        cout<<"; Material: ";
        os<<material;
        cout<<"; Culoare: ";
        os<<culoare;
        return os;
    }

    const string &getMaterial() const {
        return material;
    }

    void setMaterial(const string &material) {
        jucarieClasica::material = material;
    }

    const string &getCuloare() const {
        return culoare;
    }

    void setCuloare(const string &culoare) {
        jucarieClasica::culoare = culoare;
    }
};

class jucarieEducativa: virtual public jucarie{
protected:
    string abilitate;
public:
    jucarieEducativa() {}

    jucarieEducativa(const string &abilitate) : abilitate(abilitate) {}

    istream &read(istream &is) override {
        jucarie::read(is);
        cout<<"\nAbilitate: ";
        is>>abilitate;
        return is;
    }

    ostream &write(ostream &os) const override {
        jucarie::write(os);
        cout<<"; Abilitate: ";
        os<<abilitate;
        return os;
    }

    const string &getAbilitate() const {
        return abilitate;
    }

    void setAbilitate(const string &abilitate) {
        jucarieEducativa::abilitate = abilitate;
    }
};

class jucarieElectronica: virtual public jucarie{
protected:
    int nrBaterii;
public:
    jucarieElectronica() {}
    jucarieElectronica(int nrBaterii) : nrBaterii(nrBaterii) {}

    istream &read(istream &is) override {
        jucarie::read(is);
        cout<<"\nNrBaterii: ";
        is>>nrBaterii;
        return is;
    }

    ostream &write(ostream &os) const override {
        jucarie::write(os);
        cout<<"; NrBaterii: ";
        os<<nrBaterii;
        return os;
    }

    int getNrBaterii() const {
        return nrBaterii;
    }

    void setNrBaterii(int nrBaterii) {
        jucarieElectronica::nrBaterii = nrBaterii;
    }
};

class jucarieModerna : public jucarieEducativa, public jucarieElectronica{
private:
    string brand, model;
public:
    jucarieModerna(){}
    jucarieModerna(const string &abilitate, int nrBaterii, const string &brand, const string &model) : jucarieEducativa("generala"), jucarieElectronica(1), brand(brand), model(model) {}

    istream &read(istream &is) override {
        nrBaterii=1;
        abilitate="generala";
        jucarie::read(is);
        cout<<"\nBrand: ";
        is>>brand;
        cout<<"\nModel: ";
        is>>model;
        return is;
    }

    ostream &write(ostream &os) const override {
        jucarie::write(os);
        os<<"; Nr Baterii: "<<nrBaterii<<"; Abilitate: "<<abilitate<<"; Brand: "<<brand<<"; Model: "<<model;
        return os;
    }

    const string &getBrand() const {
        return brand;
    }

    void setBrand(const string &brand) {
        jucarieModerna::brand = brand;
    }

    const string &getModel() const {
        return model;
    }

    void setModel(const string &model) {
        jucarieModerna::model = model;
    }
};

shared_ptr<jucarie> citirej(){
    cout<<"\n1. Jucarie clasica\n2. Jucarie educativa.\n3. Jucarie electornica.\n4. Jucarie moderna.\n";
    int optiune;
    cin>>optiune;
    shared_ptr<jucarie> j;
    if (optiune==1)
        j= make_shared<jucarieClasica>();
    else if (optiune==2)
        j= make_shared<jucarieEducativa>();
    else if (optiune==3)
        j= make_shared<jucarieElectronica>();
    else if (optiune==4)
        j= make_shared<jucarieModerna>();
    cin>>*j;
    return j;
}

class copil: public IoBase{
protected:
    static unsigned int staticId;
    unsigned id;
    string nume, prenume, adresa;
    int varsta, nrfaptebune;
    vector<shared_ptr<jucarie>> j;
public:
    copil();

    copil(unsigned int id, const string &nume, const string &prenume, const string &adresa, int varsta, int nrfaptebune,
          const vector<shared_ptr<jucarie>> &j);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

    static unsigned int getStaticId();

    static void setStaticId(unsigned int staticId);

    unsigned int getId() const;

    void setId(unsigned int id);

    const string &getNume() const;

    void setNume(const string &nume);

    const string &getPrenume() const;

    void setPrenume(const string &prenume);

    const string &getAdresa() const;

    void setAdresa(const string &adresa);

    int getVarsta() const;

    void setVarsta(int varsta);

    int getNrfaptebune() const;

    void setNrfaptebune(int nrfaptebune);

    const vector<shared_ptr<jucarie>> &getJ() const;

    void setJ(const vector<shared_ptr<jucarie>> &j);
};

unsigned int copil::staticId = 0;
copil::copil(): id(staticId++){}

copil::copil(unsigned int id, const string &nume, const string &prenume, const string &adresa, int varsta,
             int nrfaptebune, const vector<shared_ptr<jucarie>> &j) : id(id), nume(nume), prenume(prenume),
                                                                      adresa(adresa), varsta(varsta),
                                                                      nrfaptebune(nrfaptebune), j(j) {}


istream &copil::read(istream &is) {
    cout<<"\nNume: ";
    is>>nume;
    cout<<"\nPrenume: ";
    is>>prenume;
    cout<<"\nAdresa: ";
    is>>adresa;
    cout<<"\nVarsta: ";
    is>>varsta;
    cout<<"\nNumar fapte bune: ";
    is>>nrfaptebune;
    cout<<"\nNumar de jucarii: ";
    int n;
    cin>>n;
    cout<<"\nJucarii: ";
    for(int i=0;i<n;i++){
        j.push_back(citirej());
    }
    return is;
}

ostream &copil::write(ostream &os) const {
    cout<<"\n"<<id<<". Nume: ";
    os<<nume;
    cout<<"\nPrenume: ";
    os<<prenume;
    cout<<"\nAdresa: ";
    os<<adresa;
    cout<<"\nVarsta: ";
    os<<varsta;
    cout<<"\nNumar fapte bune: ";
    os<<nrfaptebune;
    cout<<"\nJucarii: ";
    for(int i=0;i<j.size();i++)
        os<<*j[i]<<endl;
    cout<<endl;
    return os;
}

unsigned int copil::getStaticId() {
    return staticId;
}

void copil::setStaticId(unsigned int staticId) {
    copil::staticId = staticId;
}

unsigned int copil::getId() const {
    return id;
}

void copil::setId(unsigned int id) {
    copil::id = id;
}

const string &copil::getNume() const {
    return nume;
}

void copil::setNume(const string &nume) {
    copil::nume = nume;
}

const string &copil::getPrenume() const {
    return prenume;
}

void copil::setPrenume(const string &prenume) {
    copil::prenume = prenume;
}

const string &copil::getAdresa() const {
    return adresa;
}

void copil::setAdresa(const string &adresa) {
    copil::adresa = adresa;
}

int copil::getVarsta() const {
    return varsta;
}

void copil::setVarsta(int varsta) {
    copil::varsta = varsta;
}

int copil::getNrfaptebune() const {
    return nrfaptebune;
}

void copil::setNrfaptebune(int nrfaptebune) {
    copil::nrfaptebune = nrfaptebune;
}

const vector<shared_ptr<jucarie>> &copil::getJ() const {
    return j;
}

void copil::setJ(const vector<shared_ptr<jucarie>> &j) {
    copil::j = j;
}


class copilCuminte:public copil{
private:
    int nrdulciuri;
public:
    copilCuminte() {}

    copilCuminte(unsigned int id, const string &nume, const string &prenume, const string &adresa, int varsta,
                 int nrfaptebune, const vector<shared_ptr<jucarie>> &j, int nrdulciuri) : copil(id, nume, prenume,
                                                                                                adresa, varsta,
                                                                                                nrfaptebune, j),
                                                                                          nrdulciuri(nrdulciuri) {}

    istream &read(istream &is) override {
        copil::read(is);
        while (nrfaptebune < 10){
            cout <<"\nCopilul nu poate fi cuminte daca are mai putin de 10 fapte bune. Introduceti o alta valoare!";
            is >> nrfaptebune;
        }
        cout<<"\nNumar dulciuri: ";
        is>>nrdulciuri;
        return is;
    }

    ostream &write(ostream &os) const override {
        copil::write(os);
        cout<<"Numar dulciuri: ";
        os<<nrdulciuri;
        cout<<endl;
        return os;
    }

    int getNrdulciuri() const {
        return nrdulciuri;
    }

    void setNrdulciuri(int nrdulciuri) {
        copilCuminte::nrdulciuri = nrdulciuri;
    }
};

class copilNeastamparat: public copil{
private:
    int nrcarbuni;
public:
    copilNeastamparat() {}

    copilNeastamparat(unsigned int id, const string &nume, const string &prenume, const string &adresa, int varsta,
                      int nrfaptebune, const vector<shared_ptr<jucarie>> &j, int nrcarbuni) : copil(id, nume, prenume,
                                                                                                    adresa, varsta,
                                                                                                    nrfaptebune, j),
                                                                                              nrcarbuni(nrcarbuni) {}

    istream &read(istream &is) override {
        copil::read(is);
        cout<<"\nNumar carbuni: ";
        is>>nrcarbuni;
        return is;
    }

    ostream &write(ostream &os) const override {
        copil::write(os);
        cout<<"Numar carbuni: ";
        os<<nrcarbuni;
        cout<<endl;
        return os;
    }

    int getNrcarbuni() const {
        return nrcarbuni;
    }

    void setNrcarbuni(int nrcarbuni) {
        copilNeastamparat::nrcarbuni = nrcarbuni;
    }
};

shared_ptr<copil> citirec(){
    cout<<"\n1. Copil cuminte.\n2. Copil neastamparat.\n";
    cout<<"Alege tipul de copil: ";
    int optiune;
    cin>>optiune;
    shared_ptr<copil> c;
    if (optiune==1)
        c= make_shared<copilCuminte>();
    else if (optiune==2)
        c= make_shared<copilNeastamparat>();
    cin>>*c;
    return c;
}

class BaseMenu{
public:
    virtual void listOptions() {}
    virtual int chooseOption(int first, int last) {return 0;}
    virtual void mainLoop() {}
};

class SimpleMenu: public BaseMenu{
private:
    vector<shared_ptr<copil>> copii;
public:
    void listOptions() override{
        cout << "0. Citire informatii pentru n copii." << '\n';
        cout << "1. Afisare informatiilor pentru fiecare copil." << '\n';
        cout << "2. Cautarea unui copil dupa nume." << '\n';
        cout << "3. Afisarea copiilor ordanti dupa varsta." << '\n';
        cout << "4. Afisarea copiilor ordanti dupa numarul de fapte bune." << '\n';
        cout << "5. Cresterea numarului de fapte bune ale unui copil cu o valoare X si adaugarea de X jucarii pentru acel copil." << '\n';
        cout << "6. Afisarea numarului total de jucarii create." <<"\n";
        cout << "7. Iesire." << "\n";
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

    void option0() {
        int n;
        cout<<"Numarul de copii: ";
        cin>>n;
        for(int i = 0; i<n; i++){
            copii.push_back(citirec());
        }
    }

    void option1() {
        for(int i = 0; i<copii.size(); i++)
            cout<<*copii[i];
    }

    void option2() {
        string nume;
        int ok=0;
        cout<<"\nNumele copiului cautat: ";
        cin>>nume;
        cout<<endl;
        for(int i=0;i< copii.size();i++){
            if (nume==copii[i]->getNume() || nume==copii[i]->getPrenume()) {
                cout << *copii[i] << endl;
                ok=1;
            }
        }
        if (ok==0)
            cout<<"\nNu exista niciun copil cu acest nume.\n";
    }

    void option3() {
        for(int i=0;i<copii.size()-1;i++)
            for(int j=i+1;j<copii.size();j++)
                if(copii[i]->getVarsta()>copii[j]->getVarsta())
                    swap(copii[i],copii[j]);
        for(int i = 0; i<copii.size(); i++)
            cout<<*copii[i];
        cout<<endl;
    }

    void option4() {
        for(int i=0;i<copii.size()-1;i++)
            for(int j=i+1;j<copii.size();j++)
                if(copii[i]->getNrfaptebune()>copii[j]->getNrfaptebune())
                    swap(copii[i],copii[j]);
        for(int i = 0; i<copii.size(); i++)
            cout<<*copii[i];
        cout<<endl;
    }

    void option5() {
        int id, x;
        cout << "\nId-ul copilului: ";
        cin >> id;
        cout << "\nNumarul de fapte bune pe care vreti sa-l adaugati: ";
        cin >> x;
        for (int i = 0; i < copii.size(); i++)
            if (copii[i]->getId() == id) {
                copii[i]->setNrfaptebune(copii[i]->getNrfaptebune() + x);
                cout<<"\nInformatiile au fost actualizate:\n"<<*copii[i];
            }
    }

    void option6(){
        int C=0, Ed=0, El=0, M=0;
        for(int i=0;i<copii.size();i++)
            for(auto x: copii[i]->getJ()){
                auto* clasic=dynamic_cast<jucarieClasica*>(x.get());
                auto* edu=dynamic_cast<jucarieEducativa*>(x.get());
                auto* electro=dynamic_cast<jucarieElectronica*>(x.get());
                auto* modern=dynamic_cast<jucarieModerna*>(x.get());
                if(clasic!=nullptr)
                    C++;
                else if(modern!=nullptr)
                    M++;
                else if(edu!=nullptr)
                    Ed++;
                else if(electro!=nullptr)
                    El++;
            }
        cout<<"\nNumarul total de jucarii este "<<C+Ed+El+M<<" din care "<<C<<" sunt jucarii clasice, "<<Ed<<" sunt jucarii educative, "<<El<<" sunt jucarii electronice si "<<M<<" sunt jucarii moderne.\n";
    }

    void mainLoop() override {
        while(true){
            int option = chooseOption(0, 7);
            if(option == 0){
                option0();
            } else if (option == 1) {
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
