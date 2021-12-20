#ifndef DITREE_HPP
#define DITREE_HPP

#include <string>
#include <optional>

#include "node.hpp"
#include "word.hpp"

class DiTree {
public:
	~DiTree() {
		root.pop_off_everything();
	}
	/*
	* Adds a word only if it doesn't already exist
	*/
	bool add_word(const std::string& str, const std::string& def) {
		auto* node = &root;
		bool isFound = false;
		for (std::size_t index = 0; index < str.length(); index++) {
			char c = str.at(index);
			if (!node)
				continue;
			isFound = false;
			for (auto* check : node->get_nodes()) {
				if (c == node->get_content().get_character()) {
					node = check;
					isFound = true;
				}
			}
			if (!isFound) {
				// Create new node
				auto* n = new Node<Word>();
				n->set_content(Word(c, (index == str.length() - 1) ? def : "" ));
				node->add_node(n);
				node = n;
			}
		}
		return !isFound;
	}

	std::optional<std::string> get_definition(const std::string& str) {
		auto* node = &root;
		std::string builder;
		for (char c : str) {
			if (!node)
				continue;
			for (auto* check : node->get_nodes()) {
				if (!check)
					continue;
				if (c == check->get_content().get_character()) {
					builder += c;
					node = check;
				}
			}
		}
		if (builder == str && node)
			return { node->get_content().get_word() };
		return {};
	}

	void serialize(const std::string &dest) {
		root.serialize(dest);
	}
private:
	Node<Word> root;
};

#endif /* DITREE_HPP */