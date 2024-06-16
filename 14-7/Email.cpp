//
//  Email.cpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#include "Email.h"

Email::Email() : Document(), sender(""), recipient(""), title("") {}

Email::Email(const std::string &sender, const std::string &recipient, const std::string &title, const std::string &text)
	: Document(text), sender(sender), recipient(recipient), title(title) {}

std::string Email::getSender() const {
	return sender;
}

std::string Email::getRecipient() const {
	return recipient;
}

std::string Email::getTitle() const {
	return title;
}

void Email::setSender(const std::string &sender) {
	this->sender = sender;
}

void Email::setRecipient(const std::string &recipient) {
	this->recipient = recipient;
}

void Email::setTitle(const std::string &title) {
	this->title = title;
}

Email& Email::operator=(const Email &other) {
	if (this != &other) {
		Document::operator=(other);
		sender = other.sender;
		recipient = other.recipient;
		title = other.title;
	}
	return *this;
}
