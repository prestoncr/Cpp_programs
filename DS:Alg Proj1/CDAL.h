//Implementing ADT List with a Chained Dynamic Array-Based List
//Preston Programming
//============================================================

#ifndef _CDAL_H_
#define _CDAL_H_

#include "List.h"
 using namespace cop3530;
namespace cop3530{


template <typename X>
  class CDAL : public List<X> {

  private:

    struct node
    {
      X data[50];
      node* next;
      node* previous;
    };

    node* headNode;
    node* current;
    node* tailNode;
    size_t tail = 0;
    X nothing = NULL;
    void newArray()
    {
      for (size_t i = 0; i < 50; i++)
      current->data[i] = NULL;
    }

  public:
    template <typename dX>
        class CDAL_Iter
        {

          // type aliases required for C++ iterator compatibility
      using size_t = std::size_t;
      using value_type = dX;
      using reference = dX&;
      using pointer = dX*;
      using difference_type = std::ptrdiff_t;
      using iterator_category = std::forward_iterator_tag;


      // type aliases for prettier code
      using self_type = CDAL_Iter;
      using self_reference = CDAL_Iter&;

    private:
      node* here;
      size_t index;


    public:
      explicit CDAL_Iter( node* h = NULL, size_t ind = 0  )
      : here( h ), index (ind)  {}
      CDAL_Iter( const CDAL_Iter& src )
       : here( src.here ) {}


      reference operator*() const {
        return here->data[index];
      }
      pointer operator->() const {
         return &(operator*());
      }

      self_reference operator=( CDAL_Iter<dX> const& src ) {
        if (this == &src) return (*this);
        here = src.here;
        return *this;
      }

      self_reference operator++() {
        ++index;
        if (index == 50 && here->next)
        {
          here = here->next;
          index = 0;
        }
        return *this;
      } // preincrement

      self_type operator++(int) {
        self_type tmp (*this);
        ++(*this);
        return tmp;
      } // postincrement

      bool operator==( CDAL_Iter<dX> const& rhs ) const {
      bool result = false;
      if (here == rhs.here)
        if (index == rhs.index) result = true;
      return result;
      }
      bool operator!=( CDAL_Iter<dX> const& rhs) const {
          bool result = true;
        if (here == rhs.here)
          if (index == rhs.index) result = false;
        return result;
      }

    }; // end of CDAL iter class

 public :
  CDAL();
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

  ~CDAL () override;

  using iterator = CDAL_Iter<X>;
  using const_iterator = CDAL_Iter<X const>;


  iterator begin()  {
    return CDAL_Iter<X>( headNode, 0 );
  }


  iterator end()  {
    current = tailNode;
    size_t count = 0;
    for (size_t i = 0; i < 50; i++)
      if (current->data[i]) count++;
    return CDAL_Iter<X>(tailNode, count);
  }


 };

//-----------------------------------------------------
//Constructor

 template <typename X>
   CDAL<X>::CDAL()

