#include <iostream>
using namespace std;

int collatz(int c, int contador);

int main(){
	int contador, maxn;
	int resultado  = 0;
	for (int n=1; n <=100000; n++){
		contador = 1;
		contador = collatz(n, contador);
		if (contador > resultado){
			resultado = contador;
			maxn = n;
		}
	}
	cout << maxn << ", " << resultado << endl;
	return 0;
}


int collatz(int c, int contador){
	if (c == 1){
		return contador;
	}else{
		contador++;
		if (c%2 == 0){
			c = c/2;
			return collatz(c, contador);
		}else{
			c = 3*c + 1;
			return collatz(c, contador);
		}
	}
}
