#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y;

    double getLen(const Point& a) {
        return std::sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
    }
};

int main() {
    int n, i;
    while (std::cin >> n && n) {
        Point point[10000];
        for (i = 0; i < n; i++)
            std::cin >> point[i].x >> point[i].y;

        std::sort(point, point + n, [](const Point& a, const Point& b) -> bool { return a.x < b.x; });

        double ans = 10000;
        for (i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (point[i].x + ans < point[j].x)
                    break;
                double d = point[i].getLen(point[j]);
                if (d < ans)
                    ans = d;
            }
        }

        if (ans == 10000)
            std::cout << "INFINITY" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(4) << ans << std::endl;
    }

    return 0;
}
