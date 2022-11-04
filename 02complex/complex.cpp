#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
	complex c1(2, 1);
	complex c2;
	cout << c1 << endl;
	cout << c2 << endl;

	c2 = c1 + 5;
	c2 = 7 + c1;
	c2 = c1 + c2;
	c2 += c1;
	c2 += 3;
	c2 = -c1;

	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;
	cout << conj(c1) << endl;
	return 0;
}
