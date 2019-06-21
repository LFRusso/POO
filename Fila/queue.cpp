#include <iostream>
#include <memory>
#include <vector>

template<typename tipo>
class Queue{
	struct Node{
		tipo value;
		std::unique_ptr<Node> next;
	};
	std::unique_ptr<Node> _front;
	Node *_back{nullptr};

public:
	void push(tipo V){
		Node *new_node = new Node{V, nullptr};
		if (_back) {
			_back->next.reset(new_node);
		} else {
			_front.reset(new_node);
		}
		_back = new_node;
	}

	void pop(){
		_front->std::move(_front->next);

		if(_front.get() == nullptr){
			_back = nullptr;
		}
	}

	tipo front() const{ return _front->value; }

	bool is_empty() const{ return _front.get() == nullptr; }

};

int main(int, char const *[]) {
  Queue my_queue;
  for (int i = 0; i < 4; ++i) {
    my_queue.push(i);
  }
  std::cout << "Primeiro na fila: " << my_queue.front() << std::endl;
  my_queue.pop();
  for (int i = 0; i < 3; ++i) {
    my_queue.push(3 * i);
  }

  std::cout << "Fila atual: ";
  while (!my_queue.is_empty()) {
    auto x = my_queue.front();
    my_queue.pop();
    std::cout << x << " ";
  }
  std::cout << std::endl;
}