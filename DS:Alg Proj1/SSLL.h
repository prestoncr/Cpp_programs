//Implementing ADT List with a Simple Singly Linked List
//Preston Programming
//======================================================

#ifndef _SSLL_H_
#define _SSLL_H_

#include "List.h"
#include <iterator>
 using namespace cop3530;
namespace cop3530{


template <typename X>
  class SSLL : public List<X> {

  private:
   struct node{
     X data;
     node* next;
   };
   node* head;
   node* temp;
   node* current;
   node* tail;


  public:
    template <typename dX>
        class SSLL_Iter
        {

          // type aliases required for C++ iterator compatibility
      using size_t = std::size_t;
      using value_type = dX;
      using reference = dX&;
      using pointer = dX*;
      using difference_type = std::ptrdiff_t;
      using iterator_category = std::forward_iterator_tag;


      // type aliases for prettier code
      using self_type = SSLL_Iter;
      using self_reference = SSLL_Iter&;

    private:
      node* here;

    public:
      explicit SSLL_Iter( node* start = nullptr ) : here( start ) {}
      SSLL_Iter( const SSLL_Iter& src ) : here( src.here ) {}


      reference operator*() const {
        return here->data;
      }
      pointer operator->() const {
         return &(operator*());
      }

      self_reference operator=( SSLL_Iter<dX> const& src ) {
        if (this == &src) return (*this);
        here = src.here;
        return *this;
      }

      self_reference operator++() {
        if (here->next != NULL){ here = here->next;
        return *this;
      }
      here = nullptr;
      return *this;

      } // preincrement

      self_type operator++(int) {
        self_type tmp (*this);
        ++(*this);
        return tmp;
      } // postincrement

      bool operator==( SSLL_Iter<dX> const& rhs ) const {
        return (here == rhs.here);
      }
      bool operator!=( SSLL_Iter<dX> const& rhs) const {
        return (here != rhs.here);
      }

    }; // end of SSLL iter class



 public :
  SSLL ();
  SSLL(const SSLL<X> &list2);
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
  bool contains(X element, std::function<bool (X,X)> contains)override;
  void print (std::ostream& stream)override;
  X* contents()override;


  ~SSLL () override;


  using iterator = SSLL_Iter<X>;
  using const_iterator = SSLL_Iter<X const>;


  iterator begin() const {
    return SSLL_Iter<X>( head );
  }


  iterator end() const {
    return SSLL_Iter<X>( tail );
  }

 };




//-----------------------------------------------------
//Constructor

 template <typename X>
   SSLL<X>::SSLL(){
   head = nullptr;
   tail = nullptr;
   current = nullptr;
   temp = nullptr;

 }

//-----------------------------------------------------
//Copy Constructor
template <typename X>
  SSLL<X>::SSLL(const SSLL<X> &list2){
    head = list2.head;
    tail = list2.tail;
    temp = nullptr;
    current = nullptr;
  }



//-----------------------------------------------------
//insert
 template <typename X>
   void SSLL<X> :: insert(X ele, size_t position)
   {

     if (position < 0 || position > length())
     {
       std:: cerr << "Error position out of bounds\n";
       return;
     }

     if (position == 0)
     {
       push_front(ele);
       return;
     }
     if (position == length())
     {
       push_back(ele);
       return;
     }

     if (head == nullptr)
     {
       std:: cerr << "Error head does not exist\n";
       return;
     }

      current = head;
      size_t count = 0;

      while (count != position)
      {
        temp = current;
        current = current->next;
        count++;
      }

      node* foo = new node;
      foo-> data = ele;
      foo->next = current;
      temp->next = foo;

   }



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void SSLL<X> :: push_back(X ele)
   {

     if (head == nullptr)
     {
       node* foo = new node;
       foo->data = ele;
       foo->next = tail;
       head = foo;
       tail = foo;
       tail->next = nullptr;
       return;
     }

     node* foo = new node;
     foo->data = ele;
     foo->next = nullptr;
     tail->next = foo;
     tail = foo;
   }



 //-----------------------------------------------------
//push_front
 template <typename X>
   void SSLL<X> :: push_front(X ele)
   {
     if (head == nullptr)
     {
       node* foo = new node;
       foo->data = ele;
       foo->next = tail;
       head = foo;
       tail = foo;
       tail->next = nullptr;
       return;
     }

     node* foo = new node;
     foo->data = ele;
     foo->next = head;
     head = foo;

   }

