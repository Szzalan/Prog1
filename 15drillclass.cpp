#include <iostream>
#include <string>
using namespace std;
struct Person
{
	void People(string name,int age){
	cout << "Adja meg az ember nevét" << endl;
	cin >> name;
	cout << "adja meg az ember életkorát" << endl;
	cin >> age;}


};
int main()
{
	Person obj1;
	cout << obj1.People << endl;





}
