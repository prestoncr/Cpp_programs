//EX4 Crypto Part 2 Fall17 Dr.Richard Newman
//Designed by Preston Programming
#include <iostream>
#include <fstream>
#include <bitset>

std:: string cleaner(std:: string ogKey)
{
  ogKey.erase(remove_if(ogKey.begin(), ogKey.end(), isspace), ogKey.end());
  return ogKey;
}

std:: string bitShuffler(std:: string bits, std:: string key)
{

  int newkey[key.length()/2];
  std:: string temp = "";
  int num = 0;

  for (int i = 0; i < key.length(); i+=2)
  {
    temp += key[i];
    temp += key[i+1];
    num = stoi(temp);
    newkey[i/2] = num;
    temp = "";
  }

int size = key.length() /2;
std:: string newbits= "";
int counter = 0;
int adder = 0;

char cryptbits[bits.length()];

for (int i = 0; i < bits.length(); i++)
{

  cryptbits[newkey[i%(size)] + adder] = bits[i];
  counter++;
  if (counter == size)
  {
    adder += size;
    counter = 0;
  }
}

for (int i = 0; i < bits.length(); i++)
{
  newbits += cryptbits[i];
}
return newbits;
}


int main (int argc, char* argv[])
{

  if (argc < 3)
  {
  std:: cerr << "Not enough aruments, key needed\n";
  return -1;
  }

std:: string bits, key;

while (getline(std:: cin, bits, '\0'));
bits = cleaner(bits);


std:: string temp = argv[2];
temp = temp.substr(1);

std:: fstream reader;
reader.open(temp);
while (getline(reader, key, '\0'));
key = cleaner(key);


if (argc == 1 )
{
 std:: cout <<"Error not enough arguments\nExiting\n\n";
 return -1;
}

if (argc == 2)
{
  std:: cout <<"Error not enough arguments\nExiting\n\n";
  return -1;
}

if (argc == 3)
{
  bits = bitShuffler(bits, key);
  for (int i = 0; i < bits.length(); i+=8)
  {
    std:: cout << bits[0+i] << bits[1+i]
    << bits[2+i] << bits[3+i] << " "
    << bits[4+i] << bits[5+i]
    << bits[6+i] << bits[7+i] << std:: endl;
  }
}

if (argc == 4)
{
  //key and -e or -d or -b<n>
}

if (argc == 5)
{
  //has to be key and block size and crypt setting
}

return 0;
}
