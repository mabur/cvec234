#include <stdio.h>

#include <cvec234/matrix.h>
#include <cvec234/vector.h>

int global_assert_count = 0;
int global_assert_errors = 0;

void ASSERT_BOOL(const char* description, bool a) {
    global_assert_count++;
    if (a) {
        printf("%s ok\n", (description));
    } else {
        printf("%s bad\n", (description));
        global_assert_errors++;
    }
}

void ASSERT_EQUAL_INT(const char* description, int a, int b) {
    global_assert_count++;
    if (a == b) {
        printf("%s ok\n", (description));
    } else {
        printf("%s %i!=%i bad\n", (description), (a), (b));
        global_assert_errors++;
    }
}

#define ASSERT_NOT_EQUAL_INT(description, a, b) do { \
    global_assert_count++; \
    if (a != b) { \
        printf("%s ok\n", (description)); \
    } else { \
        printf("%s %i==%i bad\n", (description), (a), (b)); \
        global_assert_errors++; \
    } \
} while (0)

void summarize_tests() {
    if (global_assert_errors != 0) {
        printf("%d/%d test failed\n", global_assert_errors, global_assert_count);
    } else {
        printf("All %d test succeeded\n", global_assert_count);
    }
}

int main() {
    summarize_tests();
    
    return 0;
}
