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

class vaccin:public IoBase{
protected:
    string producator;
    double pret, temperaturadepozitare;
    vector<string> substante;
public:
    vaccin() {}

    vaccin(const string &producator, double pret, double temperaturadepozitare, const vector<string> &substante)
            : producator(producator), pret(pret), temperaturadepozitare(temperaturadepozitare), substante(substante) {}

    istream &read(istream &is) override {
        cout<<"Numele producatorului:";
        is>>producator;
        cout<<"Numarul substantelor folosite pentru prepararea vaccinului:";
        int n;
        is>>n;
        cout<<"Substantele folosite pentru prepararea vaccinului:\n";
        string s;
        for (int i=0;i<n;i++) {
            is>>s;
            substante.push_back(s);
        }
        cout<<"Temperatura exprimata in grade celsius la care trebuie depozitat vaccinul:";
        is>>temperaturadepozitare;
        cout<<"Pretul vaccinului exprimat in lei:";
        is>>pret;
        return is;
    }

    ostream &write(ostream &os) const override {
        os<<"Numele producatorului: "<<producator;
        os<<"\nSubstantele folosite pentru prepararea vaccinului:\n";
        for (const auto & i : substante)
            os<<i<<" ";
        os<<"\nTemperatura exprimata in grade celsius la care trebuie depozitat vaccinul: ";
        os<<temperaturadepozitare;
        os<<"\nPretul vaccinului exprimat in lei: ";
        os<<pret;
        return os;
    }

    const string &getProducator() const {
        return producator;
    }

};

class vaccinAntiGripal: public vaccin{
protected:
    string tulpina;
    bool ok;
public:
    vaccinAntiGripal() {}

    vaccinAntiGripal(const string &producator, double pret, double temperaturadepozitare,
                     const vector<string> &substante, const string &tulpina, bool ok) : vaccin(producator, pret,
                                                                                               temperaturadepozitare,
                                                                                               substante),
                                                                                        tulpina(tulpina), ok(ok) {}

    istream &read(istream &is) override {
        vaccin::read(is);
        cout<<"Pentru care tulpina a virusului se administreaza:";
        is>>tulpina;
        cout<<"Vaccinul respecta recomandarile date de Organizatia Mondial a Sanatatii?\n1. Da\n2. Nu\n";
        int optiune;
        is>>optiune;
        while(optiune!=1 && optiune!=2){
            cout << "Optiunea nu exista! Incercati din nou.\n";
            is>>optiune;
        }
        if(optiune==1)
            ok= true;
        else if(optiune==2)
            ok= false;
        return is;
    }

    ostream &write(ostream &os) const override {
        vaccin::write(os);
        os<<"\nVirusului se administreaza pentru tulpina: "<<tulpina;
        if(ok==1)
            os<<"\nVaccinul respecta recomandarile date de Organizatia Mondial a Sanatatii.";
        else
            os<<"\nVaccinul nu respecta recomandarile date de Organizatia Mondial a Sanatatii.";
        return os;
    }

    void afisareSchemaVaccinare(){
        cout<<"Vaccinul Antigripal se administreaza dupa urmatoarea schema:\n-La adulti o doza de 0.5 ml\n-La copii si adolescenti se administreaza o doza de 0.3ml\nIndiferent de varsta, vaccinul se face din 2 in 2 ani.\n";
    }
};

class vaccinSarsCov2: public vaccin{
protected:
    vector<string> reactiiAdverse, medicamenteContraindicate;
    double rataEficienta;
public:

    vaccinSarsCov2() {}

    vaccinSarsCov2(const string &producator, double pret, double temperaturadepozitare, const vector<string> &substante,
                   const vector<string> &reactiiAdverse, const vector<string> &medicamenteContraindicate,
                   double rataEficienta) : vaccin(producator, pret, temperaturadepozitare, substante),
                                           reactiiAdverse(reactiiAdverse),
                                           medicamenteContraindicate(medicamenteContraindicate),
                                           rataEficienta(rataEficienta) {}

