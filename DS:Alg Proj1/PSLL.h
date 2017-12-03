//Implementing ADT List with a Pool Using Singly Linked List
//Preston Programming
//======================================================

#ifndef _PSLL_H
#define _PSLL_H

#include "List.h"

using namespace cop3530;

namespace cop3530{


template <typename X>
  class PSLL : public List<X> {
  private:

   struct node{
     X data;
     node* next;
   };

   node* head;
   node* temp;
   node* current;
   node* tail;
   node* poolHead;
   node* poolTail;
   node* poolCurr;
   node* poolTemp;
   X nothing = NULL;


  bool freePool()
  {
  if(poolHead == nullptr) return false;
  else return true;

  }

  node* findNode()
  {
   //this function returns a free node from the pool
   poolTemp = poolHead;
   poolHead = poolHead->next;
   return poolTemp;
  }

  bool memoryWaste()
  {
   if(length() >= 100 && (poolLength() > (length()/2)))
     return true;
     else return false;
  }
  void memorySaver()
  {
   poolCurr = poolHead;
   size_t count = 0;
   size_t half = poolLength()/2;
   while (count < half)
   {
     poolCurr = poolCurr->next;
     count++;
   }
   poolTemp = poolCurr;
   while(poolCurr->next != nullptr)
   {
     node* delNode = poolCurr;
      poolCurr = poolCurr->next;
     delete delNode;
   }
   poolTemp->next = nullptr;
  }
  size_t poolLength()
  {
   if (poolHead == nullptr) return 0;

   size_t count = 0;
   poolCurr = poolHead;
   while (poolCurr->next != nullptr)
     {
       poolCurr = poolCurr->next;
       count++;
     }
   count++;
   return count;

  }

  void clearPool()
  {

      if (poolHead == nullptr)
        {
          return;
        }

      poolCurr = poolHead;

      while (poolCurr->next != nullptr)
        {
           node* delNode = poolCurr;
            poolCurr = poolCurr->next;
             delete delNode;
        }
        node* delNode = poolCurr;
        delete delNode;
  }
public:
  template <typename dX>
      class PSLL_Iter
      {

        // type aliases required for C++ iterator compatibility
    using size_t = std::size_t;
    using value_type = dX;
    using reference = dX&;
    using pointer = dX*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;


    // type aliases for prettier code
    using self_type = PSLL_Iter;
    using self_reference = PSLL_Iter&;

  private:
    node* here;

  public:
    explicit PSLL_Iter( node* start = nullptr ) : here( start ) {}
    PSLL_Iter( const PSLL_Iter& src ) : here( src.here ) {}


    reference operator*() const {
      return here->data;
    }
    pointer operator->() const {
       return &(operator*());
    }

    self_reference operator=( PSLL_Iter<dX> const& src ) {
      if (this == &src) return (*this);
      here = src.here;
      return *this;
    }

    self_reference operator++() {
      if (here->next != nullptr){ here = here->next;
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

    bool operator==( PSLL_Iter<dX> const& rhs ) const {
      return (here == rhs.here);
    }
    bool operator!=( PSLL_Iter<dX> const& rhs) const {
      return (here != rhs.here);
    }

  }; // end of PSLL iter class




 public :
  PSLL ();
  void insert (X element, size_t position)override;
  void push_back (X element)override;
  void push_front (X element)override;
  X replace (X element, size_t position)override;
  X remove (size_t position)override;
  X pop_back()override;
    X pop_front()override;
  X& item_at (size_t position)override;
  X& peek_back()override;
  X& peek_front()override;
  bool is_empty()override;
  bool is_full()override;
  size_t length()override;
  void clear()override;
  bool contains(X element, std::function<bool (X,X)> contains)override;
  void print (std::ostream& stream)override;
  X* contents()override;


  ~PSLL () override;

  using iterator = PSLL_Iter<X>;
  using const_iterator = PSLL_Iter<X const>;


  iterator begin() const {
    return PSLL_Iter<X>( head );
  }


  iterator end() const {
    return PSLL_Iter<X>();
  }

 };

  };

//-----------------------------------------------------
//Constructor

