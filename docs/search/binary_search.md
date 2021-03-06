---
title: Binary search
documentation_of: //include/search/binary_search.hpp
---

[二分探索](https://ja.wikipedia.org/wiki/%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2)をする関数が定義されています。

---

### `binary_search(ok, ng, f, diff)`

#### 引数

- `ok` - `f(ok)` が真となる十分大きい(または十分小さい)値
- `ng` - `f(ng)` が偽となる十分小さい(または十分大きい)値
- `f` - `f(x)` というコードで呼び出せて、`bool` 型の値を返すもの(関数への参照, `operator()` が定義されているクラスのオブジェクト 等)
- `diff` - 整数値の二分探索では $1$、実数値の二分探索では許容誤差 ($10^{-9}$ など)

#### 戻り値

`ok` と `ng` の間の値で、`f(x)` が真となるギリギリの値

より厳密に言うと `ok` と `ng` の中間の値 `mid` で `f(mid)` を呼び出し、結果が真なら `ok = mid` と、偽なら `ng = mid` とすることを繰り返して探索範囲を狭めていき、`ok` と `ng` の差が `diff` 以下になった時の `ok` の値を返します。

---
