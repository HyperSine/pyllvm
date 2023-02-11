from typing import TypeVar, Generic, Optional

T = TypeVar('T')

class CxxWrapper(Generic[T]):

    def __repr__(self) -> str:
        pass

    def isEmpty(self) -> bool:
        pass

    def unwrap(self) -> T:
        pass