 //-----------------------------------------------------
//replace

template<typename X>
  X SSLL<X> :: replace(X ele, size_t position)
  {
    if (position < 0 || position > length())
    {
      std:: cerr << "Error position out of bounds\n";
      return NULL;
    }

    if (head == nullptr)
    {
      std:: cerr << "Error head does not exist\n";
      return NULL;
    }

    current = head;
    size_t count = 0;

    while (count != position)
    {
      current = current->next;
      count++;
    }

    X tempDat = current->data;
    current->data = ele;
    return tempDat;

  }

//-----------------------------------------------------
//remove
 template<typename X>
   X SSLL<X>:: remove (size_t position)
   {
     if (position < 0 || position > length())
     {
       std:: cerr << "Error position out of bounds\n";
       return NULL;
     }

     if (head == nullptr)
     {
       std:: cerr << "Error head does not exist\n";
       return NULL;
     }
     if (position == 0) return pop_front();

     if (position == length() -1) return pop_back();

     size_t count = 0;
     current = head;

     while (count != position)
     {
       temp = current;
       current = current->next;
       count++;
     }
     X tempDat = current->data;
      temp->next = current->next;
     node* delPtr = current;
     delete delPtr;
     return tempDat;
   }

//-----------------------------------------------------
//pop_back

 template<typename X>
   X SSLL<X>::pop_back()
   {
     if (head == nullptr)
     {
       std:: cerr << "Error head does not exist\n";
       return NULL;
     }
     current = head;
     while (current->next != tail)
     {
       current = current->next;
     }
     node* delPtr = tail;
     X tempDat = tail->data;
     tail = current;
     tail->next = nullptr;
     delete delPtr;
     return tempDat;
   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X SSLL<X>:: pop_front()
   {
     if (head == nullptr)
     {
       std:: cerr << "Error head does not exist\n";
       return NULL;
     }

     X tempDat = head->data;
     node* delPtr = head;
     head = head->next;
     delete delPtr;
     return tempDat;
    }

//-----------------------------------------
//item_at

template<typename X>
X SSLL<X>::  item_at (size_t position)
{
  if (position < 0 || position > length())
  {
    std:: cerr << "Error position out of bounds\n";
    return NULL;
  }

  if (head == nullptr)
  {
    std:: cerr << "Error head does not exist\n";
    return NULL;
  }
  if (position == 0) return peek_front();
  if (position == length() -1) return peek_back();

  size_t count  = 0;
  current = head;
  while (count != position)
  {
    current = current->next;
    count++;
  }

  return current->data;

}


 //-----------------------------------------
//peek_back
 template <typename X>
   X SSLL<X>:: peek_back()
   {
     return tail->data;
   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X SSLL<X>:: peek_front()
   {
     return head->data;
   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool SSLL<X>::is_empty()
  {
    if (head == nullptr) return true;
    else return false;
  }


//-----------------------------------------
//is_full
 template <typename X>
   bool SSLL<X>:: is_full()
   {
     return false;
   }


 //-----------------------------------------
//length
 template <typename X>
   size_t SSLL<X>:: length()
   {
     if (head == nullptr) return 0;
     size_t count = 0;
     current = head;
     while (current->next != nullptr)
     {
        count++;
       current = current->next;
     }
     count++;
     return count;
   }

 //-----------------------------------------
//clear
template <typename X>
  void SSLL<X>:: clear()
  {
    if (head == nullptr) return;
    current = head;
    while (current->next != nullptr)
    {
      node* delPtr = current;
      current = current->next;
      delete delPtr;
    }
    head = nullptr;
    tail = nullptr;
  }


//---------------------------------------------
// contains
 template<typename X>
   bool SSLL<X>::  contains(X element, std::function<bool (X,X)> contains)
   {
     bool final = false;

     current = head;
     while (current->next != nullptr)
     {
       if (contains(element, current->data)) final = true;
       current = current ->next;
     }
      if (contains(element, tail->data)) final = true;

      return final;
   }


//---------------------------------------------
// print
 template <typename X>
 void SSLL<X>:: print (std::ostream& stream)
 {
   if (head == nullptr)
     {
       stream << "<empty list>";
       return;
     }
   current = head;
   stream << "[";
   while (current->next != nullptr)
     {
       stream  << current->data << ",";
       current = current->next;
     }
   stream << current->data << "]";

 }

//---------------------------------------------
// contents
 template <typename X>
   X* SSLL<X>:: contents()
   {

     if (head == nullptr)
       {
         std::cout << "Error, list is empty\n\n";
         return NULL;
       }

       size_t count = 0;
       X* itemArr = new X[length()];
     current = head;
     while (current->next != nullptr)
       {
         itemArr[count] = current->data;
          count++;
           current = current->next;
       }
     itemArr[count] = current->data;

     return itemArr;
   }
 //-------------------------------
 //Destructor
 template <typename X>
   SSLL<X>::~SSLL()
    {
      clear();

      delete head;  
      delete tail;
      delete current;



    }

//===========================================
//END OF SSLL.h
   }
#endif
