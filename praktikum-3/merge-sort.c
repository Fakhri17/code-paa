#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara untuk penyimpanan subarray kiri dan kanan
    char leftArr[n1], rightArr[n2];

    // Salin data ke array sementara leftArr dan rightArr
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Gabungkan kembali array sementara ke array utama arr
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen jika ada dari leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Salin sisa elemen jika ada dari rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(char arr[], int left, int right) {
    if (left < right) {
        // Temukan titik tengah array
        int mid = left + (right - left) / 2;

        // Panggil rekursif untuk subarray kiri dan kanan
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan hasilnya
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char input[n][101];

    // Inputkan kata-kata
    for (int i = 0; i < n; i++) {
        scanf("%s", input[i]);
    }

    printf("Input:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", input[i]);
    }

    // Urutkan setiap kata menggunakan mergeSort
    for (int i = 0; i < n; i++) {
        mergeSort(input[i], 0, strlen(input[i]) - 1);
    }

    printf("\nOutput:\n");
    // Tampilkan setiap kata yang telah diurutkan
    for (int i = 0; i < n; i++) {
        printf("%s\n", input[i]);
    }

    return 0;
}


// Time Complexity	 
// Best	O(n*log n)
// Worst	O(n*log n)
// Average	O(n*log n)
// Space Complexity	O(n)
// Stability	Yes
