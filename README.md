# pyllvm

A Python binding for LLVM.

__STILL IN DEVELOPMENT, feel free to contribute or create a issue if you have any questions.__

## 1. Build

### 1.1 For linux users

* Make sure you have `boost`, `pybind11`, `LLVM >= 15.x.x` installed.

  In Ubuntu, you can install them with one command:
  ```shell
  $ sudo apt install libboost-all-dev python3-pybind11 llvm
  ```

To install:

```shell
$ ./setup.py install --user
```

To build wheel:

```shell
$ ./setup.py bdist_wheel
```

### 1.2 For windows users

So far only `msys2-clang64` toolchain is tested.

You can see build script and download artifacts in [Action](https://github.com/HyperSine/pyllvm/actions) page.

## 2. Example

With code `test.py`:

```py
#!/usr/bin/env python3
import typing
import sys

import pyllvm
import pyllvm.llvm as llvm

def diagnoses_handler(diag: llvm.SMDiagnostic, user_ctx: typing.Any):
    diag.print(__name__, sys.stderr.buffer)

record_keeper = llvm.RecordKeeper()
source_manager = llvm.SourceMgr()

source_manager.setDiagHandler(diagnoses_handler, None)
source_manager.setIncludeDirs([
    '<path to LLVM source dir>/include',
    '<path to LLVM source dir>/lib/Target/X86',
])

buf = llvm.MemoryBuffer.getFile("<path to LLVM source dir>/lib/Target/X86/X86.td", True)
assert not buf.isEmpty()

source_manager.AddNewSourceBuffer(buf, llvm.SMLoc())

failed = llvm.TableGenParseFile(source_manager, record_keeper)
if not failed:
    r_insts = record_keeper.getAllDerivedDefinitions("X86Inst")
    print(r_insts[0].getName())
    print(r_insts[1].getName())
    print(r_insts[2].getName())
```

Output:

```
$ ./test.py
AAA
AAD8i8
AAM8i8
```
