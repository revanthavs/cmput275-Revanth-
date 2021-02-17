#ifndef __HEDARCLASS_H__
#define __HEDARCLASS_H__
#include <iostream>
using namespace std;

class Something{
	public:
		Something(int x = 5){
			this->x = x;
		}
		void getout(){
			cout << x << endl;
		}

	private:
		int x;
};
#endif