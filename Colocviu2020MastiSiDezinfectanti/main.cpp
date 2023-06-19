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

class masti: public IoBase{
protected:
    string culoare;
    int nrpliuri, custom;
public:
    masti() {}

    masti(const string &culoare, int nrpliuri, int custom) : culoare(culoare), nrpliuri(nrpliuri), custom(custom) {}

    istream &read(istream &is) override {
        cout<<"Culoare masca: ";
        is>>culoare;
        cout<<"Numar de pliuri: ";
        is>>nrpliuri;
        return is;
    }

    ostream &write(ostream &os) const override {
        os<<"Culoare masca: "<<culoare<<"; Numar de pliuri: "<<nrpliuri;
        return os;
    }

    int getCustom() const {
        return custom;
    }

    void setCustom(int custom) {
        masti::custom = custom;
    }
};

class ffp1: virtual public masti{
public:
    ffp1() {}

    ffp1(const string &culoare, int nrpliuri, int custom) : masti(culoare, nrpliuri, custom) {}

    istream &read(istream &is) override {
        masti::read(is);
        return is;
    }

    ostream &write(ostream &os) const override {
        masti::write(os);
        cout<<"; Masca textila, tip protectie: ffp1";
        return os;
    }
};

class ffp2: virtual public masti{
public:
    ffp2() {}

    ffp2(const string &culoare, int nrpliuri, int custom) : masti(culoare, nrpliuri, custom) {}

    istream &read(istream &is) override {
        masti::read(is);
        return is;
    }

    ostream &write(ostream &os) const override {
        masti::write(os);
        cout<<"; Masca textila, tip protectie: ffp2";
        return os;
    }
};

class ffp3: virtual public masti{
public:
    ffp3() {}

    ffp3(const string &culoare, int nrpliuri, int custom) : masti(culoare, nrpliuri, custom) {}

    istream &read(istream &is) override {
        masti::read(is);
        return is;
    }

    ostream &write(ostream &os) const override {
        masti::write(os);
        cout<<"; Masca textila, tip protectie: ffp3";
        return os;
    }
};

class mastiPolicarbonat: virtual public masti{
private:
    string tipprindere;
public:
    mastiPolicarbonat() {}

    mastiPolicarbonat(const string &culoare, int nrpliuri, int custom, const string &tipprindere) : masti(culoare,
                                                                                                          nrpliuri,
                                                                                                          custom),
                                                                                                    tipprindere(
                                                                                                            tipprindere) {}


    istream &read(istream &is) override {
        masti::read(is);
        cout<<"Tip de prindere: ";
        is>>tipprindere;
        return is;
    }

    ostream &write(ostream &os) const override {
        masti::write(os);
        cout<<"; Masca policarbonat, tip protectie: ffp0";
        os<<"; Tip prindere: "<<tipprindere;
        return os;
    }
};

shared_ptr<masti> citirem(){
    cout<<"\n1. Masca textila ffp1.\n2. Masca textila ffp2.\n3. Masca textila ffp3.\n4. Masca policarbonat(ffp0).\n";
    cout<<"Alege tipul de masca dorit: ";
    int optiune;
    cin>>optiune;
    shared_ptr<masti> masca;
    if (optiune==1)
        masca= make_shared<ffp1>();
    else if (optiune==2)
        masca= make_shared<ffp2>();
    else if (optiune==3)
        masca= make_shared<ffp3>();
    else if (optiune==4)
        masca= make_shared<mastiPolicarbonat>();
    cin>>*masca;
    return masca;
}

class dezinfectant: public IoBase{
protected:
    int nrspecii;
    vector<string> ingrediente, tipsuprafata;
public:
    dezinfectant() {}

    dezinfectant(int nrspecii, const vector<string> &ingrediente, const vector<string> &tipsuprafata) : nrspecii(
            nrspecii), ingrediente(ingrediente), tipsuprafata(tipsuprafata) {}

