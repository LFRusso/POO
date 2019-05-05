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

	void up() {
		_value++;
		_normalize();
	}

	void down(){
		_value--;
		_normalize();
	} 

	void up_by(int number){
		_value = _value + number;
		_normalize();
	}

	void down_by(int number){
		_value = _value - number;
		_normalize();
	}

};