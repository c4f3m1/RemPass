#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <clocale>

using namespace std;

string question(const string &, const string &);
void exclusiva(const string &, string);
void inclusiva(const string &, string);


int main(int argc, char const *argv[]) {

    system("clear");
    setlocale(LC_CTYPE,"Spanish");

    string old_pass, caracteres, tipo;

    old_pass = question("Introduce la contraseña utilizando _ en los huecos que desconozcas, ejemplo: Con_ra_e_a", "Contraseña: ");
    caracteres = question("Introduce los caracteres que pueden tomar los huecos", "Caracteres: ");
    tipo = question("¿Es exclusiva?", "Si / No: ");

    if (tipo == "Si") exclusiva(old_pass, caracteres);
    if (tipo == "No") inclusiva(old_pass, caracteres);

    return 0;
}


string question(const string &question, const string &subquestion) {

    string response;

    cout << endl << "_______________________________________________________________________" << endl;
    cout << endl << question << endl;
    cout << endl << subquestion;
    cin >> response;
    cout << endl << "_______________________________________________________________________" << endl;

    return response;
}

/*
[ABC] x 3 -> ABC ACB BAC BCA CAB CBA
PERMUTATION n! = n * (n-1)*(n-2)*...*3*2*1
*/
void exclusiva(const string &old_pass, string caracteres){

    string match;
    int num = 0;
    sort(caracteres.begin(), caracteres.end());

    do {
        match = old_pass;
        for (int i = 0; i < (int) caracteres.length(); i++){
            for (int j = 0; j < (int) match.length(); j++){
                if (match[j] == '_') {
                    match[j] = caracteres[i];
                    break;
                }
            }
        }
        cout << "Posibilidad nº " << ++num << " --> " << match << '\n';
    } while (next_permutation(caracteres.begin(), caracteres.end()));

}

/*
[ABC] x 3 -> AAA AAB AAC ABA ABB ABC ACA ACB ACC BAA BAB BAC BBA BBB BBC BCA BCB BCC CAA CAB CAC CBA CBB CBC CCA CCB CCC
3 x 3 = 27
*/
void inclusiva(const string &old_pass, string caracteres){

    cout << "Futuras implementaciones" << endl;

}
