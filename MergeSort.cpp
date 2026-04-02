#include <iostream>
using namespace std;

// Membuat array utama dan array bantuan
int arr[20], B[20];
int n;

void input() {
    while (true) {
        cout << "Masukkan Panjang element array (maks 20): ";
        cin >> n;

        if (n <= 20) {
            break;
        } else {
            cout << "\nMaksimal panjang array adalah 20!" << endl;
        }
    }

    cout << "\n----------------------------" << endl;
    cout << "--- Inputkan Isi Elemen ---" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Array index ke-" << i << ": ";
        cin >> arr[i];
    }
}

void mergeSort(int low, int high) {
    if (low >= high) { // Base case: Jika tumpukan tinggal 1 elemen
        return;
    }

    int mid = (low + high) / 2; // Mencari titik tengah

    // Membelah array (Divide)
    mergeSort(low, mid); 
    mergeSort(mid + 1, high);

    // Menggabungkan dan Mengurutkan (Merge)
    int i = low;     // Indeks awal bagian kiri
    int j = mid + 1; // Indeks awal bagian kanan
    int k = low;     // Indeks awal array bantuan B

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }

    // Jika ada sisa di bagian kanan
    while (j <= high) {
        B[k] = arr[j];
        j++;
        k++;
    }

    // Jika ada sisa di bagian kiri
    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    // Copy balik dari array bantuan B ke array utama arr
    for (int x = low; x <= high; x++) {
        arr[x] = B[x];
    }
}

void output() {
    cout << "\nData setelah diurutkan (Merge Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    input();
    if (n > 0) {
        mergeSort(0, n - 1);
    }
    output();

    return 0;
}