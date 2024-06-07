#include "TrieNode.h"

TrieNode::~TrieNode() {
    for (auto& child : children) {
        delete child.second;
    }
}
