//
// Created by hjrust on 03.09.25.
//
#include "gradmanager.h"
#include <iostream>
#include <limits>
#include <string>

using std::cout ;
using std::cin ;
using std::string;
int main () {
    gradmanager gm;
    while (true) {
        cout << "\n===== Notenverwaltung =====\n";
        cout << "1) Eintrag hinzufuegen\n";
        cout << "2) Alle Eintraege anzeigen\n";
        cout << "3) Durchschnitt berechnen\n";
        cout << "4) Eintrag loeschen\n";
		cout << "5) Bestehenquote \n";
		cout << "6) speichern als (grades.csv) \n";
        cout << "7) Laden (grades.csv )\n";
		cout << "8) Beenden \n";

        cout << "Auswahl: ";
        string choice ;
        cin >> choice ;
        if(choice == "1"){
            Grade g{};
            cout << "Matrikelnummer: ";
            cin >> g.matrikelnummer;
            cout << "Note : ";
            cin >> g.note;

            if (gm.add_grade(g)) {
                cout << " Eingetragen.\n";
            } else {
                cout << " Ungueltige Note (1.0..5.0).\n";
            }
        }
        else if(choice == "2"){
            gm.print();
        }
        else if(choice == "3"){
            if (gm.grades.empty()) {
                cout << "Keine Daten.\n";
            } else {
                double avg = gm.average();
                cout << "Durchschnitt: " << avg << "\n";
            }
       }else if(choice == "4"){
			cout<<"Welche Matrikelnummer : \n";
			int mk ;
			cin >>	mk;
			if(gm.delete_grade(mk)){cout<<"Erfolgreich gelöscht \n"; }else {cout<<"Die Nummer existiert nicht in unserer Tabelle . \n"; }
		}
		else if(choice == "5"){
		cout << "Bestehenquote ist :  ";
		double bq= gm.bestehquote();
		cout  << bq ; cout << "\n";
}


        else if (choice == "8") {
			int Bestaetigung;
			cout << "Sind Sie sicher (yes : 1 , no : 0  ):  \n";
			cin >> Bestaetigung;
			if(Bestaetigung == 1) {cout << "Bye!\n";
            break;}

        }
		else if (choice == "6") {
    if (gm.save_csv("grades.csv")) {
        cout << "Gespeichert nach grades.csv\n";
    } else {
        cout << "Fehler beim Speichern.\n";
    }
}
else if (choice == "7") {
    if (gm.load_csv("grades.csv")) {
        cout << "Geladen (" << gm.grades.size() << " Eintraege)\n";
    } else {
        cout << "Konnte grades.csv nicht laden.\n";
    }
}
else {
            cout << "Unbekannte Auswahl.\n";
        }
        }
return 0;




}