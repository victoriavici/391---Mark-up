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

			if (riadok.at(i) == '\\'  ) {
				
				if (hviezda) {
					if (i + 1 < riadok.size()) {
						i++;
						char znak = riadok.at(i);
						switch (znak) {
						case '*':
							hviezda = false;
							break;
						case 'b':
							break;
						case 'i':
							break;
						case 's':
							if (i < riadok.size() - 1) {
								while ((riadok.at(i + 1) == '.' || (riadok.at(i + 1) >= 48 && riadok.at(i + 1) <= 58)) && i < riadok.size() - 1) {
									i++;
								}
							}
							break;
						default:
							pom += znak;
							break;
						}
					}
				}
				else {
					if (riadok.size() >i+1 && riadok.at(i+1) == '*') {
						hviezda = true;
						i++;
					}
					else {
						pom+= riadok.at(i);
					}
				}
			}
			else {
				if(riadok.at(i) == '\\'&& hviezda) {
				}
				else {
					pom += riadok.at(i);
				}
			}
		}
		
		cout << pom << endl;
	}

	return 0;
}