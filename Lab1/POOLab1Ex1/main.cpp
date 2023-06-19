#include <iostream>
using namespace std;

struct data{
   int an, luna, zi;
}x,y;

int main(){
    cin>>x.zi>>x.luna>>x.an;
    cin>>y.zi>>y.luna>>y.an;

//    a)
    if (x.an > y.an)
    cout<<x.zi<<"."<<x.luna<<"."<<x.an<<" este mai mare";
    else if (x.an < y.an)
        cout<<y.zi<<"."<<y.luna<<"."<<y.an<<" este mai mare";
    else if (x.luna > y.luna)
        cout<<x.zi<<"."<<x.luna<<"."<<x.an<<" este mai mare";
    else if (x.luna < y.luna)
        cout<<y.zi<<"."<<y.luna<<"."<<y.an<<" este mai mare";
    else if (x.zi > y.zi)
        cout<<x.zi<<"."<<x.luna<<"."<<x.an<<" este mai mare";
    else if (x.zi < y.zi)
        cout<<y.zi<<"."<<y.luna<<"."<<y.an<<" este mai mare";
    else cout<<"Datele sunt egale";

    cout<<endl;

//    b)
    if(abs(x.an-2022) < abs(y.an-2022))
        cout<<x.zi<<"."<<x.luna<<"."<<x.an<<" este mai apropiata";
    else if (abs(x.an-2022) > abs(y.an-2022))
        cout<<y.zi<<"."<<y.luna<<"."<<y.an<<" este mai apropiata";
    else if (abs(x.luna - 2) < abs(y.luna - 2))
        cout << x.zi << "." << x.luna << "." << x.an << " este mai apropiata";
    else if (abs(x.luna - 2) > abs(y.luna - 2))
        cout << y.zi << "." << y.luna << "." << y.an << " este mai apropiata";
    else if (abs(x.zi - 21) < abs(y.zi - 21))
        cout << x.zi << "." << x.luna << "." << x.an << " este mai apropiata";
    else if (abs(x.zi - 21) > abs(y.zi - 21))
        cout << y.zi << "." << y.luna << "." << y.an << " este mai apropiata";
    else cout << "Datele sunt la fel de apropiate";

    cout<< " de data de azi, 21.2.2022";
    return 0;
}
