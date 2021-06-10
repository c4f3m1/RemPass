#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <clocale>

using namespace std;

string question(const string &, const string &);
void exclusive(const string &, string);
void inclusive(const string &, string);


int main(int argc, char const *argv[]) {

    system("clear");
    setlocale(LC_CTYPE,"Spanish");

    string old_pass, characters, type;

    old_pass = question("Introduce la contraseña utilizando _ en los huecos que desconozcas, ejemplo: Con_ra_e_a", "Contraseña: ");
    characters = question("Introduce los caracteres que pueden tomar los huecos", "Caracteres: ");
    type = question("¿Es exclusiva?", "Si / No: ");

    if (type == "Si") exclusive(old_pass, characters);
    if (type == "No") inclusive(old_pass, characters);

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
PERMUTATION WITH REPETITIONS
n! = n * (n-1)*(n-2)*...*3*2*1
*/
void exclusive(const string &old_pass, string characters){

    string match;
    int num = 0;
    sort(characters.begin(), characters.end());

    do {
        match = old_pass;
        for (int i = 0; i < (int) characters.length(); i++){
            for (int j = 0; j < (int) match.length(); j++){
                if (match[j] == '_') {
                    match[j] = characters[i];
                    break;
                }
            }
        }
        cout << "Posibilidad nº " << ++num << " --> " << match << '\n';
    } while (next_permutation(characters.begin(), characters.end()));

}

/*
PERMUTATION WITH REPETITIONS
n^k
*/
void inclusive(const string &old_pass, string characters){

    string test = "123";
    int huecos = 3;

    for(int h = 0; h < ((int) test.length()^huecos); h++){
        for (int i = 0; i < (int) test.length(); i++){
            for (int j = 0; j < huecos; j++){
                cout << test[j];
            }
            cout << endl;
        }
    }
}
