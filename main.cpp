#include <iostream>
#include "avltree.h"
using namespace std;

int main() {
    Tree tester(nullptr, "Nick", 55182448);
    cout << tester.root->name << endl;
    tester.insert(tester.root, "Bob Man", 12345678);
    return 0;
}