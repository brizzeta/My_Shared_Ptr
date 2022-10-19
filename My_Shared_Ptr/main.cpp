#include <iostream>
#include "My_Shared_Ptr.h"
using namespace std;

class Foo
{
	int m_number;
public:
	Foo(int number)	{
		m_number = number;
	}

	int GetNumber() {
		return m_number;
	}
};


int main()
{
	My_Shared_Ptr<Foo> p1(new Foo(5));
	My_Shared_Ptr<Foo> p2 = p1;
	My_Shared_Ptr<Foo> p3 = p2;
	cout << p1.get() << ' ' << p1.get()->GetNumber() << endl;
	cout << p2.get() << ' ' << p2.get()->GetNumber() << endl;
	cout << p3.get() << ' ' << p3.get()->GetNumber() << endl;
	cout << p3.Get_amount();
}