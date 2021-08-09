---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/minimum_spanning_tree/1.test.cpp
    title: test/graph/minimum_spanning_tree/1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/minimum_spanning_tree/2.test.cpp
    title: test/graph/minimum_spanning_tree/2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/minimum_spanning_tree/3.test.cpp
    title: test/graph/minimum_spanning_tree/3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/minimum_spanning_tree/4.test.cpp
    title: test/graph/minimum_spanning_tree/4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Print warning message
    links: []
  bundledCode: "#line 1 \"include/graph/minimum_spanning_tree.hpp\"\n\n//! @file minimum_spanning_tree.hpp\n\
    \n#ifndef MINIMUM_SPANNING_TREE_HPP\n#define MINIMUM_SPANNING_TREE_HPP\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <queue>\n#include <tuple>\n#include\
    \ <vector>\n\n#ifndef warn\n#  if (CP_LIBRARY_DEBUG_LEVEL >= 1)\n//! @brief Print\
    \ warning message\n//! @note You can suppress the warning by uncommenting line\
    \ 18\n#    define warn(msg) (std::cerr << (msg) << '\\n')\n// #  define warn(msg)\
    \ (static_cast<void>(0))\n#  else\n#    define warn(msg) (static_cast<void>(0))\n\
    #  endif\n#  define warn_not_defined\n#endif\n\n#ifndef O_assert\n//! @brief Assert\
    \ macro\n#  define O_assert(...) assert(__VA_ARGS__)\n#  define O_assert_not_defined\n\
    #endif\n\nnamespace lib {\n\nnamespace internal {\n  //! @note from union_find.hpp\n\
    \  class simple_union_find {\n  private:\n    const int nodes;\n    mutable std::vector<int>\
    \ par_or_size;\n\n  public:\n    simple_union_find(const int number_of_nodes)\n\
    \        : nodes(number_of_nodes), par_or_size(number_of_nodes, -1) {}\n\n   \
    \ [[nodiscard]] int parent(const int node) const {\n      O_assert(0 <= node &&\
    \ node < nodes);\n      if (par_or_size[node] < 0)\n        return node;\n   \
    \   else\n        return par_or_size[node] = parent(par_or_size[node]);\n    }\n\
    \n    [[maybe_unused]] bool merge(int node_1, int node_2) {\n      node_1 = parent(node_1);\n\
    \      node_2 = parent(node_2);\n\n      if (node_1 == node_2)\n        return\
    \ false;\n\n      if (par_or_size[node_1] > par_or_size[node_2])\n        std::swap(node_1,\
    \ node_2);\n      par_or_size[node_1] += par_or_size[node_2];\n      par_or_size[node_2]\
    \ = node_1;\n\n      return true;\n    }\n  };\n}  // namespace internal\n\n//!\
    \ @brief Find the minimum spanning tree from edge list using Kruskal method.\n\
    //! @tparam TotalCostType type of total cost (NOT deduced from parameter, int\
    \ or long long should work in most cases)\n//! @tparam NodeIndexType type of node\
    \ indices (deduced from parameter)\n//! @tparam CostType type of costs (deduced\
    \ from parameter)\n//! @tparam Container container type of edge list (deduced\
    \ from parameter)\n//! @param nodes number of nodes\n//! @param edge_list list\
    \ of edges (edges must be represented as {node_1, node_2, cost})\n//! @return\
    \ std::pair<vector, CostType> (list of edges in minimum spanning tree, total cost)\n\
    //! @note time complexity: O(E log V) where E is number of edges and V is number\
    \ of nodes\ntemplate <typename TotalCostType, typename NodeIndexType, typename\
    \ CostType, template <typename...> typename Container>\n[[nodiscard]] auto minimum_spanning_tree(const\
    \ int nodes,\n                                         const Container<std::tuple<NodeIndexType,\
    \ NodeIndexType, CostType>>& edge_list) {\n  using Edge = std::tuple<NodeIndexType,\
    \ NodeIndexType, CostType>;\n  std::pair<std::vector<Edge>, TotalCostType> res\
    \ {{}, TotalCostType(0)};\n\n  if (edge_list.empty()) {\n    warn(\"An empty edge\
    \ list is provided.\");\n    return res;\n  }\n\n  auto edge_list_cpy = edge_list;\n\
    \n  std::sort(std::begin(edge_list_cpy), std::end(edge_list_cpy), [](const Edge&\
    \ lhs, const Edge& rhs) {\n    return std::get<2>(lhs) < std::get<2>(rhs);\n \
    \ });\n\n  internal::simple_union_find uf(nodes);\n\n  for (auto&& [node_1, node_2,\
    \ cost] : edge_list_cpy) {\n    if (uf.merge(node_1, node_2)) {\n      res.first.emplace_back(node_1,\
    \ node_2, cost);\n      res.second += cost;\n    }\n  }\n\n  return res;\n}\n\n\
    //! @brief Find the minimum spanning tree from edge list using Kruskal method.\n\
    //! @tparam TotalCostType type of total cost (NOT deduced from parameter, int\
    \ or long long should work in most cases)\n//! @tparam NodeIndexType type of node\
    \ indices (deduced from parameter)\n//! @tparam CostType type of costs (deduced\
    \ from parameter)\n//! @tparam Container container type of edge list (deduced\
    \ from parameter)\n//! @param nodes number of nodes\n//! @param edge_list list\
    \ of edges (edges must be represented as {node_1, node_2, cost})\n//! @return\
    \ std::pair<vector, CostType> (list of edges in minimum spanning tree, total cost)\n\
    //! @note time complexity: O(E log V) where E is number of edges and V is number\
    \ of nodes\ntemplate <typename TotalCostType, typename NodeIndexType, typename\
    \ CostType, template <typename...> typename Container>\n[[nodiscard]] auto minimum_spanning_tree(const\
    \ int nodes,\n                                         Container<std::tuple<NodeIndexType,\
    \ NodeIndexType, CostType>>&& edge_list) {\n  using Edge = std::tuple<NodeIndexType,\
    \ NodeIndexType, CostType>;\n  std::pair<std::vector<Edge>, TotalCostType> res\
    \ {{}, TotalCostType(0)};\n\n  if (edge_list.empty()) {\n    warn(\"An empty edge\
    \ list is provided.\");\n    return res;\n  }\n\n  std::sort(std::begin(edge_list),\
    \ std::end(edge_list), [](const Edge& lhs, const Edge& rhs) {\n    return std::get<2>(lhs)\
    \ < std::get<2>(rhs);\n  });\n\n  internal::simple_union_find uf(nodes);\n\n \
    \ for (auto&& [node_1, node_2, cost] : edge_list) {\n    if (uf.merge(node_1,\
    \ node_2)) {\n      res.first.emplace_back(node_1, node_2, cost);\n      res.second\
    \ += cost;\n    }\n  }\n\n  return res;\n}\n\n//! @brief Find the minimum spanning\
    \ tree from adjacency list using Prim method.\n//! @tparam TotalCostType type\
    \ of total cost (NOT deduced from parameter, int or long long should work in most\
    \ cases)\n//! @tparam NodeIndexType type of node indices (deduced from parameter)\n\
    //! @tparam CostType type of costs (deduced from parameter)\n//! @tparam Container\
    \ container type of adjacency list (deduced from parameter)\n//! @param adjacency_list\
    \ adjacency_list[i] = { std::pair(a, cost_between_i_a), std::pair(b, cost_between_i_b),\
    \ ... }\n//! @return std::pair<2d vector, CostType> (adjacency list of minimun\
    \ spanning tree, total cost)\n//! @note time complexity: O(E log V) where E is\
    \ number of edges and V is number of nodes\ntemplate <typename TotalCostType,\
    \ typename NodeIndexType, typename CostType, template <typename...> typename Container>\n\
    [[nodiscard]] auto minimum_spanning_tree(const Container<Container<std::pair<NodeIndexType,\
    \ CostType>>>& adjacency_list) {\n  const int nodes = static_cast<int>(std::size(adjacency_list));\n\
    \  std::pair res {std::vector<std::vector<std::pair<NodeIndexType, CostType>>>(nodes),\
    \ TotalCostType(0)};\n\n  if (nodes == 0) {\n    warn(\"An empty adjacency list\
    \ is provided.\");\n    return res;\n  }\n\n  using Edge = std::tuple<CostType,\
    \ NodeIndexType, NodeIndexType>;\n  std::priority_queue<Edge, std::vector<Edge>,\
    \ std::greater<Edge>> heap;\n\n  std::vector<signed char> reached(nodes, false);\n\
    \  reached[0] = true;\n\n  for (const auto& [node, cost] : adjacency_list[0])\n\
    \    heap.emplace(cost, 0, node);\n\n  while (!heap.empty()) {\n    const auto\
    \ [cost_1_2, node_1, node_2] = heap.top();\n    heap.pop();\n\n    if (reached[node_2])\n\
    \      continue;\n\n    reached[node_2] = true;\n    res.second += cost_1_2;\n\
    \    res.first[node_1].emplace_back(node_2, cost_1_2);\n    res.first[node_2].emplace_back(node_1,\
    \ cost_1_2);\n\n    for (const auto& [node_3, cost_2_3] : adjacency_list[node_2])\n\
    \      if (!reached[node_3])\n        heap.emplace(cost_2_3, node_2, node_3);\n\
    \  }\n\n  return res;\n}\n\n//! @brief Find the minimum spanning tree from adjacency\
    \ matrix using Prim method.\n//! @tparam TotalCostType type of total cost (NOT\
    \ deduced from parameter, int or long long should work in most cases)\n//! @tparam\
    \ CostType type of costs (deduced from parameter)\n//! @tparam Container container\
    \ type of adjacency matrix (deduced from parameter)\n//! @param adjacency_matrix\
    \ adjacency_matrix[i][j] = (cost between i, j) or (infinity) if there's no edge\
    \ between i, j\n//! @param infinity very large number that indicates there is\
    \ no edge\n//! @return std::pair<2d vector, CostType> (adjacency matrix of minimun\
    \ spanning tree, total cost)\n//! @note time complexity: O(E log V) where E is\
    \ number of edges and V is number of nodes\ntemplate <typename TotalCostType,\
    \ typename CostType, template <typename...> typename Container>\n[[nodiscard]]\
    \ auto minimum_spanning_tree(const Container<Container<CostType>>& adjacency_matrix,\n\
    \                                         const CostType infinity) {\n  const\
    \ int nodes = static_cast<int>(std::size(adjacency_matrix));\n  std::pair res\
    \ {std::vector(nodes, std::vector<CostType>(nodes, infinity)), TotalCostType(0)};\n\
    \n  if (nodes == 0) {\n    warn(\"An empty adjacency matrix is provided.\");\n\
    \    return res;\n  }\n\n  using Edge = std::tuple<CostType, int, int>;\n  std::priority_queue<Edge,\
    \ std::vector<Edge>, std::greater<Edge>> heap;\n\n  std::vector<signed char> reached(nodes,\
    \ false);\n  reached[0] = true;\n\n  for (int i = 1; i < nodes; ++i)\n    if (adjacency_matrix[0][i]\
    \ < infinity)\n      heap.emplace(adjacency_matrix[0][i], 0, i);\n\n  while (!heap.empty())\
    \ {\n    const auto [cost_1_2, node_1, node_2] = heap.top();\n    heap.pop();\n\
    \n    if (reached[node_2])\n      continue;\n\n    reached[node_2] = true;\n \
    \   res.second += cost_1_2;\n    res.first[node_1][node_2] = res.first[node_2][node_1]\
    \ = cost_1_2;\n\n    for (int node_3 = 0; node_3 < nodes; ++node_3)\n      if\
    \ (adjacency_matrix[node_2][node_3] < infinity && !reached[node_3])\n        heap.emplace(adjacency_matrix[node_2][node_3],\
    \ node_2, node_3);\n  }\n\n  return res;\n}\n\n}  // namespace lib\n\n#ifdef warn_not_defined\n\
    #  undef warn\n#  undef warn_not_defined\n// warn may be defined 2 times (by uncommenting\
    \ line 18)\n#  ifdef warn\n#    undef warn\n#  endif\n#endif\n\n#ifdef O_assert_not_defined\n\
    #  undef O_assert\n#  undef O_assert_not_defined\n#endif\n\n#endif  // MINIMUM_SPANNING_TREE_HPP\n"
  code: "\n//! @file minimum_spanning_tree.hpp\n\n#ifndef MINIMUM_SPANNING_TREE_HPP\n\
    #define MINIMUM_SPANNING_TREE_HPP\n\n#include <algorithm>\n#include <cassert>\n\
    #include <queue>\n#include <tuple>\n#include <vector>\n\n#ifndef warn\n#  if (CP_LIBRARY_DEBUG_LEVEL\
    \ >= 1)\n//! @brief Print warning message\n//! @note You can suppress the warning\
    \ by uncommenting line 18\n#    define warn(msg) (std::cerr << (msg) << '\\n')\n\
    // #  define warn(msg) (static_cast<void>(0))\n#  else\n#    define warn(msg)\
    \ (static_cast<void>(0))\n#  endif\n#  define warn_not_defined\n#endif\n\n#ifndef\
    \ O_assert\n//! @brief Assert macro\n#  define O_assert(...) assert(__VA_ARGS__)\n\
    #  define O_assert_not_defined\n#endif\n\nnamespace lib {\n\nnamespace internal\
    \ {\n  //! @note from union_find.hpp\n  class simple_union_find {\n  private:\n\
    \    const int nodes;\n    mutable std::vector<int> par_or_size;\n\n  public:\n\
    \    simple_union_find(const int number_of_nodes)\n        : nodes(number_of_nodes),\
    \ par_or_size(number_of_nodes, -1) {}\n\n    [[nodiscard]] int parent(const int\
    \ node) const {\n      O_assert(0 <= node && node < nodes);\n      if (par_or_size[node]\
    \ < 0)\n        return node;\n      else\n        return par_or_size[node] = parent(par_or_size[node]);\n\
    \    }\n\n    [[maybe_unused]] bool merge(int node_1, int node_2) {\n      node_1\
    \ = parent(node_1);\n      node_2 = parent(node_2);\n\n      if (node_1 == node_2)\n\
    \        return false;\n\n      if (par_or_size[node_1] > par_or_size[node_2])\n\
    \        std::swap(node_1, node_2);\n      par_or_size[node_1] += par_or_size[node_2];\n\
    \      par_or_size[node_2] = node_1;\n\n      return true;\n    }\n  };\n}  //\
    \ namespace internal\n\n//! @brief Find the minimum spanning tree from edge list\
    \ using Kruskal method.\n//! @tparam TotalCostType type of total cost (NOT deduced\
    \ from parameter, int or long long should work in most cases)\n//! @tparam NodeIndexType\
    \ type of node indices (deduced from parameter)\n//! @tparam CostType type of\
    \ costs (deduced from parameter)\n//! @tparam Container container type of edge\
    \ list (deduced from parameter)\n//! @param nodes number of nodes\n//! @param\
    \ edge_list list of edges (edges must be represented as {node_1, node_2, cost})\n\
    //! @return std::pair<vector, CostType> (list of edges in minimum spanning tree,\
    \ total cost)\n//! @note time complexity: O(E log V) where E is number of edges\
    \ and V is number of nodes\ntemplate <typename TotalCostType, typename NodeIndexType,\
    \ typename CostType, template <typename...> typename Container>\n[[nodiscard]]\
    \ auto minimum_spanning_tree(const int nodes,\n                              \
    \           const Container<std::tuple<NodeIndexType, NodeIndexType, CostType>>&\
    \ edge_list) {\n  using Edge = std::tuple<NodeIndexType, NodeIndexType, CostType>;\n\
    \  std::pair<std::vector<Edge>, TotalCostType> res {{}, TotalCostType(0)};\n\n\
    \  if (edge_list.empty()) {\n    warn(\"An empty edge list is provided.\");\n\
    \    return res;\n  }\n\n  auto edge_list_cpy = edge_list;\n\n  std::sort(std::begin(edge_list_cpy),\
    \ std::end(edge_list_cpy), [](const Edge& lhs, const Edge& rhs) {\n    return\
    \ std::get<2>(lhs) < std::get<2>(rhs);\n  });\n\n  internal::simple_union_find\
    \ uf(nodes);\n\n  for (auto&& [node_1, node_2, cost] : edge_list_cpy) {\n    if\
    \ (uf.merge(node_1, node_2)) {\n      res.first.emplace_back(node_1, node_2, cost);\n\
    \      res.second += cost;\n    }\n  }\n\n  return res;\n}\n\n//! @brief Find\
    \ the minimum spanning tree from edge list using Kruskal method.\n//! @tparam\
    \ TotalCostType type of total cost (NOT deduced from parameter, int or long long\
    \ should work in most cases)\n//! @tparam NodeIndexType type of node indices (deduced\
    \ from parameter)\n//! @tparam CostType type of costs (deduced from parameter)\n\
    //! @tparam Container container type of edge list (deduced from parameter)\n//!\
    \ @param nodes number of nodes\n//! @param edge_list list of edges (edges must\
    \ be represented as {node_1, node_2, cost})\n//! @return std::pair<vector, CostType>\
    \ (list of edges in minimum spanning tree, total cost)\n//! @note time complexity:\
    \ O(E log V) where E is number of edges and V is number of nodes\ntemplate <typename\
    \ TotalCostType, typename NodeIndexType, typename CostType, template <typename...>\
    \ typename Container>\n[[nodiscard]] auto minimum_spanning_tree(const int nodes,\n\
    \                                         Container<std::tuple<NodeIndexType,\
    \ NodeIndexType, CostType>>&& edge_list) {\n  using Edge = std::tuple<NodeIndexType,\
    \ NodeIndexType, CostType>;\n  std::pair<std::vector<Edge>, TotalCostType> res\
    \ {{}, TotalCostType(0)};\n\n  if (edge_list.empty()) {\n    warn(\"An empty edge\
    \ list is provided.\");\n    return res;\n  }\n\n  std::sort(std::begin(edge_list),\
    \ std::end(edge_list), [](const Edge& lhs, const Edge& rhs) {\n    return std::get<2>(lhs)\
    \ < std::get<2>(rhs);\n  });\n\n  internal::simple_union_find uf(nodes);\n\n \
    \ for (auto&& [node_1, node_2, cost] : edge_list) {\n    if (uf.merge(node_1,\
    \ node_2)) {\n      res.first.emplace_back(node_1, node_2, cost);\n      res.second\
    \ += cost;\n    }\n  }\n\n  return res;\n}\n\n//! @brief Find the minimum spanning\
    \ tree from adjacency list using Prim method.\n//! @tparam TotalCostType type\
    \ of total cost (NOT deduced from parameter, int or long long should work in most\
    \ cases)\n//! @tparam NodeIndexType type of node indices (deduced from parameter)\n\
    //! @tparam CostType type of costs (deduced from parameter)\n//! @tparam Container\
    \ container type of adjacency list (deduced from parameter)\n//! @param adjacency_list\
    \ adjacency_list[i] = { std::pair(a, cost_between_i_a), std::pair(b, cost_between_i_b),\
    \ ... }\n//! @return std::pair<2d vector, CostType> (adjacency list of minimun\
    \ spanning tree, total cost)\n//! @note time complexity: O(E log V) where E is\
    \ number of edges and V is number of nodes\ntemplate <typename TotalCostType,\
    \ typename NodeIndexType, typename CostType, template <typename...> typename Container>\n\
    [[nodiscard]] auto minimum_spanning_tree(const Container<Container<std::pair<NodeIndexType,\
    \ CostType>>>& adjacency_list) {\n  const int nodes = static_cast<int>(std::size(adjacency_list));\n\
    \  std::pair res {std::vector<std::vector<std::pair<NodeIndexType, CostType>>>(nodes),\
    \ TotalCostType(0)};\n\n  if (nodes == 0) {\n    warn(\"An empty adjacency list\
    \ is provided.\");\n    return res;\n  }\n\n  using Edge = std::tuple<CostType,\
    \ NodeIndexType, NodeIndexType>;\n  std::priority_queue<Edge, std::vector<Edge>,\
    \ std::greater<Edge>> heap;\n\n  std::vector<signed char> reached(nodes, false);\n\
    \  reached[0] = true;\n\n  for (const auto& [node, cost] : adjacency_list[0])\n\
    \    heap.emplace(cost, 0, node);\n\n  while (!heap.empty()) {\n    const auto\
    \ [cost_1_2, node_1, node_2] = heap.top();\n    heap.pop();\n\n    if (reached[node_2])\n\
    \      continue;\n\n    reached[node_2] = true;\n    res.second += cost_1_2;\n\
    \    res.first[node_1].emplace_back(node_2, cost_1_2);\n    res.first[node_2].emplace_back(node_1,\
    \ cost_1_2);\n\n    for (const auto& [node_3, cost_2_3] : adjacency_list[node_2])\n\
    \      if (!reached[node_3])\n        heap.emplace(cost_2_3, node_2, node_3);\n\
    \  }\n\n  return res;\n}\n\n//! @brief Find the minimum spanning tree from adjacency\
    \ matrix using Prim method.\n//! @tparam TotalCostType type of total cost (NOT\
    \ deduced from parameter, int or long long should work in most cases)\n//! @tparam\
    \ CostType type of costs (deduced from parameter)\n//! @tparam Container container\
    \ type of adjacency matrix (deduced from parameter)\n//! @param adjacency_matrix\
    \ adjacency_matrix[i][j] = (cost between i, j) or (infinity) if there's no edge\
    \ between i, j\n//! @param infinity very large number that indicates there is\
    \ no edge\n//! @return std::pair<2d vector, CostType> (adjacency matrix of minimun\
    \ spanning tree, total cost)\n//! @note time complexity: O(E log V) where E is\
    \ number of edges and V is number of nodes\ntemplate <typename TotalCostType,\
    \ typename CostType, template <typename...> typename Container>\n[[nodiscard]]\
    \ auto minimum_spanning_tree(const Container<Container<CostType>>& adjacency_matrix,\n\
    \                                         const CostType infinity) {\n  const\
    \ int nodes = static_cast<int>(std::size(adjacency_matrix));\n  std::pair res\
    \ {std::vector(nodes, std::vector<CostType>(nodes, infinity)), TotalCostType(0)};\n\
    \n  if (nodes == 0) {\n    warn(\"An empty adjacency matrix is provided.\");\n\
    \    return res;\n  }\n\n  using Edge = std::tuple<CostType, int, int>;\n  std::priority_queue<Edge,\
    \ std::vector<Edge>, std::greater<Edge>> heap;\n\n  std::vector<signed char> reached(nodes,\
    \ false);\n  reached[0] = true;\n\n  for (int i = 1; i < nodes; ++i)\n    if (adjacency_matrix[0][i]\
    \ < infinity)\n      heap.emplace(adjacency_matrix[0][i], 0, i);\n\n  while (!heap.empty())\
    \ {\n    const auto [cost_1_2, node_1, node_2] = heap.top();\n    heap.pop();\n\
    \n    if (reached[node_2])\n      continue;\n\n    reached[node_2] = true;\n \
    \   res.second += cost_1_2;\n    res.first[node_1][node_2] = res.first[node_2][node_1]\
    \ = cost_1_2;\n\n    for (int node_3 = 0; node_3 < nodes; ++node_3)\n      if\
    \ (adjacency_matrix[node_2][node_3] < infinity && !reached[node_3])\n        heap.emplace(adjacency_matrix[node_2][node_3],\
    \ node_2, node_3);\n  }\n\n  return res;\n}\n\n}  // namespace lib\n\n#ifdef warn_not_defined\n\
    #  undef warn\n#  undef warn_not_defined\n// warn may be defined 2 times (by uncommenting\
    \ line 18)\n#  ifdef warn\n#    undef warn\n#  endif\n#endif\n\n#ifdef O_assert_not_defined\n\
    #  undef O_assert\n#  undef O_assert_not_defined\n#endif\n\n#endif  // MINIMUM_SPANNING_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/graph/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '2021-08-08 16:38:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/minimum_spanning_tree/3.test.cpp
  - test/graph/minimum_spanning_tree/4.test.cpp
  - test/graph/minimum_spanning_tree/1.test.cpp
  - test/graph/minimum_spanning_tree/2.test.cpp
