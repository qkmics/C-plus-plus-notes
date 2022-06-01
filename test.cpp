// Online C++ compiler to run C++ program online
#include <iostream>

// 输入类型，输出类型中是否有type
template <typename ...T>
struct VoidType {
    using type = void; 
};

template <typename ...T>
using void_t = typename VoidType<T...>::type; 


template <typename T, typename U = void_t<>>
struct HasType {
    constexpr static bool value = false; 
};

template <typename T>
struct HasType<T, void_t<typename T::type>> {
    constexpr static bool value = true; 
};

template <typename T>
constexpr static bool has_type_v = HasType<T>::value; 

struct A { 
    using type = int;
};

struct B{};

// 输入类型数组，输出unsigned int数组代表输入数组中每个类型的大小
template <unsigned int ...values>
struct Result {
    
    constexpr static unsigned int size = sizeof...(values);
    
    template<unsigned int index, unsigned int value, unsigned int...vs>
    struct getValue
    {
        constexpr static unsigned int getValueV = getValue<index-1, vs...>::getValueV;
    };
    
    template<unsigned int value, unsigned int...vs>
    struct getValue<0, value, vs...>
    {
        constexpr static unsigned int getValueV = value;
    };
    
    template<unsigned int value>
    struct getValue<0,value>
    {
        constexpr static unsigned int getValueV = value;
    };
    
    template<unsigned int index, unsigned int value>
    struct getValue<index, value>
    {
        constexpr static unsigned int getValueV = -1;
    };
    
    template<unsigned int index>
    struct getValueT 
    {
        constexpr static unsigned int value = getValue<index, values...>::getValueV;
    };
};

template <typename ...Ts>
struct GetSizes{
    using sizeType = Result<sizeof(Ts)...>;
};

void test() {
    std::cout << Result<1,2,3>::getValueT<0>::value <<  std::endl;
    std::cout << Result<1,2,3>::getValueT<1>::value <<  std::endl;
    std::cout << Result<1,2,3>::getValueT<2>::value <<  std::endl;
    std::cout << Result<GetSizes<int,long long ,char>::sizeType::getValueT<1>::value>::getValueT<0>::value <<  std::endl;
}


int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    // std::cout << has_type_v<A> << std::endl;
    
    // std::cout << has_type_v<B> << std::endl;
    test();
    return 0;
}