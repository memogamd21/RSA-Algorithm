// Discretemathproject.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include "Encryption.h"
#include "Encryption.cpp"
#include <sstream>

using namespace std;


int main()
{
	ifstream inputfile;
	inputfile.open("..RSAmessage.txt");


		string line;
		int counter = 0;
		vector <int> arroftexts;
		while (getline(inputfile,line))
		{
			// split text by spaces
			// in the file attached there is in each line one space
			int spaceposition;

			for(int i=0; i<line.length(); i++)
			{
				if (line[i] == ' ') {
					spaceposition = i;
				}
			}
			int firstword = stoi(line.substr(0, spaceposition));
			int secondword = stoi(line.substr(spaceposition));
			arroftexts.push_back(firstword);
			arroftexts.push_back(secondword);
		}
		inputfile.close();
		ofstream encryptedmessageee;
		encryptedmessageee.open("..Encryptedmessage.txt");

		Encryption mine;
		mine.primegeneration();
		mine.coprime(mine.m);
		mine.multiplicativeinverse(mine.a, mine.e);
		mine.encryptmessage(arroftexts);
		for (int w = 0; w < arroftexts.size(); w++) {
			stringstream ss;
			ss << mine.encryptedmessage[w];
			string newstring = ss.str();
			encryptedmessageee << newstring << "\t";
		}
		encryptedmessageee.close();

		ifstream Inputfile;
		Inputfile.open("..Encryptedmessage.txt");


		string Line;
		int Counter = 0;
		vector <int> Arroftexts;
		while (getline(Inputfile, Line))
		{
			// split text by spaces
			// in the file attached there is in each line one space
			int Spaceposition;

			for (int I = 0; I<Line.length(); I++)
			{
				if (line[I] == ' ') {
					Spaceposition = I;
				}
			}
			int Firstword = stoi(line.substr(0, Spaceposition));
			int Secondword = stoi(line.substr(Spaceposition));
			Arroftexts.push_back(Firstword);
			Arroftexts.push_back(Secondword);
		}
		Inputfile.close();
		
		Encryption Mine;
		Mine.primegeneration();
		Mine.coprime(Mine.m);
		Mine.multiplicativeinverse(Mine.a, Mine.e);
		Mine.encryptmessage(Arroftexts);

		Mine.decryptmessage(mine.encryptedmessage);

		ofstream decryptedmessageee;
		encryptedmessageee.open("..decryptedmessage.txt");

		for (int b = 0; b < mine.encryptedmessage.size(); b++) {
			stringstream sk;
			sk << mine.decryptedmessage[b];
			string newstringg = sk.str();
			encryptedmessageee << newstringg << "\t";
		}
		decryptedmessageee.close();


    return 0;
}

