import java.util.*;

public class StringSorter
{

  public static void main(String args[])
  {
    Scanner input = new Scanner(System.in);

    System.out.println("Please input a string");
    String content = input.nextLine();

    int characters[] = new int[256];
    for (int i = 0; i < 256; i++) characters[i] = 0;

    for (int i = 0; i < content.length(); i++)
    {
        characters[(int)(content.charAt(i))]++;
    }

    int userChoice = 0;
    while (userChoice != 4)
    {
        System.out.println("\n\nPlease select the option you would like to see\n");
        System.out.println("1. Display character frequencys alphabetically");
        System.out.println("2. Display sorted frequencys");
        System.out.println("3. Show types of character frequencys");
        System.out.println("4. Exit");
        while(true)
        {
          try
          {
            userChoice = input.nextInt();
            break;
          }
          catch (Exception e)
          {
            System.out.println("Error, bad input, please enter a number 1-4\n");
            input.nextLine();
          }
        }
        if(userChoice == 1)
        {
          printAlphabetically(characters);
        }

        if(userChoice == 2)
        {
          int[] tempArray = new int[characters.length];
          System.arraycopy(characters, 0, tempArray, 0, characters.length);
          theSorter(tempArray);
        }

        if(userChoice == 3)
        {
          charTypes(characters);
        }
    }

    System.out.println("\nCharacter Sorter Exited Successfully\n\n");

  }// end of Main

public static void printAlphabetically(int[] characterArr)
{
  for (int i = 0; i < 256; i++)
  {
    if(characterArr[i] != 0)
    {
      System.out.println((char)(i) + " freq: " + characterArr[i]);
    }
  }
} // end of printAlphabetically

  public static void theSorter(int [] originalArray)
  {
    int temp = 0;
    int place = 0;
    char tmpChar;
    int newFreqArray[] = new int[256];
    char newCharArray[] = new char[256];
    for (int i = 0; i < 256; i++)
    {
      newFreqArray[i] = 0;
      newCharArray[i] = '\0';
    }
  for (int j = 0; j<256; j++)
  {
    temp = 0;
    tmpChar = '\0';
    for (int i = 0; i < 256; i++)
    {
      if (originalArray[i] > temp)
      {

        temp = originalArray[i];
        tmpChar = (char)(i);
        place = i;
      }
    }
      newFreqArray[j] = temp;
      newCharArray[j] = tmpChar;
      originalArray[place] = 0;

    }

  System.out.println("The sorted by frequency characters are: \n");
  for (int i = 0; i < 256; i++)
  {
   if(newFreqArray[i] != 0)
    {
      System.out.println(newCharArray[i] + " freq: " + newFreqArray[i]);
    }
  }

}//end of theSorter

public static void charTypes(int [] originalArray)
{
int numericals = 0;
int punctuals = 0;
int textuals = 0;
int whiteSpaces = 0;
char temp;

for (int i = 0; i < 256; i++)
  {
    temp = (char)(i);
    if (Character.isLetter(temp)) textuals += originalArray[i];
    else if (Character.isDigit(temp)) numericals += originalArray[i];
    else if (Character.isWhitespace(temp)) whiteSpaces += originalArray[i];
    else punctuals+= originalArray[i];
  }

System.out.println("Textual Character count: " + textuals);
System.out.println("Numerical Character count: " + numericals);
System.out.println("WhiteSpace Character count: " + whiteSpaces);
System.out.println("Punctual/Other Character count: " + punctuals);


} // end of charTypes



}// end of Class StringSorter
