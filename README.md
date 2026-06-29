# CSES Problem Set — solutions in C

My solutions to the [CSES Problem Set](https://cses.fi/problemset/), written in C
as a way to learn the language. Organized by problem category, with a tiny test
harness so I can focus on algorithms instead of plumbing.

## Why this is simple

Every CSES problem reads its input from **stdin** and writes the answer to
**stdout**. So a "test" is just:

> compile the program, feed it an input file, compare its output to the expected
> output file.

That means **you never write code to open or parse files** — you read input with
`scanf`/`getchar` and print with `printf`. The `./cses` script does the rest.

## Layout

```
cses/
├── cses                      # the build & test harness (run ./cses)
├── template.c                # starter file for new problems
├── introductory_problems/
│   └── weird_algorithm/
│       ├── weird_algorithm.c # the solution
│       └── tests/
│           ├── 1.in  1.out   # test case 1 (input / expected output)
│           ├── 2.in  2.out
│           └── 3.in  3.out
└── sorting_and_searching/
    └── ...
```

Each problem is one folder with one `.c` file and a `tests/` folder. Test cases
are matching pairs: `N.in` (input) and `N.out` (expected output).

## Usage

The compiler comes from a Nix `devShell` defined in `flake.nix`. Enter it with
`nix develop`, or — if you have [direnv](https://direnv.net/) — just `cd` into
the repo and the `.envrc` (`use flake`) loads `gcc` onto your `PATH`
automatically. The first `direnv allow` may take a moment while Nix fetches the
shell; later entries are instant.

```bash
# Test one problem (point at the folder or the .c file)
./cses test introductory_problems/weird_algorithm

# Test EVERY problem in the repo
./cses test

# Compile and run a problem, typing input by hand (Ctrl-D to end)
./cses run introductory_problems/weird_algorithm

# Scaffold a new problem: makes the folder, a starter .c, and tests/
./cses new "Sorting and Searching" "Distinct Numbers"
```

Example output:

```
weird_algorithm
  PASS  case 1
  PASS  case 2
  PASS  case 3
  3 passed, 0 failed
```

On a failure it prints the input, the expected output, and what your program
actually produced.

## Adding and testing a new solution

The full workflow, from an empty folder to a passing solution:

1. **Scaffold the problem.** Pass the CSES category and problem name. This
   creates the folder, a starter `.c` file, and an empty `tests/` directory:

   ```bash
   ./cses new "Sorting and Searching" "Distinct Numbers"
   # created sorting_and_searching/distinct_numbers/distinct_numbers.c
   ```

   Names are slugified, so `"Sorting and Searching"` becomes
   `sorting_and_searching/` and `"Distinct Numbers"` becomes
   `distinct_numbers/`.

2. **Write your solution.** Open the generated `.c` file and fill in `main()`.
   Read input from **stdin** with `scanf`/`getchar` and print the answer to
   **stdout** with `printf` — no file handling. (`template.c` shows the common
   read patterns.)

   ```bash
   $EDITOR sorting_and_searching/distinct_numbers/distinct_numbers.c
   ```

3. **Add test cases.** Put matching `N.in` / `N.out` pairs in the problem's
   `tests/` folder. The quickest start is to copy the example from the problem
   statement: paste its sample input into `tests/1.in` and the expected output
   into `tests/1.out`. (For the full official cases, see the next section.)

   ```
   sorting_and_searching/distinct_numbers/tests/
   ├── 1.in
   └── 1.out
   ```

4. **Test it.** Point `./cses test` at the problem folder (or its `.c` file).
   It compiles your solution and runs it against every case in `tests/`:

   ```bash
   ./cses test sorting_and_searching/distinct_numbers
   ```

   Iterate on steps 2–4 until every case passes. To check your work against the
   whole repo at once, run `./cses test` with no path.

## Adding the official CSES test files

Some problems on CSES have a **"Tests"** download (a `.zip`) on the task page.
Unzip it and copy the cases into the problem's `tests/` folder, naming them
`1.in` / `1.out`, `2.in` / `2.out`, and so on. Then run `./cses test <problem>`.

You can also just hand-write a couple of small `.in`/`.out` cases from the
problem statement's examples, which is what the Weird Algorithm folder does.

## Config (optional)

`./cses` honors these environment variables:

| Variable  | Default                      | Purpose                          |
|-----------|------------------------------|----------------------------------|
| `CC`      | `gcc`                        | compiler                         |
| `CFLAGS`  | `-O2 -std=c99 -Wall -Wextra` | compiler flags                   |

For example, to see more warnings: `CFLAGS="-O2 -std=c17 -Wall -Wextra -Wpedantic" ./cses test`.
