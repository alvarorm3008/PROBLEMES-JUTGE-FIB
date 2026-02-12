# 🚀 UPC - FIB | Algorithmic Problem Solving

A comprehensive collection of algorithmic solutions and data structure implementations developed for the **Jutge.org** platform at **FIB (Universitat Politècnica de Catalunya)**.

![Language](https://img.shields.io/badge/Language-C%2B%2B%20%7C%20Python-blue?style=for-the-badge&logo=cplusplus)
![Topic](https://img.shields.io/badge/Topic-Algorithms%20%26%20Data%20Structures-green?style=for-the-badge)

## 📊 Overview

This repository serves as a portfolio of algorithmic thinking, covering topics from basic iterative logic to complex graph theory and dynamic programming.

- **Focus:** Efficiency, Code Cleanliness, and Complexity Analysis ($O(n)$, $O(\log n)$).
- **Platform:** [Jutge.org](https://jutge.org) (UPC Online Judge).
- **Core Languages:** C++ (Primary for performance), Python.

## 🗂️ Repository Structure & Categorization

The problems are organized by complexity and topic, reflecting the rigorous Computer Science curriculum at FIB:

### 🔹 1. Advanced Data Structures & Algorithms (EDA)
*Focus on Graph Theory, Maps, and Optimization.*
- **Graph Algorithms:** BFS (Breadth-First Search), DFS (Depth-First Search), Dijkstra, Topological Sort.
- **Data Structures:** Priority Queues (Heaps), BST (Binary Search Trees), Hash Maps (STL maps/sets).
- **Divide & Conquer:** MergeSort, QuickSort logic.

### 🔹 2. Modular Programming & Recursion (PRO2)
*Focus on clean code, recursion, and abstract data types.*
- **Recursion:** Backtracking solutions, recursive mathematical sequences.
- **Backtracking:** Solving constraint satisfaction problems (N-Queens, Subsets).
- **Modular Design:** Separation of interface (`.hh`) and implementation (`.cc`).

### 🔹 3. Fundamentals of Programming (PRO1)
*The building blocks of logical thinking.*
- **Iterative Logic:** Complex loops, sequence handling.
- **Vectors & Matrices:** Multi-dimensional array manipulation.
- **Basic Algorithms:** Searching (Linear/Binary) and Sorting (Selection/Insertion).

---

## 🧠 Key Algorithmic Concepts Demonstrated

### 🕸️ Graph Theory
Implementation of traversal algorithms to solve connectivity problems, shortest paths, and cycle detection.

```cpp
// Example: Graph Traversal concept
void dfs(int u, vector<bool>& vis, const vector<vector<int>>& adj) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, vis, adj);
    }
}
⚡ Dynamic Programming & Greedy
Optimization problems solved by breaking them down into simpler subproblems (Memoization) or making locally optimal choices.

🚀 How to Compile (C++)
Most solutions are written in standard C++11/C++17.

Bash
g++ -O2 -Wall -std=c++11 solution.cc -o solution
./solution < input.txt
⚠️ Academic Integrity Disclaimer
These solutions are intended for educational review and portfolio purposes. If you are currently a student at FIB, please solve the problems yourself before consulting this repository to strictly adhere to the university's academic regulations.

Author: Alvaro Rodriguez

FIB - Universitat Politècnica de Catalunya