    istream &read(istream &is) override {
        vaccin::read(is);
        cout<<"Numarul de reactii adverse posibile:";
        int n;
        is>>n;
        cout<<"Reactiile adverse posibile:\n";
        string s;
        for(int i=0;i<n;i++) {
            is>>s;
            reactiiAdverse.push_back(s);
        }
        cout<<"Numarul de medicamente contraindicate folosirii pe o peroade de 6 luni:";
        is>>n;
        cout<<"Medicamentele contraindicate folosirii pe o perioada de 6 luni:\n";
        for(int i=0;i<n;i++) {
            is>>s;
            medicamenteContraindicate.push_back(s);
        }
        cout<<"Rata de eficienta a vaccinului:";
        is>>rataEficienta;
        return is;
    }

    ostream &write(ostream &os) const override {
        vaccin::write(os);
        os<<"\nReactiile adverse posibile:\n";
        for(int i=0;i<reactiiAdverse.size();i++) {
            os<<reactiiAdverse[i]<<" ";
        }
        os<<"\nMedicamentele contraindicate folosirii pe o perioada de 6 luni:\n";
        for(int i=0;i<medicamenteContraindicate.size();i++) {
            os<<medicamenteContraindicate[i];
        }
        os<<"\nRata de eficienta a vaccinului: ";
        os<<rataEficienta;
        return os;
    }

    void afisareSchemaVaccinare(){
        cout<<"Vaccinul Sars-Cov2 se administreaza persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 de zile.\n";
    }
};

class vaccinHepatita: public vaccin{
protected:
    string tip;
public:
    vaccinHepatita() {}

    vaccinHepatita(const string &producator, double pret, double temperaturadepozitare, const vector<string> &substante,
                   const string &tip) : vaccin(producator, pret, temperaturadepozitare, substante), tip(tip) {}

    istream &read(istream &is) override {
        vaccin::read(is);
        cout<<"1. Intramuscular\n2. Subcutanat\n3. Intradermic\n";
        cout<<"Alegeti modul de vaccinare:";
        int optiune;
        is>>optiune;
        while(optiune!=1 && optiune!=2 && optiune!=3){
            cout<<"Optiunea nu exista. Incercati din nou.";
            is>>optiune;
        }
        if(optiune==1)
            tip="Intramuscular";
        else if (optiune==2)
            tip="Subcutanat";
        else if (optiune==3)
            tip="Intradermic";
        return is;
    }

    ostream &write(ostream &os) const override {
        vaccin::write(os);
        os<<"\nMod de vaccinare: "<<tip;
        return os;
    }

};

class A: public vaccinHepatita{
protected:
public:
    A() {}

    A(const string &producator, double pret, double temperaturadepozitare, const vector<string> &substante,
      const string &tip) : vaccinHepatita(producator, pret, temperaturadepozitare, substante, tip) {}

    istream &read(istream &is) override {
        return vaccinHepatita::read(is);
    }

    ostream &write(ostream &os) const override {
        return vaccinHepatita::write(os);
    }

    void afisareSchemaVaccinare(){
        cout<<"Vaccinul Antihepatita A se administreaza dupa urmatoarea schema:\n-La adulti conform schemei de imunizare recomandata de medic\n-La copii cu varsta mai mica de 1 an se administreaza 2 injectari la interval de o luna, a treia injectare dupa 6 luni de la prima administrare\n";
    }
};

class B: public vaccinHepatita{
protected:
public:
    B() {}

    B(const string &producator, double pret, double temperaturadepozitare, const vector<string> &substante,
      const string &tip) : vaccinHepatita(producator, pret, temperaturadepozitare, substante, tip) {}

    istream &read(istream &is) override {
        return vaccinHepatita::read(is);
    }

    ostream &write(ostream &os) const override {
        return vaccinHepatita::write(os);
    }

