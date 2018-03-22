#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void skip_to_int()
{
	if (cin.fail()) {
		// we found some thing that wasn’t an inte ge r
		cin.clear();
		// we ’d like to look at the characte rs
		for (char ch; cin>>ch; ) {
			// throw away non-digits
			if (isdigit(ch) || ch=='-') {
				cin.unget();
				// put the digit back,
				// so that we can re ad the numbe r
				return;
			}
		}
	}
	//error("no input");
	cout << "error, no input!!! " << endl;
//	return(0);
// e of or bad: give up
}

int get_int()
{
	int n = 0;
	cout << "Please enter an integer :" << endl;
	while (true) {
		if (cin >> n) return n;
		cout << "Sorry, that was not a number; please try a gain\n";
		skip_to_int();
	}
}

int get_int(int low, int high)
{
	cout << "Please enter an integer in the range " << low << " to " << high << " (inclusive):\n";
	while (true) {
		int n = get_int();
		if (low<=n && n<=high) return n;
		cout << "Sorry " << n << " is not in the [" << low << ':' << high << "] range; please try again\n";
	}
}

int main()
{
int p =get_int();
int n = get_int(1,10);
cout << "n: " << n << '\n';
int m = get_int(2,300);
cout << "m: " << m << '\n';

	return(0);
}
