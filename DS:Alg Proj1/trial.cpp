#include "CBL.h"
#include <string>

bool contains (int x, int y)
{
  if (x == y) return true;
  return false;
}

int main()
{
  using namespace cop3530;

  CBL<int> simple;
  std:: cout << "STARTING\n\n";


    for (int i = 21; i < 30; i++)
      {
        simple.push_back(i);
      }

      for (int i = 20; i >=0; i--)
        {
          simple.push_front(i);
        }

      simple.insert(69, 15);
      std:: cout << "Peek front " << simple.peek_front() << std:: endl;
      std:: cout << "Peek back " << simple.peek_back() << std:: endl;  





  CBL<int>::iterator iter = simple.begin();
  CBL<int>::iterator end = simple.end();


  while (iter != end)
  {
    std::cout << *iter << std:: endl;
    ++iter;
  }

    std:: cout << "ENDING\n\n";

  /*
   void insert (X element, size_t position)override;
  void push_back (X element)override;
  void push_front (X element)override;
  X replace (X element, size_t position)override;
  X remove (size_t position)override;
  X pop_back()override;
    X pop_front()override;
  X item_at (size_t position)override;
  X peek_back()override;
  X peek_front()override;
  bool is_empty()override;
  bool is_full()override;
  size_t length()override;
  void clear()override;
  bool contains(X element, bool contains)override;
  void print (std::ostream& stream)override;
  X* contents()override;
  */




  return 0;
}
