//
//  14-7.cpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#include <iostream>
#include "Email.h"
#include "File.h"

bool ContainsKeyword(const Document& docObject, const std::string& keyword) {
	if (docObject.getText().find(keyword) != std::string::npos)
		return true;
	return false;
}

int main() {
	//test inheritance
	Email email1("alice@example.com", "bob@example.com", "Meeting", "Please attend the C++ meeting tomorrow.");
	Email email2("carol@example.com", "dave@example.com", "Lunch", "Let's have lunch tomorrow.");
	File file1("/documents/report.txt", "The C++ report is due next week.");
	File file2("/notes/meeting.txt", "Meeting notes: Discussed C++ project.");

	std::cout << "Email1 contains 'C++': " << ContainsKeyword(email1, "C++") << std::endl;
	std::cout << "Email2 contains 'C++': " << ContainsKeyword(email2, "C++") << std::endl;
	std::cout << "File1 contains 'C++': " << ContainsKeyword(file1, "C++") << std::endl;
	std::cout << "File2 contains 'C++': " << ContainsKeyword(file2, "C++") << std::endl;

	return 0;
}