   {
     headNode = NULL;
     tailNode = NULL;
     current = NULL;
   }


//-----------------------------------------------------
//insert
 template <typename X>
   void CDAL<X> :: insert(X ele, size_t position)
{

  if (position < 0 || position > tail)
  {
    std:: cerr << "Position out of bounds";
    return;
  }


//if list does not exist
if (headNode == NULL)
  {
    node* foo = new node;
    current = foo;
    newArray();
    foo->data[0] = ele;
    foo->next = tailNode;
    foo->previous = NULL;
    headNode = foo;
    tailNode = headNode;
    tail++;
    return;
  }


else
  {
    X tempEle1;
    X tempEle2;
    bool filled = false;
    size_t nextFree = 0;
    size_t nodeNum = position/50;
    current = headNode;
    for (size_t i = 0; i < nodeNum; i++)
      current = current ->next;
      nodeNum = position%50;
      for (size_t i = 0; i < 50; i++)
      {
        if (current->data[i+1] == NULL && length() < 50 && position >= tail)
        {
            current->data[i+1] = ele;
            tail++;
            return;
        }
        if(current->data[i+1] == NULL)
        {
          tempEle1 = current->data[i];
          nextFree = i+1;
          break;
        }
        if (i == 48)
        {
          tempEle1 = current->data[49];
          filled = true;
          break;
        }
      }
      size_t i = 49;
      while (i > nodeNum)
      {
        current->data[i] = current->data[i-1];
        i--;
      }
      current->data[nodeNum] = ele;
      if (!filled)
      {
        //test to see if this is redundant
        current->data[nextFree] = tempEle1;
        tail++;
        return;
      }

      if (current->next == NULL)
      {
        node* foo = new node;
        foo->previous = current;
        current->next = foo;
        foo->next = NULL;
        current = foo;
        newArray();
        foo->data[0] = tempEle1;
        tailNode = foo;
        tail++;
        return;
      }

      filled = false;
      current=current->next;
      while (true)
      {
        filled = false;
        for (size_t i = 0; i < 50; i++)
        {
          if(current->data[i+1] == NULL)
          {
            tempEle2 = current->data[i];
            nextFree = i+1;
            break;
          }
          if (i == 48)
          {
            tempEle2 = current->data[49];
            filled = true;
            break;
          }
        }
        if (!filled)
        {
          for (size_t i = 49; i > 0; i--)
          {
            current->data[i] = current->data[i-1];
          }
          current->data[0] = tempEle1;
          current->data[nextFree] = tempEle2;
          tail++;
          return;
        }
        for (size_t i = 49; i > 0; i--)
        {
          current->data[i] = current->data[i-1];
        }
        current->data[0] = tempEle1;
        tempEle1 = tempEle2;

        if (current->next == NULL)
        {
          std:: cout <<"hey ooo\n\n";
          node* foo = new node;
          foo->previous = current;
          current->next = foo;
          foo->next = NULL;
          current = foo;
          newArray();
          foo->data[0] = tempEle1;
          tailNode = foo;
          tail++;
          return;
        }
        current = current->next;
      }

  }

}// end of insert



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void CDAL<X> :: push_back(X ele)
   {
     if (headNode == NULL)
     {
       node* foo = new node;
       current = foo;
       newArray();
       foo->data[0] = ele;
       foo->next = tailNode;
       foo->previous = NULL;
       headNode = foo;
       tailNode = headNode;
         tail++;
       return;
     }
     current = tailNode;
     if (current->data[49] != NULL)
     {
       node* foo = new node;
       foo->previous = current;
       current->next = foo;
       foo->next = NULL;
       current = foo;
       newArray();
       foo->data[0] = ele;
       tailNode = foo;
         tail++;
       return;

     }
     size_t spot = tail%50;
     current->data[spot] = ele;
       tail++;
   } // end of push back


 //-----------------------------------------------------
//push_front
 template <typename X>
   void CDAL<X> :: push_front(X ele)
   {
     insert(ele, 0);
   }

 //-----------------------------------------------------
//replace

template<typename X>
  X CDAL<X> :: replace(X ele, size_t position)
  {
    if (position < 0 || position > tail)
    {
      std:: cerr << "Position out of bounds";
      return nothing;
    }
    if (is_empty())
    {
      std:: cerr << "Error List is empty\n";
      return nothing;
    }
    X tempEle;
    if (headNode==NULL)
    {
        std:: cout << "Error, cannot replace, list is empty\n";
        return NULL;
    }
    current = headNode;
    size_t nodeNum = position/50;
    for(size_t i = 0; i < nodeNum; i++)
      current = current->next;
    nodeNum = position%50;
    tempEle = current->data[nodeNum];
    current->data[nodeNum] = ele;
    return tempEle;
  }//end of replace

//-----------------------------------------------------
//remove
 template<typename X>
   X CDAL<X>:: remove (size_t position)
   {
     if (position < 0 || position > tail)
     {
       std:: cerr << "Position out of bounds";
       return nothing;
     }
     if (is_empty())
     {
       std:: cerr << "Error List is empty\n";
       return nothing;
     }
     if (headNode == NULL)
     {
       std:: cout << "Error cannot remove from an empty list\n";
       return NULL;
     }

     X returnEle;
     size_t nodeNum = position/50;
     current = headNode;
     for (size_t i =0; i < nodeNum; i++) current = current->next;
     nodeNum = position%50;
     returnEle = current->data[nodeNum];


     for (size_t i = nodeNum; i < 49; i++)
     {
       current->data[i] = current->data[i+1];
     }

        if (current->next == NULL)
        {
          tail--;
          return returnEle;
        }
        current = current->next;
     while(true)
     {
       current->previous->data[49] = current->data[0];
       for (size_t i = 0; i < 49; i++)
       {
         current->data[i] = current->data[i+1];
       }
       if (current->next == NULL)
       {
         tail--;
          return returnEle;
        }
       current = current->next;
     }



   }//end of remove

//-----------------------------------------------------
//pop_back

