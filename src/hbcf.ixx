export module hbcf;
#include "string";
#include "iostream";
#include "vector";
#include <math.h>;

using namespace std;

int vtoi(vector<char> vec, int beg, int end) // vector to int
{
    int ret = 0;
    int mult = pow(10, (end - beg));

    for (int i = beg; i <= end; i++) {
        ret += (vec[i] - '0') * mult;
        mult /= 10;
    }
    return ret;
}

export vector<vector<int>> GetHitbox_Vector(string f)
{
	vector<vector<int>> collection;
    vector<int> current;
    vector<char> word;
	for (int i = 0; i < f.length(); i++ ) {
        switch (f[i]) {
        case 'R':
            current[0] = 1;
        case 'T':
            current[0] = 2;
        case ',':
            if (f[1+i] == '(') {
	            if (word.size() > 0)
	            {
		            collection.push_back(current);
	            }
	            else if ("s".find(f[1+i]) != string::npos) {
                    break;
	            } else
	            {
		            cerr << "Hitbox Collection failed";
	            }
				
            }
        default:
            break;
        }
    }
    return collection;
};
