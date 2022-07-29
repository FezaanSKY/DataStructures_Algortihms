#pragma once

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class ItemOrder {
public:
	string item;
	string name;
	string delivery;
	string status;
	ItemOrder(string n, string i, string d, string s) {
		name = n;
		item = i;
		delivery = d;
		status = s;
	}

	string Display() {
		std::stringstream result;
		result << "\tKey: " << this->name
			<< "\tName: " << this->name
			<< "\tItem: " << this->item
			<< "\tDelivery: " << this->delivery
			<< "\tStatus: " << this->status << endl;
		return result.str();
	}
};
