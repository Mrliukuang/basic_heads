//
// Created by kuang on 15-7-14.
//

#ifndef TEST_HEADS_H
#define TEST_HEADS_H

// necessary head files for every C++ project
#include <string.h>
#include <assert.h>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <bitset>
#include <limits>
#include <sstream>
#include <climits>
#include <fstream>
#include <iostream>
#include <valarray>
#include <iterator>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int INF = 987654321;

// 输出二维矩阵
template<class T>
void printBoard(const T& board) {
    for (auto& a : board) {
        for (auto& b : a)
            cout << b << " ";
        cout << endl;
    }
}

// 输出向量
template<class T>
void printVector(const T& v) {
    for (auto& e : v)
        cout << e << " ";
    cout << endl;
}

// 替代 cout << ... << endl
template<class T>
void println(const T& a) {
    cout << a << endl;
}

// convert string vector to char vector function
vector<vector<char>> toBoard(vector<string>& v) {
    vector<vector<char>> board;
    for (string s : v) {
        vector<char> v;
        for (char c : s)
            v.push_back(c);
        board.push_back(v);
    }
    return board;
}

// 判断质数
template<class T>
bool isPrime(const T a) {
    if (a <= 1) return false;
    if (a == 2) return true;
    if (a % 2 == 0) return false;
    for (T b = 3; b <= sqrt(a); b += 2)
        if (a % b == 0) return false;
    return true;
}

// 判断回文字符串
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left <= right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}

// Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left, * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) { }

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) { }
};

// Union-Find
struct UF {
    vector<int> id, sz;

    UF(int n) : id(n), sz(n, 1) { // 注意这种简便的初始化方式
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }
    }

    int find(int u) {
        while (u != id[u]) {
            u = id[id[u]]; // path compression
        }
        return u;
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) {
            id[u] = v;
            sz[v] += sz[u];
        } else {
            id[v] = u;
            sz[u] += sz[v];
        }
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

// basic string split function
vector<string> split(const string& s, const char sep) {
    // make sure there is no extra spaces front and end.
    vector<string> splited;
    int left = 0, right = 0;
    while (right != string::npos) {
        right = s.find(sep, left);
        splited.push_back(s.substr(left, right - left));
        left = right + 1;
    }
    return splited;
}

#endif //TEST_HEADS_H
