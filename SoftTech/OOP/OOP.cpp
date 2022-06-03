#include <iostream>

class Animal {
private:
	int weight;
	int age;
public:
	Animal(int weight, int age) {
		this->weight = weight,
		this->age = age;
	}
	virtual void sayHello() {
		std::cout << "hello from animal" << std::endl;
	}
	virtual void getParams() {
		std::cout << "Animal Weight: " << this->weight << std::endl;
		std::cout << "Animal's Age: " << this->age << std::endl;
	}

	void setParamsTo50() {
		this->setWeight(50);
		this->setAge(50);
	}

	int getWeight() {
		return this->weight;
	}
	int getAge() {
		return this->age;
	}
	void setWeight(int w) {
		this->weight = w;
	}
	void setAge(int a) {
		this->age = a;
	}
};

class Cat : public Animal {
private:
	int speedKMH;
	std::string color;
public:
	Cat(int weight, int age, int speedKMH, std::string color) : Animal(weight, age) {
		this->speedKMH = speedKMH;
		this->color = color;
	};
	void sayHello() override {
		std::cout << "hello from cat" << std::endl;
	}
	void getParams() override {
		std::cout << "Cat Weight: " << this->getWeight() << std::endl;
		std::cout << "Cat's Age: " << this->getAge() << std::endl;
		std::cout << "Cat's color: " << this->getColor() << std::endl;
		std::cout << "Cat now runs away with speed: " << this->getSpeed() << " KMH" << std::endl;
	}

	std::string getColor() {
		return this->color;
	}

	int getSpeed() {
		return this->speedKMH;
	}
};

class Monkey : public Animal {
private:
	int bananasInStock;
	bool isItCanBuildHouse;
public:
	Monkey(int weight, int age, int bananasInStock, bool isItCanBuildHouse) : Animal(weight, age) {
		this->bananasInStock = bananasInStock;
		this->isItCanBuildHouse = isItCanBuildHouse;
	};
	void sayHello() override {
		std::cout << "hello from monkey" << std::endl;
	}
	void getParams() override {
		std::cout << "Monkey Weight: " << this->getWeight() << std::endl;
		std::cout << "Monkey's Age: " << this->getAge() << std::endl;
		std::cout << "Monkey has " << this->getBananasQty() << " bananas" << std::endl;
		std::cout << "Monkey " << (this->getSkill() ? "can" : "can't") << " build house" << std::endl;
		if (this->getSkill()) {
			this->buildHouse();
		}
	}

	virtual bool getSkill() {
		return this->isItCanBuildHouse;
	}

	virtual int getBananasQty() {
		return this->bananasInStock;
	}

	virtual void buildHouse() {
		std::cout << "Monkey is smart. Monkey built a house. House for birbs.\nHouse for birbs:\n"
			<< "  ___ \n"
			<< "/     \\\n"
			<< "|  O  |\n"
			<< "|     |\n"
			<< "|_____|\n"
			<< "   |   \n"
			<< std::endl;
	}
};

class App {
public:
	void run() {
		Animal* a = new Cat(32, 5, 15, "PINK");
		Animal* b = new Monkey(67, 12, 99, true);
		a->getParams();
		std::cout << std::endl;
		b->getParams();
	}
};

int main() {
	App* application = new App;
	application->run();
	return 0;
}