//Vic Cipher cpp File
#include "dcoltrans.h"
#include "regcoltrans.h"
#include "Checker.h"
#include <iostream>

int main()
{

//dTrans:: dTrans board("ESTONIA", "IonceKnewaBihHisNamewasBihMcBih");
std:: string the_key, content;
bool _enc, _dec, _tab;
_enc = false; _dec = false; _tab = false;
int block_size = 5;

the_key = "4231";
content = "WothsuykewkesclonyLATItlrgHooMiAaWi";
//WothsuykewkesclonyLATItlrgHooMiAaWi
//HeyWowLookAtMeThisIsActuallyWorking
_enc = true;
_tab = true;

Checker board(3, 6, "estoniar", "dup");

board.printBoard();

std:: string boi = board.encrypt ("heywowlookatmethisisworking");
regcoltrans transposition1(the_key, content, _enc, _dec, _tab, block_size);
std:: string boi2 = transposition.return_result();




//std:: cout << "Boi : " << boi << std:: endl;
// std:: string bih = board.decrypt(boi);
// std:: cout << "Bih : " << bih << std:: endl;


}
