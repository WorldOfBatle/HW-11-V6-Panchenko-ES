#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// Проверяет, является ли n простым (n > 1)
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    // пробуем делители от 2 до sqrt(n)
    int lim = static_cast<int>(std::sqrt(n));
    for (int d = 2; d <= lim; ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

// Удаляет из вектора каждый k-й элемент
void removeEveryK(std::vector<int>& data, size_t k) {
    if (k == 0) {
        return;
    }
    size_t idx = 1;
    auto it = std::remove_if(
        data.begin(), data.end(),
        [&](int) {
            return (idx++ % k) == 0;
        }
    );
    data.erase(it, data.end());
}

void task1() {
    std::cout << "\n--- Task 1: замена простых чисел на x ---\n";

    // 1) вводим размер последовательности
    std::cout << "Введите количество элементов: ";
    size_t n;
    std::cin >> n;

    // 2) читаем саму последовательность
    std::vector<int> data(n);
    std::cout << "Введите " << n << " целых чисел через пробел:\n";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    // 3) читаем значение x
    std::cout << "Введите значение x: ";
    int x;
    std::cin >> x;

    // 4) заменяем все простые числа на x
    std::replace_if(
        data.begin(), data.end(),
        [](int v){ return isPrime(v); },
        x
    );

    // 5) выводим результат
    std::cout << "Результат: ";
    for (int v : data) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

void task2() {
    std::cout << "\n--- Task 2: удаление каждого k-го элемента ---\n";

    // 1) вводим количество элементов
    std::cout << "Введите количество элементов: ";
    size_t n;
    std::cin >> n;

    // 2) читаем саму последовательность
    std::vector<int> data(n);
    std::cout << "Введите " << n << " целых чисел через пробел:\n";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    // 3) вводим k
    std::cout << "Введите k (каждый k-й элемент будет удалён): ";
    size_t k;
    std::cin >> k;

    // 4) удаляем каждый k-й элемент
    removeEveryK(data, k);

    // 5) выводим результат
    std::cout << "Результат: ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    task1();
    task2();
    return 0;
}