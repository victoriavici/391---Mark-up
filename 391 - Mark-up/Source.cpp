#include <iostream>
#include <string>
using namespace std;

int main() {
	string riadok;
	bool hviezda = true;
	while (getline(cin, riadok)) {
	
		string pom;
		for (int i = 0; i < riadok.size(); i++)
		{
			if (riadok.at(i) == '\\') {
				if (i == riadok.size() - 1) {
					continue;
				}
				char znak = riadok.at(i + 1);
				if (hviezda) {
					switch (znak) {
						case '*':
							hviezda = false;
							break;
						case 'b':
							break;
						case 'i':
							break;
						case 's':
							if (i < riadok.size() - 2) {
								while ((riadok.at(i + 2) == '.' || (riadok.at(i + 2) >= 48 && riadok.at(i + 2) <= 58)) && i <riadok.size()-2) {
									i++;
								}
							}
							break;
						default:
							pom += znak;
							break;
					}
					i++;
				}
				else {
					if (znak == '*') {
						hviezda = true;
						i++;
					}
					else {
						if ((riadok.size() <= i + 2) || riadok.at(i+2) !='*') {
							pom += '\\';
							i++;
						}
						pom += znak;
					
					}
				}
			}
			else {
				pom += riadok.at(i);
			}
		}
		cout << pom << endl;
	}

	return 0;
}