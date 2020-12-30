// File name: Boggle.cpp
// Author: David Atwood

#include "Boggle.h"

// Constructor
// pre: boggle-in.txt and ospd.txt are valid files
// post: dictionary contains all valid words,
//      foundWords initialized,
//      board is a square array of dice with letters from boggle-in.txt,
//      numWords initialized to 0
Boggle::Boggle() : dictionary(), foundWords(), numWords(0)
{
    readDict();
    std::ifstream infile;
    infile.open(BOARD_FILE);
    if (infile.fail()) {
        throw std::invalid_argument("Error opening input data file");
    } else {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                die cur;
                infile >> cur.letter;
                cur.used = false;
                board[i][j] = cur;
            }
        }
    }
    infile.close();
}

// private helper for constructor
// reads in ospd.txt and inserts words into dictionary Trie
void Boggle::readDict()
{
    std::ifstream infile;
    infile.open(DICT_FILE);
    if (infile.fail()) {
        throw std::invalid_argument("Error opening input data file");
    } else {
        std::string cur;
        while (infile >> cur) {
            dictionary.insert(cur);
        }
    }
    infile.close();
}

// public play() method
// pre: Boggle object exists
// post: calls recursive backtracking solver for each position in board,
//      prints findings to console
void Boggle::play()
{
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            findWords("", i, j); // calls recursive solver
        }
    }
    std::cout << "The computer found the following words:" << std::endl;
    std::cout << "============" << std::endl;
    foundWords.print();
    std::cout << "============" << std::endl;
    std::cout << "The computer found " << numWords << " words." << std::endl;
}

// private helper - recursive backtracking solver
// pre: Boggle object exists
// post: inserts str param into findWords if appropriate,
//      calls increment() on [row][col] if in bounds, not a deadend,
//      and unused
void Boggle::findWords(std::string str, int row, int col)
{
    if (MIN_LENGTH <= str.length() && dictionary.isWord(str) && !foundWords.isWord(str)) {
        foundWords.insert(str);
        numWords++;
    }
    if (dictionary.isPrefix(str) && !board[row][col].used) {
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            str += board[row][col].letter;
            board[row][col].used = true;
            increment(str, row, col);
            board[row][col].used = false;
        }
    }
}

// private helper
// calls findWords on all adjacent and diagonal squares to [row][col]
void Boggle::increment(const std::string &str, int row, int col)
{
    int rowDown = row - 1;
    int rowUp = row + 1;
    int colRight = col + 1;
    int colLeft = col - 1;
    findWords(str, row, colRight);
    findWords(str, rowDown, colRight);
    findWords(str, rowDown, col);
    findWords(str, rowDown, colLeft);
    findWords(str, row, colLeft);
    findWords(str, rowUp, colLeft);
    findWords(str, rowUp, col);
    findWords(str, rowUp, colRight);
}
