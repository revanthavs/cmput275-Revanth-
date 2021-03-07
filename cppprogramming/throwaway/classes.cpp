// /*
//   Header file for the Counter class.

//   A counter that you can increment and decrement, but it stays clamped inside a range.

//   Course: CMPUT 275
//   Zac Friggstad, 2021
// */


// #ifndef __COUNTER_H_
// #define __COUNTER_H_

// class Counter {
// public:

//   // expects init_value to lie in the given range
//   // default is starting at 0 with a range [0, 100]
//   Counter(int init_value = 0, int range_low = 0, int range_high = 100);
//   ~Counter(); // destructor

//   // increment the counter, but stay in the range
//   // return true iff it actually incremented
//   bool increment();

//   // decrement the counter, but stay in the range
//   // return true iff it actually decremented
//   bool decrement();

//   // return the current value (a copy of it)
//   // const is a promise that nothing in the class will change
//   int getCurrValue() const;

//   // reset the counter to the initial value
//   void reset();

// private:
//   // Hide these from the user because we want to maintain
//   // curr_value is in the range. The user can only interact
//   // with them using the methods we provide.
//   int curr_value, range_low, range_high, init_value;
// };

// #endif
/*
  Implementation of the counter class.

  Course: CMPUT 275
  Zac Friggstad, 2021
*/

#include "counter.h" // so we know the class definition

#include <cassert>
#include <iostream>

using namespace std;

Counter::Counter(int init_value, int range_low, int range_high) {
  // make sure the initial clock value makes sense in the ranges
  assert(range_low <= init_value && init_value <= range_high);

  // remember "this" is a keyword that will be a pointer pointing to
  // this particular instance of the class or struct you are using it in
  this->init_value = init_value;
  this->range_low = range_low;
  this->range_high = range_high;

  // initially, the current value should be the initial value
  reset();

  // we don't usually print anything in a constructor, this is just there
  // to help you understand exactly when it is called
  cout << "Constructor called: " << init_value << ' '
       << range_low << ' ' << range_high << endl;
}

Counter::~Counter() {
  // does nothing here, not very useful in this case
  // we print things to help you understand when the destructor is called

  cout << "Destructor called: " << curr_value << ' '
       << range_low << ' ' << range_high << endl;
}

bool Counter::increment() {
  // can refer directly to the class member "curr_value" without using "this"
  // because nothing overshadows the name of the member
  if (curr_value < range_high) {
    ++curr_value;
    return true;
  }
  else {
    return false;
  }
}

bool Counter::decrement() {
  if (curr_value > range_low) {
    --curr_value;
    return true;
  }
  else {
    return false;
  }
}

int Counter::getCurrValue() const {
  return curr_value;
}

void Counter::reset() {
  curr_value = init_value;
}
