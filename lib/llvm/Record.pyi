from typing import List, Optional, overload
from .BitsInit import BitsInit
from .DagInit import DagInit
from .DefInit import DefInit
from .Init import Init
from .ListInit import ListInit
from .RecordKeeper import RecordKeeper
from .RecordRecTy import RecordRecTy
from .RecordVal import RecordVal

class Record:

    def checkRecordAssertions(self) -> None:
        pass

    def checkUnusedTemplateArgs(self) -> None:
        pass

    def getDefInit(self) -> DefInit:
        pass

    def getID(self) -> int:
        pass

    def getName(self) -> str:
        pass

    def getNameInit(self) -> Init:
        pass

    def getNameInitAsString(self) -> str:
        pass

    def getRecords(self) -> RecordKeeper:
        pass

    def getTemplateArgs(self) -> List[Init]:
        pass

    def getType(self) -> RecordRecTy:
        pass

    @overload
    def getValue(self, Name: Init) -> RecordVal:
        pass

    @overload
    def getValue(self, Name: str) -> RecordVal:
        pass

    def getValueAsBitsInit(self, arg0: str) -> BitsInit:
        pass

    def getValueAsDag(self, arg0: str) -> DagInit:
        pass

    def getValueAsDef(self, arg0: str) -> Record:
        pass

    def getValueAsInt(self, arg0: str) -> int:
        pass

    def getValueAsListInit(self, arg0: str) -> ListInit:
        pass

    def getValueAsListOfDefs(self, arg0: str) -> List[Record]:
        pass

    def getValueAsListOfInts(self, arg0: str) -> List[int]:
        pass

    def getValueAsListOfStrings(self, arg0: str) -> List[str]:
        pass

    def getValueAsOptionalString(self, arg0: str) -> Optional[str]:
        pass

    def getValueAsString(self, arg0: str) -> str:
        pass

    def getValueInit(self, arg0: str) -> Init:
        pass

    def hasDirectSuperClass(self, arg0: Record) -> bool:
        pass

    def isAnonymous(self) -> bool:
        pass

    def isClass(self) -> bool:
        pass

    @overload
    def isSubClassOf(self, R: Record) -> bool:
        pass

    @overload
    def isSubClassOf(self, Name: str) -> bool:
        pass

    def isTemplateArg(self, arg0: Init) -> bool:
        pass

    def isValueUnset(self, arg0: str) -> bool:
        pass

    @overload
    def removeValue(self, Name: Init) -> None:
        pass

    @overload
    def removeValue(self, Name: str) -> None:
        pass
