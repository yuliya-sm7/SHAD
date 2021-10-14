#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>

bool cover(double RR, double X[], double Y[], int kk, uint nn) {
    std::vector<std::pair<double, int>> XX(2*nn);
    uint nn_ok = 0;
    for (uint i = 0; i < nn; ++i) {
        if (RR*RR >= Y[i]*Y[i]) {
            double tmp = sqrt(RR*RR - Y[i] * Y[i]);
            XX[nn_ok*2] = std::make_pair(X[i] - tmp, -1);
            XX[nn_ok*2+1] = std::make_pair(X[i] + tmp, +1);
            nn_ok++;
        }
    }
    XX.resize(nn_ok*2);
    std::sort(XX.begin(), XX.end());
    int count = 0;
    for (uint i = 0; i < 2 * nn_ok; ++i) {
        count += -XX[i].second;
        if (count >= kk) return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(6);
    uint nn;
    int kk;
    std::cin >> nn >> kk;

    double X[nn];
    double Y[nn];
    for (uint i = 0; i < nn; ++i) {
        std::cin >> X[i] >> Y[i];
    }

    double start = 0, end = 2000;
    while (end - start > 0.000001) {
        double mm = (start + end) / 2;
        if (cover(mm, X, Y, kk, nn)) {
            end = mm;
        } else {
            start = mm;
        }
    }
    std::cout << std::fixed << end << '\n';
    return 0;
}
