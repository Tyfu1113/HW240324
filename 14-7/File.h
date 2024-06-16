//
//  File.hpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#ifndef FILE_H
#define FILE_H

#include "Document.h"

class File : public Document {
private:
	std::string pathname;
public:
	File();
	File(const std::string &pathname, const std::string &text);
	std::string getPathname() const;
	void setPathname(const std::string &pathname);
	File& operator=(const File &other);
};

#endif // FILE_H
