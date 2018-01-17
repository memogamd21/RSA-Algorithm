#ifndef Encryption_H
#define Encryption_H
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class Encryption
{
public:
	int p, q, n, m, e, a;
	void primegeneration();
	vector <int> primenumbers;
	vector <int> coprimes;
	void coprime(int m);
	int gcd(int x, int y);
	void multiplicativeinverse(int k, int r);
	void encryptmessage(vector <int> O);
	void decryptmessage(vector <int> A);
	vector <int> encryptedmessage;
	vector <int> decryptedmessage;
};





#endif //
