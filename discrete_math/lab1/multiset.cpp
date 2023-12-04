#include "multiset.h"


MultiSet::MultiSet(Universe* universe, string name) {
    m_name = name;
    m_universe = universe;

    if (m_universe->m_bitness == 0) {
        m_power = 0;
    }

    else {
        unsigned int fillingMode = GetFillingMode();
        if (fillingMode == 1) FillRandom();
        else if (fillingMode == 0) FillManually();
        else throw -1;
    }
}

MultiSet::MultiSet(Universe* universe, vector<unsigned int> mults, string name) {
    m_name = name;
    m_universe = universe;
    m_mults = mults;
    m_power = reduce(m_mults.begin(), m_mults.end());
}

MultiSet::~MultiSet() {}


void MultiSet::FillRandom() {
    m_mults.resize(pow(2, m_universe->m_bitness));
    m_power = GetPower(m_universe->m_power);

    vector<unsigned int> unfilledIndexes;

    for (unsigned int i = 0; i < m_power; i++) {
        unfilledIndexes = GetUnfilledIndexes();
        unsigned int index = unfilledIndexes[rand() % unfilledIndexes.size()];
        m_mults[index] = (rand() % (m_universe->m_mults[index] + 1)) + 1;
    }
}

void MultiSet::FillManually(){ 
    m_mults.resize(pow(2, m_universe->m_bitness));

    for (unsigned int i = 0; i < m_mults.size(); i++) {
        m_mults[i] = GetMult(i, m_universe->m_mults[i]);
    }

    m_power = count_if(m_mults.begin(), m_mults.end(), [](unsigned int num){return num != 0;});
}

vector<unsigned int> MultiSet::GetUnfilledIndexes() const {
    vector<unsigned int> unfilledIndexes;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        if (m_mults[i] == 0) {
            unfilledIndexes.push_back(i);
        }
    }
    return unfilledIndexes;
}

void MultiSet::Print() const {
    if (m_mults.size() == 0) {
        cout << "/// Multiset" << m_name << " is empty multiset ///" << endl;
    }

    else {
        cout << "/// Multiset" << m_name << " (power = " << m_power << ") ///" << endl;
        PrintValues();
    }
}

void MultiSet::PrintValues() const {
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        cout << m_mults[i] << " ";
    }
}

MultiSet MultiSet::operator!() const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        mults.push_back(m_universe->m_mults[i] - m_mults[i]);
    }
    return MultiSet(m_universe, mults);
}
MultiSet MultiSet::operator|(const MultiSet& other) const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        mults.push_back(max(m_mults[i], other.m_mults[i]));
    }
    return MultiSet(m_universe, mults);
}
MultiSet MultiSet::operator&(const MultiSet& other) const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        mults.push_back(min(m_mults[i], other.m_mults[i]));
    }
    return MultiSet(m_universe, mults);
}
MultiSet MultiSet::operator^(const MultiSet& other) const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        mults.push_back(abs(static_cast<int>(m_mults[i] - other.m_mults[i])));
    }
    return MultiSet(m_universe, mults);
}
MultiSet MultiSet::operator-(const MultiSet& other) const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        mults.push_back(max(static_cast<int>(m_mults[i] - other.m_mults[i]), 0));
    }
    return MultiSet(m_universe, mults);
}
MultiSet MultiSet::operator+(const MultiSet& other) const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        mults.push_back(min(static_cast<int>(m_mults[i] + other.m_mults[i]), static_cast<int>(m_universe->m_mults[i])));
    }
    return MultiSet(m_universe, mults);
}
MultiSet MultiSet::operator*(const MultiSet& other) const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        mults.push_back(min(static_cast<int>(m_mults[i] * other.m_mults[i]), static_cast<int>(m_universe->m_mults[i])));
    }
    return MultiSet(m_universe, mults);
}
MultiSet MultiSet::operator/(const MultiSet& other) const {
    vector<unsigned int> mults;
    for (unsigned int i = 0; i < m_mults.size(); i++) {
        if (other.m_mults[i] == 0) mults.push_back(0);
        else mults.push_back(static_cast<int>(m_mults[i] / other.m_mults[i]));
    }
    return MultiSet(m_universe, mults);
}


unsigned int MultiSet::GetFillingMode() const {
    cout << "Enter filling mode for MultiSet (0 - manually; 1 - auto)" << endl;
    unsigned int fillingMode;

    while (true) {
        fillingMode = GetNumber();

        if (fillingMode != 0 && fillingMode != 1) {
            cout << "Error! Attention: 0 - manually; 1 - auto" << endl;
        }

        else return fillingMode;
    }
}

unsigned int MultiSet::GetPower(unsigned int maxPower) const {
    cout << "Enter MultiSet's power (0 <= power <= " << maxPower << ")" << endl;
    unsigned int power;

    while (true) {
        power = GetNumber();

        if (power < 0 || power > maxPower) {
            cout << "Error! Attention: 0 <= power <= " << maxPower << endl;
        }

        else return power;
    }
}

unsigned int MultiSet::GetMult(unsigned int index, unsigned int maxValue) const {
    cout << "Enter multiplicity of " << index << "th element (0 <= value <= " << maxValue << ")" << endl;
    unsigned int value;

    while (true) {
        value = GetNumber();

        if (value < 0 || value > maxValue) {
            cout << "Error! Attention: 0 <= value <= " << maxValue << endl;
        }

        else return value;
    }
}