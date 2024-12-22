#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur Buku
struct Book {
    int ID;
    string Title;
    string Author;
};

// Deklarasi array global dengan kapasitas maksimum 100 buku
vector<Book> catalog;

// Fungsi untuk menambahkan buku ke katalog
void addBook(const Book& book) {
    if (catalog.size() >= 100) {
        cout << "Katalog penuh! Tidak dapat menambahkan buku baru." << endl;
        return;
    }
    catalog.push_back(book);
}

// Fungsi Bubble Sort Iteratif untuk mengurutkan katalog berdasarkan ID
void bubbleSortIterative() {
    for (size_t i = 0; i < catalog.size() - 1; ++i) {
        for (size_t j = 0; j < catalog.size() - i - 1; ++j) {
            if (catalog[j].ID > catalog[j + 1].ID) {
                // Menukar elemen secara manual
                Book temp = catalog[j];
                catalog[j] = catalog[j + 1];
                catalog[j + 1] = temp;
            }
        }
    }
}

// Fungsi Bubble Sort Rekursif untuk mengurutkan katalog berdasarkan ID
void bubbleSortRecursive(int n) {
    if (n == 1) {
        return;
    }
    for (int j = 0; j < n - 1; ++j) {
        if (catalog[j].ID > catalog[j + 1].ID) {
            // Menukar elemen secara manual
            Book temp = catalog[j];
            catalog[j] = catalog[j + 1];
            catalog[j + 1] = temp;
        }
    }
    bubbleSortRecursive(n - 1);
}

// Fungsi Linear Search Iteratif untuk mencari buku berdasarkan ID
int linearSearchIterative(int targetID) {
    for (size_t i = 0; i < catalog.size(); ++i) {
        if (catalog[i].ID == targetID) {
            return i;
        }
    }
    return -1;
}

// Fungsi Linear Search Rekursif untuk mencari buku berdasarkan ID
int linearSearchRecursive(int targetID, int index) {
    if (index >= catalog.size()) {
        return -1;
    }
    if (catalog[index].ID == targetID) {
        return index;
    }
    return linearSearchRecursive(targetID, index + 1);
}

// Fungsi rekursif Binary Search untuk mencari buku berdasarkan ID
int binarySearchRecursive(int targetID, int low, int high) {
    if (high < low) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (catalog[mid].ID == targetID) {
        return mid;
    } else if (catalog[mid].ID > targetID) {
        return binarySearchRecursive(targetID, low, mid - 1);
    } else {
        return binarySearchRecursive(targetID, mid + 1, high);
    }
}

// Fungsi iteratif Binary Search untuk mencari buku berdasarkan ID
int binarySearchIterative(int targetID) {
    int low = 0;
    int high = catalog.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (catalog[mid].ID == targetID) {
            return mid;
        } else if (catalog[mid].ID > targetID) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// Fungsi untuk menghapus buku dari katalog berdasarkan ID
bool removeBook(int targetID) {
    int index = linearSearchIterative(targetID);
    if (index == -1) {
        return false;
    }
    catalog.erase(catalog.begin() + index);
    return true;
}

// Fungsi untuk menampilkan katalog buku
void displayCatalog() {
    if (catalog.empty()) {
        cout << "Katalog kosong." << endl;
        return;
    }
    cout << "Katalog Buku:" << endl;
    for (const auto& book : catalog) {
        cout << "ID: " << book.ID << ", Title: " << book.Title << ", Author: " << book.Author << endl;
    }
}

int main() {
    // Menambahkan beberapa buku ke katalog
    addBook({3, "The Great Gatsby", "F. Scott Fitzgerald"});
    addBook({1, "1984", "George Orwell"});
    addBook({5, "Pride and Prejudice", "Jane Austen"});
    addBook({2, "To Kill a Mockingbird", "Harper Lee"});
    addBook({4, "Moby Dick", "Herman Melville"});
    addBook({6, "Atomic Habits", "James Clear"});

    // Mengurutkan katalog menggunakan Bubble Sort Iteratif
    bubbleSortIterative();

    // Menampilkan katalog buku
    displayCatalog();

    // Mencari buku dengan ID 3 secara iteratif
    int targetID = 3;
    int index = linearSearchIterative(targetID);
    if (index != -1) {
        cout << "\nLinear Search Iteratif: Buku dengan ID " << targetID << " ditemukan di indeks " << index
             << ": {ID:" << catalog[index].ID << ", Title:" << catalog[index].Title << ", Author:" << catalog[index].Author << "}" << endl;
    } else {
        cout << "\nLinear Search Iteratif: Buku dengan ID " << targetID << " tidak ditemukan." << endl;
    }

    // Menghapus buku dengan ID 1
    targetID = 1;
    if (removeBook(targetID)) {
        cout << "\nRemove Book: Buku dengan ID " << targetID << " berhasil dihapus." << endl;
    } else {
        cout << "\nRemove Book: Buku dengan ID " << targetID << " gagal dihapus (tidak ditemukan)." << endl;
    }

    // Menampilkan katalog buku setelah penghapusan
    displayCatalog();

    // Menambahkan buku lagi untuk demonstrasi Bubble Sort Rekursif
    addBook({6, "War and Peace", "Leo Tolstoy"});
    addBook({0, "The Catcher in the Rye", "J.D. Salinger"});

    // Mengurutkan katalog menggunakan Bubble Sort Rekursif
    bubbleSortRecursive(catalog.size());

    // Menampilkan katalog setelah pengurutan rekursif
    displayCatalog();

    return 0;
}
 
