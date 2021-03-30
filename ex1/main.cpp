#include <iostream>
#include "BoardList.h"

using namespace std;
bool check_chars(string board_name){ //checking if the board name contains only letters or digits
    for (unsigned int i =0; i<board_name.length();i++) {
        if (!isalpha(board_name[i]) && !isalnum(board_name[i])){
            return false;
        }
    }
    return true;
}
bool check_board_name(string board_name) { //checks if the board name is legal as requested
    if (!(((board_name[0] >= 'A' && board_name[0] <= 'Z')) || ((board_name[0] >= 'a' && board_name[0] <= 'z' &&  check_chars(board_name))))) {
                return false;
        }
    return true;
}

int main() {
    string cmd,board_name, stamp_name;
    BoardList *boardList = new BoardList;
    int row, cols, x, y, color, radius;
    while (cin>>cmd)
    {
        if (cmd == "quit"){
            break;
        }
        if (cmd == "board") {
            cin >> board_name >> row >> cols;
            if (!row > 0 && cols > 0) {
                cerr <<"Board: number of rows and columns must be greater that zero" << endl;

            } else if (!check_board_name(board_name)) {
                cerr <<"Invalid board name '" << board_name<<"'"<<endl;
            } else {
                if (boardList->find_board(board_name) != NULL) {
                    boardList->DeleteNode(boardList->find_board(board_name));
                }
                boardList->AddNode(new Board(board_name, row, cols));
            }
        } else if (cmd == "plot") {
            cin >> board_name >> row >> cols>>color;
            if (!check_board_name(board_name)) {
                cerr <<"Invalid board name '" << board_name<<"'"<<endl;
                return 0;
            } else if (color > 7  || color < 0) {
                cerr <<"Invalid color number " << color << endl;

            } else if (boardList->find_board(board_name) == NULL) {
                cerr <<"Board named '" << board_name << "' not found" << endl;
            } else {
                boardList->find_board(board_name)->plot(row, cols, color);
            }

        } else if (cmd == "line") {
            cin >> board_name >> row >> cols >> x >> y >> color;
            if (!check_board_name(board_name)) {
                cerr <<"Invalid board name '" << board_name<<"'"<<endl;
            } else if (color > 7  || color < 0) {
                cerr <<"Invalid color number " << color << endl;

            } else if (boardList->find_board(board_name) == NULL) {
                cerr <<"Board named '" << board_name << "' not found" << endl;
            } else {
                boardList->find_board(board_name)->line(row, cols, x, y, color);
            }

        } else if (cmd == "circle") {
            cin >> board_name >> row >> cols >> radius >> color;
            if (!check_board_name(board_name)) {
                cerr <<"Invalid board name '" << board_name<<"'"<<endl;
            } else if (color > 7  || color < 0) {
                cerr << "Invalid color number " << color << endl;

            } else if (radius <0) {
                cerr << "Circle: radius must be non-negative" << endl;

            } else if (boardList->find_board(board_name) == NULL) {
                cerr <<"Board named '" << board_name << "' not found" << endl;
            } else {
                boardList->find_board(board_name)->circle(row, cols, radius, color);
            }

        } else if (cmd == "fill") {
            cin >>board_name>>row >> cols >> color;
            if (!check_board_name(board_name)) {
                cerr <<"Invalid board name '" << board_name<<"'"<<endl;
            } else if (color > 7  || color < 0) {
                cerr << "Invalid color number " << color << endl;

            } else if (color == 0) {
                cerr << "FloodFill: cannot flood with the background color" << endl;
            } else if (boardList->find_board(board_name) == NULL) {
                cerr <<"Board named '" << board_name << "' not found" << endl;
            } else {
                boardList->find_board(board_name)->fill(row, cols, color);
            }

        }
        else if (cmd == "stamp") {
            cin >> board_name >> x >> y >> stamp_name;
            if (!check_board_name(board_name)) {
                cerr <<"Invalid board name '" << board_name<<"'"<<endl;
            } else if (color > 7  || color < 0) {
                cerr << "Invalid color number " << color << endl;

            } else if (color == 0) {
                cerr << "FloodFill: cannot flood with the background color" << endl;
            } else if (boardList->find_board(board_name) == NULL) {
                cerr <<"Board named '" << board_name << "' not found" << endl;
            } else if (boardList->find_board(stamp_name) == NULL) {
                cerr <<"Board named '" << board_name << "' not found" << endl;
            }
            else{
                boardList->find_board(board_name)->stamp(x,y,boardList->find_board(stamp_name));
            }

        }
        else if (cmd == "print") {
            cin >> board_name;
            if (boardList->find_board(board_name) == NULL) {
                cerr << "Board named '" << board_name << "' not found" << endl;
            } else {
                boardList->find_board(board_name)->print();
            }
        }
        else  {
            cerr << "unknown command '" << cmd << "'" <<endl;
            break;
        }
    }
    return 0;
}
