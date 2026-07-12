#include <stdio.h>

#define MAX_LINES 100

int shortest_line_index(int lines[], int num_lines) {
    int shortest_index = 0;
    for (int i = 1; i < num_lines; i++)
        if (lines[i] < lines[shortest_index])
            shortest_index = i;
    return shortest_index;
}

void solve(int lines[], int num_lines, int num_people) {
    int shortest_index;
    for (int i = 0; i < num_people; i++) {
        shortest_index = shortest_line_index(lines, num_lines);
        printf("%d\n", lines[shortest_index]);
        lines[shortest_index]++;
    }
}

int main(void) {

    int lines[MAX_LINES];
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
        if (scanf("%d", &lines[i]) != 1 ) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    solve(lines, n, m);
    return 0;
}
