#include <iostream>
#include "Fuzzy.h"

using namespace std;

int main() {
    double kol_rublja;
    double razina_zaprljanosti;

    string kol_deterdenta_fuzzy;
    double kol_deterdenta;

    cout << "Unesite kolicinu rublja: ";
    cin >> kol_rublja;
    while(kol_rublja < 0 || kol_rublja > 8){
        cout << "Kriva vrijednost! [0, 8]" << endl << "Ponovite unos: ";
        cin >> kol_rublja;
    }

    cout << "Unesite razinu zaprljanosti rublja: ";
    cin >> razina_zaprljanosti;
    while(razina_zaprljanosti < 1 || razina_zaprljanosti > 10){
        cout << "Kriva vrijednost! [1, 10]" << endl << "Ponovite unos: ";
        cin >> razina_zaprljanosti;
    }

    string kol_rublja_fuzzy = fuzzify_laundry(kol_rublja);
    string razina_zaprljanosti_fuzzy = fuzzify_dirty(razina_zaprljanosti);

    if(kol_rublja_fuzzy == "malo" && razina_zaprljanosti_fuzzy == "malo") kol_deterdenta_fuzzy = "malo";
    if(kol_rublja_fuzzy == "srednje" && razina_zaprljanosti_fuzzy == "malo") kol_deterdenta_fuzzy = "srednje";
    if(kol_rublja_fuzzy == "puno" && razina_zaprljanosti_fuzzy == "malo") kol_deterdenta_fuzzy = "srednje";
    if(kol_rublja_fuzzy == "malo" && razina_zaprljanosti_fuzzy == "puno") kol_deterdenta_fuzzy = "srednje";
    if(kol_rublja_fuzzy == "srednje" && razina_zaprljanosti_fuzzy == "puno") kol_deterdenta_fuzzy = "puno";
    if(kol_rublja_fuzzy == "puno" && razina_zaprljanosti_fuzzy == "puno") kol_deterdenta_fuzzy = "puno";

    kol_deterdenta = defuzzify(kol_deterdenta_fuzzy);

    cout << "Potrebno je " << kol_deterdenta << "g praska za pranje rublja." << endl;

    return 0;
}