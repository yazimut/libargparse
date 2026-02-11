#!/usr/bin/python3
import argparse

p = argparse.ArgumentParser()
p.add_argument(
    'a',
    nargs='+'
)
p.add_argument(
    'b',
    nargs='+'
)
print(p.parse_args())
