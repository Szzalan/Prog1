#include "std_lib_facilities.h"
struct Item
{
    int iid;
    string name;
    double value;
};

istream& operator>>(istream& is, Item& i)
{
    is >> i.iid >> i.name >> i.value;
    return is;
}

ostream& operator<<(ostream& os, Item& i)
{
    os << i.iid << " " << i.name << " " << i.value << endl;
    return os;
}

//6.
class Cmp_by_name 
{
    string name;
public:
    Cmp_by_name(const string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

//7.
class Cmp_by_iid 
{
    int iid;
public:
    Cmp_by_iid(const int& nn) : iid{nn} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};



int main(){

//1
    vector<Item> vi;
    ifstream ist {"source.txt"};
    if (!ist) error("The file isn't exist");
    for (Item v; ist >> v; )
    {
        vi.push_back(v);
    }
    ist.close();
    cout << "\nVector: " << endl;
    for(Item val : vi)
    {
        cout << val;
    }
//2
    cout << "\nOrder by name: " << endl;
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.name < b.name; });
    for(Item val : vi)
    {
        cout << val;
    }
//3
    cout << "\nOrder by iid: " << endl;
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.iid < b.iid; });
    for(Item val : vi)
    {
        cout << val;
    }
//4
    cout << "\nOrder by value: " << endl;
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.value > b.value; });
    for(Item val : vi)
    {
        cout << val;
    }
//5
    vi.push_back({99,"horse shoe",12.34});
    vi.push_back({9988,"Canon S400", 499.95});
    cout << "\nInserted: " << endl;
    for(Item val : vi)
    {
        cout << val;
    }
//6
    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("horse shoe")));
    cout << "\nDeletion by name: " << endl;
    for(Item val : vi)
    {
        cout << val;
    }
//7
    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_iid(9988)));
    cout << "\nDeletion by id: " << endl;
    for(Item val : vi)
    {
        cout << val;
    }
//8 List
    list<Item> li;
    ifstream ist2 {"source.txt"};
    if (!ist2) error("The file isn't exist");
    for (Item elem; ist2 >> elem; )
    {
        li.push_back(elem);
    }
    ist2.close();
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    li.sort([](const Item& a, const Item& b) { return a.value > b.value; });
    Item tmp = Item{99,"horse shoe",12.34};
    li.push_back(tmp);
    tmp = Item{9988,"Canon S400", 499.95};
    li.push_back(tmp);
    li.erase(find_if(li.begin(), li.end(), Cmp_by_name("horse shoe")));
    li.erase(find_if(li.begin(), li.end(), Cmp_by_iid(9988)));
    cout << "\nList contents: " << endl;
    for(Item val : li) 
    {
        cout << val;
    }
    return 0;
}