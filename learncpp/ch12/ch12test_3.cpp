#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <ctime>
#include <string_view>

class Monster {
  public:
  enum class Type;

  private:
  Type m_type;
  std::string m_name;
  std::string m_roar;
  int m_hits;

  public:
  enum class Type {
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    max_monster_types
  };
  Monster(Type t, std::string name, std::string roar, int hits)
      : m_type{t}, m_name{name}, m_roar{roar}, m_hits{hits} {}

  std::string getTypeString() const {
    switch (m_type) {
      case Type::dragon:
        return "dragon";
      case Type::goblin:
        return "goblin";
      case Type::ogre:
        return "ogre";
      case Type::orc:
        return "orc";
      case Type::skeleton:
        return "skeleton";
      case Type::troll:
        return "troll";
      case Type::vampire:
        return "vampire";
      case Type::zombie:
        return "zombie";
    }
    return "?";
  }
  void print() const {
    std::cout << this->m_name << " the " << (*this).getTypeString() << " has "
              << m_hits << " hit points and says *" << m_roar << "*"
              << std::endl;
  }
};

class MonsterGenerator {
  public:
  // static Monster generateMonster() {
  //   // return Monster(Monster::Type::skeleton, "Bones", "rattle",4));
  //   return Monster(Monster::Type.at(1), "Bones", "rattle", getRandomNumber(1,100));
  // }
  // ========import
  static Monster generateMonster()
	{
		auto type{ static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1)) };
		int hitPoints{ getRandomNumber(1, 100) };

		// If your compiler is not C++17 capable, use std::array<const char*, 6> instead.
		static constexpr std::array<const char*, 6> s_names{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static constexpr std::array<const char*, 6> s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};

		// Without the cast, compilers with a high warning level complain about
		// an implicit cast from a signed to an unsigned integer.
		auto name{ s_names[getRandomNumber(0, static_cast<int>(s_names.size()-1))] };
		auto roar{ s_roars[getRandomNumber(0, static_cast<int>(s_roars.size()-1))] };

		return { type, name, roar, hitPoints };
	}
  //====================
  // g) step - import this function
  // Generate a random number between min and max (inclusive)
  // Assumes srand() has already been called
  static int getRandomNumber(int min, int max) {
    static constexpr double fraction{
        1.0 / (static_cast<double>(RAND_MAX) +
               1.0)};  // static used for efficiency, so we only calculate this
                       // value once
    // evenly distribute the random number across our range
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
  }
};

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  // Monster skeleton{Monster::Type::skeleton, "Bones", "*rattle", 4};
  // skeleton.print();
  Monster m{MonsterGenerator::generateMonster()};
  m.print();
}
