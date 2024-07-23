#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    double temp, realTemp = 0.0;
    char unit;

    cout << "Enter a temperature:" << endl;
    cin >> temp >> unit;
   
    cout << fixed << setprecision(2);

    if (unit == 'C') {
        realTemp = temp;
    } else if (unit == 'F') {
        realTemp = (temp - 32) * 5 / 9;
    } else if (unit == 'K') {
        realTemp = temp - 273.15;
    } else if (unit == 'R') {
        realTemp = (temp - 491.67) * 5 / 9;
    }

    cout << "= " << realTemp << " C" << endl;
    cout << "= " << (realTemp * 9 / 5 + 32) << " F" << endl;
    cout << "= " << (realTemp + 273.15) << " K" << endl;
    cout << "= " << ((realTemp + 273.15) * 9 / 5) << " R" << endl;

    return 0;
}