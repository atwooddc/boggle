// File name: Trie.h
// Author: David Atwood

#ifndef PROJECT9_TRIE_H
#define PROJECT9_TRIE_H
#include "TrieNode.h"


class Trie {
private:

    TrieNode root;

public:
    //  The default constructor
    Trie();

    // Insert the parameter word into the Trie
    void insert(const std::string& word);

    // Insert all words in the specified file into the Trie. Throws a
    // std::invalid_argument exception if the specified file cannot be
    // opened.
    void loadFromFile(const std::string& filename);

    // Returns true if word is in the Trie, else returns false
    bool isWord(const std::string& word) const;

    // Returns true if pre is a prefix of a word in the Trie, else returns false
    bool isPrefix(const std::string& pre) const;

    //  Print all words in the Trie, one per line. Print in alphabetical order.
    void print() const;

    // Returns a count all the words in the Trie
    size_t wordCount() const;
};


#endif //PROJECT9_TRIE_H
