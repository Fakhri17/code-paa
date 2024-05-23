#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "json_parser.cpp"

// TODO
/*
1. Buat agar format printBooks sesuai dengan output yang diinginkan soal
2. Buat fungsi mergeSort untuk mengurutkan berdasarkan judul / penulis / tahun_terbit
3. Buat menu untuk memilih ingin mengurutkan berdasarkan apa
*/

void printBooks(const vector<Book> &books)
{
    for (const auto &book : books)
    {
        cout << "Judul: \"" << book.judul << ", Penulis: \"" << book.penulis << ", Tahun Terbit: " << book.tahun_terbit << ", Nomor Rak: \"" << book.nomor_rak << "\"" << endl;
    }
}

void printBooks1(const vector<Book> &books)
{
    cout << "[" << endl;
    for (const auto &book : books)
    {
        cout << " {" << "Judul: \"" << book.judul << ", Penulis: \"" << book.penulis << ", Tahun Terbit: " << book.tahun_terbit << ", Nomor Rak: \"" << book.nomor_rak << "\"" << "}," << endl;
    }
    cout << "]" << endl;
}


// membuat fungsi mergeSort untuk mengurutkan berdasarkan judul
// dengan parameter vector books, left, dan right
// dimana left adalah index pertama dan right adalah index terakhir
void mergeSortFromJudul(vector<Book> &books, int left, int right)
{
    // jika left lebih kecil dari right
    if (left < right)
    {
        // cari nilai tengah
        int mid = left + (right - left) / 2;
        // panggil fungsi mergeSortFromJudul dengan parameter books, left, dan mid
        mergeSortFromJudul(books, left, mid);
        mergeSortFromJudul(books, mid + 1, right);

        // buat vector temp sebagai tempat penyimpanan sementara
        vector<Book> temp;
        int i = left;
        int j = mid + 1;

        // lakukan perulangan selama i <= mid dan j <= right
        // fungsinya untuk membandingkan judul buku
        while (i <= mid && j <= right)
        {
            // jika judul buku i lebih kecil dari judul buku j
            if (books[i].judul < books[j].judul)
            {
                // masukkan buku i ke dalam vector temp
                temp.push_back(books[i]);
                // increment i
                i++;
            }
            else
            {
                // masukkan buku j ke dalam vector temp
                temp.push_back(books[j]);
                j++;
            }
        }

        // lakukan perulangan selama i <= mid
        // digunakan untuk memasukkan sisa buku yang belum dimasukkan ke dalam vector temp
        while (i <= mid)
        {
            temp.push_back(books[i]);
            i++;
        }

        // lakukan perulangan selama j <= right
        // digunakan untuk memasukkan sisa buku yang belum dimasukkan ke dalam vector temp
        while (j <= right)
        {
            temp.push_back(books[j]);
            j++;
        }

        
        // lakukan perulangan untuk memasukkan buku dari vector temp ke vector books
        // dimulai dari index left hingga right
        // fungsinya untuk menggantikan buku yang sudah diurutkan
        for (int i = left; i <= right; i++)
        {
            books[i] = temp[i - left];
        }
    }
}



void mergeSortFromPenulis(vector<Book> &books, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortFromPenulis(books, left, mid);
        mergeSortFromPenulis(books, mid + 1, right);

        vector<Book> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right)
        {
            if (books[i].penulis < books[j].penulis)
            {
                temp.push_back(books[i]);
                i++;
            }
            else
            {
                temp.push_back(books[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(books[i]);
            i++;
        }

        while (j <= right)
        {
            temp.push_back(books[j]);
            j++;
        }

        for (int i = left; i <= right; i++)
        {
            books[i] = temp[i - left];
        }
    }
}

void mergeSortFromTahunTerbit(vector<Book> &books, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortFromTahunTerbit(books, left, mid);
        mergeSortFromTahunTerbit(books, mid + 1, right);

        vector<Book> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right)
        {
            if (books[i].tahun_terbit < books[j].tahun_terbit)
            {
                temp.push_back(books[i]);
                i++;
            }
            else
            {
                temp.push_back(books[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(books[i]);
            i++;
        }

        while (j <= right)
        {
            temp.push_back(books[j]);
            j++;
        }

        for (int i = left; i <= right; i++)
        {
            books[i] = temp[i - left];
        }
    }
}

int main()
{
    ifstream file("data.json");

    stringstream buffer;
    buffer << file.rdbuf();
    string jsonData = buffer.str();
    int choice;

    vector<Book> books = jsonToBooks(jsonData);

    cout << "Data Buku" << endl;
    printBooks(books);
    cout << endl;

    cout << "1. Sort by Judul" << endl;
    cout << "2. Sort by Penulis" << endl;
    cout << "3. Sort by Tahun Terbit" << endl;
    cout << "Pilih: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        mergeSortFromJudul(books, 0, books.size() - 1);
        break;
    case 2:
        mergeSortFromPenulis(books, 0, books.size() - 1);
        break;
    case 3:
        mergeSortFromTahunTerbit(books, 0, books.size() - 1);
        break;
    default:
        cout << "Pilihan tidak valid" << endl;
        break;
    }

    cout << "Data Buku setelah diurutkan" << endl;
    printBooks1(books);

    return 0;
}
