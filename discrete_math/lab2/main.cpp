#include <iostream>
#include <vector>
#include <string>

#include "bool_func.h"
#include "sdnf.h"
#include "sknf.h"
#include "zpoly.h"

using namespace std;


int main() {
    BoolFunc func_0(vector<bool> {0, 0, 0, 0, 0, 0, 0, 0});
    BoolFunc func_1(vector<bool> {1, 1, 1, 1, 1, 1, 1, 1});
    BoolFunc func_2(vector<bool> {1,0,1,1,0,1,0,1});

    vector<bool> values {1, 0, 1};

    SDNF sdnf(&func_2);
    cout << sdnf.Formula(vector<string> {"x", "y", "z"}) << endl;
    cout << sdnf.Calculate(values) << endl;

    SKNF sknf(&func_2);
    cout << sknf.Formula(vector<string> {"x", "y", "z"}) << endl;

    ZPoly zpoly(&func_2);
    cout << zpoly.Calculate(values) << endl;
    cout << zpoly.Formula(vector<string> {"x", "y", "z"}) << endl;

    return 0;
}

