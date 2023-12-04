// #include "bool_func.h"


// BoolFunc::BoolFunc(vector<bool> vector) {
//     m_vector = vector;
//     m_varsCount = static_cast<int>(log2(vector.size()));
// }

// string BoolFunc::SDNF() {
//     string sdnf = "(";

//     for (int i = 0; i < pow(2, m_varsCount); i++) {
//         if (!m_vector[i]) {

//             for (int j = 0; j < m_varsCount; j++) {
//                 int mask = pow(2, m_varsCount - j - 1);

//                 if (i & mask) {
//                     sdnf = sdnf + "~" + ALPHABET[j] + " V ";
//                 }
//                 else {
//                     sdnf = sdnf + ALPHABET[j] + " V ";
//                 }
//             }
//             sdnf = sdnf.substr(0, sdnf.size() - 3) + ") ∧ (";
//         }
//     }

//     sdnf = sdnf.substr(0, sdnf.size() - 5);
//     return sdnf;
// }


// string BoolFunc::SKNF() {
//     string sknf = "";

//     for (int i = 0; i < pow(2, m_varsCount); i++) {
//         if (m_vector[i]) {

//             for (int j = 0; j < m_varsCount; j++) {
//                 int mask = pow(2, m_varsCount - j - 1);

//                 if (i & mask) {
//                     sknf = sknf + ALPHABET[j];
//                 }
//                 else {
//                     sknf = sknf + "~" + ALPHABET[j];
//                 }
//             }

//             sknf += " V ";
//         }
//     }

//     sknf = sknf.substr(0, sknf.size() - 3);
//     return sknf;
// }


// string BoolFunc::ZHPoly() {
//     string zhpoly = "";

//     vector<bool> coeffs; 
//     vector<bool> row(m_vector); 

//     for (int i = pow(2, m_varsCount) - 1; i > 0; i--) {
//         coeffs.push_back(row[0]);
//         row.clear();
//         for (int j = 0; j < i; j++) row.push_back(row[j] ^ row[j+1]);
//     }

//     coeffs.push_back(row[0]);

//     return zhpoly;
// }

// vector<string> BoolFunc::GenerateZHPolyMembers() {
//     // vector<string> polyMemmbers {"1"};

//     // for (int i = 0; i < m_varsCount; i++) {

//     // }
// }