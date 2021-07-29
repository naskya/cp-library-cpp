---
title: Binary search
documentation_of: //include/search/binary_search.hpp
---

二分探索をする関数が定義されています。

## `binary_search(ok, ng, f, diff)`

`f` は `f(x)` というコードで呼び出せて、`bool` 型の値を返すもの(関数への参照, `operator()` が定義されているクラスのオブジェクト, ...)とします。`ok` は `f(ok)` が真となる値とし、`ng` は `f(ng)` が偽となる値とし、`diff` は小さい値にします。

整数値の二分探索では `diff` を $1$ に、実数値の二分探索では `diff` を許容誤差 ($10^{-9}$ など)に設定します。

これらの引数でこの関数を呼ぶと、`ok` と `ng` の値で、`f(x)` が真となるギリギリの値を探索して返します。

より厳密に言うと `ok` と `ng` の中間の値 `mid` で `f(mid)` を呼び出し、結果が真なら `ok = mid` と、偽なら `ng = mid` とすることを繰り返して探索範囲を狭めていき、`ok` と `ng` の差が `diff` 以下になった時の `ok` の値を返します。