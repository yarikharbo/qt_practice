#include "class2.h"
#include <iostream>
#include <cstdint>


int main() {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);

	X* obj1 = new X(4, 5);
	Y* obj2 = new Y(4, 5, 6);

	obj1->show();
	std::cout << '\n';
	obj2->show();
	std::cout << '\n';

	obj1->set();
	obj1->show();
	std::cout << '\n';

	obj2->set();
	obj2->show();
	std::cout << '\n';


	int32_t ex = obj2->Run();
	std::cout << "sum of squares of class Y variables:\n" << ex << '\n';

	delete obj1;
	delete obj2;
	return 0;
}

