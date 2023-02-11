from typing import overload
from .SMLoc import SMLoc

class SMRange:

    @overload
    def __init__(self) -> None:
        pass

    @overload
    def __init__(self, St: SMLoc, En: SMLoc) -> None:
        pass

    def isValid(self) -> bool:
        pass
