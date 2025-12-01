#include <iostream>
#include "src/link.hpp"
#include "src/node.hpp"

int main() {
  Link gold = Link("Gold");
  Node* node_one = new Node(&gold);

  Link silver = Link("Silver");
  Node* node_two = new Node(&silver, node_one);

  Link bronze = Link("Bronze");
  Node* node_three = new Node(&bronze, node_two);

  Node* retrieved_node_two = node_one->next();
  Node* retrieved_node_three = node_two->next();

  std::cout << "Traversing the linked list:" << std::endl;
  Node* current = node_one;
  int position = 1;
  while (current != nullptr) {
    std::cout << "Node " << position << ": " << current->get_data()->get_material() << std::endl;
    current = current->next();
    position++;
  }

  std::cout << "\nVerification:" << std::endl;
  std::cout << "retrieved_node_two contains: " << retrieved_node_two->get_data()->get_material() << std::endl;
  std::cout << "retrieved_node_three contains: " << retrieved_node_three->get_data()->get_material() << std::endl;

  delete node_one;
  delete node_two;
  delete node_three;

  return 0;
}
