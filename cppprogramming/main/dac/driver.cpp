#include <iostream>

typedef unsigned int uint;

// forward declaration
uint climbing(const uint *heights, uint length, uint rest, uint limit);

int main() {
    std::cout << "Test 1: (expecting 70)" << std::endl;
    uint mountain1[] = {30, 70, 95, 120, 145, 190};
    std::cout << climbing(mountain1, sizeof(mountain1) / sizeof(uint), 10, 210) << std::endl;
    
    std::cout << "Test 2: (expecting 100)" << std::endl;
    uint mountain2[] = {50, 100};
    std::cout << climbing(mountain2, sizeof(mountain2) / sizeof(uint), 1, 100) << std::endl;

    std::cout << "Test 3: (expecting 50)" << std::endl;
    uint mountain3[] = {50, 99};
    std::cout << climbing(mountain3, sizeof(mountain3) / sizeof(uint), 1, 100) << std::endl;

    std::cout << "Test 4: (expecting 12)" << std::endl;
    uint mountain4[] = {1, 7, 9, 12, 13, 14, 15, 18, 20, 22, 23, 28, 30, 31, 32};
    std::cout << climbing(mountain4, sizeof(mountain4) / sizeof(uint), 5 ,45) << std::endl;

    std::cout << "Test 5: (expecting 13)" << std::endl;
    uint mountain5[] = {13, 14, 15, 18, 20, 22, 23, 28, 30, 31, 32, 36, 40, 42};
    std::cout << climbing(mountain5, sizeof(mountain5) / sizeof(uint), 2 ,48) << std::endl;
    return 0;
}
