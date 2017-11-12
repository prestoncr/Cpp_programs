//Implementing ADT List with a Circular Buffered List
//Preston Programming
//======================================================

#ifndef _CBL_H_
#define _CBL_H_

#include "list.h"
 using namespace cop3530;
namespace cop3530{


template <typename X>
  class CBL : public List<X> {

  private:

    size_t arr_size;
    X *array;
    X *newArray;
    size_t head = 0;
    size_t tail = 0;

    void makeArray(size_t size)
    {
      this->array = new X [size];
      for (int i = 0; i < size; i++) array[i] = NULL;
    }
    void resizeArray()
    {

      size_t size = arr_size*(1.5);

      this->newArray = new X [size];
      for (int i = 0; i < size; i++) newArray[i] = NULL;

      size_t curr = head;
      size_t counter = 0;
      while (counter != arr_size)
      {
        newArray[counter] = array[curr];
        if (curr+1 == arr_size) curr = -1;
        counter++;
        curr++;
      }
      head = 0;
      tail = arr_size;
      this->array = this->newArray;
      arr_size = arr_size*(1.5);

    }



public:
  template <typename dX>
      class CBL_Iter : public CBL<X>
      {

        // type aliases required for C++ iterator compatibility
    using size_t = std::size_t;
    using value_type = dX;
    using reference = dX&;
    using pointer = dX*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;


    // type aliases for prettier code
    using self_type = CBL_Iter;
    using self_reference = CBL_Iter&;

  private:
    size_t here;
     dX *array;
     size_t a_size;

  public:
    explicit CBL_Iter( size_t start = NULL, dX *a = NULL, size_t x = NULL  )
    : here( start ), array (a), a_size (x) {}
    CBL_Iter( const CBL_Iter& src, dX *a = NULL )
     : here( src.here ) , array (a) {}


    reference operator*() const {
      return array[here];
    }
    pointer operator->() const {
       return &(operator*());
    }

    self_reference operator=( CBL_Iter<dX> const& src ) {
      if (this == &src) return (*this);
      here = src.here;
      return *this;
    }

    self_reference operator++() {
      if (here+1 == a_size)
      {
         here = -1;
      }
        here++;
        return *this;

    } // preincrement

    self_type operator++(int) {
      self_type tmp (*this);
      ++(*this);
      return tmp;
    } // postincrement

    bool operator==( CBL_Iter<dX> const& rhs ) const {
      return (here == rhs.here);
    }
    bool operator!=( CBL_Iter<dX> const& rhs) const {
      return (here != rhs.here);
    }

  }; // end of CBL iter class

 public :
  CBL (size_t start_size);
  CBL();
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
  bool contains(X element, bool func(X, X))override;
  void print (std::ostream& stream)override;
  X* contents()override;

  ~CBL () override;

  using iterator = CBL_Iter<X>;
  using const_iterator = CBL_Iter<X const>;


  iterator begin()  {
    return CBL_Iter<X>( this->head, this->array, this->arr_size );
  }


  iterator end()  {
    return CBL_Iter<X>(this->tail, this->array, this->arr_size);
  }

 };

//-----------------------------------------------------
//Constructor

 template <typename X>
   CBL<X>::CBL()
   :arr_size(50)
   {
     makeArray(arr_size);
   }

 template <typename X>
   CBL<X>::CBL(size_t size)
   :arr_size (size)
   {
     makeArray (arr_size);
    }


//-----------------------------------------------------
//insert
 template <typename X>
   void CBL<X> :: insert(X ele, size_t position)
{
  if (is_full()) resizeArray(); //recopy array

    size_t curr = head;
    for (int i = 0; i < position; i++)
    {
      if (curr+1 != arr_size) curr++;
      else curr = 0;
    }

    size_t temp = tail;

    while (temp != curr)
    {
      if (temp == 0)
      {
            array[temp] = array[arr_size-1];
            temp = arr_size;
      }
      else
            array[temp] = array[temp-1];
      temp--;
    }

     array[curr] = ele;
     tail++;
}



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void CBL<X> :: push_back(X ele)
   {
     if (is_full()) resizeArray(); // recopy array
     if (tail == arr_size) tail = 0;
     array[tail] = ele;
     tail++;
   }



