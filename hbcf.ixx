module;
#include <vector>

using namespace std;
const string numerals = "-.0123456789";

int vctoi(vector<char> vec) // vector to int
{
	string s(vec.begin(), vec.end());
	return atoi(s.c_str());
}
// converts to vector of vectors of doubles (vector of objects with int data)
export void get_hitbox_vector(string f, vector<vector<double>> *collection) { // input file data
	collection->clear();
	vector<double> current;
	vector<char> word;
	for (int i = 0; i < f.length(); i++) {
		switch (f[i]) {
		case ';':
			if (current.size() > 0)
			{
				if (word.size() > 0) {
					current.push_back(static_cast<double>(vctoi(word)));
					word.clear();
				}
				collection->push_back(current);
				current.clear();
			} else {
				throw "Hitbox Collection failed: Unexpected semicolon";
			}
			break;
		case ',':
			if (word.size() > 0) {
				current.push_back(static_cast<double>(vctoi(word)));
				word.clear();
			} else {
				throw "Hitbox Collection failed: Unexpected comma";
			}
			break;
		default:
			word.push_back(f[i]);
			break;
		}
	}
};

export string get_hitbox_text(vector<vector<int>> v) {
	string f;
	for (int i = 0; i < v.size(); i++) {
		for (int n = 0; n < v[i].size(); n++) {
			if (n == 0) {
				f.append(to_string(v[i][n]));
			} else {
				f.append(", " + to_string(v[i][n]));
			}
		}
		f.append(" ; ");
	}
	return f;
}
