# language-tree-ancestor
A C++ implementation of a Lowest Common Ancestor (LCA) algorithm to find the shared roots of language dialects.Language Tree Finder (LCA Implementation) 🌳
This project is a C++ application that demonstrates how to model hierarchical data using a Tree Structure. It specifically implements the Lowest Common Ancestor (LCA) algorithm to find the shared historical root between two different languages or dialects.

🚀 Features
Custom Tree Data Structure: Uses struct Node with vector-based children for dynamic branching.

Path-Finding Algorithm: Utilizes Depth-First Search (DFS) to trace the lineage of a specific language from the root.

LCA Logic: Compares two path vectors to identify the most recent common ancestor node.

Interactive CLI: A simple menu-based interface for users to select languages and dialects.

🛠️ How It Works
The program builds a tree where the root is the language family, branches are specific languages, and leaves are dialects.

When you select two dialects, the program:

Generates a path from the Root to Dialect A.

Generates a path from the Root to Dialect B.

Iterates through both paths until they diverge. The last matching node is the Common Ancestor.

Example:

Input 1: "Egyptian" (Indo-European -> Arabic -> Egyptian)

Input 2: "Levantine" (Indo-European -> Arabic -> Levantine)

Result: Arabic

[!IMPORTANT]
Linguistic Note: In this educational code sample, "Arabic" is placed under the "Indo-European" root for demonstration purposes. In reality, Arabic belongs to the Afroasiatic (Semitic) family, while English belongs to the Indo-European family.
