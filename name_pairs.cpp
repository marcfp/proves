#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include<std_lib_facilities.h>

using namespace std;
#define debug 1


class Name_pairs{
		vector<string> name;
		vector<double> age;
	public:
		Name_pairs(string name, double age);
		void read_names(string name);
		void read_ages(double age);
}np;




