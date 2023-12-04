#pragma once

#include "utils.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_UNIVERSE_BITNESS = 61;
const int MAX_UNIVERSE_MULTIPLICITY = 50;


class Universe {
private:    
    vector<unsigned int> GenerateValues(unsigned int n);
    vector<unsigned int> GenerateMults();

public:
    unsigned int m_bitness;
    unsigned int m_power;

    vector<unsigned int> m_values;
    vector<unsigned int> m_mults;

    Universe();
    ~Universe();

    void PrintValues();
    void Print();

    unsigned int GetBitness();
};

