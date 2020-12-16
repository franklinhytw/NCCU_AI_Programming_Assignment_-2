#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm>

#define SQR               vector<vector<uint8_t>>
#define QUUEN_LIST_STRUCT vector<tuple<uint8_t, uint8_t>>

using namespace std;

void printBoard(SQR &board) {
    size_t count = board.size();
    for (size_t x = 0 ; x < count ; x++) {
        for (size_t y = 0 ; y < count ; y++) {
            if(board[x][y] == 1) {
                printf("Q|");
            }
            else printf(" |");
        }
        printf("\n");
    }
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

bool isAttcked(vector<uint16_t> &board) {
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

void putQueen(vector<uint16_t> &board) {
    vector<uint8_t> queen_index; // start from zero

    // find the quuen
    for (size_t i = 0 ; i < board.size() ; i++) {
        if(board.at(i) > 0) {
            queen_index.push_back(i);
        }
    }

    for (size_t i = 0 ; i < board.size() ; i++) {
        auto it = find(queen_index.begin(), queen_index.end(), i);
        if (it != queen_index.end()) continue;

        vector<uint16_t> unavailable_state; 
        for (const auto &qi : queen_index) {
            uint16_t cur_num = (uint16_t)(1 << qi-1);
        }
    }
    // for (size_t q = 0 ; q < queen_index.size()-1 ; q++) {
    //     for (size_t s = q+1 ; s < queen_index.size() ; s++) {
    //         if(queen_index.at(q) )
    //     }
    // }
}

void solve(vector<uint16_t> &arg_init_queen) {
    // transfer to binary mode
    vector<uint16_t> board;

    for (const auto &pos : arg_init_queen) {
        board.push_back((uint16_t)(1 << pos-1));
    }

    for (const auto &pos : board) {
        cout << (int)pos << ",";
    }
    cout << endl;

    putQueen(board);
}

void expand(SQR &board) {
    vector<tuple<uint8_t, uint8_t>> combination_list, queen_list;

    vector<uint8_t> x_list, y_list, x_avail_list, y_avail_list;

    size_t count = board.size();
    for (size_t x = 0 ; x < count ; x++) {
        for (size_t y = 0 ; y < count ; y++) {
            if(board[x][y] == 1) {
                x_list.push_back(x);
                x_list.push_back(y);
                tuple<uint8_t, uint8_t> tp(x,y);
                queen_list.push_back(tp);
            }
        }
        printf("\n");
    }

    for (size_t ct = 0 ; ct < count ; ct++) {
        auto itx = find(x_list.begin(), x_list.end(), ct);
        if (itx == x_list.end()) {
            x_avail_list.push_back(ct);
        }

        auto ity = find(y_list.begin(), y_list.end(), ct);
        if (ity == y_list.end()) {
            y_avail_list.push_back(ct);
        }
    }

    for (const auto &x : x_avail_list) {
        for (const auto &y : y_avail_list) {
            tuple<uint8_t, uint8_t> tp(x,y);
            combination_list.push_back(tp);
        }
    }

    for (const auto &queen : queen_list) {
        for (const auto &comb : combination_list) {
            uint8_t distance_pre = abs(get<0>(queen) - get<0>(comb));
            uint8_t distance_next = abs(get<1>(queen) - get<1>(comb));

            if (distance_pre == distance_next) {
                for (size_t cp = 0 ; cp < combination_list.size() ; cp++) {
                    if(get<0>(comb) == get<0>(combination_list.at(cp)) && get<1>(comb) == get<1>(combination_list.at(cp))) {
                        cout << "FUNC" << endl;
                        combination_list.erase(combination_list.begin()+cp);
                    }
                }
            }
        }
    }

    for (const auto &comb : combination_list) {
        printf("(%u,%u), ", get<0>(comb), get<1>(comb));
    }

}

int main(int argc, char const *argv[]) {
    // 1 2 4 8 16 32 64 128 
    
    SQR init_state {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}
    };

    cout << "Initial State:" << endl;
    printBoard(init_state);

    expand(init_state);

    return 0;
}
