#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include "TrieNode.h"

class Trie {
private:
    TrieNode* root;

    void insert(TrieNode* node, const std::string& word, int index);
    bool search(TrieNode* node, const std::string& word, int index) const;
    void collectWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& words) const;

public:
    Trie();
    ~Trie();
    void insert(const std::string& word);
    bool search(const std::string& word) const;
    std::vector<std::string> wordsWithPrefix(const std::string& prefix) const;
};

#endif
