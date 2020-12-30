// File name: TrieNode.h
// Author: David Atwood

#ifndef PROJECT9_TRIENODE_H
#define PROJECT9_TRIENODE_H
#include <string>
#include <stdexcept>
#include <iostream>


const size_t AL_SIZE = 26;

class TrieNode {
private:

    typedef TrieNode* TrieNodePtr;

    char letter;

    bool end;

    TrieNodePtr nextLetters[AL_SIZE];

public:

    // Class Constructor
    TrieNode(char c, bool b);

    // The copy constructor
    TrieNode(const TrieNode& rhs);

    //  The destructor
    ~TrieNode( );

    // Assignment operator
    const TrieNode& operator= (const TrieNode& rhs);

    // Insert str starting with the given TrieNode. Create new TrieNodes
    // as needed and be sure to set the boolean flag on the last node to
    // true.
    void insert(const std::string& str);

    // Returns true if str is in the sub-Trie starting at the given TrieNode,
    // else returns false
    bool isWord(const std::string& str) const;

    // Returns true if pre is a prefix of a word in the sub-Trie starting at
    // the given TrieNode, else returns false
    bool isPrefix(const std::string& pre) const;

    // Prints all words starting at the given TrieNode. The parameter
    // string str stores the letters of all previous TrieNode objects up to
    // the node currently being processed.
    void print(const std::string& str) const;

    //  Returns a count all the nodes in the sub-Trie that end a word.
    size_t wordCount() const;

};


#endif //PROJECT9_TRIENODE_H
