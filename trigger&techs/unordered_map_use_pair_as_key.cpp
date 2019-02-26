
1. unordered_map是hashmap，而map则不是。
2. unordered_map采用hash函数，查找效率为O(1)
3. map采用红黑树结构，查找效率为O(logn)
4. map可以直接采用pair作为键值，因为map只需要比较函数，而unordered_map不行，因为他需要hash函数

以下是将pair作为unordered_map键值的方式：

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

class abc {
  std::unordered_map<std::pair<int,int>, int, pairhash> rules;
};