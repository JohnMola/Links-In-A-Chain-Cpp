#include <catch2/catch_test_macros.hpp>

#include "../src/link.hpp"
#include "../src/node.hpp"

TEST_CASE("Zero nodes") {
    Node* empty = nullptr;
    REQUIRE(empty == nullptr);
}

TEST_CASE("One node stores link data") {
    Link gold = Link("Gold");
    Node* node = new Node(&gold);

    REQUIRE(node->get_data()->get_material() == "Gold");
    REQUIRE(node->next() == nullptr);

    delete node;
}

TEST_CASE("One node links to another") {
    Link gold = Link("Gold");
    Node* first = new Node(&gold);

    Link silver = Link("Silver");
    Node* second = new Node(&silver, first);

    REQUIRE(first->next() == second);
    REQUIRE(second->get_data()->get_material() == "Silver");

    delete first;
    delete second;
}

TEST_CASE("Many nodes form a chain") {
    Link gold = Link("Gold");
    Node* first = new Node(&gold);

    Link silver = Link("Silver");
    Node* second = new Node(&silver, first);

    Link bronze = Link("Bronze");
    Node* third = new Node(&bronze, second);

    REQUIRE(first->next()->get_data()->get_material() == "Silver");
    REQUIRE(second->next()->get_data()->get_material() == "Bronze");
    REQUIRE(third->next() == nullptr);

    delete first;
    delete second;
    delete third;
}

TEST_CASE("Traverse from head to end") {
    Link gold = Link("Gold");
    Node* head = new Node(&gold);

    Link silver = Link("Silver");
    Node* second = new Node(&silver, head);

    Link bronze = Link("Bronze");
    Node* third = new Node(&bronze, second);

    Node* current = head;
    REQUIRE(current->get_data()->get_material() == "Gold");

    current = current->next();
    REQUIRE(current->get_data()->get_material() == "Silver");

    current = current->next();
    REQUIRE(current->get_data()->get_material() == "Bronze");

    current = current->next();
    REQUIRE(current == nullptr);

    delete head;
    delete second;
    delete third;
}