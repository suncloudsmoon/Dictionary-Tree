#ifndef WORD_HPP
#define WORD_HPP

#include <string>

class Word {
public:
	Word() : c{}, word{} {}
	Word(char a, const std::string& w) : c(a), word(w) {}

	void set_character(char a) {
		c = a;
	}

	void set_word(const std::string& w) {
		word = w;
	}

	char get_character() const {
		return c;
	}

	std::string& get_word() {
		return word;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Word& w) {
		out << "[" << w.c << "," << "\"" << w.word << "\"" << "]";
		return out;
	}
private:
	char c;
	std::string word;
};

#endif /* WORD_HPP */