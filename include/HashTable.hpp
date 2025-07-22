#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <unordered_map>
#include <string>

class HashTable {
private:
    std::unordered_map<std::string, std::string> table;

public:
    void insert(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
};

#endif
