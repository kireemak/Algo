#include <iostream>
#include <fstream>

class Node
{
    long key;
    Node* right;
    Node* left;

public:
    Node(long key = 0)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }

    void deleteTree()
    {
        if(this->right != NULL)
            this->right->deleteTree();
        if (this->left != NULL)
            this->left->deleteTree();

        delete this->right;
        delete this->left;
    }

    static void insertNode(Node*& root, long newKey)
    {
        if (root == nullptr)
            root = new Node(newKey);
        else if (newKey == root->key)
            return;
        else if (newKey > root->key)
            if (root->right)
                insertNode(root->right, newKey);
            else
                root->right = new Node(newKey);
        else if (newKey < root->key)
            if (root->left)
                insertNode(root->left, newKey);
            else
                root->left = new Node(newKey);
    }

    static void printTree(Node* root, std::ostream& out)
    {
        if (!root)
            return;

        out << root->key << std::endl;
        printTree(root->left, out);
        printTree(root->right, out);
    }

    static Node* deleteNode(Node*& root, long key)
    {
        Node* temp = root;

        if (root == NULL)
            return NULL;

        if (root->key > key)
        {
            root->left = Node::deleteNode(root->left, key);
        }
        else if (root->key < key)
        {
            root->right = Node::deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                long min = Node::findMinKey(root->right)->key;
                root->key = min;
                root->right = deleteNode(root->right, min);
            }
        }

        return root;
    }

private:
    static Node* findMinKey(Node* root)
    {   /*
        Node* tempParent = root;
        Node* temp = root->right;
        while (temp->left != NULL)
        {
            tempParent = temp;
            temp = temp->left;
        }
        return temp;
        */

        if (root->left != NULL)
            return Node::findMinKey(root->left);
        else
            return root;
    }
};



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    long newKey, deleteKey;
    fin >> deleteKey;
    Node* rootPtr = nullptr;
    if (fin.eof())
        return 0;

    while (fin >> newKey)
        Node::insertNode(rootPtr, newKey);

    rootPtr = Node::deleteNode(rootPtr, deleteKey);

    //Node::printTree(rootPtr, std::cout);
    Node::printTree(rootPtr, fout);

    rootPtr->deleteTree();

    delete rootPtr;

    fin.close();
    fout.close();

    return 0;
}