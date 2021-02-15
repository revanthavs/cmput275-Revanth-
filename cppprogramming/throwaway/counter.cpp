#include <iostream>
using namespace std;

struct Struct_Counter{
	Struct_Counter(int value);
	void Increment();
	void Decrement();
	int getValue();
	Struct_Counter* getThis();
	int value;
};

class Counter{
	public:
		Counter(int value);
		// ~Counter();
		void Increment();
		void Decrement();
		int getValue();
		Counter* getThis();

	private:
		int value;
};


Struct_Counter::Struct_Counter(int value = 5){
	this->value = value;
	return;
}

void Struct_Counter:: Increment(){
	this->value++;
	return;
}

void Struct_Counter:: Decrement(){
	this->value--;
	return;
}

int Struct_Counter:: getValue(){
	return this->value;
}

Struct_Counter* Struct_Counter:: getThis(){
	return this;
}


Counter::Counter(int value = 5){
	this->value = value;
	return;
}

void Counter:: Increment(){
	this->value++;
	return;
}

void Counter:: Decrement(){
	this->value--;
	return;
}

int Counter:: getValue(){
	return this->value;
}

Counter* Counter:: getThis(){
	return this;
}

int main(){
	Counter myCounter(15);
	Counter counter1;
	cout << myCounter.getValue() << " ";
	myCounter.Increment();
	cout << myCounter.getValue() << " ";
	myCounter.Decrement();
	cout << myCounter.getValue() << " ";
	cout << counter1.getValue() << " ";
	counter1.Increment();
	cout << counter1.getValue() << " ";
	counter1.Decrement();
	cout << counter1.getValue() << " \n";
	Counter* value = &counter1;
	Counter* value1 = counter1.getThis();
	cout << value << " == " << value1 << endl;
	Struct_Counter counter2(15);
	Struct_Counter counter3;
	cout << counter2.getValue() << " ";
	counter2.Increment();
	cout << counter2.getValue() << " ";
	counter2.Decrement();
	cout << counter2.getValue() << " ";
	cout << counter3.getValue() << " ";
	counter3.Increment();
	cout << counter3.getValue() << " ";
	counter3.Decrement();
	cout << counter3.getValue() << " \n";
	Struct_Counter* value2 = &counter3;
	Struct_Counter* value3 = counter3.getThis();
	cout << value2 << " == " << value3 << endl;
	return 0;
}