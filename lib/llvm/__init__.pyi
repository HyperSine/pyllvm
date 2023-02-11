from .AliasPattern import AliasPattern as AliasPattern
from .AliasPatternCond import AliasPatternCond as AliasPatternCond
from .AnonymousNameInit import AnonymousNameInit as AnonymousNameInit
from .AsmToken import AsmToken as AsmToken
from .BinOpInit import BinOpInit as BinOpInit
from .BitInit import BitInit as BitInit
from .BitRecTy import BitRecTy as BitRecTy
from .BitsInit import BitsInit as BitsInit
from .BitsRecTy import BitsRecTy as BitsRecTy
from .CondOpInit import CondOpInit as CondOpInit
from .DagInit import DagInit as DagInit
from .DagRecTy import DagRecTy as DagRecTy
from .DebugCompressionType import DebugCompressionType as DebugCompressionType
from .DefInit import DefInit as DefInit
from .EmitDwarfUnwindType import EmitDwarfUnwindType as EmitDwarfUnwindType
from .ExceptionHandling import ExceptionHandling as ExceptionHandling
from .ExistsOpInit import ExistsOpInit as ExistsOpInit
from .FieldInit import FieldInit as FieldInit
from .FoldOpInit import FoldOpInit as FoldOpInit
from .Init import Init as Init
from .IntInit import IntInit as IntInit
from .IntRecTy import IntRecTy as IntRecTy
from .IsAOpInit import IsAOpInit as IsAOpInit
from .LLVMContext import LLVMContext as LLVMContext
from .ListInit import ListInit as ListInit
from .ListRecTy import ListRecTy as ListRecTy
from .MCAsmInfo import MCAsmInfo as MCAsmInfo
from .MCAsmInfoCOFF import MCAsmInfoCOFF as MCAsmInfoCOFF
from .MCAsmInfoDarwin import MCAsmInfoDarwin as MCAsmInfoDarwin
from .MCAsmInfoELF import MCAsmInfoELF as MCAsmInfoELF
from .MCAsmInfoGNUCOFF import MCAsmInfoGNUCOFF as MCAsmInfoGNUCOFF
from .MCAsmInfoGOFF import MCAsmInfoGOFF as MCAsmInfoGOFF
from .MCAsmInfoMicrosoft import MCAsmInfoMicrosoft as MCAsmInfoMicrosoft
from .MCAsmInfoWasm import MCAsmInfoWasm as MCAsmInfoWasm
from .MCAsmInfoXCOFF import MCAsmInfoXCOFF as MCAsmInfoXCOFF
from .MCAsmMacro import MCAsmMacro as MCAsmMacro
from .MCAsmMacroParameter import MCAsmMacroParameter as MCAsmMacroParameter
from .MCAssemblerFlag import MCAssemblerFlag as MCAssemblerFlag
from .MCContext import MCContext as MCContext
from .MCDataRegionType import MCDataRegionType as MCDataRegionType
from .MCDisassembler import MCDisassembler as MCDisassembler
from .MCInst import MCInst as MCInst
from .MCInstPrinter import MCInstPrinter as MCInstPrinter
from .MCInstrAnalysis import MCInstrAnalysis as MCInstrAnalysis
from .MCInstrDesc import MCInstrDesc as MCInstrDesc
from .MCInstrInfo import MCInstrInfo as MCInstrInfo
from .MCObjectFileInfo import MCObjectFileInfo as MCObjectFileInfo
from .MCOperand import MCOperand as MCOperand
from .MCOperandInfo import MCOperandInfo as MCOperandInfo
from .MCRegister import MCRegister as MCRegister
from .MCRegisterClass import MCRegisterClass as MCRegisterClass
from .MCRegisterDesc import MCRegisterDesc as MCRegisterDesc
from .MCRegisterInfo import MCRegisterInfo as MCRegisterInfo
from .MCSection import MCSection as MCSection
from .MCSectionMachO import MCSectionMachO as MCSectionMachO
from .MCSubtargetInfo import MCSubtargetInfo as MCSubtargetInfo
from .MCSymbol import MCSymbol as MCSymbol
from .MCSymbolAttr import MCSymbolAttr as MCSymbolAttr
from .MCTargetOptions import MCTargetOptions as MCTargetOptions
from .MCVersionMinType import MCVersionMinType as MCVersionMinType
from .MemoryBuffer import MemoryBuffer as MemoryBuffer
from .Module import Module as Module
from .OpInit import OpInit as OpInit
from .PatternsForOpcode import PatternsForOpcode as PatternsForOpcode
from .RecTy import RecTy as RecTy
from .Record import Record as Record
from .RecordKeeper import RecordKeeper as RecordKeeper
from .RecordRecTy import RecordRecTy as RecordRecTy
from .RecordVal import RecordVal as RecordVal
from .SMDiagnostic import SMDiagnostic as SMDiagnostic
from .SMFixIt import SMFixIt as SMFixIt
from .SMLoc import SMLoc as SMLoc
from .SMRange import SMRange as SMRange
from .SectionKind import SectionKind as SectionKind
from .SourceMgr import SourceMgr as SourceMgr
from .StringInit import StringInit as StringInit
from .StringRecTy import StringRecTy as StringRecTy
from .Target import Target as Target
from .TargetRegistry import TargetRegistry as TargetRegistry
from .TernOpInit import TernOpInit as TernOpInit
from .Triple import Triple as Triple
from .TypedInit import TypedInit as TypedInit
from .UnOpInit import UnOpInit as UnOpInit
from .UnsetInit import UnsetInit as UnsetInit
from .VarBitInit import VarBitInit as VarBitInit
from .VarDefInit import VarDefInit as VarDefInit
from .VarInit import VarInit as VarInit
from .VarListElementInit import VarListElementInit as VarListElementInit

def InitializeAllAsmParsers() -> None:
    pass

def InitializeAllAsmPrinters() -> None:
    pass

def InitializeAllDisassemblers() -> None:
    pass

def InitializeAllTargetInfos() -> None:
    pass

def InitializeAllTargetMCAs() -> None:
    pass

def InitializeAllTargetMCs() -> None:
    pass

def InitializeAllTargets() -> None:
    pass

def InitializeNativeTarget() -> bool:
    pass

def InitializeNativeTargetAsmParser() -> bool:
    pass

def InitializeNativeTargetAsmPrinter() -> bool:
    pass

def InitializeNativeTargetDisassembler() -> bool:
    pass

def TableGenParseFile(InputSrcMgr: SourceMgr, Records: RecordKeeper) -> bool:
    pass
