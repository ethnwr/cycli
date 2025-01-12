#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Для setw и setfill

using namespace std;

// ------------------------------------------------------------------
// Задание 1: Анализ числа
// ------------------------------------------------------------------
void analyzeNumber() {
    long long number;
    cout << "Введите целое число: ";
    cin >> number;

    if (number == 0) {
        cout << "Количество цифр: 1" << endl;
        cout << "Сумма цифр: 0" << endl;
        cout << "Среднее арифметическое: 0.0" << endl;
        cout << "Количество нулей: 1" << endl;
    }
    else {
        long long temp = abs(number);
        int digitCount = 0;
        int digitSum = 0;
        int zeroCount = 0;

        while (temp > 0) {
            int digit = temp % 10;
            digitCount++;
            digitSum += digit;
            if (digit == 0) {
                zeroCount++;
            }
            temp /= 10;
        }

        cout << "Количество цифр: " << digitCount << endl;
        cout << "Сумма цифр: " << digitSum << endl;
        cout << "Среднее арифметическое: " << fixed << setprecision(2) << (double)digitSum / digitCount << endl;
        cout << "Количество нулей: " << zeroCount << endl;
    }

}

// ------------------------------------------------------------------
// Задание 2: Шахматная доска
// ------------------------------------------------------------------
void drawChessboard() {
    int cellSize;
    cout << "Введите размер клеточки: ";
    cin >> cellSize;

    for (int row = 0; row < 8; ++row) {
        for (int cellRow = 0; cellRow < cellSize; ++cellRow) {
            for (int col = 0; col < 8; ++col) {
                if ((row + col) % 2 == 0) {
                    cout << setw(cellSize) << setfill('*') << ""; // Заполнение *
                }
                else {
                    cout << setw(cellSize) << setfill('-') << ""; // Заполнение -
                }

            }
            cout << endl;
        }

    }
}

// ------------------------------------------------------------------
// Задание 3: Расчет заказа в кафетерии
// ------------------------------------------------------------------
void cafeOrder() {
    int numPeople;
    cout << "На сколько человек заказ? ";
    cin >> numPeople;

    if (numPeople <= 0) {
        cout << "Некорректное количество людей" << endl;
        return;
    }

    // Меню (название напитка, цена)
    vector<pair<string, double>> menu = {
        {"Кофе", 2.50},
        {"Чай", 2.00},
        {"Сок", 2.20},
        {"Пирожное", 3.00},
        {"Торт", 5.50},
        {"Мороженое", 3.50}
    };

    double totalOrderSum = 0.0;

    for (int person = 1; person <= numPeople; ++person) {
        cout << "\nЗаказ для человека №" << person << ":" << endl;
        double personSum = 0.0;
        int choice;

        do {
            cout << "\nМеню:\n";
            for (int i = 0; i < menu.size(); ++i) {
                cout << i + 1 << ". " << menu[i].first << " - $" << menu[i].second << endl;
            }
            cout << "0. Завершить заказ для этого человека" << endl;
            cout << "Выберите пункт меню: ";
            cin >> choice;
            if (choice > 0 && choice <= menu.size()) {
                personSum += menu[choice - 1].second;
                cout << "Добавлено в заказ: " << menu[choice - 1].first << ", текущая сумма: $" << personSum << endl;
            }
            else if (choice != 0) {
                cout << "Некорректный выбор" << endl;
            }

        } while (choice != 0);
        totalOrderSum += personSum;
        cout << "Общая сумма для человека " << person << " : $" << personSum << endl;
    }
    cout << "\nИтоговая сумма общего заказа: $" << fixed << setprecision(2) << totalOrderSum << endl;
}

// ------------------------------------------------------------------
// Задание 4: Вывод номеров полей игры "Морской бой"
// ------------------------------------------------------------------
void drawSeaBattleField() {
    char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            cout << letters[col] << row << " ";
        }
        cout << endl;
    }
}


// ------------------------------------------------------------------
// Меню
// ------------------------------------------------------------------
int main() {
    int choice;
    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Анализ числа\n";
        cout << "2. Нарисовать шахматную доску\n";
        cout << "3. Расчет заказа в кафетерии\n";
        cout << "4. Вывести поле Морской бой\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            analyzeNumber();
            break;
        case 2:
            drawChessboard();
            break;
        case 3:
            cafeOrder();
            break;
        case 4:
            drawSeaBattleField();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);
    return 0;
}