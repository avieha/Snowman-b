#include <iostream>
#include <stdexcept>
#include <string>
#include "snowman.hpp"
#include <array>
using namespace std;

const int ZERO=0;
const int ONE=1;
const int TWO=2;
const int THREE=3;
const int FOUR=4;
const int FIVE=5;
const int SIX=6;
const int SEVEN=7;
const int EIGHT=8;
const int NINE=9;

array<array<string,FOUR>,EIGHT> forms = {{{"_===_", " ___ \n.....", " _ \n/_\\", " ___ \n(_*_)"},
 {",", ".", "_", " "},
 {".", "o", "O", "-"},
 {".", "o", "O", "-"},
 {"<", "\\", "/", " "},
 {">", "/", "\\", " "},
 {" : ", "] [", "> <", "   "},
 {" : ", "\" \"", "___", "   "}}};

namespace ariel
{
  bool check_dig(string num){
    for (size_t i = 0; i < num.length(); i++)
    {
      if (num.at(i)-'0'>4 || num.at(i)-'0'<1)
      {
        return false;
      }
    }
    return true;
  }

  string left_hand_first(string num){
    if (forms[FOUR][num.at(FOUR)-'0'-ONE]=="\\")
    {
      return "\\";
    }
    return "";
  }

  string right_hand_first(string num){
    if (forms[FIVE][num.at(FIVE)-'0'-ONE]=="/")
    {
      return "/";
    }
    return "";
  }

  string left_hand_second(string num){
    string l_hand = forms[FOUR][num.at(FOUR)-'0'-ONE];
    if (l_hand=="/")
    {
      return "/";
    }
    if (l_hand=="<")
    {
      return "<";
    }
    return "";
  }

  string right_hand_second(string num){
    string r_hand = forms[FIVE][num.at(FIVE)-'0'-ONE];
    if (r_hand=="\\")
    {
      return "\\";
    }
    if (r_hand==">")
    {
      return ">";
    }
    return "";
  }

  string snowman(int x)
  {
    string num = to_string(x);
    if (num.length()!=EIGHT)
    {
      throw "the number's length is not correct!";
    }
    if (!check_dig(num))
    {
      throw "one or more digits is not correct!";
    }
    string s = forms[ZERO][num.at(ZERO)-'0'-ONE]+"\n"+left_hand_first(num)+"("+forms[TWO][num.at(TWO)-'0'-ONE]
    +forms[ONE][num.at(ONE)-'0'-ONE]+forms[THREE][num.at(THREE)-'0'-ONE]+")"+right_hand_first(num)+"\n"+left_hand_second(num)
    +"("+forms[SIX][num.at(SIX)-'0'-1]+")"+right_hand_second(num)+"\n"+"("+forms[SEVEN][num.at(SEVEN)-'0'-ONE]+")";
    return s;
  }
}