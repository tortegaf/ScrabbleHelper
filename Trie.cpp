#include "Trie.h"
#include <algorithm>

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const std::string& word) {
    insert(root, word, 0);
}

void Trie::insert(TrieNode* node, const std::string& word, int index) {
    if (index == word.length()) {
        node->isEndOfWord = true;
        return;
    }
    char ch = word[index];
    if (node->children.find(ch) == node->children.end()) {
        node->children[ch] = new TrieNode();
    }
    insert(node->children[ch], word, index + 1);
}

bool Trie::search(const std::string& word) const {
    return search(root, word, 0);
}

bool Trie::search(TrieNode* node, const std::string& word, int index) const {
    if (index == word.length()) {
        return node->isEndOfWord;
    }
    char ch = word[index];
    if (node->children.find(ch) == node->children.end()) {
        return false;
    }
    return search(node->children[ch], word, index + 1);
}

std::vector<std::string> Trie::wordsWithPrefix(const std::string& prefix) const {
    std::vector<std::string> words;
    TrieNode* node = root;
    for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return words; 
        }
        node = node->children[ch];
    }
    collectWords(node, prefix, words);
    return words;
}

void Trie::collectWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& words) const {
    if (node->isEndOfWord) {
        words.push_back(prefix);
    }
    for (const auto& child : node->children) {
        collectWords(child.second, prefix + child.first, words);
    }
}
