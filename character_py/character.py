class Character:

    _MIN_LEVEL = 1
    _MAX_LEVEL = 100

    _MIN_NAME_LENGTH = 1
    _MAX_NAME_LENGTH = 10

    def __init__(self) -> None:
        self.name = ""
        self.level = self._MIN_LEVEL

    def set_level(self, new_level) -> None:

        if new_level < self._MIN_LEVEL:
            self.level = self._MIN_LEVEL

        elif new_level > self._MAX_LEVEL:
            self.level = self._MAX_LEVEL

        else:
            self.level = new_level

    def level_up(self) -> None:

        if self.level < self._MAX_LEVEL:
            self.level += 1

    def set_name(self, new_name) -> bool:

        if len(new_name) < self._MIN_NAME_LENGTH or len(new_name) > self._MAX_NAME_LENGTH:
            return False 

        self.name = new_name
        return True

