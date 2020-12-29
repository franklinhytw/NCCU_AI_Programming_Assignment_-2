#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <random>

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

bool solve(ST_BOARD arg_init_queen, int8_t index, uint8_t queen_pos) {
    if(index >= 0) arg_init_queen.at(index) = queen_pos;
    // (index, queen_pos)
    unordered_map<uint8_t, uint8_t> q_mapping;

    // find the queen then save to mapping
    for (size_t t = 0 ; t < arg_init_queen.size() ; t++) {
        if(arg_init_queen.at(t)) {
            q_mapping.insert(pair<uint8_t, uint8_t>(t, arg_init_queen.at(t)));
        }
    }

    uint8_t n = arg_init_queen.size();

    if(q_mapping.size() == n) {
        cout << "============ GOAL STATE ===========" << endl;
        printBoard(arg_init_queen);
        cout << "===================================" << endl;
        return true;
    }

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
                    // printf("%u:%u:%u:%u:%u\n", num, q.first, q.second, cp1,cp2);
                    if(num == q.second || cp1 == cp2) {
                        is_attacked = true;
                        break;
                    }
                }
                if(is_attacked) continue;
                else {
                    // # put the queen
                    if(solve(arg_init_queen, (int8_t)t, num)) {
                        return true;
                    }
                }
            }
            // if no select any position, should be return previous index to select another position of queen.
            return false;
        }
    }
    return false;
}

vector<string> split(const string& str) {
	vector<string> res;
	if("" == str) return res;

	char * strs = new char[str.length() + 1] ;
	strcpy(strs, str.c_str()); 
  
	char *p = strtok(strs, ",");
	while(p) {
		string s = p;
		res.push_back(s);
		p = strtok(NULL, ",");
	}
 
	return res;
}

int randomInteger(int min, int max) {
    random_device rd;
	mt19937 generator = mt19937(rd());
	uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

void problem(ST_BOARD &board) {
    cout << "========== INITIAL STATE ==========" << endl;
    printBoard(board);
    cout << "===================================" << endl;

    bool rs = solve(board, -1, 0);
    if (rs) {
        cout << "[V] Find the solution!" << endl;
    } else
        cout << "[X] No Answer!" << endl;
}

int main(int argc, char const *argv[]) {
    if (argc >= 1) {
		if(argc <= 2) {
			cout << "Usage: [MODE]" << endl;
        	cout << "  -random ${n}          n = >4 number" << endl;
			cout << "  -init_state ${state}  $state example: '0,0,0,0,0,0,3,0'" << endl;
		}
		else if(argc == 3) {
			if(!strcmp(argv[1], "-random")) {
				int n = atoi(argv[2]);

                int index_rand = randomInteger(0, n-1);
                int queen_pos_rand = randomInteger(1, n);

                ST_BOARD init_board;

				for(size_t t = 0 ; t < n ; t++) {
                    if (t == (size_t)index_rand) init_board.push_back((uint8_t)queen_pos_rand);
                    else init_board.push_back(0);
                }

                problem(init_board);
			}
			else if(!strcmp(argv[1], "-init_state")) {
				string init_state = argv[2];
                vector<string> n_list = split(init_state);
                ST_BOARD init_board;
                for(const auto &n : n_list) {
                    init_board.push_back((uint8_t)stoi(n));
                }

                problem(init_board);
			}
		}
		exit(EXIT_SUCCESS);
    }
    return 0;
}
