#include <iostream>
#include <fstream>
#include <vector>

int maxDiff;


class Node
{
    int data;
    Node* left;
    Node* right;
    int leftChildren, rightChildren;

public:

    Node(long data = 0)
    {
        this->data = data;
        this->left = this->right = nullptr;
        leftChildren = rightChildren = 0;
    }

    int calcChildren()
    {
        if (this == nullptr) {
            return 0;
        }

        leftChildren = left->calcChildren();

        rightChildren = right->calcChildren();

        return leftChildren + rightChildren + 1;
    }

    void deleteTree()
    {
        if (this->right != NULL)
            this->right->deleteTree();
        if (this->left != NULL)
            this->left->deleteTree();

        delete this->right;
        delete this->left;
    }

    static void insertNode(Node*& root, long newData)
    {
        if (root == nullptr)
            root = new Node(newData);
        else if (newData == root->data)
            return;
        else if (newData > root->data)
            if (root->right)
                insertNode(root->right, newData);
            else
                root->right = new Node(newData);
        else if (newData < root->data)
            if (root->left)
                insertNode(root->left, newData);
            else
                root->left = new Node(newData);
    }

    static void printTree(Node* root, std::ostream& out)
    {
        if (!root)
            return;

        out << root->data << std::endl;
        printTree(root->left, out);
        printTree(root->right, out);
    }

    static Node* deleteNode(Node*& root, long data)
    {
        Node* temp = root;

        if (root == NULL)
            return NULL;

        if (root->data > data)
        {
            root->left = Node::deleteNode(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = Node::deleteNode(root->right, data);
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
                long min = Node::findMinData(root->right)->data;
                root->data = min;
                root->right = deleteNode(root->right, min);
            }
        }

        return root;
    }

    int findDeleteKey(int count)
    {
        std::vector <int> possibleVector(count);

        int buffCount = count;
        this->findFunction(possibleVector, buffCount);
        
        count /= 2;

        return possibleVector[count];
    }

    void findFunction(std::vector <int>& notesVector, int& count)
    {
        if (this == nullptr)
            return;

        if (abs(this->leftChildren - this->rightChildren) == maxDiff)
        {
            count--;
            notesVector[count] = this->data;
            //notesVector.push_back(this->data);
            return;
        }
        this->left->findFunction(notesVector, count);
        this->right->findFunction(notesVector, count);
    }

    static void deleteMedKey(Node* root)
    {
        maxDiff = -1;
        int possibleNotesCount = 0;
        root->findMaxDifference(possibleNotesCount);
        std::ofstream fout("tst.out");

        if (possibleNotesCount % 2 == 0)
        {

            Node::printTree(root, std::cout);
            Node::printTree(root, fout);

            fout.close();

            return;
        }

        int deleteKey = root->findDeleteKey(possibleNotesCount);
        
        Node::deleteNode(root, deleteKey);

        Node::printTree(root, std::cout);
        Node::printTree(root, fout);

        fout.close();
    }

    void findMaxDifference(int& count)
    {
        if (this == NULL)
            return;

        if (abs(this->leftChildren - this->rightChildren) > maxDiff)
        {
            maxDiff = abs(this->leftChildren - this->rightChildren);
            count = 1;
        }
        else if (abs(this->leftChildren - this->rightChildren) == maxDiff)
        {
            count++;
        }

        this->left->findMaxDifference(count);
        this->right->findMaxDifference(count);

        return;
    }

private:
    static Node* findMinData(Node* root)
    {
        if (root->left != NULL)
            return Node::findMinData(root->left);
        else
            return root;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream fin("tst.in");

    int newKey;
    Node* root = nullptr;
    while (fin >> newKey)
        Node::insertNode(root, newKey);

    root->calcChildren();

    Node::deleteMedKey(root);

    fin.close();

    return 0;
}