#include "CDAL.h"
#include <string>


int main()
{
  using namespace cop3530;

  CDAL<int> simple;

  for(int i =0; i < 121; i++)
  simple.push_back(i);
  simple.insert(169, 72);
  simple.push_front(772);
  simple.remove(30);
  simple.print(std:: cout);
  std:: cout << "\n\n" << simple.peek_back() << "\n\n" << simple.peek_front() << "\n";

simple.remove(30);




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
