﻿#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
_CrtMemState s1;
_CrtMemState s2;
_CrtMemState s3;


#include <iostream>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>


class list {
	struct node {
		int* arr;
		size_t arr_size;
		double f;
		node* next;
		node* prev;
		node(int*& arr, size_t& size, double& y) : next(NULL), prev(NULL), arr(arr), arr_size(size), f(y) {}
	};
private:
	node* START, *END;
	size_t COUNT;
public:
	list(void) : START(NULL), END(NULL), COUNT(0) {}

public:
	/*void push_front(size_t size, int* arr, double f) {
		node* adds = new node(arr, size, f);
		if (adds) {
			node* p = new(adds) node(arr, size, f);
			if (START == NULL) {
				START = END = p;
			}
			else {
				p->next = START;
				START->prev = p;
				START = p;
			}
		}
		else std::cout << "Not Enought Memory.";
	}

	void push_back(size_t size, int* arr, double f) {
		node* adds = new node(arr, size, f);
		if (adds) {
			node* p = new(adds) node(arr, size, f);
			if (START == NULL) {
				START = END = p;
			}
			else {
				p->prev = END;
				END->next = p;
				END = p;
			}
		}
		else std::cout << "Not Enought Memory.";
	}*/

	void insert(size_t size, int* arr, double f, int pos) {
		node* adds = new node(arr, size, f);
		if (adds) {
			node* p = new(adds) node(arr, size, f);
			std::cout << pos << "//" << COUNT << std::endl;
			node* temp = START;
			if (START == NULL) {
				START = END = p;
				p->next = p;
				p->prev = p;
			}
			else {
				if (pos < 0) { pos = 0; }
				//else if (pos > COUNT - 1 && COUNT != 1) { pos = COUNT; }

				int n = 0;
				while (n != pos) {
					if (pos <= 0) { break; }
					temp = temp->next;
					n++;
				}
				check_memory(pos);
				// чёта с pos and COUNT не так, ломается pushfront/pushback
				if (temp == START && temp->prev == END && (pos == 0 || temp->prev != temp) && pos != COUNT ) {
					std::cout << "PUSHFRONT" << std::endl;
					END->next = p;
					p->prev = END;
					p->next = START;
					START->prev = p;
					START = p;
				}
				else if (pos > 0 && pos <= COUNT) {
					std::cout << "INSERT" << std::endl;
					temp->prev->next = p;
					p->prev = temp->prev;
					p->next = temp;
					temp->prev = p;
				}
				else if (temp == END && temp->next == START && (pos >= COUNT -1 || temp->next != temp)) {
					std::cout << "PUSHBACK" << std::endl;
					START->prev = p;
					p->prev = END;
					p->next = START;
					END->next = p;
					END = p;
				}
				else {
					
				}
			}
			COUNT++;
		}
		else std::cout << "Not Enought Memory.";
	}

	void remove(int pos) {
		if (COUNT) {
			node* temp = START;
			if (pos < 0) { pos = 0; }
			else if (pos > COUNT - 1 && COUNT != 1) { pos = COUNT - 1; }
			int n = 0;
			while (n != pos) {
				if (pos <= 0) { break; }
				temp = temp->next;
				n++;
			}
			if (temp->prev == END && pos == 0) {
				END->next = temp->next;
				temp->next->prev = END;
				delete temp;
			}	
			else if (temp->next == START) {
				START->prev = temp->prev;
				temp->prev->next = START;
				delete temp;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
			}
			if (START->next != START) { START = START->next; }
			else { START = NULL; }
			COUNT--;
		}
		else {
			std::cout << "List empty!" << std::endl;
		}
	}

	
	void print(void)
	{
		node* temp;
		temp = START;
		if (!COUNT) { std::cout << "List empty!" << std::endl; return; }
		std::cout << "TEMP " << temp << std::endl;
		std::cout << "List: " << std::endl;
		int x = 0;
		while (x != COUNT)
		{
			std::cout << x <<": [ ";
			for (int i = 0; i < temp->arr_size; i++) {
				std::cout << temp->arr[i] << " ";
			}
			std::cout << "] " << temp->f << std::endl;
			temp = temp->next;
			x++;
		}
	}

