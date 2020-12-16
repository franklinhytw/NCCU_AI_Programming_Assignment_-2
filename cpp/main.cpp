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

int main(int argc, char const *argv[]) {
    uint8_t n = 8;
    
    vector<uint16_t> init_queen {1,3,0,0,0,0,0,0};
    solve(init_queen);
    
    // 1 2 4 8 16 32 64 128 
    
    // SQR init_state {
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 0, 0, 0, 0, 0, 0, 0}
    // };

    // cout << "Initial State:" << endl;
    // printBoard(init_state);

    return 0;
}
