#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream f("phones.txt");
    vector<pair<string, double>> phones;
    string line;
    while (getline(f, line)) {
        size_t pos = line.find_last_of(' ');
        if (pos != string::npos) {
            string model = line.substr(0, pos);
            double price = stod(line.substr(pos + 1));
            phones.push_back({ model, price });
        }
    }

    string brand;
    double minP, maxP;
    cin >> brand >> minP >> maxP;

    bool found = false;
    for (auto& p : phones) {
        if (p.second >= minP && p.second <= maxP && p.first.find(brand) != string::npos) {
            cout << p.first << " " << p.second << endl;
            found = true;
        }
    }
    if (!found) cout << "Ничего не найдено";
}