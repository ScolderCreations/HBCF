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
	const string numerals = "-.0123456789";
	const string identifiers = "RTC"; // this is the current list of identifiers, subject to change (or be obsolete entirely given how useless it is)
	for (int i = 0; i < f.length(); i++ ) {
        switch (f[i]) {
		case ';':
			if (current.size() > 0)
	        {
		        if (word.size() > 0) {
					current.push_back(vtoi(word, word.begin(), word.end()))
					word.clear()
				}
				collection.push_back(current);
				current.clear();
	        }
			else
			{
				cerr << "Hitbox Collection failed: Unexpected semicolon"
			}
        case ',':
            if (word.size() > 0) {
				current.push_back(vtoi(word, word.begin(), word.end()));
				word.clear()
	        }
			else {
				cerr << "Hitbox Collection failed: Unexpected comma";
	    	}
			break;
        default:
            if (numerals.find(f[i]) != string::npos) {
				word.push_back(f[i]);
			} else if (identifiers.find(f[i])!= string::npos) {
				word[0] = identifiers.find(f[i]);
			}
			break;
        }
    }
    return collection;
};