    istream &read(istream &is) override {
        cout<<"Numar de specii ce pot fi ucise: ";
        is>>nrspecii;
        cout<<"Numar de ingrediente: ";
        int n;
        cin>>n;
        string s;
        for(int i=0;i<n;i++) {
            is >> s;
            ingrediente.push_back(s);
        }
        cout<<"Numar de tipuri de suprafata pe care poate fi aplicat: ";
        cin>>n;
        for(int i=0;i<n;i++) {
            is >> s;
            tipsuprafata.push_back(s);
        }
        return is;
    }

    ostream &write(ostream &os) const override {
        os<<"Numar de specii ce pot fi ucise: "<<nrspecii;
        os<<"\nIngrediente: "<<ingrediente;
        os<<"\nTipurile de suprafata pe care poate fi aplicat:\n"<<tipsuprafata<<"\n";
        return os;
    }

    int getNrspecii() const {
        return nrspecii;
    }

    void setNrspecii(int nrspecii) {
        dezinfectant::nrspecii = nrspecii;
    }

    const vector<string> &getIngrediente() const {
        return ingrediente;
    }

    void setIngrediente(const vector<string> &ingrediente) {
        dezinfectant::ingrediente = ingrediente;
    }

    const vector<string> &getTipsuprafata() const {
        return tipsuprafata;
    }

    void setTipsuprafata(const vector<string> &tipsuprafata) {
        dezinfectant::tipsuprafata = tipsuprafata;
    }
};

class dezinfectantBacterii: virtual public dezinfectant{
private:
public:
    dezinfectantBacterii() {}

    dezinfectantBacterii(int nrspecii, const vector<string> &ingrediente, const vector<string> &tipsuprafata)
            : dezinfectant(nrspecii, ingrediente, tipsuprafata) {}

    istream &read(istream &is) override {
        return dezinfectant::read(is);
    }

    ostream &write(ostream &os) const override {
        return dezinfectant::write(os);
    }

};

class dezinfectantFungi: virtual public dezinfectant{
private:
public:
    dezinfectantFungi() {}

    dezinfectantFungi(int nrspecii, const vector<string> &ingrediente, const vector<string> &tipsuprafata)
            : dezinfectant(nrspecii, ingrediente, tipsuprafata) {}

    istream &read(istream &is) override {
        return dezinfectant::read(is);
    }

    ostream &write(ostream &os) const override {
        return dezinfectant::write(os);
    }

};

class dezinfectantVirusuri: virtual public dezinfectant{
private:
public:
    dezinfectantVirusuri() {}

    dezinfectantVirusuri(int nrspecii, const vector<string> &ingrediente, const vector<string> &tipsuprafata)
            : dezinfectant(nrspecii, ingrediente, tipsuprafata) {}

    istream &read(istream &is) override {
        return dezinfectant::read(is);
    }

    ostream &write(ostream &os) const override {
        return dezinfectant::write(os);
    }

};

class dezinfectantUniversal: public dezinfectantBacterii, public dezinfectantFungi, public dezinfectantVirusuri{
private:
    double eficienta;
public:
    dezinfectantUniversal() {}

    dezinfectantUniversal(int nrspecii, const vector<string> &ingrediente, const vector<string> &tipsuprafata,
                          int nrspecii1, const vector<string> &ingrediente1, const vector<string> &tipsuprafata1,
                          int nrspecii2, const vector<string> &ingrediente2, const vector<string> &tipsuprafata2,
                          double eficienta) : dezinfectantBacterii(nrspecii, ingrediente, tipsuprafata),
                                              dezinfectantFungi(nrspecii1, ingrediente1, tipsuprafata1),
                                              dezinfectantVirusuri(nrspecii2, ingrediente2, tipsuprafata2),
                                              eficienta(eficienta) {}

    istream &read(istream &is) override {
        int x,y,z;
        double ef;
        dezinfectantBacterii::read(is);
        x=getNrspecii();
        ef=x/pow(10,7);
        dezinfectantFungi::read(is);
        y=getNrspecii();
        ef+=y/(15*pow(10,3));
        dezinfectantVirusuri::read(is);
        z=getNrspecii();
        ef+=z/pow(10,6);
        setNrspecii(x+y+z);
        ef/=3;
        eficienta=ef;
        return is;
    }

    ostream &write(ostream &os) const override {
        dezinfectant::write(os);
        return os;
    }

