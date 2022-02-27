#include <iostream>
#include <string>
using namespace std;
class BV
{
public:
	virtual void pvf() = 0;
};
class B1 : public BV
{
public:
	virtual void vf()
	{
		cout << "B1::vf" << endl;
	}
	void f()
	{
		cout << "B1::f" << endl;
	}
	void pvf() override
	{
		cout << "B1::pvf" << endl;
	};
};
class D1 : public B1
{
	public:
		void vf() override
		{
			cout << "D1::vf" << endl;
		}
		void f()
		{
			cout << "asdasd" << endl;
		}
		void pvf() override
	{
		cout << "D1::pvf" << endl;
	};
};
class D2 : public D1
{
public:
	void pvf() override {
		 cout << "D2::pvf" << endl;
	};
};
class B2
{
public:
	virtual void pvf() = 0;
};
class D21 : public B2 {
string car = "Trabant";
public:

	void pvf() override
	{
		
		cout << car << endl;
	}
};
class D22 : public B2
{
public:
	
	void pvf() override
	{
		
		cout << szam << endl;}
int szam = 420;
};

void f(B2& b2reff)
{
	b2reff.pvf();
}
int main()
{
	B1 b1;
	b1.vf();
	b1.f();
	D1 d1;
	d1.vf();
	d1.f();
	B1& b1ref = d1;
	b1ref.vf();
	b1ref.f();
	B1 asd;
	asd.f();
	asd.vf();
	D1 asdasd;
	asdasd.vf();
	asdasd.f();
	B1& b2ref = d1;
	b2ref.vf();
	b2ref.f();
	D2 d2;
	d2.pvf();
	d2.f();
	d2.vf();
	D21 d21o;
	d21o.pvf();
	D22 d22o;
	d22o.pvf();
	f(d21o);
	f(d22o);
}