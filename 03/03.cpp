template<typename T, typename V>
struct A {
    T x;
    V y;

    A(T v, T x = 25.8) : x(v) {};
    A(T v, V y = 25) : x(v) {};
};

int main() {
    A a(5, 36.8);
    
}