

#include <iostream>
#include <string>
#include <cstring>
using namespace std;



union Number {
    int num;
    char word[9];
};

struct Car {
    string color;
    string model;
    bool isNum;
    Number number;
};

void fill(Car& car) {
    cout << "Колір: ";
    cin >> car.color;
    cout << "Модель: ";
    cin >> car.model;
    cout << "Номер числовий? ";
    cin >> car.isNum;
    if (car.isNum) {
        cout << "Введіть номер: ";
        cin >> car.number.num;
    }
    else {
        cout << "Введіть слово: ";
        cin >> car.number.word;
    }
}

void print(const Car& car) {
    cout << "Модель: " << car.model
        << ", Колір: " << car.color
        << ", Номер: ";
    if (car.isNum) cout << car.number.num;
    else cout << car.number.word;
    cout << endl;
}

void printAll(Car arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        print(arr[i]); 
    }
}

void search(Car arr[], int size) {
    cout << "Введіть номер для пошуку: ";
    string s;
    cin >> s;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].isNum && to_string(arr[i].number.num) == s) {
            print(arr[i]);
            found = true;
        }
        else if (!arr[i].isNum && strcmp(arr[i].number.word, s.c_str()) == 0) {
            print(arr[i]);
            found = true;
        }
    }
    if (!found) cout << "Не знайдено!" << endl;
}


int main() {
    Car cars[10];
    int count = 0;

    fill(cars[count++]);
    fill(cars[count++]);

    cout << "\nУсі машини:\n";
    printAll(cars, count);

    search(cars, count);

    return 0;
}