    void afisareSchemaVaccinare(){
        cout<<"Vaccinul Antihepatita B se administreaza dupa urmatoarea schema:\n-La adulti conform schemei de imunizare recomandata de medic\n-La copii cu varsta mai mica de 1 an se administreaza 2 injectari la interval de o luna, a treia injectare dupa 6 luni de la prima administrare\n";
    }
};

class C: public vaccinHepatita{
protected:
public:
    C() {}

    C(const string &producator, double pret, double temperaturadepozitare, const vector<string> &substante,
      const string &tip) : vaccinHepatita(producator, pret, temperaturadepozitare, substante, tip) {}

    istream &read(istream &is) override {
        return vaccinHepatita::read(is);
    }

    ostream &write(ostream &os) const override {
        return vaccinHepatita::write(os);
    }

    void afisareSchemaVaccinare(){
        cout<<"Vaccinul Antihepatita C se administreaza doar la recomandarea medicului.\n";
    }
};

struct Data{
    int zi, luna, an;
};

class comanda: public IoBase{
protected:
    static unsigned int staticId;
    unsigned id;
    Data data;
    string nume;
    vector<shared_ptr<vaccin>> vaccinuri;
    vector<shared_ptr<vaccin>> vaccinuriComandate;
    vector<int> nrVaccinuri;
    double total;
public:
    comanda();

    comanda(unsigned int id, const Data &data, const string &nume, const vector<shared_ptr<vaccin>> &vaccinuri,
            const vector<int> &nrVaccinuri, double total);

    istream &read(istream &is) override;

    ostream &write(ostream &os) const override;

    void setVaccinuri(const vector<shared_ptr<vaccin>> &vaccinuri);
};
unsigned int comanda::staticId=0;

comanda::comanda(): id(++staticId) {}

comanda::comanda(unsigned int id, const Data &data, const string &nume, const vector<shared_ptr<vaccin>> &vaccinuri,
                 const vector<int> &nrVaccinuri, double total) : id(id), data(data), nume(nume), vaccinuri(vaccinuri),
                                                                 nrVaccinuri(nrVaccinuri), total(total) {}

istream &comanda::read(istream &is) {
    cout<<"Data comenzii:";
    is>>data.zi>>data.luna>>data.an;
    cout<<"Nume client:";
    is>>nume;
    cout<<"Vaccinuri pe stoc:\n";
    for(int i=0;i<vaccinuri.size();i++)
        cout<<i+1<<". "<<*vaccinuri[i]<<endl;
    cout<<"Numarul de tipuri de vaccinuri dorite:";
    int n;
    is>>n;
    int optiune;
//    nrVaccinuri.push_back(0); // initializam cu 0 numarul fiecarui tip de vaccin
//    nrVaccinuri.push_back(0);
//    nrVaccinuri.push_back(0);
//    nrVaccinuri.push_back(0);
//    nrVaccinuri.push_back(0);
    int nr;
    for(int i=0;i<n;i++){
        cout<<"Tipul vaccinului dorit(id-ul acestuia):";
        is>>optiune;
        vaccinuriComandate.push_back(vaccinuri[optiune-1]);
        cout<<"Cantitatea dorita:";
        is>>nr;
        nrVaccinuri.push_back(nr);

//        auto* G=dynamic_cast<vaccinAntiGripal *>(vaccinuri[optiune-1].get());
//        auto* S=dynamic_cast<vaccinSarsCov2 *>(vaccinuri[optiune-1].get());
//        auto* a=dynamic_cast<A *>(vaccinuri[optiune-1].get());
//        auto* b=dynamic_cast<B *>(vaccinuri[optiune-1].get());
//        auto* c=dynamic_cast<C *>(vaccinuri[optiune-1].get());
//        if (G!=nullptr){
//            nrVaccinuri[0]++;
//        } else if (S!=nullptr){
//            nrVaccinuri[1]++;
//        } else if (a!=nullptr){
//            nrVaccinuri[2]++;
//        } else if (b!=nullptr){
//            nrVaccinuri[3]++;
//        } else if (c!=nullptr){
//            nrVaccinuri[4]++;
//        }
    }
    cout<<"Totalul comenzii:";
    is>>total;
    return is;
}

