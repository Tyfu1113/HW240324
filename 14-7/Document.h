//
//  Document.hpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document {
protected:
	std::string text;
public:
	Document();
	Document(const std::string &text);
	std::string getText() const;
	void setText(const std::string &text);
	Document& operator=(const Document &other);
};

#endif // DOCUMENT_H
