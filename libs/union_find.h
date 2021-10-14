#include <iostream>
#include <memory>

typedef long long ll;

class UnionFind {
public:
  UnionFind(ll n) : par_(n, -1), siz_(n, 1) {}

  // xのルートとyのルートが一致しているか？
  bool is_same(ll x, ll y) {
    return root(x) == root(y);
  }

  // xのルートを取得する
  // また、経路圧縮も同時に行う
  ll root(ll x) {
    if (par_[x] == -1)
      return x;
    return par_[x] = root(par_[x]);
  }

  // xを含むグループとyを含むグループを結合する
  bool unit(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;

    if (siz_[x] < siz_[y])
      swap(x, y);

    par_[y] = x;
    siz_[x] += siz_[y];

    return true;
  }

  // xを含むグループの要素数（サイズ）を取得
  ll size(ll x) {
    return siz_[root(x)];
  }

private:
  std::vector<ll> par_;
  std::vector<ll> siz_;
};