	void clear(void) {
		node* t;
		if (START == NULL) {
			std::cout << "Linked List Empty" << std::endl;
		}
		else {
			while (START != NULL) {
				t = START;
				delete (t);
				COUNT--;
				if (START->next != NULL) {
					std::cout << (int)START->next;
					START = START->next;
				}
				else {
					std::cout << "2";
					break; }
			}
			END = NULL;
			COUNT = 0;
			std::cout << "Linked List was cleared" << std::endl;
		}
	}

	bool empty(void) { return START == NULL; }
	size_t size(void) { return COUNT; }

	void check_memory(int pos) {
		node* temp;
		if (START != NULL && pos < COUNT) {
			temp = START;
			int n = 0;
			if (START != END) {
				while (n != pos) {
					//std::cout << n <<std::endl;
					temp = temp->next;
					n++;
				}
			}
			node* tn = temp->next;
			node* tp = temp->prev;
			std::cout << "Temp->prev: " << tp << " // " << tp->f << std::endl;
			std::cout << "Temp:       " << temp << " // " << temp->f << std::endl;
			std::cout << "Temp->next: " << tn << " // " << tn->f << std::endl;
			std::cout << "START: " << START << " // " << START->f << std::endl;
			std::cout << "END: " << END << " // " << END->f << std::endl;
		}
		else {
			std::cout << "Can't find element with " << pos << " position!" << std::endl;
		}
	}
};

int menu() {
	int n;
	for (;;) {
		std::cout << "Actions with Cycled Linked List:" << std::endl;
		std::cout << "1) insert <lenght of array> <array of integer> <double value> <position>" << std::endl;
		std::cout << "2) remove <position>" << std::endl;
		std::cout << "3) empty <>" << std::endl;
		std::cout << "4) clear <>" << std::endl;
		std::cout << "5) print <>" << std::endl;
		std::cout << "6) exit" << std::endl;
		std::cin >> n;
		if ((std::cin.good()) && n > 0 && n <= 6 || n == 11) {
			system("cls");
			return n;
		}
		else {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		system("cls");
	}
}


int main()
{
	list L;
	for (;;) {
		system("cls");
		int n = menu();
		switch (n) {
			case 1:
			{
				size_t size;
				double f;
				for (;;) {
					std::cout << "Enter size of array: ";
					std::cin >> size;
					if (std::cin.good() && (size <= 10 && size > 0)) {
						break;
					}
					else {
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
					}
				}
				int* arr = new int[size];
				for (int i = 0; i < size; i++) {
					for (;;) {
						std::cout << "Enter " << "arr[" << i << "] elem: ";
						std::cin >> arr[i];
						if (std::cin.good() && arr[i] > INT_MIN && arr[i] < INT_MAX) {
							break;
						}
						else {
							std::cin.clear();
							std::cin.ignore(INT_MAX, '\n');
						}
					}
				}
				for (;;) {
					std::cout << "Enter double value: ";
					std::cin >> f;
					if (std::cin.good()) {
						break;
					}
					else {
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
					}
				}
				int pos;
				for (;;) {
					std::cout << "If position > count of elements: insert at end" << std::endl;
					std::cout << "Enter position: ";
					std::cin >> pos;
					if (std::cin.good() || pos >= 0) {
						break;
					}
					else {
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
					}
				}
				L.insert(size, arr, f, pos);
			}
				break;
			case 2:
			{
				int pos;
				for (;;) {
					std::cout << "Enter position: ";
					std::cin >> pos;
					if (std::cin.good() || pos >= 0) {
						break;
					}
					else {
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
					}
				}
				L.remove(pos);
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
				break;
			case 3:
				if (L.empty()) {
					std::cout << "List Empty!" << std::endl;
				}
				else {
					std::cout << "List contains " << L.size() << " elements!" << std::endl;
				}
				break;
			case 4:
				L.clear();
				break;
			case 5:
				L.print();
				break;
			case 6:
				L.clear();
				system("cls");
				exit(0);
				break;
			case 11:
			{
				int pos;
				for (;;) {
					std::cout << "Enter position: ";
					std::cin >> pos;
					if (std::cin.good() || pos >= 0) {
						break;
					}
					else {
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
					}
				}
				L.check_memory(pos);
			}
			break;
		default:
			break;
		} 
		system("pause");
	}

	return 0;
}