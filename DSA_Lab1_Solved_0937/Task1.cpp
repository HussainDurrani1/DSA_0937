#include <iostream>
using namespace std;

int linearSearch(int arr[],int elem,int N) {
	int foundelem = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] == elem) {
			foundelem = i;
		}
	}
	return foundelem;
}

int main() {
	const int size = 5;
	int arr[5] = { 0 };

	cout << "Enter the elements of array: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int selem;
	cout << "Enter the element you want to search: ";
	cin >> selem;

	int foundindex = linearSearch(arr, selem, size);
	cout << "Element found at index: " << foundindex << endl;

	return 0;
}