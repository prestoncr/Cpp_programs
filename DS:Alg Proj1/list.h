//ADT List Generic Template Class
//Preston Programming
//=========================================================

#include <iostream>

#ifndef _LIST_H_
#define _LIST_H_


namespace cop3530{

template <typename X>

  class List{

 public:
  virtual void insert (X element, size_t position) = 0;
  virtual void push_back (X element) = 0;
  virtual void push_front (X element) = 0;
  virtual X replace (X element, size_t position) = 0;
  virtual X remove (size_t position) = 0;
  virtual X pop_back() = 0;
  virtual X pop_front() = 0;
  virtual X item_at (size_t position) = 0;
  virtual X peek_back() = 0;
  virtual X peek_front() = 0;
  virtual bool is_empty() = 0;
  virtual bool is_full() = 0;
  virtual size_t length() = 0;
  virtual void clear() = 0;
  virtual bool contains(X element, bool contains) = 0;
  virtual void print (std:: ostream& stream) = 0 ;
  virtual X* contents() = 0;

  virtual ~List() {};


 };

}
#endif