 template<typename X>
   X CDAL<X>::pop_back()
   {
   if (is_empty())
   {
     std:: cerr << "Error List is empty\n";
     return nothing;
   }
     if (headNode == NULL)
     {
       std:: cout << "Error cannot pop, empty list\n";
       return NULL;
     }
     current = tailNode;
     X tempEle;
     for (size_t i = 0; i < 49; i++)
     {
       if (current->data[i] == NULL)
       {
         tempEle = current->data[i-1];
         current->data[i-1] = NULL;
         break;
       }
     }
     tail--;
     return tempEle;
   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X CDAL<X>:: pop_front()
   {
     return remove(0);
   }

//-----------------------------------------
//item_at

template<typename X>
X& CDAL<X>::  item_at (size_t position)
{
  if (position < 0 || position > tail)
  {
    std:: cerr << "Position out of bounds";
    return nothing;
  }
  if (is_empty())
  {
    std:: cerr << "Error List is empty\n";
    return nothing;
  }
  if (headNode == NULL)
  {
    std:: cout << "Error cannot get item in empty list\n";
    return nothing;
  }
  size_t nodeNum = position/50;
  current = headNode;
  for (size_t i =0; i < nodeNum; i++) current = current->next;
  nodeNum = position%50;
  return current->data[nodeNum];
}


 //-----------------------------------------
//peek_back
 template <typename X>
   X& CDAL<X>:: peek_back()
   {
     if (headNode == NULL)
     {
       std:: cout << "Error cannot peek, empty list\n";
       return nothing;
     }

     size_t count = 0;
     size_t index = 0;
     while (count < tail)
     {
       if (index == 50)
       {
         current = current->next;
         index = 0;
       }
       index++;
       count++;
     }
     return current->data[index-1];

   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X& CDAL<X>:: peek_front()
   {
     if (headNode == NULL)
     {
       std:: cout << "Error cannot peek, empty list";
       return nothing;
     }
     return headNode->data[0];
   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool CDAL<X>::is_empty()
  {

    if (headNode == NULL) return true;
    else if (length() == 0) return true;
    else return false;
  }


//-----------------------------------------
//is_full
 template <typename X>
   bool CDAL<X>:: is_full()
   {
     return false;
   }


 //-----------------------------------------
//length
 template <typename X>
   size_t CDAL<X>:: length()
   {
     return tail;
   }

 //-----------------------------------------
//clear
template <typename X>
  void CDAL<X>:: clear()
  {
    current = headNode;
    while (true)
    {
      node* delPtr = current;
      delete delPtr;
      if (current->next!= NULL) current = current->next;
      else break;
    }

    tail = 0;
    headNode = NULL;
  }


//---------------------------------------------
// contains
 template<typename X>
   bool CDAL<X>::  contains(X element, std::function<bool (X,X)> contains)
   {
     if (is_empty()) return false;
     while(true)
     {
       for (size_t i = 0; i < 50; i++)
       {
         if (current->data[i]!= NULL)
         {
           if (contains(element, current->data[i])) return true;
         }
       }
       if (current->next != NULL) current = current->next;
       else break;
     }
     return false;
   }


//---------------------------------------------
// print
 template <typename X>
 void CDAL<X>:: print (std::ostream& stream)
 {
   if (is_empty())
   {
     std:: cout << "<empty list>";
      return;
    }
   current = headNode;

   size_t count = 0;
   size_t index = 0;
   stream << "[";
   while (count < tail-1)
   {
     if (index == 50)
     {
       current = current->next;
       index = 0;
     }
     stream << current->data[index] << ",";
     index++;
     count++;
   }
   stream << current->data[index] << "]";

 }

//---------------------------------------------
// contents
 template <typename X>
   X* CDAL<X>:: contents()
   {

      X* tmpArr = new X[length()];
     size_t nextele = 0;
     current = headNode;
     size_t count = 0;
     while(true)
     {
       for (size_t i = 0; i < 50; i++)
       {
           tmpArr[nextele] = current->data[i];
           nextele++;
           count++;
           if (count == tail) return tmpArr;
       }
       if (current->next != NULL) current = current->next;
       else break;
     }
     return tmpArr;

   }
 //-------------------------------
 //Destructor
 template <typename X>
   CDAL<X>::~CDAL()
    {
    //  clear();
    }

//===========================================
//END OF CDAL.h
}

#endif
