#include "SSLL.h"
#include <string>

bool contains (int x, int y)
{
  if (x == y) return true;
  return false;
}

int main()
{
  using namespace cop3530;

  SSLL<int> simple;
// cop3530::List<char> *list = new cop3530::SSLL<char>();
// std:: cout << "here1\n";
//
// list->insert('A', 0);
// std:: cout << "here2\n";
//   list->insert('B', 1);
//   std:: cout << "here3\n";
//   list->push_back('C');
//   std:: cout << "here4\n";
//   list->push_front('D');
//   std:: cout << "here5\n";
//   list->print(std::cout);

simple.insert(69, 0);
std:: cout << "here4\n";

simple.insert(-5, 1);
  std:: cout << "\n\n\nSTARTING\n\n";


    for (int i = 0; i < 30; i++)
      {
        simple.push_back(i);
      }



      simple.insert(323, 15);
      std:: cout << "Peek front " << simple.peek_front() << std:: endl;
      std:: cout << "Peek back " << simple.peek_back() << std:: endl;


  SSLL<int>::iterator iter = simple.begin();
  SSLL<int>::iterator end = simple.end();


  while (iter != end)
  {
    std::cout << *iter << std:: endl;
    ++iter;
  }
  std::cout << *iter << std:: endl;


    //SSLL<int> complex = simple;
    complex.~SSLL();

    std:: cout << "Peek front " << complex.peek_front() << std:: endl;
    std:: cout << "Peek back " << complex.peek_back() << std:: endl;

    simple.print(std::cout);


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
