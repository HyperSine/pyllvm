#!/usr/bin/env python3
from __future__ import annotations

import sys
import argparse

from .generator_manager import GeneratorManager

def run(module_qualname: str, output_dir: str, **kwargs):
    gm = GeneratorManager(module_qualname, output_dir, **kwargs)
    gm.build_generators()
    gm.run_generators()

def main():
    arg_parser = argparse.ArgumentParser('python3 -m stubgen')

    arg_parser.add_argument('--log-level', type = str, default = 'INFO', help = 'Set output log level')
    arg_parser.add_argument('--indent', type = int, default = 4)
    arg_parser.add_argument('--sys-path', action = 'append', type = str, default = [])
    arg_parser.add_argument('--skip-name', action = 'append', type = str, default = [])
    arg_parser.add_argument('--output-dir', type = str, required = True, help = 'Stub files output directory')
    arg_parser.add_argument('MODULE')

    args = arg_parser.parse_args(sys.argv[1:])

    kwargs = {}
    kwargs['log_level'] = args.log_level
    kwargs['indent'] = args.indent
    if len(args.sys_path) > 0:
        kwargs['sys_paths'] = args.sys_path
    if len(args.skip_name) > 0:
        kwargs['skip_qualnames'] = set(args.skip_name)

    run(args.MODULE, args.output_dir, **kwargs)
