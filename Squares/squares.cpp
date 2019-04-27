#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

struct square{ // tipo de dado square, contendo as coordenadas, o lado e o nome de cada quadrado
   float x, y, side;
   std::string name;
};

bool intercept(float x1,float y1,float l1,float x2,float y2,float l2){  // função para checar se dois quadrados se interceptam ou não, de acordo com o tamanho dos seus lados e as suas coordenadas
   float dx = abs(x2 + l2 - x1) + abs(x1 + l1 - x2);
   float dy = abs(y2 + l2 - y1) + abs(y1 + l1 - y2);
   if (abs(dx - dy) > 10E-5){
      return false;
   }else{
      return true;
   }
}

float area(float x1,float y1,float l1,float x2,float y2,float l2){   // dados dois quadrados que se interceptam, retorna a área de intersecção
   float area, left, right, up, down;
   if (x1 < x2){left = x2;}else{left = x1;}
   if (x1 + l1 < x2 + l2){right  = x1 + l1;}else{right = x2 + l2;}
   if (y1 > y2){down = y1;}else{down = y2;}
   if (y1 + l1 < y2 + l2) {up = y1 + l1;}else{up = y2 + l2;}

   area = abs(up - down)*abs(right - left);
   return area;
}

int main()
{
   std::vector<square> squares;  // vetor no qual serão armazenados os quadrados do arquivo
	std::ifstream file;
	file.open("squares.dat");

	std::string nome;   // nome do quadrado
   float xi, yi, li; // suas coordenadas x, y e o lado

	while(file >> nome >> xi >> yi >> li){
      std::string nomei = nome;  // a variável auxiliar nomei armazena o nome do quadrado como sting
      square nome;
      nome.x = xi;   
      nome.y = yi;
      nome.side = li;
      nome.name = nomei;   // armazeno os dados do documento no meu square criado
      squares.push_back(nome);   // armazeno cada square em um vetor
	}
   int lenght = squares.size();

   for (int i = 0; i < lenght; i++){   // aqui comparo cada quadrado um a um, imprimindo no terminal sua área de intresecção, caso exista
      for (int j = i+1; j < lenght; j++){
         if (intercept(squares[i].x, squares[i].y, squares[i].side, squares[j].x, squares[j].y, squares[j].side)){
            cout << squares[i].name << " intercepts " << squares[j].name << " with area " << area(squares[i].x, squares[i].y, squares[i].side, squares[j].x, squares[j].y, squares[j].side) << endl;
         }
      }
   }
	return 0;
}
