#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Time {
    int hour;
    int minute;
};

void printTime(const Time& time) {
    cout << setw(2) << setfill('0') << time.hour << ":" << setw(2) << setfill('0') << time.minute;
}

Time getTime(const string& prompt) {
    Time time;
    char sep;

    do {
        cout << prompt;
        cin >> time.hour >> sep >> time.minute;

        if (cin.fail() || sep != ':' || time.hour < 0 || time.hour > 23 || time.minute < 0 || time.minute > 59) {
            cout << "Invalid time; try again.\n";
            cin.clear();

        } else {
            break;
        }
    } while (true);

    return time;
}

int main() {
    Time class1_start, class1_end, class2_start, class2_end;

    class1_start = getTime("Class 1 start time:\n");
    class1_end = getTime("Class 1 end time:\n");
    while (class1_end.hour < class1_start.hour || (class1_end.hour == class1_start.hour && class1_end.minute <= class1_start.minute)) {
        cout << "Start time must be later than end time; try again.\n";
        class1_start = getTime("Class 1 start time:\n");
        class1_end = getTime("Class 1 end time:\n");
    }

    class2_start = getTime("Class 2 start time:\n");
    class2_end = getTime("Class 2 end time:\n");
    while (class2_end.hour < class2_start.hour || (class2_end.hour == class2_start.hour && class2_end.minute <= class2_start.minute)) {
        cout << "Start time must be later than end time; try again.\n";
        class2_start = getTime("Class 2 start time:\n");
        class2_end = getTime("Class 2 end time:\n");
    }

    cout << "Class 1 runs from ";
    printTime(class1_start);
    cout << " to ";
    printTime(class1_end);
    cout << ".\n";

    cout << "Class 2 runs from ";
    printTime(class2_start);
    cout << " to ";
    printTime(class2_end);
    cout << ".\n";

    if (class1_end.hour < class2_start.hour || (class1_end.hour == class2_start.hour && class1_end.minute <= class2_start.minute) ||
        class2_end.hour < class1_start.hour || (class2_end.hour == class1_start.hour && class2_end.minute <= class1_start.minute)) {
        cout << "No conflict.\n";
    } else {
        cout << "Conflict!\n";
    }

    return 0;
}