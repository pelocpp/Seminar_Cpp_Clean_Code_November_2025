
#include <vector>
#include <list>
#include <print>

#include <cstdint>

// alignment // padding
class Person
{
    std::string m_first;
    std::string m_last;
    int         m_age;
};

static void stl_00()
{
    std::vector<std::uint8_t> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
}

static void stl_01()
{
    std::vector<int> numbers;

    // Die capacity kann man beeinflussen
    numbers.reserve(80);   // Performanz  // unnötige Reallokationen

    for (int i = 0; i != 100; ++i) {
        numbers.push_back(2 * i);
        std::println("Size: {:03} - {:3}", numbers.size(), numbers.capacity());
    }

    // mehr Daten werden es nicht !!!

    numbers.shrink_to_fit();
    std::println("Size: {:03} - {:3}", numbers.size(), numbers.capacity());

}


static void stl_02()
{
    std::vector<int> numbers;
    //std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // Typ eines Iterators
    std::vector<int>::iterator pos = numbers.begin();

    if (pos == numbers.end()) {
        std::println("Done.");
    }

    // ist perfekt
    int value = *pos;

    // Für die Puristen // Clean Code
    std::vector<int>::value_type value2 = *pos;

    std::println("{}", value);

    ++pos;
    if (pos == numbers.end()) {
        std::println("Done.");
    }
    value = *pos;
    std::println("{}", value);

    ++pos;
    if (pos == numbers.end()) {
        std::println("Done.");
    }
    value = *pos;
    std::println("{}", value);

    ++pos;
    if (pos == numbers.end()) {
        std::println("Done.");
        return;
    }
    value = *pos;
    std::println("{}", value);

    // We can do absolutely better ..... clean
}



void stl()
{
    stl_02();
}
