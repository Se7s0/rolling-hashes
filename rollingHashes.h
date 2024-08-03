#pragma once

class rollingHash {

public:
	// Constructor args are base and prime(mod)
	rollingHash(int, int);

	void append(char);
	void skip(char);
	int getHash();
	int multiplicativeInverse(int, int); //returns the multiplicative inverse of a mod m

private:
	int base;
	int iBase; //multiplicative inverse of base mod prime
	int prime;
	int hash;
	int magic; //the precomputed value of base^(length-1) % prime

	//int wordLength; //dont need wordLength, we will call append L times
};
