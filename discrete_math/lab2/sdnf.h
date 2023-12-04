#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

#include "bool_func.h"

using namespace std;


class SDNF {

private:
    BoolFunc* m_func;
    vector<vector<bool>> m_values;

    void GenerateValues() {
        for (int i = 0; i < pow(2, m_func->m_varsCount); i++) {
            if (m_func->m_vector[i]) {
                vector<bool> row;

                for (int j = 0; j < m_func->m_varsCount; j++) {
                    int mask = pow(2, m_func->m_varsCount - j - 1);
                    row.push_back(i & mask);
                };

                m_values.push_back(row);
            }
        }
    }

public:
    SDNF(BoolFunc* func) {
        m_func = func;
        GenerateValues();
    }

    string Formula(vector<string> vars) {
        if (vars.size() != m_func->m_varsCount) throw "Mismatch of the number of variables!"; 

        if (m_values.size() == 0) return "0";

        string formula("");

        for (int i = 0; i < m_values.size(); i++) {
            for (int j = 0; j < m_func->m_varsCount; j++) {
                if (m_values[i][j]) formula = formula + vars[j];
                else formula = formula + "~" + vars[j];
            }
            formula = formula + " V ";
        }

        formula = formula.substr(0, formula.size() - 3);
        return formula;
    };

    bool Calculate(vector<bool> varsValues) {
        if (varsValues.size() != m_func->m_varsCount) throw "Mismatch of the number of variables!"; 

        for (int i = 0; i < m_values.size(); i++) {
            bool success = true;

            for (int j = 0; j < m_func->m_varsCount; j++) {
                if (m_values[i][j] != varsValues[j]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return true;
            }
        }

        return false;
    };
};
