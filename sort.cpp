// Online C++ compiler to run C++ program online
#include <iostream>

template<class...>struct types{using type=types;};

struct A { 
    int v1;
    int v2;
    A (int a, int b) { v1 = a; v2 = b;}
    
    template <typename T>
    A(types<T>)  {
        v1 = T::v1;
        v2 = T::v2;
    }
};

template <typename T>
A getA() {
    return A{T::v1,T::v2};
}
struct B
{
    constexpr static int v1 = 1;
    constexpr static int v2 = 2;
};


void test() {
    A a = A(types<B>{});
    std::cout << a.v1 << " " << a.v2 << std::endl;
    
    A a2 = getA<B>();
    std::cout << a2.v1 << " " << a2.v2 << std::endl;
}


int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    // std::cout << has_type_v<A> << std::endl;
    
    // std::cout << has_type_v<B> << std::endl;
    test();
    return 0;
}