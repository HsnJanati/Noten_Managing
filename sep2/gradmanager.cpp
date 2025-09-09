//
// Created by hjrust on 03.09.25.
//
#include "gradmanager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <fstream>
#include <locale>
#include <string>

using std::cout;
using std::endl;

bool gradmanager::validgrade (const Grade &grade){
    if(grade.note <1.0 || grade.note > 5.0){
        return false;
    }
    return true;
}

bool gradmanager::add_grade(const Grade &grade){
    if(!validgrade(grade)){
        cout<<"falsche Note "<<endl;
    return false;
    }
    grades.push_back(grade);
    return true;
}
bool gradmanager::delete_grade(int matrikelnummer) {
	for (auto it = grades.begin(); it != grades.end(); ++it) {
        if (it->matrikelnummer == matrikelnummer) {
            grades.erase(it);
            return true;
        }
    }
    return false;
}



void gradmanager::print() const {
    if (grades.empty()) {
        cout << "- Keine Eintraege.\n";
        return;
    }
    cout << std::left << std::setw(28) << "Matrikulnummer" << "Note\n";
    cout << std::string(40, '-') << "\n";
    for (const auto& g : grades) {
        cout << std::left << std::setw(28) << g.matrikelnummer << g.note << "\n";
    }
}


double gradmanager::average() const {
    double  sum=0;
    for(const auto  &grade : grades){
        sum += grade.note;
    }
return static_cast<double>(sum / grades.size());}

bool gradmanager::save_csv(const std::string& path) const {
    std::ofstream out(path, std::ios::trunc);
    if (!out) return false;

    out << "Matrikelnummer: Note\n";
    out.setf(std::ios::fixed);
    out << std::setprecision(2);

    for (const auto& g : grades) {
        out << g.matrikelnummer << ':' << g.note << '\n';
    }
    return true;
}

bool gradmanager::load_csv(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;

    std::vector<Grade> tmp;
    std::string line;
    bool first = true;

    std::locale::global(std::locale::classic());

    while (std::getline(in, line)) {
        if (first) {
            first = false;
            if (line.rfind("matrikelnummer;", 0) == 0) continue;
        }
        if (line.empty()) continue;

        std::size_t sep = line.find(';');
        if (sep == std::string::npos) continue;

        std::string sMat = line.substr(0, sep);
        std::string sNote = line.substr(sep + 1);

        for (char& c : sNote) if (c == ',') c = '.';

        try {
            int m = std::stoi(sMat);
            double n = std::stod(sNote);
            tmp.push_back({m, n});
        } catch (...) {
        }
    }

    grades.swap(tmp);
    return true;
}
double gradmanager::bestehquote(){
	if (grades.empty()) {
        cout << "- Keine Eintraege.\n";
        return 0;
    }
	int passed = 0;
	for (const auto& grade : grades) {
		if(grade.note >= 1 && grade.note <= 4){
		passed++;
		}
	}
	return (static_cast<double> (passed)/grades.size())*100;
}




