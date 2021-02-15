#include <iostream>
using namespace std;

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
	return 0;
}