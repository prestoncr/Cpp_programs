//Pokemon Tournament Name Generator
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{

std:: string austin = "austin";
std:: string andy = "andy";
std:: string me = "me";

srand(time(0));
int x = rand()%3;
int y = rand()%3;

if (x == 0) std:: cout << austin << std:: endl;
if (y == 0) std:: cout << austin << std:: endl;
if (x == 1) std:: cout << andy << std:: endl;
if (y == 1) std:: cout << andy << std:: endl;
if (x == 2) std:: cout << me << std:: endl;
if (y == 2) std:: cout << me << std:: endl;


}
