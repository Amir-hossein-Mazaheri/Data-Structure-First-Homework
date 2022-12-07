#include <iostream>

#include "List.h"
#include "Patient.h"

using namespace std;

int main() {
    auto ls = new List();
    const Patient *p = new Patient("1234567899");
    const Patient *p2 = new Patient();
    const Patient *p3 = new Patient("9987654321");

    ls->insert(*p);
    ls->insert(*p2);
    ls->insert(*p3);

//    ls->remove(*p);
//    ls->removeAll();

    cout << "search result is: " << ls->search(*p)->getCareCard() << endl;

    ls->printList();

    return 0;
}
