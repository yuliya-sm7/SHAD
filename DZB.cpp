#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

bool CompareFeature(const std::pair<int, int64_t> &lhs, const std::pair<int, int64_t> &rhs) {
    return lhs.second < rhs.second;
}

int main() {
    uint nn;
    std::cin >> nn;
    std::vector<std::pair<int, int64_t>> players(nn);
    for (uint i = 0; i < nn; ++i) {
        int feature;
        std::cin >> feature;
        players[i] = std::make_pair(i, feature);
    }

    if (nn == 1) {
        std::cout << players[0].second << std::endl;
        std::cout << 1 << std::endl;
        return 0;
    }

    std::sort(players.begin(), players.end(), CompareFeature);

    int64_t maxx = 0;
    int64_t summ = 0;
    int64_t worst = 0, best;
    int begin = 0, end = 1;
    for (uint ii = 0; ii < nn; ++ii) {
        best = players[worst].second + players[worst + 1].second;
        if (players[ii].second <= best) {
            summ += players[ii].second;
        } else {
            if (summ > maxx) {
                maxx = summ;
                begin = worst;
                end = ii;
            }
            summ -= players[worst].second;
            --ii;
            ++worst;
        }
    }
    if (summ > maxx) {
        maxx = summ;
        begin = worst;
        end = nn;
    }

    std::vector<int> team;
    for (int i = begin; i < end; ++i) {
        team.push_back(players[i].first);
    }
    std::sort(team.begin(), team.end());

    std::cout << maxx << std::endl;
    for (uint i = 0; i < team.size(); ++i) {
        std::cout << team[i] + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}
