cmake_minimum_required(VERSION 3.18)
project(pyllvm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(PYLLVM_OPT_STATIC_CXXRT "Link with static C/C++ runtime library" OFF)
option(PYLLVM_OPT_STATIC_LLVM "Link with static LLVM" OFF)

#find_package(Boost REQUIRED)
find_package(pybind11 REQUIRED)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

if (PYLLVM_OPT_STATIC_LLVM)
    set(PYLLVM_LLVM_CONFIG_LINKOPT "--link-static")
else()
    set(PYLLVM_LLVM_CONFIG_LINKOPT "--link-shared")
endif()
execute_process(
    COMMAND "${LLVM_TOOLS_BINARY_DIR}/llvm-config" ${PYLLVM_LLVM_CONFIG_LINKOPT} --system-libs
    OUTPUT_VARIABLE llvm_system_libraries OUTPUT_STRIP_TRAILING_WHITESPACE
    COMMAND_ERROR_IS_FATAL ANY
)
execute_process(
    COMMAND "${LLVM_TOOLS_BINARY_DIR}/llvm-config" ${PYLLVM_LLVM_CONFIG_LINKOPT} --libs all
    OUTPUT_VARIABLE llvm_libraries OUTPUT_STRIP_TRAILING_WHITESPACE
    COMMAND_ERROR_IS_FATAL ANY
)

pybind11_add_module(
    pyllvm
        src/macro.hpp
        src/py.hpp
        src/init.hpp
        src/init.cpp
        src/CxxWrapper.hpp
        src/CxxWrapper.cpp

        src/llvm/ADT/ArrayRef.hpp
        src/llvm/ADT/Optional.hpp
        src/llvm/ADT/StringRef.hpp
        src/llvm/ADT/Triple.cpp

        src/llvm/IR/LLVMContext.cpp
        src/llvm/IR/Module.cpp

        src/llvm/MC/MCDisassembler/MCDisassembler.cpp
        src/llvm/MC/SectionKind.cpp
        src/llvm/MC/TargetRegistry.cpp
        src/llvm/MC/MCAsmInfo.hpp
        src/llvm/MC/MCAsmInfo.cpp
        src/llvm/MC/MCAsmInfoCOFF.cpp
        src/llvm/MC/MCAsmInfoDarwin.cpp
        src/llvm/MC/MCAsmInfoELF.cpp
        src/llvm/MC/MCAsmInfoGOFF.cpp
        src/llvm/MC/MCAsmInfoWasm.cpp
        src/llvm/MC/MCAsmInfoXCOFF.cpp
        src/llvm/MC/MCAsmMacro.cpp
        src/llvm/MC/MCContext.cpp
        src/llvm/MC/MCDirectives.cpp
        src/llvm/MC/MCInst.cpp
        src/llvm/MC/MCInstPrinter.cpp
        src/llvm/MC/MCInstrAnalysis.cpp
        src/llvm/MC/MCInstrDesc.cpp
        src/llvm/MC/MCInstrInfo.cpp
        src/llvm/MC/MCObjectFileInfo.cpp
        src/llvm/MC/MCRegister.cpp
        src/llvm/MC/MCRegisterInfo.cpp
        src/llvm/MC/MCSection.cpp
        src/llvm/MC/MCSectionMachO.cpp
        src/llvm/MC/MCSubtargetInfo.cpp
        src/llvm/MC/MCSymbol.cpp
        src/llvm/MC/MCTargetOptions.cpp

        src/llvm/Support/MemoryBuffer.cpp
        src/llvm/Support/raw_py_binaryio_ostream.hpp
        src/llvm/Support/SMLoc.cpp
        src/llvm/Support/SourceMgr.cpp
        src/llvm/Support/TargetSelect.cpp

        src/llvm/TableGen/Parser.cpp
        src/llvm/TableGen/Record.cpp
)
target_include_directories(pyllvm PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_directories(pyllvm PRIVATE ${LLVM_LIBRARY_DIRS})

#target_link_libraries(pyllvm PRIVATE Boost::headers)
target_link_libraries(pyllvm PRIVATE pybind11::module)
if (PYLLVM_OPT_STATIC_CXXRT)
    target_compile_definitions(pyllvm PRIVATE _LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS)
    target_compile_definitions(pyllvm PRIVATE _LIBCXXABI_DISABLE_VISIBILITY_ANNOTATIONS)
    target_link_libraries(pyllvm PRIVATE -static-libgcc -static-libstdc++)
endif()
if (PYLLVM_OPT_STATIC_LLVM)
    target_link_libraries(pyllvm PRIVATE -Wl,-Bstatic ${llvm_system_libraries} ${llvm_libraries} LLVMTableGen -Wl,-Bdynamic)
else()
    target_link_libraries(pyllvm PRIVATE ${llvm_system_libraries} ${llvm_libraries} LLVMTableGen)
endif()

install(TARGETS pyllvm LIBRARY DESTINATION ".")
