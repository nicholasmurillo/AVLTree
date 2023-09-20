#include <iostream>
#include <cmath>
#include <exception>

struct Node {
    int id;
    std::string name;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* setRight(Node* root) {
        this->right = root;
    }
    Node* setLeft(Node* root) {
        this->left = root;
    }
    Node() {}
    Node(int id, std::string name) {
        this->id = id;
        this->name = name;
    }
};

struct Tree {
    int height = 0;
    Node* root = nullptr;
    // TODO: BALANCE TREE FUNC
    Node* insert(Node* root, std::string name, int id) 
    {
        try
        {
            for(auto c : name) // Checking for characters a-z, A-Z, or space
            {
                if(not (isalpha(c) or c == ' '))
                {
                    throw nullptr;
                }
            }
            if(trunc(log10(id)) + 1 != 8) // Checking if id is 8 numbers long
            {
                throw nullptr;
            }
            if(root == nullptr)
            {
                std::cout << "successful insert" << std::endl;
                root = new Node(id, name);
                return root;
            }
            if(id < root->id)
            {
                root->setLeft(insert(root->left, name, id));
            }
            else
            {
                root->setRight(insert(root->right, name, id));
            }
            return root;
        }
        catch(...)
        {
            std::cout << "unsuccessful insert" << std::endl;
        }
        
    }
    // TODO: REMOVE ID, PRIORITIZE IN ORDER SUCCESSOR (ONE RIGHT, THEN FURTHEST LEFT)
    Node* remove(Node* root, int id) {
        return root;
    }
    // TODO: SEARCH ID
    // TODO: SEARCH NAME
    // TODO: PRINT IN ORDER
    // TODO: PRINT PRE ORDER
    // TODO: PRINT POST ORDER
    // TODO: PRINT LEVEL COUNT (HEIGHT)
    // TODO: REMOVE IN ORDER NODE  
    Tree(Node* root, std::string name, int id) {
        this->root = insert(root, name, id);
        this->height++;
    }
};