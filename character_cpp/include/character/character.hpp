#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>  // Standard library headers use <>, and commonly don't use any extensions

class Character {
   private:
    std::string name_;
    int level_;

   public:
    Character();

    // Specify MIN and MAX members as static const, to ensure
    // that they are uniform across all instances (static) and
    // that they are not changed (const).

    // It is possible to have non-static const members, that is
    // immutable members which can be unique for each instance
    // of the class. Similarly, it's possible to have static
    // members which are not immutable, meaning that they are
    // shared across all instances of a class.

    static const int MIN_LEVEL;
    static const int MAX_LEVEL;

    static const int MIN_NAME_LENGTH;
    static const int MAX_NAME_LENGTH;

    void set_level(int new_level);
    int get_level();
    void level_up();
    bool set_name(std::string new_name);
    std::string get_name();

};  // Note that the semi-colon is required for the definiton of the class

#endif  // CHARACTER_H