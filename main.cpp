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

//karp rabin prototype fucntion
int karpRabin(string s, string t);

void main() {

	//test case 1
	string s = "Hello";
	string t = "Good morning, everyone. Today, I want to share with you a story that has been "
                "close to my heart for many years. It all began when I was just a child, curious "
                "and eager to explore the world around me. One day, while walking through a "
                "bustling market, I heard a sound that caught my attention. It was a soft voice, "
                "almost like a whisper, saying. I turned around to see a kind stranger "
                "smiling at me, and that moment changed my perspective on kindness and human connection. "
                "From that day forward, I made it a point to greet Hello everyone I met with a warm smile "
                "and a friendly word. This small gesture has opened countless doors and created lasting memories. "
                "So, remember, a simple can have a profound impact on someone's life. "
				"Thank you for listening.";

	cout << karpRabin(s, t) << endl;
}

int karpRabin(string s, string t) {
	rollingHash sHash(55, 7919);
	rollingHash tHash(55, 7919);

	for (int i = 0; i < s.length(); i++) {
		sHash.append(s[i]);
	}
	for (int i = 0; i < s.length(); i++) {
		tHash.append(t[i]);
	}

	int sHashValue = sHash.getHash();
	int tHashValue = tHash.getHash();

	if (sHashValue == tHashValue) {
		return 0;
	}

	for (int i = 0; i < t.length() - s.length(); i++) {
		tHash.skip(t[i]);
		tHash.append(t[i + s.length()]);

		if (sHash.getHash() == tHash.getHash()) {
			return i + 1;
		}
	}

	return -1;
}