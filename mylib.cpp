#include "mylib.h"

double vidurkiosk(const vector<int>& pazymiai) {
    int dydis = pazymiai.size();
    if (dydis == 0) {
        return 0.0;
    }
    int sum;
    for (int num : pazymiai) {
        sum += num;
    }
    return static_cast<double>(sum) / dydis;
}

double medianossk(const vector<int>& pazymiai) {
    vector<int> surusiuota = pazymiai;
    sort(surusiuota.begin(), surusiuota.end());
    int dydis = surusiuota.size();
    if (dydis % 2 == 0) {
        int vid1 = surusiuota[dydis / 2 - 1];
        int vid2 = surusiuota[dydis / 2];
        return static_cast<double>(vid1 + vid2) / 2.0;
    } else {
        return static_cast<double>(surusiuota[dydis / 2]);
    }
}

void generuoti(studentas &Studentas) {
    int ndskaicius = rand() % 11;
    cout << "Pazymiai: ";
    for (int i = 0; i < ndskaicius; i++) {
        int pazymys = rand() % 11;
        cout << pazymys<< " ";
        Studentas.pazymiai.push_back(pazymys);
    }
    cout << endl;
    Studentas.egzaminas = rand() % 11;
    cout << "Egzamino pazymys: "<< Studentas.egzaminas<<endl;

}


void mano_funkcija() {
    int studsk;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studsk;
    studentas Studentas;
    int skaicius;
    cout << "Jei norite galutini bala skaiciuti pagal mediana rasykite 1, jei norite pagal mediana rasykite 2:";
    cin >> skaicius;
    vector<studentas> grupe;

    for (int j = 0; j < studsk; j++) {
        cout << "Ivesk varda ir pavarde: ";
        cin >> Studentas.vardas >> Studentas.pavarde;

        int ivedimas;
        cout << "Jei norite ivesti pazymius  rasykite 1, jei norite, kad sugeneruotu rasykite 2:";
        cin >> ivedimas;
        if (ivedimas == 1){
            cout << "Iveskite pazymi (baigti su -1): ";
            int k;
            while (cin >> k && k != -1 ) {
                Studentas.pazymiai.push_back(k);
            }
            cout << "Iveskite egzamina: ";
            cin >> Studentas.egzaminas;
        }else if (ivedimas == 2) {
            generuoti(Studentas);
            }

        if (skaicius == 1) {
            double galutinis = 0.4 * medianossk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
            Studentas.rezultatas = galutinis;
        } else if (skaicius == 2) {
            double galutinis1 = 0.4 * vidurkiosk(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
            Studentas.rezultatas = galutinis1;
        }

        grupe.push_back(Studentas);
        Studentas.pazymiai.clear();
    }

    if (skaicius == 1) {
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Med.)"  << endl;
    cout << string(55, '-') << endl;
    for (auto& a : grupe) {
        cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
        cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
        }
    } else if (skaicius == 1) {
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)"<< endl;
        cout << string(55, '-') << endl;
        for (auto& a : grupe) {
            cout << left << setw(20) << a.vardas << setw(20) << a.pavarde;
            cout << fixed << setprecision(2) << setw(15) << a.rezultatas << endl;
        }
    }
}

