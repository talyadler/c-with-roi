#include <iostream> 
#include <functional>

void activate(std::function<void()> f) {
    f();
}

void activate2(std::function<void(int)> f, int x) {
    f(x);
}

int main() {
    auto f = [](){ std::cout << "This is f activated" << std::endl; };
    activate(f);
    auto g = [](int x){ std::cout << "The input of g is '" << x << "'" << std::endl; };
    activate2(g, 6);

    int x = 5;
    auto h = [x](int y){ std::cout << "x (from main = " << x << ") + y (given = " << y << ") = " << x + y << std::endl; };
    activate2(h, 6);
    std::cout << "x = " << x << std::endl;
    auto j = [&x](int y){ std::cout << "x (from main = " << x << ") + y (given = " << y << ") = " << x + y << std::endl; x = 12;};
    activate2(j, 6);
    std::cout << "x = " << x << std::endl;
}
