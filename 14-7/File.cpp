//
//  File.cpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#include "File.h"

File::File() : Document(), pathname("") {}

File::File(const std::string &pathname, const std::string &text) : Document(text), pathname(pathname) {}

std::string File::getPathname() const {
	return pathname;
}

void File::setPathname(const std::string &pathname) {
	this->pathname = pathname;
}

File& File::operator=(const File &other) {
	if (this != &other) {
		Document::operator=(other);
		pathname = other.pathname;
	}
	return *this;
}
