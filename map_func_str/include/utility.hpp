#ifndef __UTILITY_H__
#define __UTILITY_H__

/* @brief
 * Макрос на текущее время
 */
#define GET_NOW_TIME std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()

/* @brief
 * Форматированный вывод
 */

template <typename... args>
static void print_msg(const char* format, const args&... arguments) {
  std::cout << (boost::format(format) % ... % arguments) << '\n';
}

template <typename... args>
static void print_msg(COLOR_CONSOLE clr, const char* format, const args&... arguments) {
  std::cout << "\033[" << clr << ";1m" << (boost::format(format) % ... % arguments) << "\033[0m\n";
}

/* @brief
 * Макросы принтов
 */
#define IS_STOUT_TERMINAL isatty(fileno(stdout))
#define LOG_MSG(...) print_msg(__VA_ARGS__)
#define LOG_GREEN(...)           \
  if (IS_STOUT_TERMINAL)         \
    LOG_MSG(GREEN, __VA_ARGS__); \
  else                           \
    LOG_MSG(__VA_ARGS__)

#define LOG_YELLOW(...)         \
  if (IS_STOUT_TERMINAL)        \
    LOG_MSG(BROW, __VA_ARGS__); \
  else                          \
    LOG_MSG(__VA_ARGS__)

#define LOG_RED(...)           \
  if (IS_STOUT_TERMINAL)       \
    LOG_MSG(RED, __VA_ARGS__); \
  else                         \
    LOG_MSG(__VA_ARGS__)

#define LOG_BLUE(...)           \
  if (IS_STOUT_TERMINAL)        \
    LOG_MSG(BLUE, __VA_ARGS__); \
  else                          \
    LOG_MSG(__VA_ARGS__)

#define LOG_PURPLE(...)            \
  if (IS_STOUT_TERMINAL)           \
    LOG_MSG(MAGENTA, __VA_ARGS__); \
  else                             \
    LOG_MSG(__VA_ARGS__)

/* @brief
 * Макрос на конкатенацию c-строк
 */
#define STR_CONCAT(STR1, STR2) STR1 STR2

#endif  // __UTILITY_H__