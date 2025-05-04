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

void task1() {
    // 1) пусть у нас уже есть вектор data и число x
    std::vector<int> data = { /* ... */ };
    int x = {/* ... */};

    // 2) заменяем все простые числа на x
    std::replace_if(
        data.begin(), data.end(),
        [](int v){ return isPrime(v); },
        x
    );

    // 3) далее будем выводить результат
}

void task2() {

}

int main() {
    task1();
    task2();
    return 0;
}