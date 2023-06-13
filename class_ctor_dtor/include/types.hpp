#ifndef __TYPES_H__
#define __TYPES_H__

namespace ASxAA {
using TMessage = const char*;
using TCString = const char*;
using TString = std::string;

template <typename _Tp, std::size_t _Nm>
using TArray = std::array<_Tp, _Nm>;
template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
using TVector = std::vector<_Tp, _Alloc>;
template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<std::pair<const _Key, _Tp> > >
using TMap = std::map<_Key, _Compare, _Alloc>;

}  // namespace ASxAA
enum COLOR_CONSOLE { BLACK = 30, RED = 31, GREEN = 32, BROW = 33, BLUE = 34, MAGENTA = 35, CYAN = 36, WHITE = 37 };
#endif  // __TYPES_H__