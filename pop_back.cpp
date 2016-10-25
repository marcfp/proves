#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }

  std::cout << "The elements of myvector add up to " << sum << '\n';
  std::cout << "myvector.size() = " << myvector.size() ;
  for(int i=0; i<myvector.size(); ++i)
	std::cout << myvector[i] << i ;
  return 0;
}

	

