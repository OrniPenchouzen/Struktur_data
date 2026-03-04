#include <iostream>

// Расширенный алгоритм Евклида
int gcdExtended(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    // Находим НОД(a, b) и коэффициенты x0, y0 такие, что a*x0 + b*y0 = gcd(a,b)
    int x0, y0;
    int gcd = gcdExtended(a, b, x0, y0);

    // Проверяем, существует ли решение
    if (c % gcd != 0) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    // Находим частное решение
    int k = c / gcd;
    long long x = (long long)x0 * k;
    long long y = (long long)y0 * k;

    // Общее решение: x = x0*(c/gcd) + (b/gcd)*t
    //                 y = y0*(c/gcd) - (a/gcd)*t
    // где t - целое число

    // Находим t, чтобы x был наименьшим неотрицательным
    long long step = b / gcd;  // шаг изменения x

    if (step < 0) step = -step;  // делаем шаг положительным

    if (x >= 0) {
        // Уменьшаем x, пока он остается неотрицательным
        long long t = x / step;
        x -= t * step;
        y += t * (a / gcd);
    }
    else {
        // Увеличиваем x до первого неотрицательного значения
        long long t = (-x + step - 1) / step;  // ceil(-x / step)
        x += t * step;
        y -= t * (a / gcd);
    }

    // Дополнительная проверка: если x все еще отрицательный
    if (x < 0) {
        x += step;
        y -= (a / gcd);
    }

    std::cout << x << " " << y << std::endl;

    return 0;
}