documentation_of: include/graph/minimum_spanning_tree.hpp
layout: document
title: Minimum spanning tree
---

グラフの[最小全域木](https://ja.wikipedia.org/wiki/%E5%85%A8%E5%9F%9F%E6%9C%A8#%E6%9C%80%E5%B0%8F%E5%85%A8%E5%9F%9F%E6%9C%A8)を求める関数が定義されています。

---

### `minimum_spanning_tree<TotalCostType>(N, edge_list)`

$N$ 頂点の、`edge_list` に含まれる辺を持つグラフの最小全域木を [Kruskal 法](https://ja.wikipedia.org/wiki/%E3%82%AF%E3%83%A9%E3%82%B9%E3%82%AB%E3%83%AB%E6%B3%95)によって求めます。

#### テンプレート引数

- `TotalCostType` - コストの総和の型
  - 辺のコストを `int` 型で保持しているがコストの和が `int` 型で表せる範囲を超えている場合にはここで `long long` 型を指定すればよいです。

#### 引数

- `N` - グラフの頂点数
- `edge_list` - 辺のリスト
  - `std::tuple` のリストです。頂点 $u$ と頂点 $v$ を繋ぐコスト $c$ の辺を `std::tuple(u, v, c)` として表します。

#### 戻り値

最小全域木の辺のリスト(`edge_list` と同じ形式)と辺のコストの総和(`TotalCostType` 型)をこの順に保持した `std::pair` 型の値

---

### `minimum_spanning_tree<TotalCostType>(adjacency_list)`

隣接リスト `adjacency_list` で表されるグラフの最小全域木を [Prim 法](https://ja.wikipedia.org/wiki/%E3%83%97%E3%83%AA%E3%83%A0%E6%B3%95)によって求めます。

#### テンプレート引数

- `TotalCostType` - コストの総和の型
  - 辺のコストを `int` 型で保持しているがコストの和が `int` 型で表せる範囲を超えている場合にはここで `long long` 型を指定すればよいです。

#### 引数

- `N` - グラフの頂点数
- `adjacency_list` - 隣接リスト
  - 頂点 $u$ と頂点 $v$ を繋ぐコスト $c$ の辺が有る場合、`adjacency_list[u]` の中に `std::pair(v, c)` が含まれるようにします。

#### 戻り値

最小全域木の隣接リスト(`adjacency_list` と同じ形式)と辺のコストの総和(`TotalCostType` 型)をこの順に保持した `std::pair` 型の値

---

### `minimum_spanning_tree<TotalCostType>(adjacency_matrix, infinity)`

隣接行列 `adjacency_matrix` で表されるグラフの最小全域木を [Prim 法](https://ja.wikipedia.org/wiki/%E3%83%97%E3%83%AA%E3%83%A0%E6%B3%95)によって求めます。

#### テンプレート引数

- `TotalCostType` - コストの総和の型
  - 辺のコストを `int` 型で保持しているがコストの和が `int` 型で表せる範囲を超えている場合にはここで `long long` 型を指定すればよいです。

#### 引数

- `N` - グラフの頂点数
- `adjacency_matrix` - 隣接リスト
  - 頂点 $u$ と頂点 $v$ を繋ぐコスト $c$ の辺が有る場合、`adjacency_matrix[u][v] = c` とし、辺が無い場合は `adjacency_matrix[u][v] = infinity` とします。
- `infinity` - 辺が無いことを表す十分大きい値

#### 戻り値

最小全域木の隣接行列(`adjacency_matrix` と同じ形式)と辺のコストの総和(`TotalCostType` 型)をこの順に保持した `std::pair` 型の値

---