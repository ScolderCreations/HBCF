#include <fstream>
#include <iostream>
#include <string>
#include <vector>
import HBCF;

using namespace std;

int main() {
  ifstream fin("./example/example.txt", ios::in | ios::binary);
    string data, line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            data += line + "\n";
        }
        fin.close();
    }
	const vector<vector<int>> res = get_hitbox_vector(data.c_str());
    cout << res[0][1];
  return 1;
}
