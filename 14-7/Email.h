//
//  Email.hpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#ifndef EMAIL_H
#define EMAIL_H

#include "Document.h"

class Email : public Document {
private:
	std::string sender;
	std::string recipient;
	std::string title;
public:
	Email();
	Email(const std::string &sender, const std::string &recipient, const std::string &title, const std::string &text);
	std::string getSender() const;
	std::string getRecipient() const;
	std::string getTitle() const;
	void setSender(const std::string &sender);
	void setRecipient(const std::string &recipient);
	void setTitle(const std::string &title);
	Email& operator=(const Email &other);
};

#endif // EMAIL_H

