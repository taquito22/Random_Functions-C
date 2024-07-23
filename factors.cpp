#include <iostream>
#include <cmath>

using namespace std;

bool primer(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void primePrint(int n) {
    int x = abs(n);
    if (x < 2) {
        cout << "This number has no prime factors." << endl;
        return;
    }

    cout << "The prime factors of " << n << " are:" << endl;

    for (int i = 2; i <= x; ++i) {
        while (x % i == 0 && primer(i)) {
            int count = 0;
            while (x % i == 0) {
                x /= i;
                ++count;
            }

            cout << i;
            if (count > 1) {
                cout << '^' << count;
            }
            cout << endl;
        }
    }
}

int main() {
    int num;

    cout << "Enter a number:" << endl;
    cin >> num;
  
    primePrint(num);

    return 0;
}