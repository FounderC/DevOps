#include <cassert>
#include <iostream>

int add(int a, int b) {
    return a + b;
}

void testAdd() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testAdd();
    return 0;
}
