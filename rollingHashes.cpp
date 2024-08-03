#include <cmath>
#include <array>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <algorithm>
#include <limits> 
#include <utility> 
#include <stdexcept>
#include <sstream>
#include "rollingHashes.h"
#include <fstream>
#include <cstring>
#include <sstream>
#include <assert.h>
#include <queue>
#include <thread>
#include <iterator>
#include <vector>        
#include <deque>         
#include <list>          
#include <array>         
#include <map>           
#include <unordered_map> 
#include <set>           
#include <unordered_set> 
#include <stack>         
#include <queue>         
#include <algorithm>     
#include <iostream>      
#include <string> 

using namespace std;

rollingHash::rollingHash(int base, int prime) {
	this->base = base; //any base supported
	this->prime = prime;
	this->hash = 0;
	this->magic = 1;
	this->iBase = multiplicativeInverse(base, prime);
}

void rollingHash::append(char c) {
	hash = (hash * base + c) % prime;
	magic = (magic * base) % prime;

	cout << "hash: " << hash << endl;
}

void rollingHash::skip(char c) {
	magic = (magic * iBase) % prime;
	hash = (hash - c * magic + prime * base) % prime;
	//magic = (magic * iBase) % prime;
	
}

int rollingHash::getHash() {
	return hash;
}

int rollingHash::multiplicativeInverse(int a, int m) {
	int m0 = m, t, q;
	int x0 = 0, x1 = 1;

	if (m == 1)
		return 0;

	// Apply extended Euclid Algorithm
	while (a > 1) {
		// q is quotient
		q = a / m;

		t = m;

		// m is remainder now, process same as euclid's algo
		m = a % m, a = t;

		t = x0;

		x0 = x1 - q * x0;

		x1 = t;
	}

	// Make x1 positive
	if (x1 < 0)
		x1 += m0;

	return x1;
}
