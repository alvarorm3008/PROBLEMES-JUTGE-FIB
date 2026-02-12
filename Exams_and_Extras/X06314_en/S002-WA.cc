#include <iostream>
using namespace std;

void escriu_linia(char c, string s, bool b) {
	cout << s << "('" << c << "') = ";
	if (b) cout << "true" << endl;
	else cout << "false" << endl;
}

int main() {
	char in;
	cin >> in;
	if ('0' <= in and in <= '9') {
		escriu_linia(in, "letter", false);
		escriu_linia(in, "vowel", false);
		escriu_linia(in, "consonant", false);
		escriu_linia(in, "uppercase", false);
		escriu_linia(in, "lowercase", false);
		escriu_linia(in, "digit", true);
	} else if (('A' <= in and in <= 'Z') or ('a' <= in and in <= 'z'))   {
		escriu_linia(in, "letter", true);
		bool vocals_minuscules = (in == 'a') or (in == 'e') or (in == 'i') or (in == 'o') or (in == 'u');
		bool vocals_majuscules = (in == 'A') or (in == 'E') or (in == 'I') or (in == 'O') or (in == 'U');
		if (vocals_minuscules or vocals_majuscules) {
			escriu_linia(in, "vowel", true);
			escriu_linia(in, "consonant", false);
		} else {
			escriu_linia(in, "vowel", false);
			escriu_linia(in, "consonant", true);
		}

		if ('A' <= in and in <= 'Z') {
			escriu_linia(in, "uppercase", true);
			escriu_linia(in, "lowercase", false);
		} else {
			escriu_linia(in, "uppercase", false);
			escriu_linia(in, "lowercase", true);
		}
		escriu_linia(in, "digit", false);
	} else {
		escriu_linia(in, "letter", false);
		escriu_linia(in, "vowel", false);
		escriu_linia(in, "consonant", false);
		escriu_linia(in, "uppercase", false);
		escriu_linia(in, "lowercase", false);
		escriu_linia(in, "digit", false);
	}
}