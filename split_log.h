//
// Created by rudri on 7/26/2023.
//

#ifndef DEMO_SPLIT_LOG_H
#define DEMO_SPLIT_LOG_H
#include <iostream>
#include <regex>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

template <typename Key, typename Value>
std::vector<Key> keys_as_initializer_list(const std::unordered_map<Key, Value>& map) {
    std::vector<Key> keys;
    transform(begin(map), end(map), back_inserter(keys), [](const auto& pair){ return pair.first;});
    return keys;
}

template <typename Iterator, typename UnaryFunction>
void split_log(Iterator start, Iterator stop, UnaryFunction fun) {
    regex re(
            R"((\w+)\s+-\s)"
            R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}.\d{3});\s)"
            R"((.+);\s)"
            R"((.+)->)"
            R"((.+):)"
            R"((.+)\s)"
            R"(webapp=(.+)\s)"
            R"(path=(.+)\s)"
            R"(params=(.+)\s)"
            R"(hits=(.+)\s)"
            R"(status=(.+)\s)"
            R"(QTime=(.+))"
    );
    unordered_map<int, string> fields = {
            {1, "tag"},
            {2, "timestamp"},
            {3, "namespace"},
            {4, "entry"},
            {5, "entry_timestamp"},
            {6, "collection"},
            {7, "webapp"},
            {8, "path"},
            {9, "params"},
            {10, "hits"},
            {11, "status"},
            {12, "QTime"},
    };
    auto it = sregex_token_iterator(start, stop, re, keys_as_initializer_list(fields));
    auto w_end = sregex_token_iterator();
    for (int i = 0; i < size(fields); ++i) {
        auto m = *it++;
        fun(fields[i+1], m.str());
    }
}

#endif //DEMO_SPLIT_LOG_H
