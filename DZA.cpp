#include <iostream>
#include <algorithm>
#include <vector>
int inf = 2e9;

struct sliding_window {
    std::vector<int> LL, RR;
    int rmax;

    sliding_window() {
        rmax = -inf;
    }

    void push_back(int xx) {
        RR.push_back(xx);
        rmax = std::max(rmax, xx);
    }

    void pop_front() {
        if (LL.empty()) {
            for (int mn = -inf; !RR.empty();) {
                mn = std::max(mn, RR.back());
                LL.push_back(mn);
                RR.pop_back();
            }
            rmax = -inf;
        }
        LL.pop_back();
    }

    int get_max() {
        int res = rmax;
        if (!LL.empty()) res = std::max(res, LL.back());
        return res;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint nn;
    std::cin >> nn;
    int A[nn];
    for (uint i = 0; i < nn; ++i) {
        std::cin >> A[i];
    }
    uint mm, rr = 0;
    std::cin >> mm;

    sliding_window SW;
    SW.push_back(A[0]);

    char S;
    for (uint i = 0; i < mm; ++i) {
        std::cin >> S;
        if (S == 'L') {
            SW.pop_front();
        } else {
            rr++;
            SW.push_back(A[rr]);
        }
        std::cout << SW.get_max() << ' ';
    }
    std::cout << std::endl;
    return 0;
}
