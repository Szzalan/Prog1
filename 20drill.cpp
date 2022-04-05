#include "std_lib_facilities.h"
int main(){
	int arr [10] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
	list <int> ls = {0,1,2,3,4,5,6,7,8,9};
	for(int i=0;i<10;++i)
		{
			arr[i] = arr[i]+2;
			cout << arr[i] << endl;
		};
	for(int i=0;i<10;++i)
		{
			vec[i] = vec[i]+3;
			cout << vec[i] << endl;
		};
	return 0;
}
