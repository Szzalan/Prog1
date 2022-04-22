#include <stdio.h>
void function(const char* p, int x)
{
	printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
	//1
	printf("Hello world!\n");
	//2
	char firsthalf[] = "Hello";
	char secondhalf[] = "World!";
	printf("%s %s\n",firsthalf,secondhalf);
	//3
	function("C nyelv",9);
	function("A",7);
	function("WD",40);
	return 0;
}