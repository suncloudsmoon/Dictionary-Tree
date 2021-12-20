#include <iostream>
#include <string>

#include "ditree.hpp"

int main() {
	DiTree tree;
	std::string word = "hello";
	std::string def = "greeting";

	bool is_word_added = tree.add_word(word, def);
	auto def_result = tree.get_definition(word);

	std::cout << std::boolalpha << "Success adding word?: " << is_word_added << std::endl;

	if (def_result)
		std::cout << "Defintion of word \"" << word << "\": " << *def_result << std::endl;

	tree.serialize("out.txt");
}