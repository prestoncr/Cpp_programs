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

    for (int i = 0; i < 256; i++)
    {
      if(characters[i] != 0)
      {
        System.out.println((char)(i) + " freq: " + characters[i]);
      }
    }

    theSorter(characters);

  }
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
}
}
