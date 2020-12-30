// File name: Trie.cpp
// Author: David Atwood

#include "Trie.h"
#include <fstream>


// The default constructor
Trie::Trie() : root(' ', false)
{
}


// pre: trie exists and word is passed
// post: word is added to the trie, by adding nodes and/or by switching a flag.
//      If word was already in the trie, nothing happens
void Trie::insert(const std::string& word)
{
    root.insert(word);
}


// pre: trie exists
// post: inserts all words in the specified file into the Trie. Throws a
// std::invalid_argument exception if the specified file cannot be
// opened.
void Trie::loadFromFile(const std::string& filename)
{
    std::ifstream infile;
    infile.open(filename);
    if (infile.fail()) {
        throw std::invalid_argument("Error opening input data file");
    } else {
        std::string cur;
        while (infile >> cur) {
            root.insert(cur);
        }
    }
    infile.close();
}


// pre: trie exists
// post: returns true if word is in the Trie, else returns false
bool Trie::isWord(const std::string& word) const
{
    return root.isWord(word);
}

// pre: trie exists
// post: returns true if pre is a prefix of a word in the Trie, else returns false
bool Trie::isPrefix(const std::string& pre) const
{
    return root.isPrefix(pre);
}

// pre: trie exists
// post: all words in trie are printed in alphabetical order, one per line
void Trie::print() const
{
    root.print("");
}
// pre: trie exists
// post: returns a count all the words in the trie
size_t Trie::wordCount() const
{
    return root.wordCount();
}
