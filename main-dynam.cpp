#include <iostream>
#include <dlfcn.h>
#include "vector.h"

using namespace std;

int main(void) {
	void *handle = dlopen("./libvector.so", RTLD_LAZY);

	if (!handle) {
		cerr <<  dlerror() << endl;
		return 0;
	}
	new_vector_t *new_vector = (new_vector_t *) dlsym(handle, "new_vector");
	delete_vector_t *delete_vector = (delete_vector_t *) dlsym(handle, "delete_vector");

	if (!new_vector || !delete_vector) {
		cerr <<  dlerror() << endl;
		return 0;
	}


	size_t size = 5;
	Vector *arr = new_vector();
	arr->Resize(size);
	for (size_t i = 0; i < arr->Size(); i++) {
		arr->SetValue(i, i);
	}
	for (size_t i = 0; i < arr->Size(); i++) {
		cout << arr->GetValue(i) << ' ';
	}
	cout << endl;
	delete_vector(arr);
	dlclose(handle);
	return 0;
}
