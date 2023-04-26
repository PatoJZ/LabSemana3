#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct lista{
    int data;
    lista *next;    
};
void getintegerinformaction(){
    int number;
    string string;
    cout << "coloca un numero<< ";
    cin >> number;
    getchar();
    cout << " coloca una palabra ";
    getline(cin,string);
    cout << "number: " << number << endl;
    cout << "string: " << string << endl;
}
void getAverageGrades(){
    int grades;
    int numberofgrades;
    int i;
    int promedio = 0;
    cout << "coloca la cantidad de notas<< ";
    cin >> numberofgrades;
    for (i = 0; i < grades; i++)
    {
        cout << "coloca las notas<< ";
        cin >> grades;
        promedio += grades;
    }
    promedio = promedio/numberofgrades;

    cout << "el promedio es" << grades << endl;

}
void returnstringlenght(){
    string str;
    getchar();
    cout<< "coloca una palabra ";
    getline(cin,str);
    cout<< "la longitd es "<< str.length() << endl;
}
void numberarray(){
    int 



}

int main(){

    cout << "hola" << endl;
    cout << "hola" << endl;
    //ejercicio1
    getintegerinformaction();
    //ejercicio2
    getAverageGrades();
    //ejercicio3
    returnstringlenght();
    //ejercicio4



    return 0;
}