 //-----------------------------------------------------
//push_front
 template <typename X>
   void CBL<X> :: push_front(X ele)
{
     if (is_full()) resizeArray(); //recopy array
     if (head == 0)
     {
       array[arr_size-1] = ele;
       head = arr_size-1;
     }
    else
    {
      array[head-1] = ele;
      head = head-1;
    }
}

 //-----------------------------------------------------
//replace

template<typename X>
  X CBL<X> :: replace(X ele, size_t position)
  {
    size_t curr = head;
    for (int i = 0; i < position; i++)
    {
      if (curr+1 != arr_size) curr++;
      else curr = 0;
    }

    X tempDat = array[curr];
    array[curr] = ele;
    return tempDat;
  }

//-----------------------------------------------------
//remove
 template<typename X>
   X CBL<X>:: remove (size_t position)
   {
     size_t curr = head;
     for (int i = 0; i < position; i++)
     {
       if (curr+1 != arr_size) curr++;
       else curr = 0;
     }

     X tempDat = array[curr];

     while(curr != tail)
     {
       if(curr == arr_size-1)
       {
         array[curr] = array[0];
         curr = -1;
       }

       else
            array[curr] = array[curr+1];
        curr++;
     }

      array[tail] = NULL;
      tail--;
     return tempDat;
   }

//-----------------------------------------------------
//pop_back

 template<typename X>
   X CBL<X>::pop_back()
   {
     if (tail == 0) tail = arr_size;
     X tempDat = array[tail-1];
     array[tail-1] = NULL;
     tail--;
     return tempDat;
   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X CBL<X>:: pop_front()
   {
     X tempDat = array[head];
     array[head] = NULL;
     if (head == arr_size-1) head = 0;
     else head++;

    return tempDat;
   }

//-----------------------------------------
//item_at

template<typename X>
X CBL<X>::  item_at (size_t position)
{
  size_t curr = head;
  for (int i = 0; i < position; i++)
  {
    if (curr+1 != arr_size) curr++;
    else curr = 0;
  }

return array[curr];
}

 //-----------------------------------------
//peek_back
 template <typename X>
   X CBL<X>:: peek_back()
   {

    if (tail-1 == -1) return array[arr_size-1];
    else return array[tail-1];

   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X CBL<X>:: peek_front()
   {
     return array[head];
   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool CBL<X>::is_empty()
  {
    if (head == tail) return true;
    else return false;
  }


//-----------------------------------------
//is_full
 template <typename X>
   bool CBL<X>:: is_full()
   {
     bool final = false;
     if (head -1 == tail) final = true;
     if (head == 0)
     {
       if (tail == arr_size) final = true;
     }

    return final;
   }


 //-----------------------------------------
//length
 template <typename X>
   size_t CBL<X>:: length()
   {
     size_t curr = head;
     size_t counter = 0;
     while (curr != tail)
     {
       counter++;
       if (curr+1 == arr_size) curr = -1;
       curr++;
     }

     return counter;
   }

 //-----------------------------------------
//clear
template <typename X>
  void CBL<X>:: clear()
  {
    delete array;
  }


//---------------------------------------------
// contains
 template<typename X>
   bool CBL<X>::  contains(X element, bool contains(X,X))
   {
     bool final = false;
     size_t curr = head;

     while (curr != tail)
     {
       if (curr == arr_size) curr == 0;
       if (contains(element, array[curr])) final = true;
       curr++;
     }

     return final;
   }


//---------------------------------------------
// print
 template <typename X>
 void CBL<X>:: print (std::ostream& stream)
 {
   if (is_empty()) stream << "<empty list>";
   else
   {
     size_t curr = head;
     while (curr != tail)
     {
       stream << "[" << array[curr] << "],";
       if (curr+1 == arr_size) curr = -1;
       curr++;
     }

   }
}

//---------------------------------------------
// contents
 template <typename X>
   X* CBL<X>:: contents()
   {
     return array;
   }
 //-------------------------------
 //Destructor
 template <typename X>
   CBL<X>::~CBL()
    {
      clear();
    }

//===========================================
//END OF CBL.h
   }
#endif
