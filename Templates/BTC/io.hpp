#pragma once
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, const pair<T, U> &p) {
    return stream << p.first << " " << p.second;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, const vector<T> &vec) {
    for (const T &x : vec) out << x << ' ';
    return out;
}
template <typename T>
std::istream &operator>>(std::istream &in, vector<T> &vec) {
    for (auto &x : vec) in >> x;
    return in;
}