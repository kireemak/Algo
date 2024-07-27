#include <iostream>
#include <fstream>

class Node
{
    int key;
    Node* right;
    Node* left;

public:
    Node(int key = 0)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }

    ~Node()
    {
        delete this->right;
        delete this->left;
    }

    static void insertNode(Node* root, int newKey)
    {
        if (newKey == root->key)
            return;                 //There is nothing we can do if the newKey is equal to other key in our tree
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
};



int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int newKey;
    fin >> newKey;
    Node* rootPtr = new Node(newKey);

    while (!fin.eof())
    {
        fin >> newKey;
        Node::insertNode(rootPtr, newKey);
    }

    //Node::printTree(rootPtr, std::cout);
    Node::printTree(rootPtr, fout);

    delete rootPtr;

    fin.close();
    fout.close();

    return 0;
}