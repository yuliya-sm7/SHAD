#include <iostream>

int main() {
    int lenn;
    std::cin >> lenn;
    int A[lenn];
    for (int i = 0; i < lenn; ++i) {
        std::cin >> A[lenn-i-1];
    }
    if (lenn == 1) {
        std::cout << A[0];
        return 0;
    }

    int inc_idx[lenn]; // предыдущий элемент меньше
    int inc_len[lenn]; // длина последовательности
    int dec_idx[lenn]; // предыдущий элемент больше
    int dec_len[lenn]; // длина последовательности

    int max_len = 1;
    int max_idx = 1; // это конец
    for (int cur_idx = 0; cur_idx < lenn; ++cur_idx) {
        inc_idx[cur_idx] = -1;
        inc_len[cur_idx] = 1;
        dec_idx[cur_idx] = -1;
        dec_len[cur_idx] = 1;
        for (int prev_idx = 0; prev_idx < cur_idx; ++prev_idx) { // конец предыдущей
            // самой хорошей последовательности заканчивающейся на prev_idx
            if (A[prev_idx] < A[cur_idx]) {
                if (dec_len[prev_idx] + 1 >= inc_len[cur_idx]) {
                    inc_idx[cur_idx] = prev_idx;
                    inc_len[cur_idx] = dec_len[prev_idx] + 1;
                    if (max_len <= inc_len[cur_idx]) {
                        max_len = inc_len[cur_idx];
                        max_idx = cur_idx;
                    }
                }
            } else if (A[prev_idx] > A[cur_idx]) {
                if (inc_len[prev_idx] + 1 >= dec_len[cur_idx]) {
                    dec_idx[cur_idx] = prev_idx;
                    dec_len[cur_idx] = inc_len[prev_idx] + 1;
                    if (max_len <= dec_len[cur_idx]) {
                        max_len = dec_len[cur_idx];
                        max_idx = cur_idx;
                    }
                }
            }
        }
    }

    int ans[max_len];
    bool dec = dec_len[max_idx] == max_len;
    int pos = max_idx;
    for (int i = 0; i < max_len; ++i) {
        ans[i] = A[pos];
        if (dec) {
            pos = dec_idx[pos];
        } else {
            pos = inc_idx[pos];
        }
        dec = !dec;
    }

//    for (int i = 0; i < lenn; i++)
//        std::cout << inc_idx[i] << " ";
//    std::cout << std::endl;
//
//    for (int i = 0; i < lenn; i++)
//        std::cout << dec_idx[i] << " ";
//    std::cout << std::endl;
//
//    for (int i = 0; i < lenn; i++)
//        std::cout << inc_len[i] << " ";
//    std::cout << std::endl;
//
//    for (int i = 0; i < lenn; i++)
//        std::cout << dec_len[i] << " ";
//    std::cout << std::endl;

    for (int i = 0; i < max_len; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
