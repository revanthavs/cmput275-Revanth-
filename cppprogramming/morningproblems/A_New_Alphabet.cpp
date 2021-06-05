#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<char, string> new_alphabets;
	new_alphabets['A'] = "@"; new_alphabets['a'] = "@";
	new_alphabets['B'] = "8"; new_alphabets['b'] = "8";
	new_alphabets['C'] = "("; new_alphabets['c'] = "(";
	new_alphabets['D'] = "|)"; new_alphabets['d'] = "|)";
	new_alphabets['E'] = "3"; new_alphabets['e'] = "3";
	new_alphabets['F'] = "#"; new_alphabets['f'] = "#";
	new_alphabets['G'] = "6"; new_alphabets['g'] = "6";
	new_alphabets['H'] = "[-]"; new_alphabets['h'] = "[-]";
	new_alphabets['I'] = "|"; new_alphabets['i'] = "|";
	new_alphabets['J'] = "_|"; new_alphabets['j'] = "_|";
	new_alphabets['K'] = "|<"; new_alphabets['k'] = "|<";
	new_alphabets['L'] = "1"; new_alphabets['l'] = "1";
	new_alphabets['M'] = "[]\\/[]"; new_alphabets['m'] = "[]\\/[]";
	new_alphabets['N'] = "[]\\[]"; new_alphabets['n'] = "[]\\[]";
	new_alphabets['O'] = "0"; new_alphabets['o'] = "0";
	new_alphabets['P'] = "|D"; new_alphabets['p'] = "|D";
	new_alphabets['Q'] = "(,)"; new_alphabets['q'] = "(,)";
	new_alphabets['R'] = "|Z"; new_alphabets['r'] = "|Z";
	new_alphabets['S'] = "$"; new_alphabets['s'] = "$";
	new_alphabets['T'] = "']['"; new_alphabets['t'] = "']['";
	new_alphabets['U'] = "|_|"; new_alphabets['u'] = "|_|";
	new_alphabets['V'] = "\\/"; new_alphabets['v'] = "\\/";
	new_alphabets['W'] = "\\/\\/"; new_alphabets['w'] = "\\/\\/";
	new_alphabets['X'] = "}{"; new_alphabets['x'] = "}{";
	new_alphabets['Y'] = "`/"; new_alphabets['y'] = "`/";
	new_alphabets['Z'] = "2"; new_alphabets['z'] = "2";

	string input_string;
	string output_string;
	// cin >> input_string;
	getline(cin, input_string);
	for (auto chr: input_string)
		(new_alphabets.find(chr) != new_alphabets.end()) ? output_string += new_alphabets[chr] : output_string += chr;
	cout << output_string << endl;
	return 0;
}