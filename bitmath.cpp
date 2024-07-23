#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int subtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b; 
        a = a ^ b; 
        b = borrow << 1; 
    }
    return a;
}

void printNum(unsigned int num) {
    cout << "0b";
for (int i = 31; i >= 0; i = subtract(i, 1)) {
       cout << ((num >> i) & 1);
}
    cout << "  ";
    cout << "0x" << hex << setw(8) << setfill('0') << num << "  ";
    cout << dec << num << endl;
}

unsigned int add(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int change = a & b;
        a = a ^ b;
        b = change << 1;
    }
    return a;
}

unsigned int sub(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    return a;
}

unsigned int mul(unsigned int a, unsigned int b) {
    unsigned int result = 0;
    while (b != 0) {
        if (b & 1) {
            result = add(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int main() {
    string Operation;
    cout << "Operation:\n";
    cin >> Operation;

    if (Operation == "see") {
        unsigned int operand;
        cout << "First operand:\n";
        cin >> operand;
        printNum(operand);
    } else if (Operation == "add" || Operation == "sub" || Operation == "mul") {
        unsigned int operand1, operand2;
        cout << "First operand:\n";
        cin >> operand1;
        cout << "Second operand:\n";
        cin >> operand2;

        if (Operation == "add") {
            unsigned int result = add(operand1, operand2);
            printNum(operand1);
            printNum(operand2);
            printNum(result);
        } else if (Operation == "sub") {
            unsigned int result = sub(operand1, operand2);
            printNum(operand1);
            printNum(operand2);
            printNum(result);
        } else if (Operation == "mul") {
            unsigned int result = mul(operand1, operand2);
            printNum(operand1);
            printNum(operand2);
            printNum(result);
        }
    } else {
        cout << "Invalid Operation.\n";
    }

    return 0;
}