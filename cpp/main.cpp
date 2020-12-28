#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <math.h>
#include <algorithm>
#include <set>
#include <cstdlib>

#define QUUEN_LIST_STRUCT vector<tuple<uint8_t, uint8_t>>

using namespace std;

typedef vector<uint8_t> ST_BOARD;

void printBoard(ST_BOARD &board) {
    size_t count = board.size();
    for (size_t x = 0; x < count; x++) {
        for (size_t y = 0; y < count; y++) {
            if (board[y] == x+1) {
                printf("Q|");
            } else
                printf(" |");
        }
        printf("\n");
    }
    printf("\n");
}

#if 0
QUUEN_LIST_STRUCT availableNextStep(SQR &board) {
    size_t count = board.size();
    QUUEN_LIST_STRUCT queen_list;

    // find all queen position
    for (size_t x = 0 ; x < count ; x++) {
        for (size_t y = 0 ; y < count ; y++) {
            if(board[x][y] == 1) {
                tuple<uint8_t, uint8_t> pos(x,y);
                queen_list.push_back(pos);
            }
        }
    }


    return true;
}
#endif

bool isAttcked(ST_BOARD &board) {
    for (size_t i = 0 ; i < board.size() ; i++) {
        auto &s = board.at(i);
        if(s) {
            auto it = find(board.begin(), board.end(), s);
            if (it != board.end()) return true;
            else {
                int start_dis = i-0;
            }
        }
    }
}

bool solve(ST_BOARD arg_init_queen, int8_t index, uint8_t queen_pos) {
    if(index >= 0) arg_init_queen.at((int)index) = queen_pos;
    // (index, queen_pos)
    unordered_map<uint8_t, uint8_t> q_mapping;

    // find the queen then save to mapping
    for (size_t t = 0 ; t < arg_init_queen.size() ; t++) {
        if(arg_init_queen.at(t)) {
            q_mapping.insert(pair<uint8_t, uint8_t>(t, arg_init_queen.at(t)));
        }
    }

    uint8_t n = arg_init_queen.size();

    if(q_mapping.size() == n) return true;

    // solving problem
    for (size_t t = 0 ; t < n ; t++) {
        auto it = q_mapping.find(t);
        if(it == q_mapping.end()) {
            //select queen of position:
            for (size_t num = 1 ; num <= n ; num++) {
                // check if available
                bool is_attacked = false;
                for(const auto &q : q_mapping) {
                    uint8_t cp1 = abs(q.first - (uint8_t)t);
                    uint8_t cp2 = abs(q.second - (uint8_t)num);
                    printf("%u:%u:%u:%u:%u\n", num, q.first, q.second, cp1,cp2);
                    if(num == q.second || cp1 == cp2) {
                        is_attacked = true;
                        break;
                    }
                }
                if(is_attacked) continue;
                else {
                    //# put the queen
                    return solve(arg_init_queen, (int)t, num);
                }
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    // uint8_t n = 8;
    
    ST_BOARD init_queen {4,0,0,0,0,0,0,0};
    printBoard(init_queen);
    bool ans = solve(init_queen, -1, 0);
    cout << ans << endl;
    
    // 1 2 4 8 16 32 64 128 
    
    // SQR init_state {
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {Q, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0}
    // };

    // cout << "Initial State:" << endl;
    // printBoard(init_state);

    return 0;
}
