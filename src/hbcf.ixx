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
	const string numerals = "-.0123456789"
	for (int i = 0; i < f.length(); i++ ) {
        switch (f[i]) {
        case 'R':
            current[0] = 1;
			break;
        case 'T':
            current[0] = 2;
			break;
        case ',':
            if (f[i-1] == ')') {
	            if (current.size() > 0)
	            {
		            collection.push_back(current);
	            }
			}
	        else if (numerals.find(f[i-1]) != string::npos) {
                current.push_back(vtoi(word, 0, word.size()));
	        }
			else {
				cerr << "Hitbox Collection failed";
	    	}
			break;
        default:
            if (numerals.find(f[i]) != string::npos) {
				word.push_back(f[i]);
			}
			break;
        }
    }
    return collection;
};
