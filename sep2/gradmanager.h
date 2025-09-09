//
// Created by hjrust on 03.09.25.
//

#ifndef SEP2_GRADMANAGER_H
#define SEP2_GRADMANAGER_H
#include "grade.h"
#include <vector>
#include <string>
class gradmanager {

public: std::vector<Grade> grades;
    bool validgrade (const Grade  &grade);

    bool add_grade(const Grade &grade);
    bool delete_grade(int matrikelnummer);
    double average() const;
    void print() const;
	bool save_csv(const std::string& path) const;
    bool load_csv(const std::string& path);
	double bestehquote();


};


#endif //SEP2_GRADMANAGER_H