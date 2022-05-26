#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
void age_check(int age) //checker bemenetre
{
	if(age < 0 or age >= 150)
		throw runtime_error("Invalid age!");
}
void name_check(string name)
{
	for (int i = 0; i < name.length(); ++i)
	{
		if(!isalpha(name[i]))
			throw runtime_error("Invalid name!");
	}
}
struct Person //person adatai
{	
	private:
		string f_name;
		string s_name;
		int age;

	public:
		Person(){}; //default konstruktor
		Person(string fn,string sn,int a) : f_name(fn), s_name(sn),age(a){ //konstruktor
			name_check(fn+sn);
			age_check(a);


		}
		string get_fname() const { //getter függvények kiíratáshoz
			return f_name;
		}
		string get_sname() const {
			return s_name;
		}
		int get_age() const {
			return age;
		}

};
ostream& operator<< (ostream& os,Person& p) // << operátor túlterhelés
{
	return os << p.get_fname() << " " << p.get_sname() << " " << p.get_age() << endl;
}
istream& operator>> (istream& is,Person& p) // >> operátor túlterhelés
{
	string fn;
	string ln;
	int a;
	is >> fn >> ln >> a;
	p = Person(fn,ln,a);
	return is;
}

int main()
{
	try{
	//2es
	Person obj0("Goofy", "",63);
	cout << obj0.get_fname() << "\n" << obj0.get_age() << endl;
	
	//3as
	cout << "Adjon meg egy persont" << endl; //operátor túlterheléssel megoldva a feladat
	Person ptest;
	cin >> ptest;
	cout << ptest << endl;

	string obj1_fname;
	cout << "Kérlek add meg a keresztnevét!" << endl;
	cin >> obj1_fname;

	string obj1_sname;
	cout << "Kérlek add meg a vezeték nevét!" << endl;
	cin >> obj1_sname;

	int obj1_age;
	cout << "Kérlek add meg az életkorát!" << endl;
	cin >> obj1_age;
	Person obj1(obj1_fname,obj1_sname,obj1_age); //getter függvénnyel megoldva
	cout << obj1.get_fname() << " " << obj1.get_sname() << " " <<  obj1.get_age() << endl;
	vector<Person> vec;
	cout << "Adjon meg keresztneveket, vezetékneveket, év adatokat." << endl;
	cout << "A kilépéshez használja az x billentyűt" << endl;
	while(true) //personokat tartalmazó vektor feltöltése
	{
		string obj3_fname;
		string obj3_sname;
		int obj3_age;

		cin >> obj3_fname;			
		if(obj3_fname == "x") break;
		cin >> obj3_sname;
		cin >> obj3_age;
		vec.push_back(Person(obj3_fname,obj3_sname,obj3_age));		

	}
	for (int i = 0; i < vec.size(); ++i) //kiíratás
	{
		cout << vec[i].get_fname() << " " << vec[i].get_sname() << " " <<  vec[i].get_age() << endl;
	}

	return 0;
}
	catch(exception& e)
		{
			cerr << e.what() << endl;
    		return 2;
		}

}