    double getEficienta() const {
        return eficienta;
    }

};

shared_ptr<dezinfectant> citired(){
    cout<<"\n1. Dezinfectant impotriva bacteriilor.\n2. Dezinfectant impotriva fungilor.\n3. Dezinfectant impotriva virusurilor.\n4. Dezinfectant universal.\n";
    cout<<"Alege tipul de dezinfectant dorit: ";
    int optiune;
    cin>>optiune;
    shared_ptr<dezinfectant> d;
    if (optiune==4)
        d= make_shared<dezinfectantUniversal>();
    else if (optiune==1)
        d= make_shared<dezinfectantBacterii>();
    else if (optiune==2)
        d= make_shared<dezinfectantFungi>();
    else if (optiune==3)
        d= make_shared<dezinfectantVirusuri>();
    cin>>*d;
    return d;
}

struct data_calendaristica{
    int zi, luna, an;
};

class achizitie: public IoBase{
private:
    string nume;
    data_calendaristica data;
    vector<shared_ptr<dezinfectant>> d,dezinfectantiachizitionati;
    vector<shared_ptr<masti>> m, mastiachizitionate;
    double total;
public:
    achizitie() {}

    achizitie(const string &nume, const data_calendaristica &data, const vector<shared_ptr<dezinfectant>> &d,
              const vector<shared_ptr<dezinfectant>> &dezinfectantiachizitionati, const vector<shared_ptr<masti>> &m,
              const vector<shared_ptr<masti>> &mastiachizitionate, double total) : nume(nume), data(data), d(d),
                                                                                   dezinfectantiachizitionati(
                                                                                           dezinfectantiachizitionati),
                                                                                   m(m), mastiachizitionate(
                    mastiachizitionate), total(total) {}

    istream &read(istream &is) override {
        cout<<"Nume client: ";
        is>>nume;
        cout<<"Data achizitiei: ";
        is>>data.zi>>data.luna>>data.an;
        cout<<"Mastile aflate pe stoc sunt:\n";
        for(int i=0;i<m.size();i++)
            cout<<to_string(i+1)+". "<<*m[i]<<endl;
        cout<<"Care este numarul de masti dorit?\n-";
        int n, optiune;
        is>>n;
        for(int i=0;i<n;i++) {
            cout<<"Alegeti numarul mastii dorite: ";
            is>>optiune;
            mastiachizitionate.push_back(m[optiune-1]);
            cout<<"Doriti ca masca sa fie personalizata?\n1. Da\n2. Nu\nAlegeti 1 sau 2: ";
            int c;
            is>>c;
            mastiachizitionate[mastiachizitionate.size()-1]->setCustom(c);
        }
        cout<<"Dezinfectantii aflati pe stoc sunt:\n";
        for(int i=0;i<d.size();i++)
            cout<<to_string(i+1)+". "<<*d[i]<<endl;
        cout<<"Care este numarul de dezinfectanti dorit?\n-";
        is>>n;
        for(int i=0;i<n;i++) {
            cout<<"Alegeti numarul dezinfectanutului dorit: ";
            is>>optiune;
            dezinfectantiachizitionati.push_back(d[optiune-1]);
        }
        return is;
    }

    ostream &write(ostream &os) const override {
        os<<"Nume client: "<<nume;
        os<<"; Data achizitiei: "<<data.zi<<"/"<<data.luna<<"/"<<data.an;
        os<<"\nMastile achizitionate sunt:\n";
        for(int i=0;i<mastiachizitionate.size();i++)
            os<<to_string(i+1)+". "<<*mastiachizitionate[i]<<endl;
        os<<"\nDezinfectantii achizitionati sunt:\n";
        for(int i=0;i<dezinfectantiachizitionati.size();i++)
            os<<to_string(i)+". "<<*dezinfectantiachizitionati[i]<<endl;
        return os;
    }

    void setD(const vector<shared_ptr<dezinfectant>> &d) {
        achizitie::d = d;
    }

    void setM(const vector<shared_ptr<masti>> &m) {
        achizitie::m = m;
    }

    const data_calendaristica &getData() const {
        return data;
    }

