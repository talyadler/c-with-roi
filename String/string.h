#pragma once
#include <iostream>

class String {
// every piece of code can access these members
public:
	String() = delete;
	/**
	 * @brief Creates an instance of String from a given array of characters.
	 */
	String(const char* str);

	/**
	 * @brief Copy CTOR (constructor) - creates a deep copy of another String instance.
	 * @param o An existing String instance to copy.
	 */
	String(const String& o); 

	virtual ~String();

	//doxygen documentation style:
	/** 
	 * @brief Returns the character at a given index - if such an index exists for the string
	 * @param index The given index.
	 * @returns The character at the given index.
	 */
	char charAt(int index) const;

	/**
	 * @returns The length of this string.
	 */
	int length() const;

	/*
	 *@brief Functionality for using String and variables with = 
	 */
	String& operator=(const String& o);

	/*
	 *@brief Functionality to output data to outpu stream
	 */
	friend std::ostream& operator<<(std::ostream& o, const String& s) {
		o << s.start;
		return o;
	}

	/*
	 *@brief Compares two strings lexicographically.
	 */
	// examples: 
	// "asdf".compareTo("qwer") < 0  --> first letter difference: a < q
	// "asdf".compareTo("asdf") == 0 --> no difference in letters or length
	// "qwer".compareTo("asdf") > 0 --> first letter difference: q > a
	// "aaa".compareTo("aab") < 0 --> 3rd letter difference : a < b
	// "aaaa".compareTo("aaa") > 0 --> length difference: 4 > 3
    int compareTo(const String& anotherString) const;

// only code of methods of this class can access these members
private:
	unsigned int size;
	char* start;
};

