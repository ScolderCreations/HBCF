import hbcf
import <fstream>
import <iostream>
import <vector>
using namespace std;

int main() {
  ifstream in("FileReadExample.cpp");
  string example((istreambuf_iterator<char>(in)), 
    istreambuf_iterator<char>());
  cout << GetHitbox_Vector(example.c_str())
}
