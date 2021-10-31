#include <iostream>
#include <vector>


std::vector<int> merge(std::vector<int> &nums1, std::vector<int> &nums2) {
    int nn = nums2.size();
    int mm = nums1.size();
    int li = 0, rj = 0;
    std::vector<int> MM(mm + nn);
    for (int k = 0; k < mm + nn; ++k) {
        if (rj >= nn || (li < mm && nums1[li] <= nums2[rj])) {
            MM[k] = nums1[li], li++;
        } else {
            MM[k] = nums2[rj], rj++;
        }
    }
    return MM;
}


int main() {
    uint nn, mm;
    std::cin >> nn >> mm;

    std::vector<std::vector<int>> AA(nn, std::vector<int>(mm));
    for (uint i = 0; i < nn; ++i) {
        for (uint j = 0; j < mm; ++j) {
            std::cin >> AA[i][j];
        }
    }

    uint col = (nn + 1) / 2;
    std::vector<std::vector<int>> BB;
    while (AA.size() > 1) {
        BB = std::vector<std::vector<int>>(col);
        for (uint j = 0; j + 1 < AA.size(); j += 2) {
            BB[j / 2] = merge(AA[j], AA[j + 1]);
        }
        if (AA.size() % 2 == 1) {
            BB[col - 1] = AA[AA.size() - 1];
        }
        col = (col + 1) / 2;
        AA = BB;
    }

    for (uint i = 0; i < nn * mm; ++i) {
        std::cout << AA[0][i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
