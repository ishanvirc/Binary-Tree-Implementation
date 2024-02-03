/**
 * @file binarytree.cpp
 */

#include <iostream>

using namespace std;

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    return height(root);
}

/**
 * @param subRoot
 * @return The height of the subtree.
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    printLeftToRight(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    if (subRoot == nullptr) {
        return; // Base case: Reached a null node
    }

    // Recursively print left subtree
    printLeftToRight(subRoot->left);

    // Print the current node's value
    cout << subRoot->elem << " ";

    // Recursively print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 * (i.e. not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node* subRoot)
{
    if (subRoot == nullptr) {
        return;  // Base case: Reached a null node
    }

    // Recursively mirror the left and right subtrees
    mirror(subRoot->left);
    mirror(subRoot->right);

    // Swap the left and right subtrees at the current node
    Node* temp = subRoot->left;
    subRoot->left = subRoot->right;
    subRoot->right = temp;
}

/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards,
 * ending at a leaf node.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
  vector<T> currentPath;
  printPaths(root, currentPath);
}

template <typename T>
void BinaryTree<T>::printPaths(const Node* subRoot, vector<T>& currentPath) const
{
    if (subRoot == nullptr) {
        return;  // Base case: Reached a null node
    }

    currentPath.push_back(subRoot->elem);

    if (subRoot->left == nullptr && subRoot->right == nullptr) {
        // Reached a leaf node, so print the path
        cout << "Path: ";
        for (const T& nodeValue : currentPath) {
            cout << nodeValue << " ";
        }
        cout << endl;
    } else {
        // Recursively explore left and right subtrees
        printPaths(subRoot->left, currentPath);
        printPaths(subRoot->right, currentPath);
    }

    currentPath.pop_back();  // Backtrack to explore other paths
}

/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes).
 * @return The sum of the distances of all nodes to the root.
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
  return sumDistances(root, 0);
}

template <typename T>
int BinaryTree<T>::sumDistances(const Node* subRoot, int depth) const
{
    if (subRoot == nullptr) {
        return 0;  // Base case: Reached a null node, so no distance to add
    }

    // Calculate the distance of the current node to the root
    int nodeDistance = depth;

    // Recursively calculate distances of left and right subtrees
    int leftDistance = sumDistances(subRoot->left, depth + 1);
    int rightDistance = sumDistances(subRoot->right, depth + 1);

    // Return the sum of distances of the current node and its subtrees
    return nodeDistance + leftDistance + rightDistance;
}

/**
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
  return isOrdered(root, nullptr, nullptr);
}

template <typename T>
bool BinaryTree<T>::isOrdered(const Node* subRoot, const T* minVal, const T* maxVal) const
{
    if (subRoot == nullptr) {
        return true;  // An empty tree is ordered
    }

    // Check if the current node's value is within the valid range
    if ((minVal != nullptr && subRoot->elem <= *minVal) ||
        (maxVal != nullptr && subRoot->elem >= *maxVal)) {
        return false;  // Violation of ordering constraint
    }

    // Recursively check left and right subtrees with updated value ranges
    return isOrdered(subRoot->left, minVal, &(subRoot->elem)) &&
           isOrdered(subRoot->right, &(subRoot->elem), maxVal);
}