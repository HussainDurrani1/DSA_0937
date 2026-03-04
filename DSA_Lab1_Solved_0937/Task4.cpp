#include <iostream>
using namespace std;

class Product {
    int productId;
    float price;
public:
    Product(int pid = 0, float pr = 0) : productId(pid), price(pr) {}

    int getProductId() { return productId; }
    float getPrice() { return price; }
    void setProductId(int pid) { productId = pid; }
    void setPrice(float pr) { price = pr; }

    void display() {
        cout << "Product ID: " << productId << ", Price: " << price << endl;
    }
};

void displayProduct(Product* p) {
    cout << "Product ID: " << p->getProductId() << ", Price: " << p->getPrice() << endl;
}

void displayArray(Product* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Product " << i + 1 << ": ";
        displayProduct(&arr[i]);
    }
}

int linearSearch(Product* arr, int size, float price) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getPrice() == price)
            return i;
    }
    return -1;
}

void sortProducts(Product* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getPrice() > arr[j + 1].getPrice()) {
                Product temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Product* arr, int size, float price) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].getPrice() == price)
            return mid;
        else if (arr[mid].getPrice() < price)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {

    cout << "--- Task 1: Pointer to a single product ---\n";
    Product p1(101, 99.99);
    Product* ptr = &p1;
    cout << "Using -> operator: ";
    cout << ptr->getProductId() << ", " << ptr->getPrice() << endl;
    cout << "Using * operator: ";
    cout << (*ptr).getProductId() << ", " << (*ptr).getPrice() << endl;

    cout << "\n--- Task 2: Pointer to an array and pointer arithmetic ---\n";
    Product sampleArray[5] = { {1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50} };
    Product* pArray = sampleArray;
    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << ": ";
        cout << (pArray + i)->getProductId() << ", " << (pArray + i)->getPrice() << endl;
    }

    cout << "\n--- Task 3: Using displayProduct function ---\n";
    for (int i = 0; i < 5; i++) {
        displayProduct(&sampleArray[i]);
    }

    cout << "\n--- Dynamic Product List ---\n";
    int n;
    cout << "How many products would you like to enter? ";
    cin >> n;

    Product* products = new Product[n];

    for (int i = 0; i < n; i++) {
        int id;
        float price;
        cout << "Enter ID and Price for product " << i + 1 << ": ";
        cin >> id >> price;
        products[i].setProductId(id);
        products[i].setPrice(price);
    }

    cout << "\nHere are all the products you entered:\n";
    displayArray(products, n);

    float searchPrice;
    cout << "\nEnter a price to search for: ";
    cin >> searchPrice;

    int index = linearSearch(products, n, searchPrice);
    if (index != -1) {
        cout << "\nProduct found using Linear Search:\n";
        displayProduct(&products[index]);
    } else {
        cout << "No product found with that price using Linear Search.\n";
    }

    sortProducts(products, n);

    index = binarySearch(products, n, searchPrice);
    if (index != -1) {
        cout << "\nProduct found using Binary Search:\n";
        displayProduct(&products[index]);
    } else {
        cout << "No product found with that price using Binary Search.\n";
    }

    delete[] products;
    products = nullptr;

    return 0;
}