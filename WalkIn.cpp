#include <iostream>

#include "List.h"
#include "Patient.h"

using namespace std;

int main() {
    auto ls = new List();

    const Patient *p = new Patient("9234567890");
    const Patient *p2 = new Patient("3456789012");
    const Patient *p3 = new Patient("2345678901");
    const Patient *p4 = new Patient("6789012345");

    ls->insert(*p);
    ls->insert(*p2);
    ls->insert(*p4);
    ls->insert(*p3);

//    ls->remove(*p);
//    ls->removeAll();

//    cout << "search result is: " << ls->search(*p)->getCareCard() << endl;

    ls->printList();

    return 0;
}
