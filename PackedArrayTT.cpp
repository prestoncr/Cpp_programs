//Packed Array Representation of Tournament Tree
//Preston Programming Oct 15, 2017

#include <iostream>
#include <cmath>
int* makeTT(int* scores_begin, int* scores_end)
{

int size = scores_end - scores_begin +1;
int TT[size*2 -1];
int* current = scores_begin;
int temp = 0;
int index = 0;
int rounds = size/2;
int subround = size;
float divisor = 0;
int x = 0;
for (int i = 0; i < rounds; i++)
{
  divisor = std::pow(2, i);
  subround = size/((int)divisor);
  x = size/subround;

  for (int j = 0; j < x; j++)
  {
    for (int k = 0; k < subround; k++)
      if (*(current+k) > temp) temp = *(current +k);
    TT[index]= temp;
    index++;
    current = current + subround;
    temp = 0;

  }
  current = scores_begin;
}

return TT;
}


int main()
{
int size;
std:: cout << "Enter number of players ";
std:: cin >> size;
int game[size];
std::cout << "Enter number of each player\n";

for (int i = 0; i < size; i++)
{
  std::cin>>game[i];
}
std:: cout << "\n\n";

int* TT = makeTT(&game[0], &game[size-1]);

int final[size*2 -1];
for (int i = 0; i < (size*2-1); i++)
{
  final[i] = *(TT+i);
  //std:: cout << "TT + i is: " << *(TT+i) << std::endl;
}

for (int i = 0; i < (size*2-1); i++)
{
  std:: cout << final[i] << " ";
}
std:: cout << std::endl;


std:: cout <<"Worked..\n";

}
