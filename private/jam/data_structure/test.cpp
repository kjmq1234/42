#include <iostream>
#include <utility>
using namespace std;

template <class T>
class TreeNode {
public:
    pair<int, int> pr;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
    int leftSize;

    TreeNode(int number, int score) {
        pr = make_pair(number, score);
        leftChild = NULL;
        rightChild = NULL;
        leftSize = 0;
    }
};

template <class T>
class BST {
private:
    TreeNode<T>* root;

public:
    BST() {
        root = NULL;
    }

    TreeNode<T>* getroot() {
        return root;
    }

    void inorder() {
        inorder(root);
    }

    void inorder(TreeNode<T>* currentNode) {
        if (currentNode) {
            inorder(currentNode->leftChild);
            Visit(currentNode);
            inorder(currentNode->rightChild);
        }
    }

    void Visit(TreeNode<T>* currentNode) {
        cout << "번호: " << currentNode->pr.first << " ";
        cout << "점수: " << currentNode->pr.second;
        cout << endl;
    }

    TreeNode<T>* findMin(TreeNode<T>* node) {
        while (node->leftChild != NULL) {
            node = node->leftChild;
        }
        return node;
    }

    template <class K, class E>
    void insert(const pair<K, E>& insertNode) {
        TreeNode<T>* p = root, * pp = NULL;
        while (p) {
            pp = p;
            if (insertNode.first < p->pr.first) {
                p->leftSize++;
                p = p->leftChild;
            }
            else if (insertNode.first > p->pr.first) {
                p = p->rightChild;
            }
            else {
                p->pr.second = insertNode.second;
                return;
            }
        }

        p = new TreeNode<T>(insertNode.first, insertNode.second);

        if (root) {
            if (insertNode.first < pp->pr.first) {
                pp->leftChild = p;
            }
            else {
                pp->rightChild = p;
            }
        }
        else {
            root = p;
        }
    }

    TreeNode<T>* Delete(TreeNode<T>* node, int number) {
        if (node == NULL)
            return node;

        if (number < node->pr.first) {
            node->leftChild = Delete(node->leftChild, number);
            node->leftSize--;
        }
        else if (number > node->pr.first) {
            node->rightChild = Delete(node->rightChild, number);
        }
        else {
            if (node->leftChild == NULL && node->rightChild == NULL) {
                delete node;
                return NULL;
            }
            else if (node->leftChild == NULL) {
                TreeNode<T>* temp = node->rightChild;
                delete node;
                return temp;
            }
            else if (node->rightChild == NULL) {
                TreeNode<T>* temp = node->leftChild;
                delete node;
                return temp;
            }
            else {
                TreeNode<T>* successor = findMin(node->rightChild);
                node->pr = successor->pr;
                node->rightChild = Delete(node->rightChild, successor->pr.first);
            }
        }

        return node;
    }

    pair<int, int> get(int number) {
        TreeNode<T>* currentNode = root;

        while (currentNode != NULL) {
            if (number < currentNode->pr.first) {
                currentNode = currentNode->leftChild;
            }
            else if (number > currentNode->pr.first) {
                currentNode = currentNode->rightChild;
            }
            else {
                return currentNode->pr;
            }
        }
	return make_pair(0,0);	
    }


    pair<int, int>* rank(int r) {
        r--;
        TreeNode<T>* currentNode = root;
        while (currentNode) {
            if (r < currentNode->leftSize) {
                currentNode = currentNode->leftChild;
            }
            else if (r > currentNode->leftSize) {
                r -= currentNode->leftSize + 1;
                currentNode = currentNode->rightChild;
            }
            else {
                return &(currentNode->pr);
            }
        }
	return NULL;
    }
};

int main(void) {
    BST<int> bst;

    //1.
    bst.insert(make_pair(33, 90));
    bst.insert(make_pair(50, 73));
    bst.insert(make_pair(43, 99));
    bst.insert(make_pair(11, 82));
    bst.insert(make_pair(24, 78));
    bst.insert(make_pair(46, 96));
    bst.insert(make_pair(1, 72));
    bst.insert(make_pair(8, 88));
    bst.insert(make_pair(36, 77));
    bst.insert(make_pair(56, 93));
    bst.insert(make_pair(53, 82));
    bst.insert(make_pair(59, 100));

    //2.
    bst.inorder();

    //3.
    bst.Delete(bst.getroot(), 50);

    //4.
    cout << endl;
    bst.inorder();

    //5.
    bst.Delete(bst.getroot(), 8);

    //6.
    cout << endl;
    bst.inorder();

    //7.
    bst.Delete(bst.getroot(), 56);

    //8.
    cout << endl;
    bst.inorder();

    //9.
    pair<int, int> get = bst.get(43);
    cout << endl;
    cout << "번호: " << get.first << " ";
    cout << "점수: " << get.second;
    cout << endl;

    //10.
    pair<int, int>* rank = bst.rank(5);
    cout << endl;
    cout << "번호: " << rank->first << " ";
    cout << "점수: " << rank->second<<endl;
}