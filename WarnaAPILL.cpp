#include <iostream>
using namespace std;

int main()
{
    int t;
    cout << "Masukkan detik ke: ";
    cin >> t;

    int cycle = ((t - 45) % 103 + 103) % 103;
    cycle = cycle + 1;

    if (cycle <= 3)
    {
        cout << "Lampu berwarna Kuning di detik ke: " << t << "\n";
    }
    else if (cycle <= 23)
    {
        cout << "Lampu berwarna Hijau di detik ke: " << t << "\n";
    }
    else
    {
        cout << "Lampu berwarna Merah di detik ke: " << t << "\n";
    }

    return 0;
}
