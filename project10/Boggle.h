// File name: Boggle.h
// Author: David Atwood

#ifndef PROJECT10_BOGGLE_H
#define PROJECT10_BOGGLE_H

#include <string>
#include <iostream>
#include <fstream>
#include "Trie.h"


const std::string DICT_FILE = "ospd.txt";
const std::string BOARD_FILE = "boggle-in.txt";
const int MIN_LENGTH = 4;
const int BOARD_SIZE = 4;


class Boggle {
private:

    struct die {
        char letter;
        bool used;
    };

    //holds all valid words
    Trie dictionary;

    Trie foundWords;

    int numWords;

    //holds board
    die board[BOARD_SIZE][BOARD_SIZE];

    //read words from ospd.txt into Trie dictionary
    void readDict();

    void findWords(std::string str, int row, int col);

    void increment(const std::string &str, int row, int col);

public:

    Boggle();

    void play();

};


#endif //PROJECT10_BOGGLE_H
