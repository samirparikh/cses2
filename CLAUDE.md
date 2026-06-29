# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

Solutions to the [CSES Problem Set](https://cses.fi/problemset/) written in C as a learning exercise. Every CSES problem reads from **stdin** and writes to **stdout**, so solutions never open files — they use `scanf`/`getchar` and `printf`.

## The `./cses` harness

All builds and tests go through `./cses`, a bash script that compiles via `gcc` inside a [toolbox](https://containertoolbx.org/) container. Do not invoke `gcc` directly — the project assumes the toolbox path. Compiled binaries land at `<problem_dir>/.<name>.bin` (gitignored).

```bash
./cses test <path>             # compile + run all tests/*.in for one problem
./cses test                    # run every problem in the repo
./cses run <path>              # compile + run interactively (stdin from keyboard)
./cses new "Category" "Name"   # scaffold new problem (slugifies names)
```

`<path>` can be either the problem directory or its `.c` file.

Environment overrides: `TOOLBOX` (default `gcc`), `CC` (default `gcc`), `CFLAGS` (default `-O2 -std=c99 -Wall -Wextra` in the script, though the README documents `-std=c17` — the script's `c99` is the actual default).

## Repository layout

```
<category_slug>/<problem_slug>/
    <problem_slug>.c       # solution (exactly one .c file per problem)
    tests/N.in  tests/N.out # matching test case pairs
```

Categories mirror CSES sections (`introductory_problems/`, `sorting_and_searching/`, etc.). The harness discovers problems by finding `.c` files at depth 2–3 from the repo root.

## Test case conventions

- Tests are pairs of files: `tests/N.in` (input piped to stdin) and `tests/N.out` (expected stdout).
- Output comparison normalizes trailing whitespace and trailing blank lines (CSES grades token-by-token), so don't worry about a stray trailing newline.
- Sample inputs from the problem statement go in as `1.in`/`1.out`. Full official cases come from the "Tests" `.zip` on the CSES task page.
- A `.in` without a matching `.out` is reported as SKIP, not failure.

## Writing solutions

- Start from `template.c` or use `./cses new` (which generates a similar starter).
- The first comment line should be the problem name and CSES task URL.
- `main` reads stdin, prints to stdout, returns 0. No file I/O.
- Inputs can be large (e.g. `repetitions.c` allocates a 1M-byte buffer for the string). Size buffers for CSES's stated constraints.
