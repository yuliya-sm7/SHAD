#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    uint An, Bm, ll;
    std::cin >> An >> Bm >> ll;

    uint A[An][ll];
    for (uint i = 0; i < An; ++i) {
        for (uint j = 0; j < ll; ++j) {
            std::cin >> A[i][j];
        }
    }

    uint B[Bm][ll];
    for (uint i = 0; i < Bm; ++i) {
        for (uint j = 0; j < ll; ++j) {
            std::cin >> B[i][j];
        }
    }

    uint qq;
    std::cin >> qq;
    for (uint zz = 0; zz < qq; ++zz) {
        uint ii, jj;
        std::cin >> ii >> jj;
        int start = -1, end = static_cast<int>(ll);
        while (end - start > 1) {
            int mm = (start + end) / 2;
            if (A[ii - 1][mm] > B[jj - 1][mm]) {
                end = mm;
            } else {
                start = mm;
            }
        }
        if (start == -1 || (end != static_cast<int>(ll)
                            && A[ii - 1][end] < B[jj - 1][start])) {
            std::cout << end + 1 << '\n';
        } else {
            std::cout << start + 1 << '\n';
        }
    }

    return 0;
}
