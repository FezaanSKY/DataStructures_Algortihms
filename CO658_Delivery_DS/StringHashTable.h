#pragma once
#pragma once

#include <iostream>
#include <string>
#include "ItemOrder.h"

using namespace std;

class StringHashTable {
private:
	ItemOrder** data;

	int HashFunction(string key) {
		int ASCIItot = 0;
		for (int i = 0; i < key.length(); i++) {
			ASCIItot += (int)key[i];
		}
		return ASCIItot % size;
	}

public:

	int size;

	StringHashTable(int size) //: size(size) //initialisation list
	{
		this->size = size;
		data = new ItemOrder * [size]; //array of ItemOrder pointers
		for (int i = 0; i < size; i++)
			data[i] = NULL;
	}
	void Display() {
		for (int i = 0; i < size; i++)
			if (data[i] != NULL)
				cout << "Index: " << i
				<< "\tKey: " << data[i]->name
				<< data[i]->Display()
				<< endl;
	}

	void Insert(ItemOrder* item) {
		string key = item->name;
		int hash = HashFunction(key);
		while (data[hash] != NULL) {
			++hash;
			hash %= size;
		}
		data[hash] = item;
	}

	ItemOrder* Find(string key) {
		int hash = HashFunction(key);
		while (data[hash] != NULL) {
			if (data[hash]->name == key) {
				return data[hash];
			}
			hash++;
			hash = hash % size;
		}
		return NULL;
	}


	ItemOrder* Delete(string key) {
		int hash = HashFunction(key);
		while (data[hash] != NULL) {
			if (data[hash]->name == key) {
				ItemOrder* itemToDelete = data[hash];
				data[hash] = NULL;
				return itemToDelete;
			}
			hash++;
			hash = hash % size;
		}
		return NULL;
	}
};

