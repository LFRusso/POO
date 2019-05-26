#include <iostream>

class Limited_Counter {
	int _a;
	int _b;
	int _value;
	void _normalize() {
		if (_value > _b){_value = _b;}
		if (_value < _a){_value = _a;}
	}

public:
	Limited_Counter(int b = 0, int a = 0){
		if (a < b){
			_a = a;
			_b = b;
			_value = a;

		} else {
			_a = b;
			_b = a;
			_value = b;
		}
	};

	int value() {return _value;};

	Limited_Counter &operator++(){
		_value = _value + 1;
		_normalize();
		return *this;
	}
	
		Limited_Counter operator++(int){
		Limited_Counter old(*this);
		++(*this);
		return old;
	}

	Limited_Counter &operator--(){
		_value = _value - 1;
		_normalize();
		return *this;
	} 
	
		Limited_Counter operator--(int){
		Limited_Counter old(*this);
		--(*this);
		return old;
	} 

	Limited_Counter &operator+= (int number){
		_value = _value + number;
		_normalize();
		return *this;
	}

	Limited_Counter &operator-= (int number){
		_value = _value - number;
		_normalize();
		return *this;
	}

};
