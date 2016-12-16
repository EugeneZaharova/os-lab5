#include <iostream>
#include "vector.h"

using namespace std;

int main(void) {
	size_t size;
	Vector arr;
	cout << "Arr size:" << endl;
	cin >> size;
	arr.Resize(size);
	cout << "Arr elements (" << size << ")" << endl;
	for (size_t i = 0; i < arr.Size(); i++) {
		cin >> arr[i];
	}
	for (size_t i = 0; i < arr.Size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
