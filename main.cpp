#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void StringMatchBF(string input, string arr[], int i, int n)
{
	n = 0;
	// jika ada string yang cocok maka n akan di increment
	for(i = 0; i <= 19; i++) {	
		if(arr[i].find(input) != string::npos) {
			n++;
		}
	}
	
	// menampilkan banyak n dan string yang cocok
	cout << "\n" << n << " Hasil ditemukan untuk string [ " << input << " ] :" << endl;
	cout << "\n\tMatch: [\n";
	for(i = 0; i <= 19; i++) {	
		if(arr[i].find(input) != string::npos && n>0) {
			cout << "\t\t Idx: " << i << " --> " << arr[i] << endl;
		}
	}
	cout << "\t       ];\n";
}

int main()
{
	string input, yesno, getData, arr[19]; // 20 data
	int i, n;
	
	// Copy data txt ke dalam array
	ifstream myFile;
	myFile.open("db.txt");
		
	if(myFile.is_open()) 
	{
		i = 0;
		while(getline(myFile, getData)) {
				
			arr[i] = getData;
			i++;
		}
	}
	myFile.close();
	
	// menu program
	while(true) {
		system("CLS");
		cout << "\t\t\t\t\tSTRING MATCH BRUTE FORCE\n";
		cout << "\nInput string yang ingin dicocokkan: ";
		cin.ignore();
		getline(cin, input);
		
		StringMatchBF(input, arr, i, n);
		
		cout << "\nUlangi lagi? (y/n) ";
		cin >> yesno;
		if(yesno == "y" || yesno == "Y") {
			continue;
		} 
		else {
			cout << "\nTerima kasih :)";
			break;
		}	
	}
	return 0;
}
