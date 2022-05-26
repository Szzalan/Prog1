#include "std_lib_facilities.h"

template<typename T>
struct S {
    private:
        T val;
    public:
        S(T vall2) : val(vall2) {} //T típusú val-ba belerakjuk a vall2-t
    
        T& get();
        T get() const { return val; } 

        T operator=(const T&);
};

template<typename T> T& S<T>::get() { return val; }  //getter függvény

template<typename T> T S<T>::operator=(const T& nval) { val = nval; } // = operátor túlterhelés

template<typename T>
istream& operator>>(istream& is, S<T>& tt){ //>> operátor túlterhelés
    is >> tt.get();
    return is;
}

template<typename T> void read_val(T& v) { cin >> v; } //beolvasás függvénnyel

int main()
try {
    S<int> num {30};
    S<char> ch {'q'};
    S<double> dnum {3.14};
    S<string> strng {"Szöveg"};
    S<vector<int>> vec { {1, 2, 3, 4, 5} };

    cout << num.get() << " " << ch.get() << " " << dnum.get() << " " << strng.get() << endl; 
    vector<int> vecfil = vec.get();
    for (auto a : vecfil) cout << a << " ";
    cout << "\n\n";

    S<int> num2 {45};
    cout << "Number: " << num.get() << endl;
    num = num2; 
    cout << "New num: " << num.get() << endl;

    S<int> numin{0};
    S<double> dnumin{0};
    S<string> stringin{"asd"};
    S<char> chin{'a'};
    cout << "Type in a number, a double number, a string and a char!" << endl;
    read_val(numin); read_val(dnumin); read_val(stringin); read_val(chin);
    cout << "Number: "<< numin.get() << "\n" << "Double number: " << dnumin.get() << "\n" << 
            "String: " << stringin.get() << "\n" << "Char: " << chin.get() << endl;

    return 0;
} catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
} catch (...) {
    cerr << "Something went wrong" << endl;
    return 2;
}