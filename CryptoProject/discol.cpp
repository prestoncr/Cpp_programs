//Disrupted Columnar Transposition
//Preston programming
// EX1 Make Up
// CIS4362 Fall 17 UF Dr. Newman
#include <iostream>
#include "dcoltrans.h"

int main(int argc, char* argv[])
{
std:: string content;
while (getline(std::cin, content, '\0'));
content.erase(remove_if(content.begin(), content.end(), isspace), content.end());
bool _enc, _dec, _tab, _N, _help;
_enc = false; _dec = false; _tab = false; _N = false; _help = false;
bool all_nums = true;
bool just_once = true;
std:: string x = "";
int block_size = 5;
for (int i = 1; i < argc; i++)
{
  for (int j = 0; j < sizeof(argv[i]); j++)
  {
    if (argv[i][1] == 'e') _enc = true;
    if (argv[i][1] == 'd') _dec = true;
    if (argv[i][1] == 't') _tab = true;
    if (argv[i][1] == 'N')_N = true;
    if (argv[i][1] == 'h') _help = true;

  }
}
if (_N)
{
  for (int i = 1; i < argc; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (isdigit(argv[i][j])) x+= argv[i][j];
    }
  }
  block_size = std:: stoi(x);
}

std:: string the_key = "";
if (_enc == false && _dec == false) _enc = true;

for (int i = 0; i < argc; i++)
  {
    if (argv[i][1] == 'k') the_key = argv[i+1];
  }

if (_help)
{
std:: cout << "This program runs Disrupted Transposition\n";
std:: cout << "You must pipe in a file at the beginning for the content\n";
std:: cout << "-k <key> is needed for program to run\n";
std:: cout << "-e for encrypt, -d for decrypt, -t for intermediate table\n";
std:: cout << "-N <number> for output block\n";
std:: cout << "Including the help flag -h makes only this message happen\n";
std:: cout << "run program again to perform an action\n";
}
else
{
  dcoltrans transpositon(the_key, content, _enc, _dec, _tab, block_size);
}

return 0;
}
