#include <iostream>

using namespace std;

void test(int& v) {
    v = v * 5;
}

int main() {
    int x = 5;
    int* ptr = &x;
    test(x);
    cout << " *ptr = " << *ptr <<" et x =" << x << endl;
    return 0;
}