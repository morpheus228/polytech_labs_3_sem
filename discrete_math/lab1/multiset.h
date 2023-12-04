#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <bitset>

#include "utils.h"
#include "universe.h"

using namespace std;


class MultiSet {
private:
    string m_name;
    Universe* m_universe;
    vector<unsigned int> m_mults;
    
    void FillRandom();
    void FillManually();

    vector<unsigned int> GetUnfilledIndexes() const;

public:
    unsigned int m_power;

    MultiSet(Universe* universe, vector<unsigned int> mults, string name = "");
    MultiSet(Universe* universe, string name = "");
    ~MultiSet();

    MultiSet operator!() const; // complement - дополнение
    MultiSet operator&(const MultiSet& other) const; // intersection - пересечение
    MultiSet operator|(const MultiSet& other) const; // union - объединение
    MultiSet operator^(const MultiSet& other) const; // symmetric difference - симметрическая разность
    MultiSet operator-(const MultiSet& other) const; // арифметическая разность
    MultiSet operator+(const MultiSet& other) const; // арифметическое сложение
    MultiSet operator*(const MultiSet& other) const; // арифметическое умножение
    MultiSet operator/(const MultiSet& other) const; // арифметическое деление

    void Print() const;
    void PrintValues() const;

    unsigned int GetFillingMode() const;
    unsigned int GetPower(unsigned int maxPower) const;
    unsigned int GetMult(unsigned int index, unsigned int maxValue) const;
};

