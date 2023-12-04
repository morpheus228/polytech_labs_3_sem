#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class BoolFunc {

public:
    vector<bool> m_vector;
    int m_varsCount;

    BoolFunc(vector<bool> vector) {
        m_vector = vector;
        m_varsCount = static_cast<int>(log2(vector.size()));
    };

    friend class SDNF; 
    friend class SKNF;
    friend class ZPoly;
};
