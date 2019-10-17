## initialization
``` C++
std::bitset<16> foo;
std::bitset<16> bar (0xfa2);
std::bitset<16> baz (std::string("0101111001"));

std::cout << "foo: " << foo << '\n';
std::cout << "bar: " << bar << '\n';
std::cout << "baz: " << baz << '\n';
```
OUTPUT:
``` C++
foo: 0000000000000000
bar: 0000111110100010
baz: 0000000101111001
```

## operator []
The function returns the value (or a reference) to the bit at position pos.
``` C++
std::bitset<4> foo;

foo[1]=1;             // 0010
foo[2]=foo[1];        // 0110

std::cout << "foo: " << foo << '\n';
```

## Member function
1. count():
Returns the number of bits in the bitset that are set (i.e., that have a value of one).

2. size():
Returns the number of bits in the bitset.

3. test(size_t pos):
Returns whether the bit at position pos is set (i.e., whether it is one).

4. any() / none() / all():
Test if any / none/ all bit(s) is set.

5. set() / reset() / flip():
Modify bit. If no parameter provided, set/reset/flip all bits. Otherwise, only modify specified position.

6. to_string() / to_ulong() / to_ullong():
Convert to string / unsigned long / unsigned long long

## Pass bitset as parameter:
```C++
template<std::size_t N>
void foo(std::bitset<N> n)
{
    std::cout << n.size() << "\n";
}
```