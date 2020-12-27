#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm>

#define SQR               vector<ST_BOARD>
#define QUUEN_LIST_STRUCT vector<tuple<uint8_t, uint8_t>>

using namespace std;

typedef vector<uint16_t> ST_BOARD;

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

void putQueen(ST_BOARD &board) {
    uint16_t queen_index = 0;
    // ST_BOARD queen_index; // start from zero

    // find the quuen
    for (size_t i = 0 ; i < board.size() ; i++) {
        if(board.at(i) > 0) {
            queen_index = i;
            break;
            // queen_index.push_back(i);
        }
    }

    for (size_t i = queen_index+1 ; i < board.size() ; i++) {
        
    }

    for (size_t i = 0 ; i < board.size() ; i++) {
        auto it = find(queen_index.begin(), queen_index.end(), i);
        if (it != queen_index.end()) continue;

        ST_BOARD unavailable_state; 
        for (const auto &qi : queen_index) {
            uint8_t cur_num = (uint8_t)(1 << qi-1);
        }
    }
    // for (size_t q = 0 ; q < queen_index.size()-1 ; q++) {
    //     for (size_t s = q+1 ; s < queen_index.size() ; s++) {
    //         if(queen_index.at(q) )
    //     }
    // }
}

void solve(ST_BOARD &arg_init_queen) {
    // transfer to binary mode
    ST_BOARD board;

    for (const auto &pos : arg_init_queen) {
        board.push_back((uint8_t)(1 << pos-1));
    }

    for (const auto &pos : board) {
        cout << (int)pos << ",";
    }
    cout << endl;

    // putQueen(board);
}

int main(int argc, char const *argv[]) {
    // uint8_t n = 8;
    
    ST_BOARD init_queen {3,0,0,0,0,0,0,0};
    printBoard(init_queen);
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