 template <typename X>
   PSLL<X>::PSLL(){
   head = nullptr;
   tail = nullptr;
   current = nullptr;
   temp = nullptr;
   poolHead = nullptr;
   poolTail = nullptr;
   poolCurr = nullptr;
   poolTemp = nullptr;

 }



 //-----------------------------------------------------
//insert
 template <typename X>
   void PSLL<X> :: insert(X ele, size_t position)
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

           node* foo;
            if(freePool()) foo = findNode();
            else foo = new node;
           foo-> data = ele;
           foo->next = current;
           temp->next = foo;

   }

   //-----------------------------------------------------
   //push_back

   template <typename X>
     void PSLL<X> :: push_back(X ele)
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

            node* foo;
             if(freePool()) foo = findNode();
             else foo = new node;
            foo->data = ele;
            foo->next = nullptr;
            tail->next = foo;
            tail = foo;
     }

   //-----------------------------------------------------
    //push_front
     template <typename X>
       void PSLL<X> :: push_front(X ele)
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

         node* foo;
          if(freePool()) foo = findNode();
          else foo = new node;
         foo->data = ele;
         foo->next = head;
         head = foo;

       }

    //-----------------------------------------------------
    //replace

       template<typename X>
        X PSLL<X> :: replace(X ele, size_t position)
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
        X PSLL<X>:: remove (size_t position)
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
             current->next = poolHead;
             poolHead = current;
             if (memoryWaste()) memorySaver();
             return tempDat;
           }



//-----------------------------------------------------
//pop_back

    template<typename X>
      X PSLL<X>::pop_back()
      {
        if (head == nullptr)
        {
          std:: cerr << "Error head does not exist\n";
          return NULL;
        }
        if (length() == 1)
        {
          return pop_front();
        }
        current = head;
        while (current->next != tail)
        {
          current = current->next;
        }
        X tempDat = tail->data;
        tail->next = poolHead;
        poolHead = tail;
        tail = current;
        tail->next = nullptr;
        return tempDat;
    }
//-----------------------------------------------------
//pop_front

      template<typename X>
        X PSLL<X>:: pop_front()
        {
          if (head == nullptr)
          {
            std:: cerr << "Error head does not exist\n";
            return NULL;
          }

          X tempDat = head->data;

          temp = head->next;

          head->next = poolHead;

          poolHead = head;

          head = temp;

          return tempDat;
       }

 //-----------------------------------------
 //item_at

 template<typename X>
 X& PSLL<X>::  item_at (size_t position)
 {
   if (position < 0 || position > length())
   {
     std:: cerr << "Error position out of bounds\n";
     return nothing;
   }

   if (head == nullptr)
   {
     std:: cerr << "Error head does not exist\n";
     return nothing;
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
   X& PSLL<X>:: peek_back()
   {
     if (head == nullptr)
     {
       std:: cerr << "Error head does not exist\n";
       return nothing;
     }

     return tail->data;
   }

 //-----------------------------------------
 //peek_front
 template <typename X>
   X& PSLL<X>:: peek_front()
   {
     if (head == nullptr)
     {
       std:: cerr << "Error head does not exist\n";
       return nothing;
     }

     return head->data;
   }


 //-----------------------------------------
 //is_empty
 template <typename X>
  bool PSLL<X>::is_empty()
  {
    if (head == nullptr) return true;
    else return false;
  }


 //-----------------------------------------
 //is_full
 template <typename X>
   bool PSLL<X>:: is_full()
   {
     return false;
   }

   //-----------------------------------------
  //length
   template <typename X>
     size_t PSLL<X>:: length()
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
 void PSLL<X>:: clear()
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
   //also need to clear pool? or add all these to pool instead?
 }

 //---------------------------------------------
 // contains
  template<typename X>
    bool PSLL<X>::  contains(X element, std::function<bool (X,X)> contains)
    {
      if (head == nullptr)
      {
        std:: cerr << "Error head does not exist\n";
        return nothing;
      }
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
 void PSLL<X>:: print (std::ostream& stream)
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
    X* PSLL<X>:: contents()
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
    PSLL<X>::~PSLL()
     {
       clear();

       delete head;
       delete tail;
       delete current;
       //also delete pool?
     }



//=======================================
//END OF PSLL.h

#endif
