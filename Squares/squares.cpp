#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool intercept(float x1,float y1,float l1,float x2,float y2,float l2){
   float dx = abs(x2 + l2 - x1) + abs(x1 + l1 - x2);
   float dy = abs(y2 + l2 - x1) + abs(y1 + l1 - y2);

   if (dx == l1 + l2 or dy == l1 + l2){
      return false;
   }else{
      return true;
   }
}

float area(float x1,float y1,float l1,float x2,float y2,float l2){
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
   std::vector<float> x;
   std::vector<float> y;
   std::vector<float> l;
   std::vector<string> name;
	std::ifstream file;
	file.open("squares4.dat");

	std::string nome;
   float xi, yi, li;

	while(file >> nome >> xi >> yi >> li){
		name.push_back(nome);
      x.push_back(xi);
      y.push_back(yi);
      l.push_back(li);
	}

   for (int i = 0; i < name.size(); i++){
      for (int j = i+1; j < name.size(); j++){
         if (intercept(x[i], y[i], l[i], x[j], y[j], l[j])){
            cout << name[i] << " intercepts " << name[j] << " with area " << area(x[i], y[i], l[i], x[j], y[j], l[j]) << endl;
         }else{
            //cout << name[i] << " does not intercept " << name[j] << endl;
         }
      }
   }
	return 0;
}
