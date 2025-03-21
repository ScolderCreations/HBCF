#include <fstream>
#include <iostream>
#include <string>
import hbcf;

using namespace std;

int main() {
  ifstream fin("message.txt", ios::in | ios::binary);
    string data, line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            data += line + "\n";
        }
        fin.close();
    }
  GetHitbox_Vector(data.c_str());
  return 1;
}
