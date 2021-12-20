#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <stack>
#include <fstream>

template<typename T>
class Node {
public:
	Node() = default;
	void pop_off_everything() {
		std::stack<Node*> stack;
		for (Node* n : nodes) {
			stack.push(n);
		}
		while (!stack.empty()) {
			Node* n = stack.top();
			stack.pop();
			for (Node* other : n->get_nodes()) {
				stack.push(other);
			}
			delete n;
		}
	}

	void serialize(const std::string &dest) {
		std::ofstream output(dest);

		output << content << "\n"; // Write the root node to file with new line

		std::stack<Node*> stack;
		for (Node* n : nodes) {
			stack.push(n);
		}
		while (!stack.empty()) {
			Node* n = stack.top();
			stack.pop();

			auto node_size = n->get_nodes().size();
			if (node_size)
				output << "(" << node_size << ") ";

			for (Node* other : n->get_nodes()) {
				stack.push(other);
				output << other->get_content() << " ";
			}
			output << "\n";
		}
	}

	void add_node(Node* n) {
		nodes.push_back(n);
	}

	T get_content() const {
		return content;
	}

	void set_content(T cont) {
		content = cont;
	}

	std::vector<Node*>& get_nodes() {
		return nodes;
	}
private:
	T content;
	std::vector<Node*> nodes;
};

#endif /* NODE_HPP */