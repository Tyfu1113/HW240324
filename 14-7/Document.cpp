//
//  Document.cpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#include "Document.h"

Document::Document() : text("") {}

Document::Document(const std::string &text) : text(text) {}

std::string Document::getText() const {
	return text;
}

void Document::setText(const std::string &text) {
	this->text = text;
}

Document& Document::operator=(const Document &other) {
	if (this != &other) {
		text = other.text;
	}
	return *this;
}
