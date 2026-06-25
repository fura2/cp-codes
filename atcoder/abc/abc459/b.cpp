#include "template/template.hpp"

int main() {
  int n = input();
  string o;
  rep (i, n) {
    string s = input();
    if (s[0] <= 'c')
      o += "2";
    else if (s[0] <= 'f')
      o += "3";
    else if (s[0] <= 'i')
      o += "4";
    else if (s[0] <= 'l')
      o += "5";
    else if (s[0] <= 'o')
      o += "6";
    else if (s[0] <= 's')
      o += "7";
    else if (s[0] <= 'v')
      o += "8";
    else if (s[0] <= 'z')
      o += "9";
  }
  output(o);
  return 0;
}
