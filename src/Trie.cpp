#include "Trie.hpp"

TrieNode::TrieNode() : isEndOfWord(false) {}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    clear(root);
}

void Trie::clear(TrieNode* node) {
    for (auto& pair : node->children) {
        clear(pair.second);
    }
    delete node;
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children[ch];
    }
    return current->isEndOfWord;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* current = root;
    for (char ch : prefix) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children[ch];
    }
    return true;
}
