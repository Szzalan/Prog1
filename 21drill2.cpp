#include "std_lib_facilities.h"
#include <map>
#include <numeric>

template<typename T, typename Z>
void m_print(const map<T,Z>& m)
{
    cout << "Map: " << endl;

    for (const auto& a : m)
        cout << a.first << " > " << a.second << endl;

    cout << endl;
}
istream& operator>>(istream& is, map<string,int>& m)
{
    string key;
    int value;

    is >> key >> value;
    m.insert(make_pair(key, value));
    return is;
}
void read_to_map(map<string,int>& m, int num)
{
    while(m.size() < num)
        cin >> m;
}

int main(){
//1,2
    map<string,int> msi;
    msi["Toyota"] = 1;
    msi["Mitsubishi"] = 2;
    msi["Subaru"] = 3;
    msi["Suzuki"] = 4;
    msi["Mazda"] = 5;
    msi["Ford"] = 6;
    msi["Fiat"] = 7;
    msi["Lada"] = 8;
    msi["Trabant"] = 9;
    msi["Wartburg"] = 10;
//3
    m_print(msi);
//4
    msi.erase(msi.begin(), msi.end());
//5,6
    read_to_map(msi, 10);
//7
    m_print(msi);
//8
    int sum = 0;
    for(const auto& a : msi)
    {
        sum += a.second;
    }
    cout << "Sum of the values in msi =: " << sum << '\n';
//9
    map<int, string> mis;
//10
    for(const auto& a : msi)
    {
        mis.insert(make_pair(a.second, a.first));
    }
//11
    m_print(mis);
    return 0;
}