#include <fstream>
#include <iostream>
#include <vector>
import hbcf

using namespace std;

int main() {
  ifstream in("example/example.txt");
  string example((istreambuf_iterator<char>(in)), 
    istreambuf_iterator<char>());
  cout << GetHitbox_Vector(example.c_str());
  return 1;
}
