#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool isSplitterSuggestion(const char& ch) {
	return ch == '.' || ch == '?' || ch == '!' || ch == ')' || ch == '(' || ch == '\n' || ch == '\0';
}

std::string task(const string& s) {
	std::string ans = "";
	bool isSuggestion = false;
	int startSuggestoin = 0;
	int countSugesstion = 0;
	int number = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isSplitterSuggestion(s[i])) {
			ans.append(s.substr(startSuggestoin, i + 1 - startSuggestoin));
			startSuggestoin = i + 1;
			countSugesstion++;
			if (countSugesstion == 3)
				break;
		}
		
	}
	if (countSugesstion == 3) {
		string tmpA;
		int endSuggestoin = ans.size() - 1;
		for (int i = ans.size() - 2; i >= 0; i--) {
				if (isSplitterSuggestion(ans[i])) {
					tmpA.append(ans.substr(i + 1, endSuggestoin - i));
					endSuggestoin = i;
				}
				if (i == 0)
					tmpA.append(ans.substr(0, endSuggestoin + 1));
		}
		ans = tmpA;
	}
	else
		ans.clear();

	return !ans.empty() ? ans : "В файле нет 3х предложенимй\n";
}

string readFile(ifstream& input) {
	string s = "";
	string tmpS;
	while (getline(input, tmpS))
		s.append(tmpS).append("\n");
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "Результат работы:\n" << task(readFile(input));
	input.close();
}