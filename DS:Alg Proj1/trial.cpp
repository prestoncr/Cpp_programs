#include "SDAL.h"
#include <string>

void print_reversed( char const * string ) {
  if ( *string ) {
    print_reversed( string+1 );
    std::cout << *string;
  }
}

int main()
{
  using namespace cop3530;

// char a = 'A';
// char c = 'Q';
// char d = 'Z';
// char b = 'B';
char x[] = {'T', 'h', 'e', ' ', 'd', 'o', 'g'};
//char const* ptr1 = &a;
//char* const ptr2 = &b;

print_reversed(x);




std:: cout << "Success\n\n";




// SDAL<int> simple;
//
// for (int i = 0; i < 50; i++) simple.push_back(i);
//
//
// simple.push_back(50);
// simple.push_back(51);
//
//
// simple.print(std::cout);
// std:: cout << std:: endl;
// std:: cout << simple.peek_back() << std:: endl;

// simple.push_front(12);
// simple.insert(24, 3);
// simple.replace(25,3);
// int* arr = simple.contents();
// simple.print(std::cout);
// std::cout << "\n\n";
// std:: cout << *arr << std::endl;
// arr++;
// std:: cout << *arr << std::endl;
// arr++;
// std:: cout << *arr << std::endl;
//
// std::cout << "\n\n";


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
