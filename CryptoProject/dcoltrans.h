//Disrupted Transposition Header File
//Preston Programming

#ifndef _dcoltrans_H
#define _dcoltrans_H

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

class dcoltrans
{
private:

 std:: string * rows;
  int * delimiter;
  int position = 0;
  std:: string final_result = "";

  char compare_chars(char a, char b, int q)
  {
    char _ret_char;
    int x = a;
    int y = b;

    if  (x >= 48 && x <= 57) x += 43;
    if  (y >= 48 && y <= 57) y += 43;

    if (x < y) _ret_char = a;
    else _ret_char = b;

    if (_ret_char == b) position = q;
    return _ret_char;
  }

public:

  dcoltrans(std:: string key, std:: string content, bool _enc, bool _dec, bool _tab, int block);
  void encrypt(std:: string key, std:: string content, bool _tab);
  void decrypt(std:: string key, std:: string content, bool _tab);
  std:: string key_converter(std::string key);
  std:: string return_result();
  ~dcoltrans();

};


dcoltrans:: dcoltrans(std:: string key, std:: string content, bool _enc, bool _dec, bool _tab, int block)

{
   if (_enc) encrypt(key, content, _tab);
   if (_dec) decrypt(key, content, _tab);

  // int counter = 1;
  // for (int i = 0; i < final_result.length(); i++)
  //   {
  //     std:: cout << final_result[i];
  //     if (i%block == 0 && i != 0) std:: cout << " ";
  //   }

}
std:: string dcoltrans:: return_result()
{
  return final_result;
}
void dcoltrans:: encrypt(std:: string key, std:: string content, bool _tab)
{
    final_result = "";
    int key_length = key.length();
    int content_length = content.length();
    int total_space = key_length;
    for (int i = 1; i < key_length+1; i++) total_space+=i;
    int _num = content_length/total_space + (content_length % total_space != 0);
    rows = new std:: string[(key_length+1)*_num];
    std::string numKey = key_converter(key);

    int z, q, p, t;
    p = 1;
    t = 0;

    key_length = (key_length+1)*_num;

    //this is awful programming practice but
    //key_length and key.length() are now different..

    delimiter = new int [key_length];
    delimiter[0] = key.length();


    for (int i = 1; i < key_length; i++)
    {
        for (int j = 0; j < numKey.length(); j++)
        {
          z = numKey[j] - '0';
          if (z == p) delimiter[i] = j;
        }
        if (p==key.length())
        {
          i++;
          t=1;
          delimiter[i] = key.length();
          p=0;
        }
    p++;
    }


    for (int i = 0; i < key_length; i++)
    {
      for (int j = 0; j < key.length(); j++)
      {
        rows[i]+="&";
      }
      rows[i][delimiter[i]+1] = '*';

    }


  content+= "*";
  p = 0;
  for (int i = 0; i < key_length; i++)
  {
    for (int j = 0; rows[i][j]!= '*' && j < key.length(); j++)
    {
      rows[i][j] = content[p];
      p++;
      if (content[p] == '*') {i = key_length; break;}
    }
  }

  z = 0;
  for (int i = 0; i < key.length(); i++)
  {
    z = numKey[i] - '0';
    z--;
    for (int j = 0; j < key_length; j++)
    {
      if (rows[j][z] != '*' && rows[j][z] != '&') final_result+=rows[j][z];
    }
  }
  if (_tab)
  {
    for (int i = 0; i < key_length; i++)
    std:: cerr << rows[i] << std:: endl;
  }
}

void dcoltrans:: decrypt(std:: string key, std:: string content, bool _tab)
{
    final_result = "";
  int key_length = key.length();
  int content_length = content.length();
  int total_space = key_length;
  for (int i = 1; i < key_length+1; i++) total_space+=i;
  int _num = content_length/total_space + (content_length % total_space != 0);
  rows = new std:: string[(key_length+1)*_num];
  std::string numKey = key_converter(key);

  int z, q, p, t;
  p = 1;
  t = 0;

  key_length = (key_length+1)*_num;

  //this is awful programming practice but
  //key_length and key.length() are now different..

  delimiter = new int [key_length];
  delimiter[0] = key.length();


  for (int i = 1; i < key_length; i++)
  {
      for (int j = 0; j < numKey.length(); j++)
      {
        z = numKey[j] - '0';
        if (z == p) delimiter[i] = j;
      }
      if (p==key.length())
      {
        i++;
        t=1;
        delimiter[i] = key.length();
        p=0;
      }
  p++;
  }


  for (int i = 0; i < key_length; i++)
  {
    for (int j = 0; j < key.length(); j++)
    {
      rows[i]+="&";
    }
    for (int j = delimiter[i]+1; j < key.length(); j++ )
        rows[i][j] = '*';
  }



  content+= '*';

  p = 0;

int amps = 0;
  for (int i = 0; i < key_length; i++)
    {
      for (int j = 0; j < key.length(); j++)
      {
        if (amps >= content_length) rows[i][j] = '*';
        if (rows[i][j] == '&') amps++;
      }
    }


  for (int i = 0; i < key.length(); i++)
  {
    z = numKey[i] - '0';
    z--;
    for (int j = 0; j < key_length; j++)
    {
      if (rows[j][z] != '*')
      {
        rows[j][z] = content[p];
        p++;
        if (content[p] == '*') {i = key.length(); break;}
      }
    }
  }


  for (int i = 0; i < key_length; i++)
  {
    for (int j = 0; j < key.length(); j++)
    {
      if (rows[i][j] != '*' && rows[i][j] != '&') final_result+=rows[i][j];
    }
  }
  if (_tab)
  {
    for (int i = 0; i < key_length; i++)
    std:: cerr << rows[i] << std:: endl;
  }
}


std:: string dcoltrans:: key_converter(std:: string key)
{
  std:: string numKey = "";
  for (int i = 0; i < key.length(); i++) numKey+="x";
  std::transform(key.begin(), key.end(), key.begin(), toupper);
  char lowest = 'x';
  char temp;
  for (int i = 0; i < key.length(); i++)
  {
    for (int j = 0; j < key.length(); j++)
    {
      lowest = compare_chars(lowest, key[j], j);
    }
    temp = (char)(i+1) + '0';
    numKey[position] = temp;
    key [position] = 'x';
    lowest = 'x';

  }
return numKey;
}

dcoltrans:: ~dcoltrans()
{

  //delete [] rows;
  //delete [] delimiter;
}


#endif
