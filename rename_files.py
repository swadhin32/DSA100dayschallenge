#!/usr/bin/env python3
import os
import re
from pathlib import Path


def make_new_name(filename: str) -> str:
    base, ext = os.path.splitext(filename)
    # Keep the first underscore in the base name, convert all subsequent
    # underscores to hyphens. Preserve existing hyphens.
    first_us = base.find('_')
    if first_us == -1:
        return base + ext
    # Build new base char-by-char
    chars = []
    for i, ch in enumerate(base):
        if ch == '_':
            if i == first_us:
                chars.append('_')
            else:
                chars.append('-')
        else:
            chars.append(ch)
    new_base = ''.join(chars)
    # Collapse any accidental multiple hyphens into single ones
    new_base = re.sub(r'-{2,}', '-', new_base)
    return new_base + ext


def main(root: str):
    root = Path(root)
    renamed = 0
    for p in root.rglob('*'):
        if p.is_file():
            new_name = make_new_name(p.name)
            if new_name != p.name:
                target = p.with_name(new_name)
                if target.exists():
                    print(f"Skipping {p.relative_to(root)} -> {target.relative_to(root)} (target exists)")
                else:
                    print(f"Renaming: {p.relative_to(root)} -> {target.relative_to(root)}")
                    p.rename(target)
                    renamed += 1
    print(f"Done. {renamed} files renamed.")


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(description='Rename files: replace underscores with hyphens.')
    parser.add_argument('root', nargs='?', default='.', help='Root directory to scan (default: current directory)')
    args = parser.parse_args()
    main(args.root)
