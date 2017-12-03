//Straddling Checkerboard Cipher Header file
#ifndef _CHECKER_H
#define _CHECKER_H

#include <iostream>

class Checker
{
private:
int a; // 1st key number
int b; // 2nd key number
std:: string keyword;
std:: string mixedAlphKey;
char Checkerboard[3][10];
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

public:
  Checker(int a, int b, std:: string key1, std:: string key2);
  void makeBoard();
  void eliminateChars(std:: string content);
  bool checkAlph(char x);
  char nextChar();
  void printBoard();
  std:: string encrypt(std:: string content);
  std:: string decrypt(std:: string nums);
};


Checker:: Checker(int x, int y, std:: string key1, std:: string key2)
{
  //needs to check all components are what they should be
  //i.e x and y < 10; key1 8 chars long with no duplicates
  //also needs to make strings lowercase
  //make sure to run all inputs through a "Cleaner" function first
  //which will remove duplicates and check the numbers
  a = x;
  b = y;
  keyword = key1;
  mixedAlphKey = key2;
  for (int i = 0; i < 3; i++)
  {
      for (int j = 0; j < 10; j++)
        Checkerboard[i][j] = '0';
  }
  makeBoard();
}

void Checker:: makeBoard()
{
  //filling the two designated no-go spots with arbitrary chars
  Checkerboard[0][a] = '*';
  Checkerboard[0][b] = '*';

  //assuming keyword is 8 chars long like it should be
  //and has no duplicates... filling the first row
  //=================================================
  int index = 0;
  for (int i = 0; i < 10; i++)
  {
    if (i == a) i++;
    if (i == b) i++;
    if (i != a && i != b)
    {
      Checkerboard[0][i] = keyword[index];
      index++;
    }
   }
   eliminateChars(keyword);
  //=================================================

  //assuming mixedAlphKey is valid; filling the
  //checkerboard with that key
  //=================================================
  index = 0;
  for (int i = 0; i < mixedAlphKey.length(); i++)
  {
    if (checkAlph(mixedAlphKey[i]))
    {
      Checkerboard[1][index] = mixedAlphKey[i];
      index++;
    }
  }
  eliminateChars(mixedAlphKey);
  //=================================================

 for (int i = index; i < 10; i++)
 {
   Checkerboard[1][i] = nextChar();
 }
 for (int i = 0; i < 8; i ++)
 {
   Checkerboard[2][i] = nextChar();
 }
 Checkerboard[2][8] = '.';
 Checkerboard[2][9] = '/';


}

//function takes in a string and adjusts the alphabet array
//by setting the chars passed in to sentinel characters that
//the same char never gets used more than once
void Checker:: eliminateChars(std:: string content)
{
for (int i = 0; i < content.length(); i++)
{
  for (int j = 0; j < 26; j++)
  {
    if (content[i] == alphabet[j]) alphabet[j] = '*';
  }
}
}

//function checks to see if the character was already used
//returns true if char is still able to be used
bool Checker:: checkAlph(char test)
{
  bool final = false;
for (int i = 0; i < 26; i++)
{
  if (test == alphabet[i]) final = true;
}
  return final;
}

//finds the next character to be used
char Checker:: nextChar()
{

  for (int i = 0; i < 26; i++)
  {
      if (alphabet[i] != '*')
      {
        char temp = alphabet[i];
        alphabet[i] = '*';
        return temp;
      }
  }
  return '*';
}

//prints the board for testing purposes
void Checker:: printBoard()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 10; j++)
      std:: cout << "[" << Checkerboard[i][j] << "]";
      std:: cout << "\n";

  }

}

std:: string Checker:: encrypt(std:: string content)
{
  //assumes all lower case stuff
  int x = -1;
  int y = -1;
  std:: string final = "";
  for (int i = 0; i < content.length(); i++)
  {

      for (int j = 0; j < 3; j++)
      {
          for (int k = 0; k < 10; k++)
              {
                if (content[i] == Checkerboard[j][k])
                {
                  x = j;
                  y = k;
                }
              }
      }
      if (x >=0 && y >= 0)
      {
        if (x == 1) final += std:: to_string(a);
        if (x == 2) final += std:: to_string(b);
        final+= std:: to_string(y);
      }
      x = -1;
      y = -1;
    }

    return final;
}

std:: string Checker:: decrypt(std:: string nums)
{
  int temp1 = -1;
  int temp2 = -1;
  std:: string final = "";

for (int i = 0; i < nums.length(); i++)
{
temp1 = (int)nums[i] - '0';
if (temp1 == a || temp1 == b)
{
  if (temp1 == a) temp1 = 1;
  if (temp1 == b) temp1 = 2;
  i++;
  temp2 = (int)nums[i] - '0';
}

if (temp2 != -1) final += Checkerboard[temp1][temp2];
else final+= Checkerboard[0][temp1];
temp1 = -1;
temp2 = -1;

}

return final;
}




#endif
