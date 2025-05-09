#include <iostream>
#include <functional>

int addOne(int x) {
    return x + 1;
}

std::function<int(int)> lambdaAddOne = [](int x) { return x + 1; };
std::function<int(int,int)> lambdaAdd = [](int x, int y) {
    for (int i = 0 ; i < y; i++) {
        x = lambdaAddOne(x);
    }
    return x;
};

int main (){
    std::cout << "2 + 1 = " << addOne(2) << std::endl;
    std::cout << "2 + 1 = " << lambdaAddOne(2) << std::endl;
    std::cout << "3 + 4 = " << lambdaAdd(3,4) << std::endl;
}
