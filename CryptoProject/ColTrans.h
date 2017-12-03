//Columnar Transposition Header File
//Preston Programming

#ifndef _ColTrans_H
#define _ColTrans_H

#include <iostream>

class ColTrans
{
private:

  std:: string * columns;
  std:: string result;

public:
  ColTrans(std:: string key, std:: string content);
  ~ColTrans();
  std:: string do_col_trans(std:: string key, std:: string content, int x);
};


ColTrans:: ColTrans(std:: string key, std:: string content)

{

  int x = key.length();

  this->columns = new std:: string [x];

  for (int i = 0; i < x; i++) columns[i] = "";

  result = do_col_trans(key, content, x);

  std:: cout << "Result is " << result << std::endl;

}

std:: string ColTrans:: do_col_trans(std:: string key, std:: string content, int x)
{
    std:: string _result = "";
    int z;
    int length_final = content.length();
    int length = content.length();
    int j = 0;

    while (length)
    {
      for (int i = 0; i < x; i++)
      {
        if (j > length_final)
        {length = 0; break;}
        columns[i] += content[j];
        j++;
        length--;
      }
    }

    // for (int i = 0; i < key.length(); i++)
    // {
    //   z = key[i] - '0';
    //   _result += columns[z-1];
    // }
    for (int i = 0; i < key.length(); i++)
    {
      for (int j = 0; j < key.length(); j++)
      {
        z = key[j] - '0';
        if (z-1 == i)
        {
          _result += columns[j];
        }
      }

    }

    return _result;
}

ColTrans:: ~ColTrans()
{

  delete [] columns;
}


#endif
