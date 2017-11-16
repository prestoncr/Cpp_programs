#include "SSLL.h"
#include <string>


bool contains (int x, int y)
{
  if (x == y) return true;
  return false;
}

int main()
{

  cop3530::List<char> *list = new cop3530::SSLL<char>();


  list->insert('A', 0);

    list->insert('B', 1);

    list->push_back('C');

    list->push_front('D');

    list->print(std::cout);

    list->clear();

}
