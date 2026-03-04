#include <iostream>
using namespace std;

int binarySearch(int sarr[], int key, int size) {
	int low = 0;
	int high = size - 1;
	while (low <= high) {
		int mid = (low + high) / 2;

		if (sarr[mid] == key) {
			return mid;
		}
		else if (key < sarr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
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

	int foundindex = binarySearch(arr, selem, size);
	cout << "Element found at index: " << foundindex << endl;


	return 0;
}