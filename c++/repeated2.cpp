#include<iostream>
#include<string>
using namespace std;
int main()
{
	int number_of_words = 0;
	string previous = " ";
	// previous word; initialize d to “not a word”
	string current;
	// current word
	while (cin>>current) {
	// read a stream of words
		++number_of_words;
		if (previous == current) // check if the word is the same as last
			cout << "word number " << number_of_words << " repeated word: " << current << " \n ";
		previous = current;
	}

	return (0);
}
