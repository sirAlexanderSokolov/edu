#include "include/includes.hpp"

using TIndex = uint16_t;
using THealth = int16_t;
using TName = std::string;
using THit = uint16_t;

std::map<TName, TIndex> g_map_orc_name{};
std::map<TIndex, THealth> g_map_orc_hp{};

TIndex g_orc_id{0};

// std::map<std::string,uint16_t> g_map_orc_name{};
// std::map<uint16_t,int16_t> g_map_orc_hp{};

void add_orc();
void check_orc_name(TName& orc_name);
void hit_orc();
void give_potion();
void give_loot(int loot_lvl);
void d_print_allorcs();

int main(int argc, char* argv[]) {
  int command{0};
start:
  // clang-format off
  std::cout << "выберите команду:\n\
                    1 - добавить нового орка\n\
                    2 - ебнуть\n\
                    3 - хильнуть\n\
                    4 - дать шмотку\n\
                    0 - ливнуть\n";
  // clang-format on
  std::cin >> command;
  switch (command) {
    case 0: {
      std::cout << "пока,пес\n";
      exit(EXIT_SUCCESS);
    } break;
    case 1: {
      add_orc();
    } break;
    case 2: {
      hit_orc();
    } break;
    case 3: {
      give_potion();  // TODO хилка вводим большая маленькая хил максимум до 120 хп
    } break;
    case 4: {
      give_loot(0);  // TODO std::rand(0-50) проверка на 0-10 беспонт 45-50 - эпик
    } break;
    case 666: {
      d_print_allorcs();
    } break;
    default:
      std::cout << "ты ебанутый? цифру введи";
      break;
  }
  goto start;
  return 0;
}
void add_orc() {
  TName name;

  std::cout << "введите имя орка \n";
  std::cin >> name;

  check_orc_name(name);  // TODO check_orc_name
  ::g_map_orc_name[name] = ::g_orc_id;
  ::g_map_orc_hp[::g_orc_id] = 120;
  ::g_orc_id++;
}

void hit_orc() {
  TName name;
  THit hit;
  std::cout << "меню ввода силы въебыша\n";
  d_print_allorcs();
  std::cout << "введите кому въебать\n";
  std::cin >> name;
  if (::g_map_orc_name.count(name) != 0) {
    std::cout << "введите силу въебыша\n";
    std::cin >> hit;
    auto id = ::g_map_orc_name.at(name);
    ::g_map_orc_hp.at(id) -= hit;
    if (::g_map_orc_hp.at(id) <= 0) {
      std::cout << name << " сдох\n";
      ::g_map_orc_name.erase(name);
      ::g_map_orc_hp.erase(id);
    } else
      std::cout << "текущее хп " << name << ::g_map_orc_hp.at(id) << '\n';
  } else
    std::cout << "орк сдох уже давно\n";
}
void give_potion() {
  std::cout << "меню ввода хилки\n";
  // std::cout << "введите номер слота хилки\n";
  //  std::cin >> potion;
}
void give_loot(int loot_lvl) {
  std::cout << "экипировать шмотку уровня " << loot_lvl << "\n";
  // << "рандомная шмотка\n";
}
void d_print_allorcs() {
  for (auto& [orc_name, orc_id] : ::g_map_orc_name) {
    std::cout << "id: " << orc_id << " name: " << orc_name << " hp: \t" << ::g_map_orc_hp.at(orc_id) << "\n";
  }
}
void check_orc_name(TName& orc_name) {
  // проверка уникальности имени и замена дубля на дубль(1)
}