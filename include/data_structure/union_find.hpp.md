---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/1.test.cpp
    title: test/data_structure/union_find/1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/2.test.cpp
    title: test/data_structure/union_find/2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union-find data structure
    links:
    - https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp)
  bundledCode: "#line 1 \"include/data_structure/union_find.hpp\"\n\n//! @file union_find.hpp\n\
    //! @brief Union-find data structure\n//! @details Provide a data structure for\
    \ managing disjoint sets.\n//! @note This file is based on AtCoder Library (https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp)\n\
    \n#ifndef UNION_FIND_HPP\n#define UNION_FIND_HPP\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\n#ifndef O_assert\n//! @brief Assert macro\n\
    #  define O_assert(...) assert(__VA_ARGS__)\n#  define O_assert_not_defined\n\
    #endif\n\nnamespace lib {\n\n//! @brief Data structure for managing disjoint sets\n\
    class union_find {\nprivate:\n  const int nodes;\n  mutable std::vector<int> par_or_size;\n\
    \npublic:\n  //! @brief Construct an undirected graph with number_of_nodes nodes\
    \ and 0 edges\n  union_find(const int number_of_nodes)\n      : nodes(number_of_nodes),\
    \ par_or_size(number_of_nodes, -1) {}\n\n  //! @return Number of nodes in the\
    \ whole graph\n  [[nodiscard]] int size() const noexcept {\n    return nodes;\n\
    \  }\n\n  //! @param node Index of the node (0-indexed)\n  //! @return Index of\
    \ the parent node (0-indexed)\n  //! @note Time complexity: O(a(number_of_nodes))\
    \ where a is the inverse ackermann function\n  [[nodiscard]] int parent(const\
    \ int node) const {\n    O_assert(0 <= node && node < nodes);\n    if (par_or_size[node]\
    \ < 0)\n      return node;\n    else\n      return par_or_size[node] = parent(par_or_size[node]);\n\
    \  }\n\n  //! @param node_1 Index of node 1 (0-indexed)\n  //! @param node_2 Index\
    \ of node 2 (0-indexed)\n  //! @return Whether node 1 and node 2 belong to the\
    \ same group\n  //! @note Time complexity: O(a(number_of_nodes)) where a is the\
    \ inverse ackermann function\n  [[nodiscard]] bool same(const int node_1, const\
    \ int node_2) const {\n    return parent(node_1) == parent(node_2);\n  }\n\n \
    \ //! @param node Index of the node (0-indexed)\n  //! @return Size of the group\
    \ to which node belongs\n  //! @note Time complexity: O(1)\n  [[nodiscard]] int\
    \ group_size(const int node) const {\n    return -par_or_size[parent(node)];\n\
    \  }\n\n  //! @param node_1 Index of node 1 (0-indexed)\n  //! @param node_2 Index\
    \ of node 2 (0-indexed)\n  //! @return Whether the graph is changed by the operation\n\
    \  //! @note Time complexity: O(a(number_of_nodes)) where a is the inverse ackermann\
    \ function\n  [[maybe_unused]] bool merge(int node_1, int node_2) {\n    node_1\
    \ = parent(node_1);\n    node_2 = parent(node_2);\n\n    if (node_1 == node_2)\n\
    \      return false;\n\n    if (par_or_size[node_1] > par_or_size[node_2])\n \
    \     std::swap(node_1, node_2);\n    par_or_size[node_1] += par_or_size[node_2];\n\
    \    par_or_size[node_2] = node_1;\n\n    return true;\n  }\n\n  //! @return Vector\
    \ of the connected components of the graph\n  //! @note Time complexity: O(number_of_nodes)\n\
    \  [[nodiscard]] std::vector<std::vector<int>> groups() const {\n    std::vector<int>\
    \ leader_buf(nodes), group_size(nodes);\n    for (int i = 0; i < nodes; i++) {\n\
    \      leader_buf[i] = parent(i);\n      group_size[leader_buf[i]]++;\n    }\n\
    \    std::vector<std::vector<int>> res(nodes);\n    for (int i = 0; i < nodes;\
    \ i++) {\n      res[i].reserve(group_size[i]);\n    }\n    for (int i = 0; i <\
    \ nodes; i++) {\n      res[leader_buf[i]].emplace_back(i);\n    }\n    res.erase(\n\
    \      std::remove_if(std::begin(res), std::end(res),\n                     [&](const\
    \ std::vector<int>& v) { return v.empty(); }),\n      std::end(res));\n    return\
    \ res;\n  }\n};\n\n}  // namespace lib\n\n#ifdef O_assert_not_defined\n#  undef\
    \ O_assert\n#  undef O_assert_not_defined\n#endif\n\n#endif  // UNION_FIND_HPP\n"
  code: "\n//! @file union_find.hpp\n//! @brief Union-find data structure\n//! @details\
    \ Provide a data structure for managing disjoint sets.\n//! @note This file is\
    \ based on AtCoder Library (https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp)\n\
    \n#ifndef UNION_FIND_HPP\n#define UNION_FIND_HPP\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\n#ifndef O_assert\n//! @brief Assert macro\n\
    #  define O_assert(...) assert(__VA_ARGS__)\n#  define O_assert_not_defined\n\
    #endif\n\nnamespace lib {\n\n//! @brief Data structure for managing disjoint sets\n\
    class union_find {\nprivate:\n  const int nodes;\n  mutable std::vector<int> par_or_size;\n\
    \npublic:\n  //! @brief Construct an undirected graph with number_of_nodes nodes\
    \ and 0 edges\n  union_find(const int number_of_nodes)\n      : nodes(number_of_nodes),\
    \ par_or_size(number_of_nodes, -1) {}\n\n  //! @return Number of nodes in the\
    \ whole graph\n  [[nodiscard]] int size() const noexcept {\n    return nodes;\n\
    \  }\n\n  //! @param node Index of the node (0-indexed)\n  //! @return Index of\
    \ the parent node (0-indexed)\n  //! @note Time complexity: O(a(number_of_nodes))\
    \ where a is the inverse ackermann function\n  [[nodiscard]] int parent(const\
    \ int node) const {\n    O_assert(0 <= node && node < nodes);\n    if (par_or_size[node]\
    \ < 0)\n      return node;\n    else\n      return par_or_size[node] = parent(par_or_size[node]);\n\
    \  }\n\n  //! @param node_1 Index of node 1 (0-indexed)\n  //! @param node_2 Index\
    \ of node 2 (0-indexed)\n  //! @return Whether node 1 and node 2 belong to the\
    \ same group\n  //! @note Time complexity: O(a(number_of_nodes)) where a is the\
    \ inverse ackermann function\n  [[nodiscard]] bool same(const int node_1, const\
    \ int node_2) const {\n    return parent(node_1) == parent(node_2);\n  }\n\n \
    \ //! @param node Index of the node (0-indexed)\n  //! @return Size of the group\
    \ to which node belongs\n  //! @note Time complexity: O(1)\n  [[nodiscard]] int\
    \ group_size(const int node) const {\n    return -par_or_size[parent(node)];\n\
    \  }\n\n  //! @param node_1 Index of node 1 (0-indexed)\n  //! @param node_2 Index\
    \ of node 2 (0-indexed)\n  //! @return Whether the graph is changed by the operation\n\
    \  //! @note Time complexity: O(a(number_of_nodes)) where a is the inverse ackermann\
    \ function\n  [[maybe_unused]] bool merge(int node_1, int node_2) {\n    node_1\
    \ = parent(node_1);\n    node_2 = parent(node_2);\n\n    if (node_1 == node_2)\n\
    \      return false;\n\n    if (par_or_size[node_1] > par_or_size[node_2])\n \
    \     std::swap(node_1, node_2);\n    par_or_size[node_1] += par_or_size[node_2];\n\
    \    par_or_size[node_2] = node_1;\n\n    return true;\n  }\n\n  //! @return Vector\
    \ of the connected components of the graph\n  //! @note Time complexity: O(number_of_nodes)\n\
    \  [[nodiscard]] std::vector<std::vector<int>> groups() const {\n    std::vector<int>\
    \ leader_buf(nodes), group_size(nodes);\n    for (int i = 0; i < nodes; i++) {\n\
    \      leader_buf[i] = parent(i);\n      group_size[leader_buf[i]]++;\n    }\n\
    \    std::vector<std::vector<int>> res(nodes);\n    for (int i = 0; i < nodes;\
    \ i++) {\n      res[i].reserve(group_size[i]);\n    }\n    for (int i = 0; i <\
    \ nodes; i++) {\n      res[leader_buf[i]].emplace_back(i);\n    }\n    res.erase(\n\
    \      std::remove_if(std::begin(res), std::end(res),\n                     [&](const\
    \ std::vector<int>& v) { return v.empty(); }),\n      std::end(res));\n    return\
    \ res;\n  }\n};\n\n}  // namespace lib\n\n#ifdef O_assert_not_defined\n#  undef\
    \ O_assert\n#  undef O_assert_not_defined\n#endif\n\n#endif  // UNION_FIND_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2021-07-28 14:52:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/1.test.cpp
  - test/data_structure/union_find/2.test.cpp
documentation_of: include/data_structure/union_find.hpp
layout: document
redirect_from:
- /library/include/data_structure/union_find.hpp
- /library/include/data_structure/union_find.hpp.html
title: Union-find data structure
---