#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

	IntegerArray array(4);
	//array.insertItem(11, 5);
	//array.printInfo(array.getLength());
	IntegerArray* b = array.copyContain();
	cout << b->getItem(0);

	//cout << &(array.copyContain());

    //cout << array.getLength();
	//cout << array.findItem(41);

}
