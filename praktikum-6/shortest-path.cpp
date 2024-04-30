#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minDistance = INT_MAX; // Menyimpan jarak terpendek yang ditemukan
vector<int> shortestPath; // Menyimpan rute terpendek yang ditemukan

// Fungsi rekursif untuk mencari rute terpendek
void findShortestPath(vector<vector<int>> &graph, vector<int> &path, vector<bool> &visited, int currentDistance) {
    int currentCity = path.back(); // Kota saat ini dalam rute

    // Jika semua kota telah dikunjungi, periksa rute saat ini
    if (path.size() == graph.size()) {
        currentDistance += graph[currentCity][0]; // Tambahkan jarak kembali ke titik awal
        // Jika jarak saat ini lebih pendek dari jarak terpendek yang ditemukan sebelumnya,
        // update jarak terpendek dan simpan rute terpendek
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            shortestPath = path;
        }
        return;
    }

    // Coba semua kemungkinan rute yang belum dieksplorasi
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            visited[i] = true; // tandai kota sebagai sudah dikunjungi
            path.push_back(i); // tambahkan kota ke rute saat ini
            
            // Cari rute terpendek dari kota saat ini ke kota selanjutnya
            findShortestPath(graph, path, visited, currentDistance + graph[currentCity][i]);
            
            visited[i] = false; // kota dikembalikan menjadi belum dikunjungi
            path.pop_back(); // hapus kota dari rute saat ini untuk mencoba rute lainnya
        }
    }
}

int main() {
    // Representasi graf berdasarkan soal
    vector<vector<int>> graph = {{0, 10, 30, 25}, {10, 0, 20, 15}, {30, 20, 0 ,35}, {25 ,15 ,35 ,0}};
    
    // Inisialisasi vektor visited dengan false untuk semua kota
    vector<bool> visited(graph.size(), false);
    visited[0] = true; // Mulai dari kota A
    
    vector<int> path = {0}; // Mulai dari kota A

    // Temukan rute terpendek
    findShortestPath(graph, path, visited, 0);

    // Tampilkan rute terpendek dan total jaraknya
    cout << "Rute terpendek: ";
    for (int city : shortestPath) {
        cout << char(city + 'A') << " "; // konversi indeks kota menjadi huruf dan tampilkan
    }
    cout << char(0 + 'A'); // Kembali ke kota A
    cout << "\nTotal Jarak: " << minDistance << endl;

    return 0;
}
