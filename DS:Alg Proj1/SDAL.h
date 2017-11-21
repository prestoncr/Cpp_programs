//Implementing ADT List with a Simple Dynamic Array-Based List
//Preston Programming
//======================================================

#ifndef _SDAL_H_
#define _SDAL_H_

#include "List.h"
 using namespace cop3530;
namespace cop3530{


template <typename X>
  class SDAL : public List<X> {

  private:

    size_t arr_size;
    X *array;
    X *newArray;
    size_t og_size;
    size_t tail = 0;

    bool is_small()
    {
      if (arr_size >= 2*og_size  &&  length() < 0.5*arr_size) return true;
      else return false;
    }

    void downsize()
    {
      size_t size = arr_size*(0.75);
      this->newArray = new X [size];
      for (int i = 0; i < size; i++) newArray[i] = NULL;

      for (int i = 0; i < arr_size; i++)
      {
        this->newArray[i] = this->array[i];
      }
      this->array = this->newArray;
      arr_size = arr_size*(0.75);

    }

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

      for (int i = 0; i < arr_size; i++)
      {
        this->newArray[i] = this->array[i];
      }
      this->array = this->newArray;
      arr_size = arr_size*(1.5);

    }



public:
  template <typename dX>
      class SDAL_Iter
      {

        // type aliases required for C++ iterator compatibility
    using size_t = std::size_t;
    using value_type = dX;
    using reference = dX&;
    using pointer = dX*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;


    // type aliases for prettier code
    using self_type = SDAL_Iter;
    using self_reference = SDAL_Iter&;

  private:
    size_t here;
     dX *array;

  public:
    explicit SDAL_Iter( size_t start = 0, dX *a = NULL  )
    : here( start ), array (a)  {}
    SDAL_Iter( const SDAL_Iter& src, dX *a = NULL )
     : here( src.here ) , array (a) {}


    reference operator*() const {
      return array[here];
    }
    pointer operator->() const {
       return &(operator*());
    }

    self_reference operator=( SDAL_Iter<dX> const& src ) {
      if (this == &src) return (*this);
      here = src.here;
      return *this;
    }

    self_reference operator++() {
      if (array[here] != NULL){ here++;
      return *this;
    }
    here = NULL;
    return *this;
    //temporarily fixed I guess ! :))
    //has to return end somehow
    //must fix this to not get Illegal Instruction 4
    } // preincrement

    self_type operator++(int) {
      self_type tmp (*this);
      ++(*this);
      return tmp;
    } // postincrement

    bool operator==( SDAL_Iter<dX> const& rhs ) const {
      return (here == rhs.here);
    }
    bool operator!=( SDAL_Iter<dX> const& rhs) const {
      return (here != rhs.here);
    }

  }; // end of SDAL iter class

 public :
  SDAL (size_t start_size);
  SDAL();
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


  ~SDAL () override;

  using iterator = SDAL_Iter<X>;
  using const_iterator = SDAL_Iter<X const>;


  iterator begin()  {
    return SDAL_Iter<X>( 0, this->array );
  }


  iterator end()  {
    return SDAL_Iter<X>(this->length(), this->array);
  }

 };

//-----------------------------------------------------
//Constructor

 template <typename X>
   SDAL<X>::SDAL()
   :arr_size(50)
   {
     og_size = 50;
     makeArray(arr_size);
   }

 template <typename X>
   SDAL<X>::SDAL(size_t size)
   :arr_size (size)
   {
     og_size = size;
     makeArray (arr_size);
    }


//-----------------------------------------------------
//insert
 template <typename X>
   void SDAL<X> :: insert(X ele, size_t position)
{
  if (is_full()) resizeArray(); //recopy array

     for (size_t i = length(); i > position; i--)
      {
        array[i] = array[i-1];
      }
      array[position] = ele;
      tail++;
}



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void SDAL<X> :: push_back(X ele)
   {
     if (is_full())resizeArray(); // recopy array
      array[tail] = ele;
      tail++;
   }



 //-----------------------------------------------------
//push_front
 template <typename X>
   void SDAL<X> :: push_front(X ele)
{
     if (is_full())resizeArray(); //recopy array

        for (size_t i = length(); i > 0; i--)
         {
           array[i] = array[i-1];
         }
         array[0] = ele;
         tail++;
}

 //-----------------------------------------------------
//replace

template<typename X>
  X SDAL<X> :: replace(X ele, size_t position)
  {
    X tempDat = array[position];
    array[position] = ele;
    return tempDat;
  }

//-----------------------------------------------------
//remove
 template<typename X>
   X SDAL<X>:: remove (size_t position)
   {
     X tempDat = array[position];

     for (size_t i = position; i < length(); i++)
     {
       array[i] = array[i+1];
     }
     array[length()-1] = NULL;
     tail--;
     return tempDat;

   }

//-----------------------------------------------------
//pop_back

 template<typename X>
   X SDAL<X>::pop_back()
   {
     X tempDat = array[length()-1];
     array[length() -1] = NULL;
     tail--;
     return tempDat;

   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X SDAL<X>:: pop_front()
   {
     X tempDat = array[0];
     for (size_t i = 0; i < length(); i++)
     {
       array[i] = array[i+1];
     }
     array[length()-1] = NULL;
     tail--;
    return tempDat;
   }

//-----------------------------------------
//item_at

template<typename X>
X SDAL<X>::  item_at (size_t position)
{
  return array[position];
}

 //-----------------------------------------
//peek_back
 template <typename X>
   X SDAL<X>:: peek_back()
   {
     return array[length()-1];
   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X SDAL<X>:: peek_front()
   {
     return array[0];
   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool SDAL<X>::is_empty()
  {
    if (array[0] == NULL) return true;
    else return false;
  }


//-----------------------------------------
//is_full
 template <typename X>
   bool SDAL<X>:: is_full()
   {
     if(array[arr_size-1] == NULL) return false;
     else return true;
   }


 //-----------------------------------------
//length
 template <typename X>
   size_t SDAL<X>:: length()
   {

     return tail;
   }

 //-----------------------------------------
//clear
template <typename X>
  void SDAL<X>:: clear()
  {
    delete array;
    makeArray(arr_size);
    tail = 0;

  }


//---------------------------------------------
// contains
 template<typename X>
   bool SDAL<X>::  contains(X element, std::function<bool (X,X)> contains)
   {
    if (is_empty()) return false;

     for (int i = 0; i < arr_size; i++)
     {
       if (array[i] != NULL)
       {
         if (contains(element, array[i])) return true;
       }
     }
     return false;
   }


//---------------------------------------------
// print
 template <typename X>
 void SDAL<X>:: print (std::ostream& stream)
 {
   if (is_empty())
   {
    stream << "<empty list>";
    return;
    }
  size_t count = 0;
  stream << "[";
   while (count < tail-1)
   {
     stream << array[count] << ",";
     count++;
   }
   stream << array[tail-1] << "]";

}

//---------------------------------------------
// contents
 template <typename X>
   X* SDAL<X>:: contents()
   {
      X* itemArr = new X[length()];
      itemArr = array;
     return itemArr;
   }
 //-------------------------------
 //Destructor
 template <typename X>
   SDAL<X>::~SDAL()
    {
      delete array;
    }

//===========================================
//END OF SDAL.h
   }
#endif
