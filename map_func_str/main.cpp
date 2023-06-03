#include "include/includes.hpp"
// int y2 = 10;

void chrono();
int summ(int a, int b) {
  if (a > 9) {
    b = 3;
    y2 = b;
  }
  return a + b;
}

int main(int argc, char* argv[]) {
  int x{0};
  // std::cin >> x;
  chrono();
  int y1 = 10;
  int y2 = 10;

  auto xxxx = summ(y1, y2);
  std::cout << xxxx << '\n';
  std::cout << "y1 = " << y1 << '\n';
  std::cout << "y2 = " << y2 << '\n';

  char aaaa = '1';
  std::string a1{"1111"};
  std::string a2{"2222"};
  int aa = 0;
  auto vv = a1 + a2 + std::to_string(aa);
  for (auto& i : a1)
    aa += i;

  std::vector<int> asd1{1, 2, 34, 5, 6};

  std::cout << asd1.at(2) << '\n';

  std::map<int, std::string> my_map_11111{{1, "qwe"}, {2, "sad"}, {0, "dsa"}};
  my_map_11111.insert(std::make_pair<int, std::string>(22, "10"));

  std::map<std::string, int> tt1;
  tt1["asd"] = 1;
  tt1["sad"] = 12;
  tt1["zx cz"] = 3;
  tt1["xzcdvd"] = 4;
  tt1["asd"] = 2;

  std::cout << my_map_11111.at(2) << "  dsfdsf  " << tt1["asd"] << '\n';
  return 0;
}

void chrono() {
  std::cout << "a12313sd" << '\n';
}