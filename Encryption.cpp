#include "stdafx.h"
#include "Encryption.h"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


void Encryption::primegeneration() {
	for (int i = 2; i<100000; i++)
	{
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime){
			primenumbers.push_back(i);
	}
}
     p = primenumbers[primenumbers.size()-1];
     q = primenumbers[primenumbers.size()-2];
	 n = p*q;
	 m = (p - 1) * (q - 1);
}

void Encryption::coprime(int m) {
	for (int l = 2; l < 100000; l++) {
		if (gcd(l, m) == 1) {
			coprimes.push_back(l);
		}
	}
	 e = coprimes[0];
}

int Encryption::gcd(int x, int y) {
	int max = x;
	if (x < y) {
		max = y;
	}
	if (max == x) {
		if (y == 0) {
			return x;
		}
		else {
			return gcd(y, x%y);
		}
	}else if (max == y) {
		if (x == 0) {
			return y;
		}
		else {
			return gcd(x, y%x);
		}
	}
	}

void Encryption::multiplicativeinverse(int k, int r)
{
	r = m;
	k = e;
	k = k%r;
	vector <int> mulinverse;
	for (int x = 1; x < r; x++) {
		if ((x*k) % r == 1){
			mulinverse.push_back(x);
		}
	}
	a = mulinverse[0];
}

void Encryption::encryptmessage(vector <int> O) {
	int h;
	for (int j = 0; j < O.size(); j++) {
		h = (int)pow((double)O[j], (double)e) %  n;
		encryptedmessage.push_back(h);
	}
}

void Encryption::decryptmessage(vector <int> A) {
	int w;
	for (int f = 0; f < A.size(); f++) {
		w = (int)pow((double)A[f], (double)a) % n;
		decryptedmessage.push_back(w);
	}
}
