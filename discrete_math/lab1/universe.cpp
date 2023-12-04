#include "universe.h"


Universe::Universe() {
    m_bitness = GetBitness();
    m_values = GenerateValues(m_bitness);
    m_mults = GenerateMults();
    m_power = count_if(m_mults.begin(), m_mults.end(), [](unsigned int num){return num != 0;});
}


Universe::~Universe() {}


vector<unsigned int> Universe::GenerateValues(unsigned int bitness) {
    if (bitness == 0) return vector<unsigned int>();
   
    if (bitness == 1) return  vector<unsigned int>{0, 1};

    if (bitness > 1) {
        vector<unsigned int> values = GenerateValues(bitness - 1);
        int mask = 1 << (bitness - 1);

        for (int i = pow(2, bitness - 1) - 1; i >= 0; i--) {
            values.push_back(values[i] | mask);
        }

        return values;
    }
    
    throw -1;
}

vector<unsigned int> Universe::GenerateMults() {
    vector<unsigned int> mults;

    if (m_bitness > 0) {
        for (int i = 0; i < pow(2, m_bitness); i++) {
            mults.push_back(1 + rand() % MAX_UNIVERSE_MULTIPLICITY);
        }
    }

    return mults;
}


void Universe::PrintValues() {
    if (m_bitness == 0) {
        cout << "[]" << endl;
        return;
    }

    for (int i = 0; i < pow(2, m_bitness); i++) {
        BitsPrint(m_values[i], m_bitness);
        cout << "\n";
    }
}


void Universe::Print() {
    if (m_mults.size() == 0) {
        cout << "/// Universe is an empty set ///" << endl;
    }

    else {
        cout << endl << "/// Universe (power = " << m_power << ") ///" << endl;

        for (unsigned int i = 0; i < m_mults.size(); i++) {
            cout << m_mults[i] << " ";
        }
    }
}

unsigned int Universe::GetBitness() {
    unsigned int bitness;

    cout << "Enter Universe's bitness (0 <= bitness <= " << MAX_UNIVERSE_BITNESS << "): " << endl;

    while (true) {
        bitness = GetNumber();

        if (bitness < 0 || bitness > MAX_UNIVERSE_BITNESS) {
            cout << "Error! Attention: 0 < bitness <= " << MAX_UNIVERSE_BITNESS << endl;
        }

        else return bitness;
    }
}


