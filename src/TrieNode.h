#ifndef TRIENODE_H
#define TRIENODE_H

#include <map>
#include <string>

class TrieNode {
public:
    bool isEndOfWord;
    std::map<char, TrieNode*> children;

    TrieNode() : isEndOfWord(false) {}
    ~TrieNode();
};

#endif
