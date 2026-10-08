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
	std::cout << "Enter square matrix size:\n";
	size_t n;
	std::cin >> n;
	if (n <= 0 || n > 1000) {
		throw "Incorrect size";
	}
	int32_t** A = new int32_t * [n] {};
	for (size_t i = 0; i < n; ++i) {
		A[i] = new int32_t[n]{};
	}
	std::cout << "Enter matrix:\n";
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			std::cin >> A[i][j];
		}
	}
	int64_t negSum{};
	int32_t negCount{};
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (A[i][j] < 0) {
				++negCount;
				negSum += A[i][j];
			}
		}
	}
	if (abs(negSum) > INT_MAX) {
		throw "Sum is too big";
	}
	std::cout << "Number of negative numbers:\n" << negCount << "\nSum of negative numbers:\n" << negSum << '\n';
	for (size_t i = 0; i < n; ++i) {
		delete[] A[i];
	}
	delete[] A;
}