ostream &comanda::write(ostream &os) const {
    os<<endl<<id<<". ";
    os<<"Data comenzii: "<<data.zi<<"/"<<data.luna<<"/"<<data.an;
    os<<"\nNume client: "<<nume;
    os<<"\nVaccinuri comandate:\n\n";
    for(int i=0;i<vaccinuriComandate.size();i++)
        os<<*vaccinuriComandate[i]<<endl<<nrVaccinuri[i]<<endl<<endl;
    os<<"\nTotalul comenzii:"<<total;
    os<<endl;
    return os;
}

void comanda::setVaccinuri(const vector<shared_ptr<vaccin>> &vaccinuri) {
    comanda::vaccinuri = vaccinuri;
}


shared_ptr<vaccin> citirev(){
    cout<<"\n1. Vaccin Antigripal.\n2. Vaccin Sars-Cov2.\n3. Vaccin Hepatita.\n";
    cout<<"Alege tipul de vaccin:";
    int optiune;
    cin>>optiune;
    shared_ptr<vaccin> v;
    if (optiune==1)
        v= make_shared<vaccinAntiGripal>();
    else if (optiune==2)
        v= make_shared<vaccinSarsCov2>();
    else if (optiune==3) {
        cout<<"1. Vaccin Hepatita A.\n2. Vaccin Hepatita B.\n3. Vaccin Hepatita C.\n";
        cout<<"Alege tipul de hepatita impotriva caruia actioneaza vaccinul:\n";
        cin>>optiune;
        if(optiune==1){
            v = make_shared<A>();
        } else if(optiune==2){
            v = make_shared<B>();
        } else if(optiune==3){
            v = make_shared<C>();
        }
    }
    cin>>*v;
    return v;
}

class BaseMenu{
public:
    virtual void listOptions() {}
    virtual int chooseOption(int first, int last) {return 0;}
    virtual void mainLoop() {}
};

class SimpleMenu: public BaseMenu{
private:
    vector<comanda> comenzi;
    vector<shared_ptr<vaccin>> vaccinuri;
public:
    void listOptions() override{
        cout << "1. Adaugrea unui vaccin nou." << '\n';
        cout << "2. Afisarea tuturor vaccinurilor pe care le detine." << '\n';
        cout << "3. Numele producatorilor pentru toate vaccinurile." << '\n';
        cout << "4. Adaugarea unei comenzi." << '\n';
        cout << "5. Afisarea tuturor comenzilor." << '\n';
        cout << "6. Valoarea comenzilor dintr-o anumita zi." << '\n';
        cout << "7. Iesire." << "\n";
    }

    int chooseOption(int first, int last) override {
        int option = -1;
        while(option < first || option > last){
            cout << '\n';
            cout << "Pentru a rula comanda, alegeti un numar intre "
                 << first << " si " << last << '\n';
            listOptions();
            cout << "Alegere:";
            cin >> option;
        }
        return option;
    }


    void option1(){
        vaccinuri.push_back(citirev());
    }

    void option2(){
        for(auto x:vaccinuri)
            cout<<*x<<endl;
    }

    void option3(){
        for(int i=0;i<vaccinuri.size();i++){
            cout<<i+1<<". "<<vaccinuri[i]->getProducator()<<endl;
        }
    }

    void option4(){
        comanda c;
        c.setVaccinuri(vaccinuri);
        cin>>c;
        comenzi.push_back(c);
    }

    void option5(){
        for(auto x:comenzi){
            cout<<x<<endl;
        }
    }

    void option6(){

    }

    void mainLoop() override {
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