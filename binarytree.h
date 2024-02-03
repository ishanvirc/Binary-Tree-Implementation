/**
 * @file binarytree.h
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
 * The BinaryTree class represents a templated linked-memory tree data
 * structure.
 */
template <typename T>
struct BinaryTree {
    struct Node {
        T elem;
        Node* left;
        Node* right;
        Node(const T& element) : elem(element), left(NULL), right(NULL) {}
    };

    /**
     * Constructor to create an empty tree.
     */
    BinaryTree();

    /**
     * Copy constructor.
     */
    BinaryTree(const BinaryTree& other);

    /**
     * Destructor
     */
    ~BinaryTree();

    /**
     * @param rhs The tree to make a copy of.
     * @return A reference to the current tree.
     */
    const BinaryTree& operator=(const BinaryTree& rhs);

    /**
     * Frees all nodes associated with this tree and sets it to be empty.
     */
    void clear();

    /**
     * Inserts into the BinaryTree.
     * @param elem The element to insert
     * @param sorted By default, this parameter is false. That means that the
     *   element takes a pseudo-random path to a leaf where it is inserted. If
     *   true, the insert function will act like it does in a BST.
     */
    void insert(const T& elem, bool sorted = false);

    /**
     * Prints the contents of the tree to stdout.
     */
    void print() const;

    /**
     * @return The height of the binary tree. 
     */
    int height() const;

    /**
     * Pre-order Traversal 
     */
    void printLeftToRight() const;

    /**
     * Flips the tree over a vertical axis, modifying the tree itself
     */
    void mirror();

    /**
     * Prints out all the possible paths from the root of the tree to any leaf
     * node.
     */
    void printPaths() const;

    /**
     * @return The sum of the distances of all nodes to the root.
     */
    int sumDistances() const;

    /**
     * @return True if an in-order traversal of the tree would produce a
     *   nondecreasing list output values, and false otherwise.
     */
    bool isOrdered() const;

    Node* root;
    mt19937 rng;
    
  private:

    /**
     * Private helper function for the public height function.
     * @param subRoot The current node in the recursion.
     * @return The height of the subtree.
     */
    int height(const Node* subRoot) const;

    /**
     * Private helper function for the public insert function.
     * @param node The current node in the recursion.
     * @param elem The element to insert.
     * @param sorted By default, this parameter is false. That means that the
     *   element takes a pseudo-random path to a leaf where it is inserted. If
     *   true, the insert function will act like it does in a BST.
     */
    void insert(Node*& node, const T& elem, bool sorted);

    /**
     * Helper function for operator= and cctor.
     * @param subRoot The current node in the recursion.
     */
    Node* copy(const Node* subRoot);

    /**
     * Private helper function for clear that clears beneath the parameter node.
     * @param subRoot The current node in the recursion.
     */
    void clear(Node* subRoot);

    void printLeftToRight(const Node* subRoot) const;
    void mirror(Node* subRoot);
    void printPaths(const Node* subRoot, vector<T>& currentPath) const;
    int sumDistances(const Node* subRoot, int depth) const;
    bool isOrdered(const Node* subRoot, const T* minVal, const T* maxVal) const;

};

#include "binarytree_2.cpp"
#include "binarytree.cpp"
#endif
