#include <iostream>
#include <vector>
#include <algorithm>


uint aa, bb;
unsigned int cur = 0; // беззнаковое 32-битное число
unsigned int nextRand24() {
    cur = cur * aa + bb; // вычисляется с переполнениями
    return cur >> 8; // число от 0 до 2**24-1.
}


unsigned int nextRand32() {
    unsigned int aa = nextRand24(), bb = nextRand24();
    return (aa << 8) ^ bb; // число от 0 до 2**32-1.
}


int main() {
    uint nn;
    std::cin >> nn;
    std::cin >> aa >> bb;

    std::vector<uint> AA(nn);
    for (uint i = 0; i < nn; ++i) {
        AA[i] = nextRand32();
    }
    std::nth_element(AA.begin(), AA.begin()+nn/2, AA.end());
    uint yy = AA[nn/2];

    int64_t dist = 0;
    for (uint i = 0; i < nn; ++i) {
        dist += std::abs(static_cast<int64_t>(AA[i]) - yy);
    }

    std::cout << dist << std::endl;
    return 0;
}