    double calculareTotal() {
        for (auto x: mastiachizitionate) {
            auto *policarb = dynamic_cast<mastiPolicarbonat *>(x.get());
            auto *p1 = dynamic_cast<ffp1 *>(x.get());
            auto *p2 = dynamic_cast<ffp2 *>(x.get());
            auto *p3 = dynamic_cast<ffp3 *>(x.get());
            if (policarb != nullptr) {
                if (policarb->getCustom() == 1)
                    total += 30;
                else total += 20;
            } else if (p1 != nullptr) {
                if (p1->getCustom() == 1)
                    total += 7.5;
                else total += 5;
            } else if (p2 != nullptr) {
                if (p2->getCustom() == 1)
                    total += 15;
                else total += 10;
            } else if (p3 != nullptr) {
                if (p3->getCustom() == 1)
                    total += 22.5;
                else total += 15;
            }
        }

        double eficienta;
        for (auto x: dezinfectantiachizitionati) {
            auto *univ = dynamic_cast<dezinfectantUniversal *>(x.get());
            auto *bacterii = dynamic_cast<dezinfectantBacterii *>(x.get());
            auto *fungi = dynamic_cast<dezinfectantFungi *>(x.get());
            auto *virusuri = dynamic_cast<dezinfectantVirusuri *>(x.get());
            if (univ != nullptr) {
                eficienta = univ->getEficienta();
            } else if (bacterii != nullptr) {
                eficienta = bacterii->getNrspecii() / pow(10, 7);
            } else if (fungi != nullptr) {
                eficienta = fungi->getNrspecii() / (15 * pow(10, 3));
            } else if (virusuri != nullptr) {
                eficienta = virusuri->getNrspecii() / pow(10, 6);
            }
            if (eficienta < 90)
                total += 10;
            else if (eficienta < 95)
                total += 20;
            else if (eficienta < 97.5)
                total += 30;
            else if (eficienta < 99)
                total += 40;
            else if (eficienta < 99.99)
                total += 50;
        }
        return total;
    }

    double calculareVenitMastiCustom(){
        double venitCustom=0;
        for (auto x: mastiachizitionate) {
            if (x->getCustom()==1){
                auto *policarb = dynamic_cast<mastiPolicarbonat *>(x.get());
                auto *p1 = dynamic_cast<ffp1 *>(x.get());
                auto *p2 = dynamic_cast<ffp2 *>(x.get());
                auto *p3 = dynamic_cast<ffp3 *>(x.get());
                if (policarb != nullptr) {
                    venitCustom += 30;
                } else if (p1 != nullptr) {
                    venitCustom += 7.5;
                } else if (p2 != nullptr) {
                    venitCustom += 15;
                } else if (p3 != nullptr) {
                    venitCustom += 22.5;
                }
            }
            return venitCustom;
        }
    }

};

class BaseMenu{
public:
    virtual void listOptions() {}
    virtual int chooseOption(int first, int last) {return 0;}
    virtual void mainLoop() {}
};

class SimpleMenu: public BaseMenu{
private:
    vector<achizitie> achizitii;
    vector<shared_ptr<dezinfectant>> d;
    vector<shared_ptr<masti>> m;
public:
    void listOptions() override{
        cout << "1. Adauga un nou dezinfectant in stoc." << '\n';
        cout << "2. Adaouga o noua masca in stoc" << '\n';
        cout << "3. Adauga o noua achizitie." << '\n';
        cout << "4. Afiseaza dezinfectantul cel mai eficient." << '\n';
        cout << "5. Calculeaza venitul intr-o anumita luna. " << '\n';
        cout << "6. Calculeaza venitul obtinut din mastile chirurgicale cu model." << "\n";
        cout << "7. Modifica reteta unui dezinfectant." << '\n';
        cout << "8. Afiseaza cel mai fidel client." << '\n';
        cout << "9. Afiseaza ziua cu cele mai slabe venituri." << '\n';
        cout << "10. Calculeaza TVA-ul care trebuie returnat la ANAF pentru un anumit an." << '\n';
        cout << "11. Afiseaza toate achizitiile." << '\n';
        cout << "12. Iesire." << '\n';
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
        d.push_back(citired());
    }

