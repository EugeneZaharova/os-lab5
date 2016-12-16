#include <iostream>
#include "vector.h"

using namespace std;

int main(void) {
	size_t size = 5;
	Vector arr;
	arr.Resize(size);
	for (size_t i = 0; i < arr.Size(); i++) {
		arr[i] = i;
	}
	for (size_t i = 0; i < arr.Size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
