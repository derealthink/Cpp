
#include "Span.hpp"

#include <iostream>
#include <vector>

static void basicTest() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void rangeTest() {
    std::vector<int> data;
    for (int i = 0; i < 10000; ++i) {
        data.push_back(i);
    }

    Span sp(10000);
    sp.addNumber(data.begin(), data.end());
    std::cout << "range shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "range longest: " << sp.longestSpan() << std::endl;
}

int main() {
    try {
        basicTest();
        rangeTest();
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}


//improve clarity of tests clearly printing out what is which, which tests what for evaluators