    void option2(){
        m.push_back(citirem());
    }

    const vector<shared_ptr<dezinfectant>> &getD() const {
        return d;
    }

    const vector<shared_ptr<masti>> &getM() const {
        return m;
    }

    void option3(){
        achizitie a;
        a.setD(d);
        a.setM(m);
        cin>>a;
        achizitii.push_back(a);
    }

    void option4() {
        double eficienta, eficientamax = 0;
        int poz = 0, k;
        for (auto x: d) {
            auto *univ = dynamic_cast<dezinfectantUniversal *>(x.get());
            auto *bacterii = dynamic_cast<dezinfectantBacterii *>(x.get());
            auto *fungi = dynamic_cast<dezinfectantFungi *>(x.get());
            auto *virusuri = dynamic_cast<dezinfectantVirusuri *>(x.get());
            if (univ!=nullptr){
                eficienta=univ->getEficienta();
            } else if (bacterii!=nullptr){
                eficienta=bacterii->getNrspecii()/pow(10,7);
            }
            else if (fungi!=nullptr){
                eficienta=fungi->getNrspecii()/(15*pow(10,3));
            }
            else if (virusuri!=nullptr){
                eficienta=virusuri->getNrspecii()/pow(10,6);
            }

            if(eficienta>eficientamax) {
                eficientamax = eficienta;
                k=poz;
            }
            poz++;
        }
        cout<<"\nCel mai eficient este dezinfectantul cu numarul "<<k+1<<" cu o eficienta de "<<setprecision(4)<<eficientamax<<"%\n";
        cout<<*d[k]<<endl;
    }


    void option5(){
        int luna;
        double venit=0;
        cout<<"Luna pe care ses doreste aflarea venitului: ";
        cin>>luna;
        for(auto x: achizitii)
            if (x.getData().luna==luna)
                venit+=x.calculareTotal();
        cout<<"Venitul pe luna "<<luna<<" este: "<<venit<<" lei."<<endl;
    }

    void option6(){
        double venitCustom=0;
        for(auto x: achizitii)
            venitCustom+=x.calculareVenitMastiCustom();
        cout<<"Venitul obtinut din mastile chirurgicale cu model este: "<<venitCustom<<" lei."<<endl;
    }

    void option7(){
        for(int i=0;i<d.size();i++)
            cout<<to_string(i+1)+". "<<*d[i]<<endl;
        cout<<"Alegeti numarul dezinfectantului a carui reteta doriti sa o modificati: ";
        int x;
        cin>>x;
        cout<<"Numarul nou de ingrediente: ";
        int n;
        cin>>n;
        string s;
        vector<string> ingrediente, tipsuprafata;
        for(int i=0;i<n;i++) {
            cin >> s;
            ingrediente.push_back(s);
        }
        cout<<"Numarul de specii ucise dupa modificarea formulei chimice: ";
        int nrspecii;
        cin>>nrspecii;
        cout<<"Numar de tipuri de suprafata pe care poate fi aplicat: ";
        cin>>n;
        for(int i=0;i<n;i++) {
            cin >> s;
            tipsuprafata.push_back(s);
        }
        d[x-1]->setIngrediente(ingrediente);
        d[x-1]->setTipsuprafata(tipsuprafata);
        d[x-1]->setNrspecii(nrspecii);
    }

    void option8(){

    }

    void option9(){

    }

    void option10(){
        int an;
        double venit=0, TVA;
        cout<<"Anul pe care se doreste aflarea TVA-ului: ";
        cin>>an;
        for(auto x: achizitii)
            if (x.getData().an==an)
                venit+=x.calculareTotal();
        TVA=venit*19/100;
        cout<<"Venitul pe anul "<<an<<" este: "<<venit<<" lei, iar TVA-ul este in valoare de: "<<TVA<<" lei"<<endl;
    }

    void option11(){
        for(const auto & i : achizitii)
            cout<<i;
    }

    void mainLoop() override {
        while(true){
            int option = chooseOption(1, 12);
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
                option9();
            } else if (option == 10) {
                option10();
            } else if (option == 11) {
                option11();
            } else if (option == 12) {
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