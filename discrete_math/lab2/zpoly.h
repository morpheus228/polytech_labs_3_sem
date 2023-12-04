#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

#include "bool_func.h"

using namespace std;


class ZPoly {

private:
    BoolFunc* m_func;
    vector<bool> m_values;

    void GenerateValues() {
        vector<bool> row(m_func->m_vector); 

        for (int i = pow(2, m_func->m_varsCount) - 1; i > 0; i--) {
            m_values.push_back(row[0]);
            row.clear();
            for (int j = 0; j < i; j++) row.push_back(row[j] ^ row[j+1]);
        }

        m_values.push_back(row[0]);
    }

public:
    ZPoly(BoolFunc* func) {
        m_func = func;
        GenerateValues();
    }
    
    string Formula(vector<string> vars) {
        if (vars.size() != m_func->m_varsCount) throw "Mismatch of the number of variables!"; 

        string formula("");

        for (int i = 0; i < m_values.size(); i++) {
            if (m_values[i]) {

                if (i == 0) {
                    formula += "1";
                    continue;
                }

                string summand("");

                for (int j = 0; j < m_func->m_varsCount; j++) {
                    if ((i & (1 << j)) != 0) summand += vars[m_func->m_varsCount - j - 1];
                }

                formula = formula + " + " + summand;
            }
        }

        if (formula == string("")) return "0";
        return formula;
    }

    bool Calculate(vector<bool> varsValues) {
        int value = 0;
        bool result = false;

        for (int i = 0; i < varsValues.size(); ++i) {
            value = (value << 1) | varsValues[i];
        }

        for (int i = 0; i < m_values.size(); i++) {
            if (i == 0) result ^= 1;
            else if (m_values[i]) result = result ^ ((i & value & i) != 0);
        }

        return result;
    }
};
