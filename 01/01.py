#!/bin/env python3.8
import sys, re, operator

open(sys.argv[2], 'w').write(
    '\n'.join(
        filter(
            lambda s: s == s[::-1],
            map(
                operator.methodcaller('group', 0),
                re.compile(r'[^\s().,?!]+', re.MULTILINE).finditer(open(sys.argv[1], 'r').read())
            )
        )
    ) + '\n'
)