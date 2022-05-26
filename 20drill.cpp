#include "std_lib_facilities.h"
template<typename Iter1, typename Iter2> //iterátor copy
Iter2 copyer(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while( f1 != e1) //amíg az első konténer tart
	{
		*f2 = *f1; //értékadás

		f2++; //léptetés

		f1++;
			
	}

 return f2;
}

int main(){
	const int length = 10;
	array<int,length> ar;
	vector<int> vec;
	list <int> ls;
		for (int i = 0; i < length; ++i) //értékadás
		{
			ar[i] = i;
		}
		//
		for (int i = 0; i < length; ++i)
		{
			vec.push_back(i);
		}
		//
		for(int i=0;i<length;++i)
		{
			ls.push_back(i);
		}
			for (array<int, length>::iterator iter = ar.begin(); iter != ar.end(); iter++)
			{
				*iter += 2; //értéket eléri majd hozzáad 2-t
			}
			for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
			{
				*iter += 3;
			}
			for (list<int>::iterator iter = ls.begin(); iter != ls.end(); iter++)
			{
				*iter += 5;
			}

	//copies
	array <int,length>ar2=ar;
	vector<int> vec2= vec;
	list<int> ls2= ls;
	//copipasta
	copyer(ar2.begin(),ar2.end(),vec2.begin()); //copy használat
	copyer(ls2.begin(),ls2.end(),ar2.begin());
	for (array<int, length>::iterator iter = ar2.begin(); iter != ar2.end(); iter++)
			{
				cout << *iter << endl; //kiíratás
			}
	for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++)
			{
				cout << *iter << endl;
			}
	//find
	vector<int>::iterator fi = find(vec2.begin(),vec2.end(),3); //megkapja a helyzetét
	if (fi != vec2.end())
	{
		cout << "The searched position is: " << distance(vec2.begin(),fi) << endl; //így íratjuk ki
	}
	else
		cout << "The searched number is not found" << endl;
	list<int>::iterator fi2 = find(ls2.begin(),ls2.end(),27);
	if (fi2 != ls2.end())
	{
		cout << distance(ls2.begin(),fi2) << endl;
	}
	else
		cout << "The searched number is not found" << endl;

	return 0;
}
