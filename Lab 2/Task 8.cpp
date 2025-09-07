#include <iostream>
using namespace std;

int main() {
    int days, times;
    cout << "Enter days and times per day: ";
    cin >> days >> times;

    int** temp = new int*[days];
    for (int i = 0; i < days; i++) {
        temp[i] = new int[times];
        int sum = 0;
        for (int j = 0; j < times; j++) {
            cin >> temp[i][j];
            sum += temp[i][j];
        }
        cout << "Day " << i+1 << " average: " << (float)sum / times << endl;
    }

    int hottest = 0, coldest = 0;
    for (int i = 1; i < days; i++) {
        if (temp[i][0] > temp[hottest][0]) hottest = i;
        if (temp[i][0] < temp[coldest][0]) coldest = i;
    }

    cout << "Hottest day: " << hottest+1 << "\nColdest day: " << coldest+1 << endl;

    for (int i = 0; i < days; i++) delete[] temp[i];
    delete[] temp;
}
