//Vic Cipher cpp File
#include "dcoltrans.h"
#include "regcoltrans.h"
#include "Checker.h"
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>

int main()
{
std:: cout << "********************************************\n";
std:: cout << "********************************************\n";
std:: cout << "*** WELCOME TO THE VIC CIPHER SIMULATOR ****\n";
std:: cout << "********************************************\n";
std:: cout << "********************************************\n\n";
std:: cout << "********************************************\n";
std:: cout << "Enter 1 for encryption\n";
std:: cout << "********************************************\n";
std:: cout << "Enter 2 for decryption\n";
std:: cout << "********************************************\n";

int option;
std:: cin >> option;


if (option == 1)
{
std:: cout << "Enter message to encrypt\n";
std:: string message_content;
std:: cin.ignore(256, '\n');
std:: getline(std:: cin, message_content);
message_content.erase(remove_if(message_content.begin(), message_content.end(), isspace), message_content.end());
std::transform(message_content.begin(), message_content.end(), message_content.begin(), ::tolower);
std:: cout << "Enter your 2 digit Agent ID seperated by a space\n";
int agent1, agent2;
std:: cin >> agent1;
std:: cin >> agent2;
std:: cout << "Enter the date key (i.e. July 4, 1776 ==> 741776)\n";
std:: string date_key;
std:: cin >> date_key;
std:: cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
std:: cout << "********************************************\n";
std:: cout << "****** STRADDLING CHECKERBOARD CIPHER ******\n";
std:: cout << "********************************************\n\n";

Checker board(agent1, agent2, "estoniar", "");
board.printBoard();
std:: string intermediate1 = board.encrypt(message_content);
std:: cout << "\nIntermediate Result: " << intermediate1 << std:: endl;

std:: cout << "\n\n********************************************\n";
std:: cout << "****** COLUMNAR TRANSPOSITION CIPHER *******\n";
std:: cout << "********************************************\n\n";

regcoltrans transposition1(date_key, intermediate1, true, false, true, 5);
std:: string intermediate2 = transposition1.return_result();
std:: cout << "\nIntermediate Result: " << intermediate2 << std:: endl;

std:: cout << "\n********************************************\n";
std:: cout << "***** DISRUPTED COLUMNAR TRANSPOSITION *****\n";
std:: cout << "********************************************\n\n";

dcoltrans transposition2(date_key, intermediate2, true, false, true, 5);
std:: string encryption_result = transposition2.return_result();
std:: cout << "\nFinal Encryption Result: ";
for (int i = 0; i < encryption_result.length(); i++)
{
  std:: cout << encryption_result[i];
  if (i % 5 == 0 && i != 0) std:: cout << " ";
  if (i% 80 == 0 && i != 0) std:: cout << std::endl;
}


}


if (option == 2)
{
  std:: cout << "Enter message to decrypt\n";
  std:: string message_content;
  std:: cin.ignore(256, '\n');
std:: getline(std:: cin, message_content);
message_content.erase(remove_if(message_content.begin(), message_content.end(), isspace), message_content.end());
std::transform(message_content.begin(), message_content.end(), message_content.begin(), ::tolower);
  std:: cout << "Enter your 2 digit Agent ID seperated by a space\n";
  int agent1, agent2;
  std:: cin >> agent1;
  std:: cin >> agent2;
  std:: cout << "Enter the date key (i.e. July 4, 1776 ==> 741776)\n";
  std:: string date_key;
  std:: cin >> date_key;
  std:: cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  std:: cout << "\n********************************************\n";
  std:: cout << "***** DISRUPTED COLUMNAR TRANSPOSITION *****\n";
  std:: cout << "********************************************\n\n";
  dcoltrans transposition2(date_key, message_content, false, true, true, 5);
  std:: string intermediate1 = transposition2.return_result();
  std:: cout << "\nIntermediate Result: " << intermediate1 << std:: endl;

  std:: cout << "\n\n********************************************\n";
  std:: cout << "****** COLUMNAR TRANSPOSITION CIPHER *******\n";
  std:: cout << "********************************************\n\n";

  regcoltrans transposition1(date_key, intermediate1, false, true, true, 5);
  std:: string intermediate2 = transposition1.return_result();
  std:: cout << "\nIntermediate Result: " << intermediate2 << std:: endl;

  std:: cout << "\n\n********************************************\n";
  std:: cout << "****** STRADDLING CHECKERBOARD CIPHER ******\n";
  std:: cout << "********************************************\n\n";

  Checker board(agent1, agent2, "estoniar", "");
  board.printBoard();
  std:: string  encryption_result = board.decrypt(intermediate2);
  std:: cout << "\nFinal Encryption Result: " << encryption_result << std:: endl;



}




}
