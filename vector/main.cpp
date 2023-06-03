#include "include/includes.hpp"

bool get_opt(const std::string& in, const std::string& key, std::vector<std::string>& out) {
  std::stringstream iss{in};
  std::string tmp{};
  while (std::getline(iss, tmp))
    out.push_back(std::move(tmp));
  for (auto& i : out)
    std::cout << i << '\n';
}

int main(int argc, char* argv[]) {
  LOG_GREEN("%s", "введи число");

  std::string line{"struct = item0 time item1 item2 item3"};
  std::string tmp{};

  if (line.find("struct") != std::string::npos) {
    tmp.resize(line.size());
    sscanf(line.c_str(), "struct = %s", tmp.data());
    std::cout << tmp << '\n';
  }

  int n = 10;
  std::vector<int> x;
  auto sum = 0;
  std::cin >> n;
  for (size_t i = 1; i < 4; i++) {
    x.push_back(i);
  }
  // auto sum = std::accumulate(x.begin(), x.end(), 0);
  for (size_t i = 0; i < x.size(); i++) {
    sum = sum + x.at(i);
  }
  if (sum == n) {
    std::vector<int> x2;
    // for (size_t i = 1; i < 11; i++) {
    //   x2.push_back(1);
    //   printf("%d\n", x2.back());
    // }
    for (size_t i = 1; i < 11; i++) {
      x2.push_back(1);
    }
    for (size_t i = 0; i < x2.size(); i++) {
      printf("%d\n", x2.at(i));
    }
  } else {
    std::vector<int> x3;
    auto sum1 = 0;
    for (size_t i = 1; i < 52; i++) {
      x3.push_back(i + 49);
    }
    for (size_t i = 0; i < x3.size(); i++) {
      sum1 = sum1 + x3.at(i);
    }
    printf("%d\n", sum1 - 66);
  }
  return 0;
}
