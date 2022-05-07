#include "character/character.hpp"
#include "gtest/gtest.h"

namespace {

class CharacterTest : public testing::Test {
    // Use protected access modifier to make members accessible
    // sub-classes
   protected:
    // Note that 'override' keyword is specified to ensure that
    // we're overriding a method. Initially SetUp was misspelled
    // which caused the compiler to throw an error, which
    // saved debugging time.
    void SetUp() override { character = Character(); }
    // Declare members of the fixture
    Character character;
};

// Note that EXPEXT_EQ(a,b) is implemented as
// EXPECT_TRUE((a) == (b)) but with additional information output
// when the assertion fails. Because of this, EXPECT_EQ is
// preferred

// TEST has two parameters: the test case name and the test name.
// Logically related tests grouped in test cases. The naming of
// test cases should follow valid C++ identifier syntax, and
// should not include underscore.

TEST_F(CharacterTest, DefaultConstructor) {
    EXPECT_EQ(character.get_level(), Character::MIN_LEVEL);
    EXPECT_EQ(character.get_name(), "");
}

TEST_F(CharacterTest, SetLevelValid) {
    int new_level = 20;
    character.set_level(new_level);
    EXPECT_EQ(character.get_level(), new_level);
}

TEST_F(CharacterTest, SetLevelBelowMin) {
    int new_level = Character::MIN_LEVEL - 10;
    character.set_level(new_level);
    EXPECT_EQ(character.get_level(), Character::MIN_LEVEL);
}

TEST_F(CharacterTest, SetLevelAboveMax) {
    int new_level = Character::MAX_LEVEL + 10;
    character.set_level(new_level);
    EXPECT_EQ(character.get_level(), Character::MAX_LEVEL);
}

TEST_F(CharacterTest, LevelUpValid) {
    int no_level_ups = 10;
    for (int i = 0; i < no_level_ups; i++) {
        character.level_up();
    }
    EXPECT_EQ(character.get_level(), Character::MIN_LEVEL + no_level_ups);
}

TEST_F(CharacterTest, LevelUpAboveMax) {
    int no_level_ups = Character::MAX_LEVEL + 10;
    for (int i = 0; i < no_level_ups; i++) {
        character.level_up();
    }
    EXPECT_EQ(character.get_level(), Character::MAX_LEVEL);
}

TEST_F(CharacterTest, SetNameValid) {
    // Arrange
    std::string new_name = "";
    for (int i = 0; i < Character::MIN_LEVEL; i++) {
        new_name.append("a");
    }

    // Act
    character.set_name(new_name);

    // Assert
    EXPECT_EQ(character.get_name(), new_name);
}

TEST_F(CharacterTest, SetNameInvalid) {
    // Arrange
    std::string original_name = character.get_name();
    std::string new_name = "";
    for (int i = 0; i < Character::MAX_NAME_LENGTH + 1; i++) {
        new_name.append("a");
    }

    // Act
    character.set_name(new_name);

    // Assert
    EXPECT_EQ(character.get_name(), original_name);
}

}  // Namespace