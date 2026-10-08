#include <iostream>
#include <cstdint>

void solve();

int main() {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
	try {
		solve();
	}
	catch (const char* err) {
		std::cerr << err << '\n';
	}
	return 0;
}

void solve() {
	int32_t* A = new int32_t[5]{};
	int32_t* B = new int32_t[5]{};
	std::cout << "Input 5 integers (array A) :\n";
	for (size_t i = 0; i < 5; ++i) {
		std::cin >> A[i];
	}
	std::cout << "Input 5 integers (array B) :\n";
	for (size_t i = 0; i < 5; ++i) {
		std::cin >> B[i];
	}
	int32_t mina{ INT_MAX }, minb{ INT_MAX };
	for (size_t i = 0; i < 5; ++i) {
		if (A[i] < mina) {
			mina = A[i];
		}
		if (B[i] < minb) {
			minb = B[i];
		}
	}
	std::cout << "Processed array A :\n";
	for (size_t i = 0; i < 5; ++i) {
		std::cout << A[i] + mina << ' ';
	}
	std::cout << "\nProcessed array B :\n";
	for (size_t i = 0; i < 5; ++i) {
		std::cout << B[i] + minb << ' ';
	}
	std::cout << '\n';
	delete[] A;
	delete[] B;
}