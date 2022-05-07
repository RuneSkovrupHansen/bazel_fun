#include <character/character.hpp>

Character::Character() {
    level_ = MIN_LEVEL;
    name_ = "";
}

// Const members must be initialized, since they are static
// this is done in the .cpp file rather than as part of
// instantiation.
const int Character::MIN_LEVEL = 1;
const int Character::MAX_LEVEL = 100;
const int Character::MIN_NAME_LENGTH = 1;
const int Character::MAX_NAME_LENGTH = 10;

void Character::set_level(int new_level) {
    if (new_level < MIN_LEVEL) {
        level_ = MIN_LEVEL;
    } else if (new_level > MAX_LEVEL) {
        level_ = MAX_LEVEL;
    } else {
        level_ = new_level;
    }
}

int Character::get_level() { return level_; }

void Character::level_up() {
    if (level_ < MAX_LEVEL) {
        level_++;
    }
}

bool Character::set_name(std::string new_name) {
    if (new_name.size() > MAX_NAME_LENGTH ||
        new_name.size() < MIN_NAME_LENGTH) {
        return false;
    }

    name_ = new_name;
    return true;
}

std::string Character::get_name() { return name_; }