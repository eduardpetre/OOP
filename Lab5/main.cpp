#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Nota {
    int value;
    string subject;

    Nota(int value, const string &subject) : value(value), subject(subject) {}
};

class PersoanaEvaluata {
protected:
   vector<Nota> note;
public:
   PersoanaEvaluata(const vector<Nota> &note) : note(note) {}
   double mean() {
       double sum = 0;
       for(auto nota : note) {
           sum += nota.value;
       }
       return sum / note.size();
   }
};

// acestea sunt clasele derivate:
class Pupil : public PersoanaEvaluata { // aceasta este sintaxa pentru „moștenire publică”
private:
   string cycle;
   vector<string> materii;
public:
   Pupil(const vector<Nota> &note, const string &cycle) : PersoanaEvaluata(note), cycle(cycle) {}

   void showGradeSheet() {
       // TODO va afisa toate notele, sub form materie: nota
       for (int i=0;i<note.size();i++){
           cout<<note[i].subject<<" : "<<note[i].value<<endl;
       }
   }
   void gradesGroupedBySubject() {
   // TODO similar cu showGradeSheet, dar daca aveti doua note la aceiasi materie
    for(auto nota: note){
        if(count(materii.begin(),materii.end(),nota.subject)==0)
            materii.push_back(nota.subject);
    }

    for(int i=0;i<materii.size();i++) {
        cout << materii[i] << " : ";
        for (auto nota: note) {
            if (materii[i] == nota.subject)
                cout << nota.value << " ";
        }
        cout<<endl;
    }
   // hint: step-by-step
   //  puteti prima data crea un vector cu toate materiile (vector<string>)
   //  iar dupa aceea parcurgeti cu un prim for subiectele, iar cu un al doilea for parcurgeti toate notele si le afisati pe cele cu acea materie

   // e.g. afisare
   // literature: 10 9
   // mathematics: 8 7 10
    }
};

class Student: public PersoanaEvaluata{
private:
    string nume;
public:
    Student(const vector<Nota> &note, const string &nume) : PersoanaEvaluata(note), nume(nume) {}
};

int main(){
    Pupil a({
        Nota(10,"romana"),
        Nota(8, "matematica"),
        Nota(10, "informatica"),
        Nota(9, "informatica")
    }, "liceal" );
    a.showGradeSheet();
    a.gradesGroupedBySubject();
    return 0;
}