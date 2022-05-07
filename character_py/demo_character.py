from character import Character

def main():

    #Example of manually testing set_level() funcitonality

    character = Character()

    character.set_level(-1)
    print(f"set_level(-1), chracter.level: {character.level}")
    # set_level(-1), chracter.level: 1

    character.set_level(150)
    print(f"set_level(150), chracter.level: {character.level}")
    # set_level(150), chracter.level: 100

if __name__ == "__main__":
    main()