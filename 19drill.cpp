#include "std_lib_facilities.h"

template<typename T>
struct S {
    private:
        T val;
    public:
        S(T vall2 = T()) : val(vall2) {}
    
        T& get();
        T get() const { return val; }

        T operator=(const T&);
};

template<typename T> T& S<T>::get() { return val; }

template<typename T> T S<T>::operator=(const T& nval) { val = nval; } 

template<typename T>
istream& operator>>(istream& is, S<T>& tt){
    is >> tt.get();
    return is;
}

template<typename T> void read_val(T& v) { cin >> v; }

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

    S<int> numin;
    S<double> dnumin;
    S<string> stringin;
    S<char> chin;
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