#pragma once

#include "link.hpp"

class Node {
private:
    Link* data;
    Node* next_node;

public:
    Node(Link* link) {
        this->data = link;
        this->next_node = nullptr;
    }

    Node(Link* link, Node* prev) {
        this->data = link;
        this->next_node = nullptr;
        if (prev != nullptr) {
            this->next_node = prev->next_node;
            prev->next_node = this;
        }
    }

    Node* next() {
        return this->next_node;
    }

    Link* get_data() {
        return this->data;
    }
};