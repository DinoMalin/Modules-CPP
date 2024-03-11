#include "Identify.hpp"

int main() {
    std::srand(std::time(0));
    Base *testOne = generate();
    Base *testTwo = generate();
    Base *testThree = generate();

    identify(testOne);
    identify(testTwo);
    identify(testThree);

    A a;
    B b;
    C c;

    identify(a);
    identify(b);
    identify(c);
    
    delete testOne;
    delete testTwo;
    delete testThree;
}
