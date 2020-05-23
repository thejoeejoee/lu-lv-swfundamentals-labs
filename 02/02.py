#!/usr/env python3
from functools import reduce

print(
    *reduce(
        *[  # inverse order of parameters to load VALUES at first, and after that, load REMOVER
             (),  # start from empty list
             input().split(),  # load VALUES from first line
             lambda  # reduce lambda
                 acc, v,  # standard reduce params, accumulator and new value
                 _remover=input(),  # load REMOVER
                 _last_removed=type(  # state object to notify, if last item was skipped or not
                     'LastRemoved',
                     (object,),
                     dict(
                         state=False,  # was last item skipped?
                         # state changer - not None value means value has not been skipped and flag to False
                         # None value sets flag to True (last value has been skipped)
                         set=lambda self, value: (setattr(self, 'state', not bool(value)), value)[1]
                     ),
                 )()
             : (
                 (v,)  # first call return accumulated first value
                 if not acc else
                 (
                     # return only accumulator if value does not meet condition
                     (acc, _last_removed.set(None))[0]
                     # remover condition, last in acc is remover, current value is not remover
                     # and last loop did not remove value (to avoid double removes after remover)
                     if acc[-1] == _remover and v != _remover and not _last_removed.state else
                     # add value to accumulator
                     acc + (_last_removed.set(v),)
                 )
             ),
         ][::-1]  # params for reduce() order inversion
    ),
    sep=" ",
)
