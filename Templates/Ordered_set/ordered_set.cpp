#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = tree<
    K, V, Comp,
    rb_tree_tag,
    tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

int main() {
    ordered_set<int> s;
    s.insert(20);
    s.insert(50);
    cout << s.order_of_key(60) << endl;   // count elements smaller than 60
    cout << *s.find_by_order(1) << endl;  // element with index 1
}