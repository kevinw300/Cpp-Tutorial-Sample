#include "stdafx.h"

#include <iostream>
#include <string>

// Base class for all Text derived classes
class Text {
private:
	std::string text;

public:
	// Create a Text object from a client-supplied string
	Text(const std::string& t) : text(t) {}
	// Allow clients to see the text field
	virtual std::string get()  const {
		return text;
	}
	// Concatenate another string onto 
	// back of the existing text
	virtual void append(const std::string& extra) {
		text += extra;
	}
};

// Provides minimal decoration for the text
class FancyText : public Text {
private:
	std::string left_bracket;
	std::string right_bracket;
	std::string connector;

public:
	// Client supplies the string to wrap plus some extra
	// decorations
	FancyText(const std::string& t, const std::string& left,
		const std::string& right, const std::string& conn) :
		Text(t), left_bracket(left), right_bracket(right),
		connector(conn) {}
	// Allow clients to see the decorated text field
	std::string get() const override {
		return left_bracket + Text::get() + right_bracket;
	}
	// Concatenate another string onto the
	// back of the existing text, inserting the connector
	// string
	void append(const std::string& extra) override{
		Text::append(connector + extra);
	}
};

// The text is always the world FIXED
class FixedText : public Text {
public:
	FixedText() : Text("FIXED") {}
	void append(const std::string&) override {}
};

int main() {
	Text t1("plain");
	FancyText t2("fancy","<<",">>","***");
	FixedText t3;

	std::cout << t1.get() << '\n';
	std::cout << t2.get() << '\n';
	std::cout << t3.get() << '\n';

	std::cout << "------------------------\n";
	t1.append("A");
	t2.append("A");
	t3.append("A");
	std::cout << t1.get() << '\n';
	std::cout << t2.get() << '\n';
	std::cout << t3.get() << '\n';


	std::cout << "------------------------\n";
	t1.append("B");
	t2.append("B");
	t3.append("B");
	std::cout << t1.get() << '\n';
	std::cout << t2.get() << '\n';
	std::cout << t3.get() << '\n';
	return 0;
}