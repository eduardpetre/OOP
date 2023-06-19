#include<iostream>
#include<algorithm>
using namespace std;

class Film{
private:
    string titlu;
    int like;
public:
    void citire(){
        getline(cin>>ws, titlu);
        cin>>like;
    }

    Film(){
        titlu="";
    }

    Film(string _titlu, int _like){
        titlu=_titlu;
        like=_like;
    }

    int getLike(){
        return like;
    }

    void getTitlu(){
        cout<<titlu<<endl;
    }
};

int compare(Film x, Film y){
    return x.getLike()>y.getLike();
}

void afisarePopulare(int n, Film filme[], int k){
    sort(filme, filme+n, compare);
    for(int i=0;i<k;i++)
        filme[i].getTitlu();
}

int main(){
    int n, k;
    cin>>n;
    Film filme[101];
    for (int i=0;i<n;i++)
        filme[i].citire();
    cin>>k;
    afisarePopulare(n, filme, k);
    return 0;
}