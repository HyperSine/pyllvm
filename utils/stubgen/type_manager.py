#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple, Dict

import weakref
import collections

if TYPE_CHECKING:
    from .generators import StubGenerator

class TypenameTraits:

    __builtins_typenames__ = {
        'object',
        'bool',
        'int', 'float', 'complex',
        'list', 'tuple', 'set', 'dict', 'frozenset',
        'str', 'bytes', 'bytearray', 'memoryview',
        'range',
    }

    __redirect_typenames__ = {
        'buffer': 'ByteString',
        'capsule': 'Any',
        'handle': 'Any',
    }

    __typing_typenames__ = {
        'Any',
        'List', 'Tuple', 'Dict', 'Set',
        'Callable', 'Optional', 'Iterator',
        'ByteString', 'BinaryIO'
    }

    @classmethod
    def is_builtins(cls, typename: str) -> bool:
        return typename in cls.__builtins_typenames__

    @classmethod
    def is_typing(cls, typename: str):
        return typename in cls.__typing_typenames__

    @classmethod
    def redirect(cls, typename: str) -> str:
        if typename in cls.__redirect_typenames__:
            return cls.__redirect_typenames__[typename]
        else:
            return typename

class TypeManager:

    def __init__(self, current_path: Tuple[str, ...], parent_stubgen: StubGenerator):
        from .generators import ModuleStubGenerator, ClassStubGenerator

        self._current_path = current_path

        assert isinstance(parent_stubgen, (ModuleStubGenerator, ClassStubGenerator))
        self._parent_stubgen = weakref.ref(parent_stubgen)

        self._typepath_reprs = {}                           # type: Dict[Tuple[str, ...], str]
        self._from_import_map = collections.defaultdict(dict)   # type: Dict[Tuple[str, ...], Dict[str, bool]]

    def import_(self, typepath: Tuple[str, ...], is_export: bool = False):
        if len(typepath) == 1:
            s = self._import_typename(typepath[0], is_export)
        else:
            if self._current_path[0] == typepath[0]:
                s = self._import_typepath_rel(typepath, is_export)
            else:
                s = self._import_typepath_abs(typepath, is_export)

        if typepath in self._typepath_reprs:
            assert self._typepath_reprs[typepath] == s
        else:
            self._typepath_reprs[typepath] = s

    def repr_of(self, typepath: Tuple[str, ...]) -> str:
        return self._typepath_reprs[typepath]

    def make_import_strings(self):
        if ('typing',) in self._from_import_map:
            typenames_map = self._from_import_map['typing',]
            typenames_export = list(map(lambda item: item[0], filter(lambda item: item[1], typenames_map.items())))
            typenames_not_export = list(map(lambda item: item[0], filter(lambda item: not item[1], typenames_map.items())))

            if len(typenames_not_export) > 0:
                yield 'from typing import {0:}'.format(', '.join(sorted(typenames_not_export)))
            for typename in typenames_export:
                yield 'from typing import {0:} as {0:}'.format(typename)

        for frompath, typenames_map in sorted(self._from_import_map.items(), key = lambda item: item[0]):
            if frompath != ('typing',):
                typenames_export = list(map(lambda item: item[0], filter(lambda item: item[1], typenames_map.items())))
                typenames_not_export = list(map(lambda item: item[0], filter(lambda item: not item[1], typenames_map.items())))

                if len(typenames_not_export) > 0:
                    yield 'from {0:} import {1:}'.format('.'.join(frompath), ', '.join(sorted(typenames_not_export)))
                for typename in typenames_export:
                    yield 'from {0:} import {1:} as {1:}'.format('.'.join(frompath), typename)

    def _get_outer_typepath(self, typepath: Tuple[str, ...]) -> Tuple[str, ...]:
        for i in reversed(range(0, len(typepath))):
            if typepath[:i] in self._parent_stubgen().manager().outer_classes:
                return typepath[:i]
        else:
            return typepath

    def _calc_common_prefix_length(self, a: Tuple[str, ...], b: Tuple[str, ...]) -> int:
        l = min(len(a), len(b))
        for i in range(0, l):
            if a[i] != b[i]:
                return i
        else:
            return l

    def _import_typename(self, typename: str, is_export: bool) -> str:
        typename = TypenameTraits.redirect(typename)
        if TypenameTraits.is_builtins(typename):
            return typename
        elif TypenameTraits.is_typing(typename):
            self._from_import_map['typing',][typename] = is_export
            return typename
        else:
            raise NotImplementedError('todo: {}'.format(typename))

    def _import_typepath_abs(self, typepath: Tuple[str, ...], is_export: bool) -> str:
        assert len(typepath) > 1
        self._from_import_map[typepath[:-1]][typepath[-1]] = is_export
        return typepath[-1]

    def _import_typepath_rel(self, typepath: Tuple[str, ...], is_export: bool) -> str:
        assert len(typepath) > 1

        outer_typepath = self._get_outer_typepath(typepath)
        assert len(outer_typepath) > 1

        common_prefix_len = self._calc_common_prefix_length(self._current_path, outer_typepath)
        assert 1 <= common_prefix_len

        if common_prefix_len == len(self._current_path):
            assert self._current_path == typepath[:common_prefix_len]
            return '.'.join(typepath[common_prefix_len - 1:])
        else:
            assert common_prefix_len < len(self._current_path)

            back_level = len(self._current_path) - 1 - common_prefix_len
            assert back_level >= 0

            self._from_import_map[('.' * back_level,) + outer_typepath[common_prefix_len:]][outer_typepath[-1]] = is_export
            return '.'.join(typepath[len(outer_typepath) - 1:])
