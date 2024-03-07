#include <iostream>
using namespace std;
int metode_ini(int arr[], int n, int key)
{
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] == key)
      return i;
  }
  return -1;
}
int main()
{
  int arr[] = {10, 20, 30, 40, 50};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 30;
  int result = metode_ini(arr, n, key);
  if (result != -1)
    cout << "Berhasil: " << result << endl;
  else
    cout << "Tidak berhasil" << endl;
  return 0;

  // Apa yang dilakukan oleh program di atas?
  // Program di atas mencari nilai key pada array arr. Jika nilai key ditemukan, maka program akan mengembalikan indeks dari nilai key tersebut.

  //  Apa nama algoritma tersebut?
  // Algoritma tersebut adalah algoritma linear search.

  // Berapakah Kompleksitas algoritma tersebut? (Dalam Big O)
  // Kompleksitas algoritma tersebut adalah O(n). kenapa ? karena algoritma tersebut akan melakukan iterasi sebanyak n kali, dimana n adalah jumlah elemen pada array arr.

  // Apakah ada algoritma lain yang lebih baik dari algoritma di atas? 
  // Ada, yaitu algoritma binary search. Algoritma binary search memiliki kompleksitas O(log n) dimana n adalah jumlah elemen pada array arr.

  // buatkan kode program yang menggunakan algoritma tersebut
  
  // kenapa O(n) lebih buruk dari pada O(log n) ?
  // Karena O(n) akan melakukan iterasi sebanyak n kali, sedangkan O(log n) akan melakukan iterasi sebanyak log n kali. Sehingga O(log n) lebih cepat daripada O(n). 
}
