#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

class Carte{
private:
    string titlu;
    int n,pag;
public:
    void citeste(){
        getline(cin>>ws, titlu);
        cin>>n>>pag;
    }

    Carte(){
        titlu="";
    }

    Carte(string _titlu, int _n, int _pag) {
        titlu = _titlu;
        n = _n;
        pag = _pag;
    }

    void setPaginaCurenta(int _pag){
        if(_pag>n)
            cout<<"Nu poti sari la pagina "<<_pag<<" din "<<n<<", deoarece nu exista!";
        else
            pag=_pag;
    }

    int getPaginaMaxima(){
        return n;
    }

    void afiseaza(){
        cout<<"Cartea cu titlul "<<titlu<<" sta deschisa la pagina "<<pag<<" din "<<n<<endl;
    }

};

int main() {
    Carte c;
    c.citeste();
    c.afiseaza();
    c.setPaginaCurenta(30);
    c.afiseaza();

    c.setPaginaCurenta(c.getPaginaMaxima() + 1);
    return 0;
}
