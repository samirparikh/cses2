# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

Solutions to the [CSES Problem Set](https://cses.fi/problemset/) written in C as a learning exercise. Every CSES problem reads from **stdin** and writes to **stdout**, so solutions never open files — they use `scanf`/`getchar` and `printf`.

## The `./cses` harness

All builds and tests go through `./cses`, a bash script that shells out to `gcc`. Compiled binaries land at `<problem_dir>/.<name>.bin` (gitignored).

```bash
./cses test <path>             # compile + run all tests/*.in for one problem
./cses test                    # run every problem in the repo
./cses run <path>              # compile + run interactively (stdin from keyboard)
./cses new "Category" "Name"   # scaffold new problem (slugifies names)
```

`<path>` can be either the problem directory or its `.c` file.

Environment overrides: `CC` (default `gcc`), `CFLAGS` (default `-O2 -std=c99 -Wall -Wextra`).

## NixOS dev environment

`gcc` is **not installed globally**. It's provided by the Nix `devShell` defined in `flake.nix` and pinned via `flake.lock`. There are two ways to get `gcc` onto `PATH`:

1. **`nix develop`** — enter an interactive shell with `gcc` available.
2. **direnv** — the repo's `.envrc` contains `use flake`, so `cd`-ing in auto-loads the shell (after a one-time `direnv allow`).

When running the harness from a non-interactive context where you can't rely on direnv (e.g. a Claude Code session that wasn't started inside the loaded shell), prefix commands with `nix develop --command`:

```bash
nix develop --command ./cses test introductory_problems/weird_algorithm
```

This is the safest way to invoke `./cses` from automation — if `gcc` is already on `PATH` (you're inside the shell) this is a near no-op; if not, Nix sets it up first.

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
