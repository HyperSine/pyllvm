from .MCSection import MCSection

class MCSectionMachO(MCSection):

    @staticmethod
    def classof(S: MCSection) -> bool:
        pass

    def getSegmentName(self) -> str:
        pass

    def getStubSize(self) -> int:
        pass

    def getTypeAndAttributes(self) -> int:
        pass

    def hasAttribute(self, Value: int) -> bool:
        pass

    def isVirtualSection(self) -> bool:
        pass

    def useCodeAlign(self) -> bool:
        pass
