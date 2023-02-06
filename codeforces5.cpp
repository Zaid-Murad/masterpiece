// I believe I was clever with this one
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main()
{


  std::unordered_map<char, int> mp;

  int counter = 0;

  int x;

  std::string w;

  for (int i = 0; i < 4; i++)
  {
    std::cin >> x;

    mp.insert(std::pair<char, int>(char((i + 1) + 48), x));
  }

  std::cin >> w;

  for (int i = 0; i < w.size(); i++)
    counter += mp.find(w[i])->second;

  std::cout << counter << std::endl;

}
