//
// Created by kuang on 15-7-14.
//

#ifndef TEST_HEADS_H
#define TEST_HEADS_H

// necessary head files for every C++ project
// #include <bits/stdc++.h>
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
#include <cctype>
#include <sstream>
#include <climits>
#include <numeric>
#include <fstream>
#include <iostream>
#include <valarray>
#include <iterator>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, n) for (int i = a; i < (n); ++i)

const int INF = 987654321;
const double PI = 3.1415926535898;
const double EPS = 1e-7;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> PII;
typedef vector<int> VI;

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

// Another way to output through iterators.
template<typename Iter>
ostream& _out(ostream& s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; ++it) s << (it == b ? "" : " ") << *it;
    s << "]";
    return s;
}

// use "cout<<" to output vector/set/pair/map
template<typename A, typename B>
ostream& operator<<(ostream& s, const pair<A, B>& p) { return s << "(" << p.first << ", " << p.second << ")"; }

template<typename T>
ostream& operator<<(ostream& s, const vector<T>& v) { return _out(s, ALL(v)); }

template<typename T>
ostream& operator<<(ostream& s, const set<T>& c) { return _out(s, ALL(c)); }

template<typename A, typename B>
ostream& operator<<(ostream& s, const map<A, B>& c) { return _out(s, ALL(c)); }

// 替代 cout << ... << endl
template<class T>
void println(const T& a) {
    cout << a << endl;
}

// convert string vector to char vector function
vector<vector<char>> toBoard(vector<string>& v) {
    vector<vector<char>> board;
    for (string s : v) {
        vector<char> w;
        for (char c : s)
            w.push_back(c);
        board.push_back(w);
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
    size_t left = 0;
    size_t right = s.size() - 1;
    while (left <= right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}

// 最大公约数
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
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
    size_t left = 0, right = 0;
    while (right != string::npos) {
        right = s.find(sep, left);
        splited.push_back(s.substr(left, right - left));
        left = right + 1;
    }
    return splited;
}

#endif //TEST_HEADS_H
