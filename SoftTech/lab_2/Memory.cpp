#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>

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
		double* fptr;
		node* next;
		node* prev;
		node(int*& arr, size_t& size, double& y) : next(NULL), prev(NULL), arr(arr), arr_size(size), f(y) {}
	};
private:
	node* START;
	size_t COUNT;
public:
	list(void) : START(NULL), COUNT(0) {}

public:
	void insert(size_t size, int* arr, double f, int pos) {
		node* adds = new node(arr, size, f);
		
		if (adds) {
			node* p = new(adds) node(arr, size, f);
			p->fptr = &(p->f);
			node* temp = START;
			if (pos < 0) { pos = 0; }
			if (START == NULL) {
				START = p;
				p->next = p;
				p->prev = p;
			}
			else {
				int n = 0;
				while (n != pos % COUNT) {
					temp = temp->next;
					n++;
				}
				temp->prev->next = p;
				p->prev = temp->prev;
				p->next = temp;
				temp->prev = p;
			}
			COUNT++;
		}
		else std::cout << "Not Enought Memory.";
	}

	bool remove(int pos) {
		if (COUNT) {
			node* temp = START;
			if (pos < 0) { pos = 0; }
			else if (pos > COUNT - 1 && COUNT != 1) { pos = COUNT - 1; }
			int n = 0;
			while (n != pos % COUNT) {
				temp = temp->next;
				n++;
			}
			if (START->next != START) { 
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				START = START->next; 
				delete temp;
			}
			else { 
				delete temp;
				START = NULL; 
			}
			COUNT--;
			return true;
		}
		else {
			std::cout << "Can't find element with " << pos << " position!" << std::endl;
			return false;
		}
	}

	
	void print(void)
	{
		node* temp;
		temp = START;
		if (!COUNT) { std::cout << "List empty!" << std::endl; return; }
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
		while (remove(0)) {
			continue;
		}
		system("cls");
		std::cout << "List cleared!" << std::endl;
	}

	bool empty(void) { return START == NULL; }
	size_t size(void) { return COUNT; }
	void check_memory(int pos) {
		node* temp;
		if (pos < 0) { pos = 0; }
		if (START != NULL && pos < COUNT) {
			temp = START;
			int n = 0;
			while (n != pos % COUNT) {
				if (pos == 0) { break; }
				temp = temp->next;
				n++;
			}
			node* tn = temp->next;
			node* tp = temp->prev;
			std::cout << "Temp->prev: " << tp << " // " << tp->f << std::endl;
			std::cout << "Temp:       " << temp << " // " << temp->f << std::endl;
			std::cout << "Temp->next: " << tn << " // " << tn->f << std::endl;
			std::cout << "START: " << START << " // " << START->f << std::endl;
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
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
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
					std::cout << "Enter size of array [1; 10]: ";
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
					std::cout << "If position > count of elements: a cyclic shift will be performed!" << std::endl;
					std::cout << "If position < 0 -> pos will be == 0!" << std::endl;
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
				std::cout<< " " << std::endl;
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
					std::cout << "List empty!" << std::endl;
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
				
				_CrtDumpMemoryLeaks();

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
	_CrtDumpMemoryLeaks();
	std::cout<<'\n';
	return 0;
}
