#!/usr/bin/env python3
from __future__ import annotations
from typing import Tuple, Set

import sys, os
import logging
import importlib

from .generators import ModuleStubGenerator

class GeneratorManager:

    def __init__(self, module_qualname: str, output_dir: str, **kwargs):
        self.module_path = tuple(module_qualname.split('.'))
        assert all(s.isidentifier() for s in self.module_path)

        self.output_dir = output_dir
        assert os.path.isdir(self.output_dir)

        self.indent = kwargs.get('indent', 4)
        self.skip_qualnames = kwargs.get('skip_qualnames', set())
        self.outer_classes = set()  # type: Set[Tuple[str, ...]]

        logging.basicConfig(
            level = kwargs.get('log_level', 'INFO').upper(),
            format = '[%(asctime)s] {%(filename)s:%(lineno)d} %(levelname)s - %(message)s'
        )

        for path in reversed(kwargs.get('sys_paths', [])):
            assert os.path.exists(path)
            sys.path.insert(0, os.path.abspath(path))

        self.target_module = importlib.import_module(module_qualname)

    def build_generators(self):
        self.root_stubgen = ModuleStubGenerator(self, self.target_module)

    def run_generators(self):
        self.root_stubgen.run()
