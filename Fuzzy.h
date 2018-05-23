//
// Created by filip on 23.05.18..
//

#ifndef FUZZYLOGIC_FUZZY_H
#define FUZZYLOGIC_FUZZY_H

#include <string>

std::string fuzzify_laundry(double value)
{
    if (value < 3.0) return "malo";
    else if (value >= 3.0 && value < 5.0) return "srednje";
    else return "puno";
}

std::string fuzzify_dirty(double value)
{
    if (value < 5.0) return "malo";
    else return "puno";
}

double defuzzify(const std::string& value)
{
    if (value == "malo") {
        return 30.0;
    } else if (value == "srednje") {
        return 90.0;
    } else {
        return 150.0;
    }
}


#endif //FUZZYLOGIC_FUZZY_H
