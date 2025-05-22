#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

bool isDigits(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return !str.empty();
}

int enterDigit(const string& label) {
    string input;
    while (true) {
        cout << label;
        cin >> input;
        if (isDigits(input)) {
            return stoi(input);
        }
        cout << "Ошибка: введите целое число!" << endl;
    }
}

int getHours() {
    while (true) {
        int hours = enterDigit("Введите часы (0-23): ");
        if (hours >= 0 && hours <= 23) {
            return hours;
        }
        cout << "Часы должны быть от 0 до 23!" << endl;
    }
}

int getMinutes() {
    while (true) {
        int minutes = enterDigit("Введите минуты (0-59): ");
        if (minutes >= 0 && minutes <= 59) {
            return minutes;
        }
        cout << "Минуты должны быть от 0 до 59!" << endl;
    }
}

int toTotalMinutes(int hours, int minutes) {
    return hours * 60 + minutes;
}

int timeDifference(int totalMinutes) {
     int referenceTime = 12 * 60;
    return abs(totalMinutes - referenceTime);
}

int main() {
    int choice = 1;
    int H = 0, M = 0;

    while (choice != 0) {
        cout << "\n1. Ввести часы" << endl;
        cout << "2. Ввести минуты" << endl;
        cout << "3. Перевести время в минуты" << endl;
        cout << "4. Разница с 12:00" << endl;
        cout << "0. Выход" << endl;

        cout << "Выберите опцию - ";
        string input;
        cin >> input;

        try {
            choice = stoi(input);
        } catch (...) {
            cout << "Ошибка: введите число!" << endl;
            continue;
        }

        if (choice == 1) {
            H = getHours();
            cout << "Часы установлены: " << H << endl;
        } else if (choice == 2) {
            M = getMinutes();
            cout << "Минуты установлены: " << M << endl;
        } else if (choice == 3) {
            int total = toTotalMinutes(H, M);
            cout << "Общее время в минутах: " << total << endl;
        } else if (choice == 4) {
            int total = toTotalMinutes(H, M);
            int diff = timeDifference(total);
            cout << "Разница с 12:00 в минутах: " << diff << endl;
        } else if (choice == 0) {
            cout << "Выход из программы." << endl;
        } else {
            cout << "Неверный выбор!" << endl;
        }
    }

    return 0;
}