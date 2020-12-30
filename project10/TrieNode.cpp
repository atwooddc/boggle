// File name: TrieNode.cpp
// Author: David Atwood

#include "TrieNode.h"

// Class Constructor
TrieNode::TrieNode(char c, bool b) : letter(c), end(b)
{
    for (size_t i = 0; i < AL_SIZE; i++) {
        nextLetters[i] = nullptr;
    }
}

// The copy constructor
TrieNode::TrieNode(const TrieNode& rhs) : letter(rhs.letter), end(rhs.end)
{
    for (size_t i = 0; i < AL_SIZE; i++) {
        if (rhs.nextLetters[i] != nullptr) {
            nextLetters[i] = new TrieNode(*rhs.nextLetters[i]);
        } else {
            nextLetters[i] = nullptr;
        }
    }
}

//  The destructor
TrieNode::~TrieNode()
{
    for (size_t i = 0; i < AL_SIZE; i++) {
        if (nextLetters[i] != nullptr) {
            delete nextLetters[i];
            nextLetters[i] = nullptr;
        }
    }
}

// Assignment operator
const TrieNode& TrieNode::operator= (const TrieNode& rhs)
{
    if (this != &rhs) {
        TrieNode tmp(rhs);
        std::swap(letter, tmp.letter);
        std::swap(end, tmp.end);
        for (size_t i = 0; i < AL_SIZE; ++i) {
            std::swap(nextLetters[i], tmp.nextLetters[i]);
        }
    }
    return *this;
}

// Insert str starting with the given TrieNode. Create new TrieNodes
// as needed and be sure to set the boolean flag on the last node to
// true.
void TrieNode::insert(const std::string& str)
{
    if (str.length() == 0) {
        return;
    } else {
        size_t index = str[0] - 'a';
        if (str.length() > 1) {
            if (nextLetters[index] == nullptr) {
                nextLetters[index] = new TrieNode(str[0], false);
            }
            nextLetters[index]->insert(str.substr(1));
        } else { //str.length() == 1
            if (nextLetters[index] == nullptr) {
                nextLetters[index] = new TrieNode(str[0], true);
            } else {
                nextLetters[index]->end = true;
            }
        }
    }
}

// Returns true if str is in the sub-Trie starting at the given TrieNode,
// else returns false
bool TrieNode::isWord(const std::string& str) const
{
    if (str.length() == 0) {
        return false;
    }
    size_t index = str[0] - 'a';
    if (nextLetters[index] == nullptr) {
        return false;
    } else if (str.length() == 1) {
        return nextLetters[index]->end;
    } else {
        return nextLetters[index]->isWord(str.substr(1));
    }
}

// Returns true if pre is a prefix of a word in the sub-Trie starting at
// the given TrieNode, else returns false
bool TrieNode::isPrefix(const std::string& pre) const
{
    if (pre.length() == 0) {
        return true;
    } else if (nextLetters[pre[0] - 'a'] == nullptr) {
        return false;
    } else {
        return nextLetters[pre[0] - 'a']->isPrefix(pre.substr(1));
    }
}

// Prints all words starting at the given TrieNode. The parameter
// string str stores the letters of all previous TrieNode objects up to
// the node currently being processed.
void TrieNode::print(const std::string& str) const
{
    if (end) {
        std::cout << str << std::endl;
    }
    for (size_t i = 0; i < AL_SIZE; ++i) {
        if (nextLetters[i] != nullptr) {
            std::string cur = str + nextLetters[i]->letter;
            nextLetters[i]->print(cur);
        }
    }
}

//  Returns a count all the nodes in the sub-Trie that end a word.
size_t TrieNode::wordCount() const
{
    size_t count = 0;
    if (end) {
        count++;
    }
    for (size_t i = 0; i < AL_SIZE; ++i) {
        if (nextLetters[i] != nullptr) {
            count += nextLetters[i]->wordCount();
        }
    }
    return count;
}