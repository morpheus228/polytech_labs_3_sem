#include "universe.h"
#include "multiset.h"


int main() {
    srand(time(0));

    Universe universe;

    cout << "\nUniverse's Values:" << endl;
    universe.PrintValues();
    cout << "\n";

    universe.Print();
    cout << "\n\n";

    MultiSet A(&universe);
    A.Print();
    cout << "\n\n";

    MultiSet B(&universe);
    B.Print();
    cout << "\n\n";

    cout << "!A" << endl;
    (!A).Print();
    cout << "\n\n";

    cout << "!B" << endl;
    (!B).Print();
    cout << "\n\n";

    cout << "A ⋂ B" << endl;
    (A & B).Print();
    cout << "\n\n";

    cout << "A ⋃ B" << endl;
    (A | B).Print();
    cout << "\n\n";

    cout << "A - B" << endl;
    (A - B).Print();
    cout << "\n\n";

    cout << "B - A" << endl;
    (B - A).Print();
    cout << "\n\n";

    cout << "A ^ B" << endl;
    (A ^ B).Print();
    cout << "\n\n";

    cout << "A + B" << endl;
    (A + B).Print();
    cout << "\n\n";
    
    cout << "A * B" << endl;
    (A * B).Print();
    cout << "\n\n";

    cout << "A \\ B" << endl;
    (A / B).Print();
    cout << "\n\n";

    cout << "B \\ A" << endl;
    (B / A).Print();
    cout << "\n\n";

    return 0;
}


// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<unsigned int> vec;
//     std::cout << vec.max_size() << std::endl;
//     return 0;
// }

