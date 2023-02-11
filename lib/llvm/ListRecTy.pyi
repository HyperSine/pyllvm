from .RecTy import RecTy

class ListRecTy(RecTy):

    @staticmethod
    def classof(RT: RecTy) -> bool:
        pass

    @staticmethod
    def get(RK: RecTy) -> ListRecTy:
        pass

    def getElementType(self) -> RecTy:
        pass
