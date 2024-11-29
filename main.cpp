#include <string>
#include <iostream>

class Squirrel {
private:
    std::string name;

public:
    Squirrel(std::string name) {
        this->name = name;
    }

    std::string get_name() {
        return this->name;
    }
};

class Node {
private:
    Squirrel* data;
    Node* leftChild;
    Node* rightChild;

public:
    Node(Squirrel* squirrel) {
        this->data = squirrel;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    Squirrel* get_data() {
        return this->data;
    }

    void set_left(Node* node) {
        this->leftChild = node;
    }

    void set_right(Node* node) {
        this->rightChild = node;
    }

    Node* left() {
        return this->leftChild;
    }

    Node* right() {
        return this->rightChild;
    }
};

int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node* node_one = new Node(&cheeks);
    Node* node_two = new Node(&squeaks);
    Node* node_three = new Node(&fluffybutt);

    node_one->set_left(node_two);
    node_one->set_right(node_three);

    std::cout << "Root: " << node_one->get_data()->get_name() << std::endl;
    std::cout << "Left child: " << node_one->left()->get_data()->get_name() << std::endl;
    std::cout << "Right child: " << node_one->right()->get_data()->get_name() << std::endl;

    delete node_one;
    delete node_two;
    delete node_three;

    return 0;
}
