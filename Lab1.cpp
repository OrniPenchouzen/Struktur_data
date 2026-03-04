#include <iostream>
#include <locale>

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

    std::locale::global(std::locale("Russian"));
    int x0, y0;
    int gcd = gcdExtended(a, b, x0, y0);

   
    if (c % gcd != 0) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

   
    int k = c / gcd;
    long long x = (long long)x0 * k;
    long long y = (long long)y0 * k;



   
    long long step = b / gcd; 

    if (step < 0) step = -step;  
    if (x >= 0) {
        
        long long t = x / step;
        x -= t * step;
        y += t * (a / gcd);
    }
    else {
     
        long long t = (-x + step - 1) / step;  
        x += t * step;
        y -= t * (a / gcd);
    }

  
    if (x < 0) {
        x += step;
        y -= (a / gcd);
    }

    std::cout << x << " " << y << std::endl;
    std::cout << "Зыков Алексей Александрович 020303-АИСа-о25"

    return 0;
}
