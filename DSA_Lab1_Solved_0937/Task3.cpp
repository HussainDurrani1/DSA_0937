#include <iostream>
using namespace std;


class Product {
	int productId;
	float price;
public:
	Product(int pid=0,float pr=0):productId(pid),price(pr) {}
	int getProductId() {
		return productId;
	}
	float getPrice() {
		return price;
	}
	void setProductId(int prid) {
		productId = prid;
	}
	void setPrice(float prc) {
		price = prc;
	}
	void display() {
		cout << "Product ID: " << productId << endl;
		cout << "Product Price: " << price << endl;
	}
};

Product linearSearch(Product arr[], int elem, int N) {
	int foundelem = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i].getPrice() == elem) {
			foundelem = i;
		}
	}
	return arr[foundelem];
};

Product binarySearch(Product sarr[], int key, int size) {
	int low = 0;
	int high = size - 1;
	while (low <= high) {
		int mid = (low + high) / 2;

		if (sarr[mid].getPrice() == key) {
			return sarr[mid];
		}
		else if (key < sarr[mid].getPrice()) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
};
void sort(Product arr[], int size) {
	for (int passes = 0; passes < size - 1; passes++) {
		for (int iter = 0; iter < passes - size - 1; iter++) {
			if (arr[iter].getPrice() > arr[iter + 1].getPrice()) {
				Product tempproduct = arr[iter];
				arr[iter] = arr[iter + 1];
				arr[iter + 1] = tempproduct;
			}
		}
	}
};

int main() {
	const int size = 15;
	Product prds[size];

	for (int i = 0; i < size; i++) {
		int prodid = 1000;
		float prodprice = 100;
		prds[i] = Product(prodid + i, prodprice + i);
	}

	for (int i = 0; i < size; i++) {
		cout << "<--------------------------------------------->" << endl;
		cout << "Product " << i + 1 << endl;
		prds[i].display();
		cout << "<--------------------------------------------->" << endl;
	}

	int pvalue;
	cout << "Enter the price value you want to search: ";
	cin >> pvalue;

	cout << "Using Linear Search" << endl;
	Product lfoundproduct = linearSearch(prds, pvalue, size);
	cout << "Product with price value " << pvalue << endl;
	lfoundproduct.display();

	sort(prds, size);

	cout << endl;
	cout << "Using Binary Search" << endl;
	Product bfoundproduct = binarySearch(prds, pvalue, size);
	cout << "Product with price value " << pvalue << endl;
	bfoundproduct.display();


	return 0;
}