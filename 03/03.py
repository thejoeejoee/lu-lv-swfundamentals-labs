#!/bin/env python3.8
import collections, sys, re, operator, functools

print(
    '\n'.join(  # join to lines
        map(
            ' '.join,  # join key and count by space
            map(
                functools.partial(map, str),  # retype both members of 'item' to str => (('aa', '1'), ('ab', '3'), ...)
                collections.Counter(  # count occurrences
                    map(
                        # make them lower
                        str.lower,
                        map(
                            # get first two chars
                            operator.itemgetter(slice(0, 2)),
                            map(
                                # extract words from matched groups
                                operator.methodcaller('group', 0),
                                # ready all, split by separators and get only those with 2+ chars
                                re.compile(r'[^\s().,?!]{2,}', re.MULTILINE).finditer(sys.stdin.read())
                            )
                        )
                    )
                ).items()  # counter.items() to get (('aa', 1), ('ab', 3), ...)
            )
        )
    )
)
