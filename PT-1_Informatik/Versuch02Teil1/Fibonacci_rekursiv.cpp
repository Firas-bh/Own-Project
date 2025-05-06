#include <iostream>
using namespace std;

int rekursiv(int n);

int main()
{
	int n;
	cout << "Nummer eingeben:\n";
	cin >> n;


	for (int var = 0; var <= n; var++) {

		cout << "\nRekursiv Fib " << var << ":\t" << rekursiv(var);

	}

}

int rekursiv(int n){

	if(n==0) return 0;
	if(n==1) return 1;

	return rekursiv(n-1)+rekursiv(n-2);
}
