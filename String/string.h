#pragma once
#include <iostream>

class String {
// class starts with implicit 'private:' devition

// every piece of code can access these members
public:
	/**
	 * @brief Creates an instance of String from a given array of characters.
	 */
	String(const char* str);
	/**
	 * @brief Copy CTOR (constructor) - creates a deep copy of another String instance.
	 * @param o An existing String instance to copy.
	 */
	String(const String& o); 

	//doxygen documentation style:
	/** 
	 * @brief Returns the character at a given index - if such an index exists for the string
	 * @param index The given index.
	 * @returns The character at the given index.
	 */
	char charAt(int index);

	/**
	 * @returns The length of this string.
	 */
	int length();

	String& operator=(const String& o);

	friend std::ostream& operator<<(std::ostream& o, String& s) {
		o << s.start;
		return o;
	}

// only code of methods of this class can access these members
private:
	unsigned int size;
	char* start;
};
