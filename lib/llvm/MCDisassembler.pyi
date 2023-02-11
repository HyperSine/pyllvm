from typing import Any, BinaryIO, ByteString, ClassVar, Tuple, overload
from .MCContext import MCContext
from .MCInst import MCInst
from .MCSubtargetInfo import MCSubtargetInfo

class MCDisassembler:

    class DecodeStatus:

        Fail: ClassVar[MCDisassembler.DecodeStatus]
        SoftFail: ClassVar[MCDisassembler.DecodeStatus]
        Success: ClassVar[MCDisassembler.DecodeStatus]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MCDisassembler.DecodeStatus) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    def getContext(self) -> MCContext:
        pass

    @overload
    def getInstruction(self, Inst: MCInst, Bytes: ByteString, Address: int) -> Tuple[MCDisassembler.DecodeStatus, int]:
        pass

    @overload
    def getInstruction(self, Inst: MCInst, Bytes: ByteString, Address: int, CStream: BinaryIO) -> Tuple[MCDisassembler.DecodeStatus, int]:
        pass

    def getSubtargetInfo(self) -> MCSubtargetInfo:
        pass

    def tryAddingPcLoadReferenceComment(self, Value: int, Address: int) -> None:
        pass

    def tryAddingSymbolicOperand(self, Inst: MCInst, Value: int, Address: int, IsBranch: bool, Offset: int, OpSize: int, InstSize: int) -> bool:
        pass
