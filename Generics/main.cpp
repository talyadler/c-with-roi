#include <iostream>

template<typename T>
T max(T x, T y) {
    return x < y ? y : x;
}


template<typename T>
class Array {
  public:
    int length;
  private:
    T *start;

  public:
    Array() {}

    Array(int length) : length(length), start(new T[length]) {
    }

    T get(int index) {
        return (index < 0 || index >= length) ? throw std::out_of_range("Index out of range") : /*this->*/start[index];
    }

    void set(T val, int index) {
        (index < 0 || index >= length) ? printf("cant set. index %d is out of bounds; array set to %d\n", index,length) : start[index] = val;
        return;
    }

    Array<T>& operator=(/*Array<T>* this*/const Array<T>& o) {
        length = o.length;
        start = new T[length];
        for (int i = 0 ; i < length ; i++) 
            start[i] = o.start[i];
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
        out << "[";
        for (int i = 0; i < arr.length - 1; i++)
            out << arr.start[i] << ", ";
        if (arr.length - 1 >= 0) out << arr.start[arr.length - 1];
        return out  << "]";
    }
};

int main() {
    //std::cout << max("3123213", "5") << std::endl; // "<>" is a char* type. ie, returnes the address and then dereference the value in the address
    //std::cout << max('3', '5') << std::endl;
    //std::cout << max(1, 5) << std::endl;
    //std::cout << max(1.2, 6.2) << std::endl;
    //std::cout << max(7.2, 5.) << std::endl;
    
    Array<int> intArr(4);
    intArr.set(4,3);
    intArr.set(9,1);
    intArr.set(6,2);
    intArr.set(3,0);
    intArr.set(100,100);
    
    try {
        std::cout << "intArr[100] = " << intArr.get(100) << std::endl;
    }
    catch(std::out_of_range& e){
        printf("%s\n",e.what());
    }
    
    std::cout << "intArr[10] = " << intArr.get(1) << std::endl;
    std::cout << intArr<< std::endl;
    
    Array<char> charArr(5);
    charArr.set('a', 2);
    charArr.set('g', 0);
    charArr.set('z', 4);
    charArr.set('y', 1);
    charArr.set('c', 3);
    std::cout << charArr << std::endl;

    Array<Array<int>> intArrArr(2);
    Array<int> intArr2(0);
    intArrArr.set(intArr, 0);
    intArrArr.set(intArr2, 1);
    std::cout << intArrArr << std::endl;
}
