#include <iostream>
#include <string>
using namespace std;

int main()
{
	char code [2][26] = {{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
							{ 'B', 'V', 'C', 'X', 'Y', 'N', 'M', 'L', 'K', 'J', 'H', 'G', 'F', 'D', 'S', 'A', 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P' }};
	//Verschlüsselung
	{
		int MAX;
		int stelle;
		string wort;
		cout<<"Geben Sie ein Wort ein: ";
		getline (cin, wort);
		MAX = wort.length();



		for(int i = 0; i < MAX ; i++)
			{
			stelle = wort[i] % 32;
			cout<< code[1][stelle-1];
			}
	}
	//Entschlüsselung
	{
		int x;
			string z;
			cout<<"\nGeben Sie ein Wort ein: ";
			cin>> z;
			x = z.length();

			for (int n= 0; n <x; n++)
			{
				for (int i=0; i<26; i++)
				{
					if(z[n] == code[1][i])
					{
						cout<<code[0][i];


					}
				}
			}
	}


	return 0;
}
