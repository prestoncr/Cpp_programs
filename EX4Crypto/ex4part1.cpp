//EX4 Crypto Part 1 Fall17 Dr.Richard Newman
//Designed by Preston Programming
#include <iostream>
#include <bitset>

std:: string toBinaryChars (std:: string content)
{
  std:: string theChars = "";
  int temp = 0;
  for (int i = 0; i < content.length(); i+=8)
  {
    temp+= (content[0+i] - '0')*128;
    temp+= (content[1+i] - '0')*64;
    temp+= (content[2+i] - '0')*32;
    temp+= (content[3+i] - '0')*16;
    temp+= (content[4+i] - '0')*8;
    temp+= (content[5+i] - '0')*4;
    temp+= (content[6+i] - '0')*2;
    temp+= (content[7+i] - '0');
    theChars += (char)temp;
    temp = 0;
  }
return theChars;
}
std::string toBinaryNums (std:: string content)
{
  std:: string bits = "";
std::bitset<8> temp;
for (int i = 0; i < content.length(); i++)
  {
    temp = std::bitset<8>(content[i]);
    bits += temp.to_string();
  }
return bits;
}
int main(int argc, char* argv[])
{
std:: string content;
while (getline(std:: cin, content, '\0'));



if (argc == 1)
{

  content = toBinaryNums(content);

  for (int i = 0; i < content.length(); i+=8)
  {
    std:: cout << content[0+i] << content[1+i]
    << content[2+i] << content[3+i] << " "
    << content[4+i] << content[5+i]
    << content[6+i] << content[7+i] << std:: endl;
  }
}

if (argc == 2)
{
  //one default
  //if ASCBIN
  content.erase(remove_if(content.begin(), content.end(), isspace), content.end());
  content = toBinaryChars(content);
  for (int i = 0; i < content.length(); i++)
  {
    std:: cout << content[i];
  }

}

if (argc == 3)
{
  //no defaults
}

return 0;
}
