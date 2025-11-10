#include <stdio.h>
#include <limits.h>
#include <string.h>

// Declare your ft_printf here
int ft_printf(const char *format, ...);

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

int test_num = 0;
int passed = 0;
int failed = 0;

// Macro to make testing easier and avoid va_list issues
#define TEST(desc, format, ...) do { \
    test_num++; \
    printf("\n" YELLOW "Test %d: %s" RESET "\n", test_num, desc); \
    printf("Format: \"%s\"\n", format); \
    printf("printf:    "); \
    fflush(stdout); \
    int ret1 = printf(format, ##__VA_ARGS__); \
    printf(" [return: %d]\n", ret1); \
    printf("ft_printf: "); \
    fflush(stdout); \
    int ret2 = ft_printf(format, ##__VA_ARGS__); \
    printf(" [return: %d]\n", ret2); \
    if (ret1 == ret2) { \
        printf(GREEN "✓ PASS - Return values match\n" RESET); \
        passed++; \
    } else { \
        printf(RED "✗ FAIL - Return value mismatch (expected %d, got %d)\n" RESET, ret1, ret2); \
        failed++; \
    } \
} while(0)

int main(void) {
    printf("=== FT_PRINTF HEAVY TEST SUITE ===\n");
    
    // ========== %c TESTS ==========
    printf("\n========== CHARACTER (%%c) TESTS ==========\n");
    TEST("Single char", "%c", 'A');
    TEST("Null character", "%c", '\0');
    TEST("Multiple chars", "%c%c%c", 'a', 'b', 'c');
    TEST("Char with text", "Hello %c World", '!');
    TEST("Special chars", "%c%c%c%c", '\n', '\t', '\r', ' ');
    TEST("ASCII boundary", "%c%c", 0, 127);
    TEST("Extended ASCII", "%c", 255);
    TEST("Negative char", "%c", -1);
    
    // ========== %s TESTS ==========
    printf("\n========== STRING (%%s) TESTS ==========\n");
    TEST("Simple string", "%s", "Hello");
    TEST("Empty string", "%s", "");
    TEST("NULL string", "%s", NULL);
    TEST("Multiple strings", "%s %s %s", "one", "two", "three");
    TEST("Long string", "%s", "This is a very long string to test buffer handling and memory management");
    TEST("String with special chars", "%s", "Hello\nWorld\tTab");
    TEST("Mixed format", "Start %s Middle %s End", "AAA", "BBB");
    TEST("Only special chars", "%s", "\n\t\r\v\f");
    TEST("String with spaces", "%s", "   spaces   ");
    TEST("Single char string", "%s", "X");
    
    // ========== %d and %i TESTS ==========
    printf("\n========== INTEGER (%%d/%%i) TESTS ==========\n");
    TEST("Zero", "%d", 0);
    TEST("Positive number", "%d", 42);
    TEST("Negative number", "%d", -42);
    TEST("INT_MAX", "%d", INT_MAX);
    TEST("INT_MIN", "%d", INT_MIN);
    TEST("Multiple integers", "%d %d %d", 1, 2, 3);
    TEST("Negative zero", "%d", -0);
    TEST("Large positive", "%d", 999999999);
    TEST("Large negative", "%d", -999999999);
    TEST("%i format", "%i", 42);
    TEST("%i negative", "%i", -42);
    TEST("Mixed %d and %i", "%d %i %d", -100, 0, 100);
    TEST("Single digit", "%d", 5);
    TEST("Two digits", "%d", 99);
    
    // ========== %u TESTS ==========
    printf("\n========== UNSIGNED (%%u) TESTS ==========\n");
    TEST("Zero unsigned", "%u", 0);
    TEST("Small unsigned", "%u", 42);
    TEST("UINT_MAX", "%u", UINT_MAX);
    TEST("Negative as unsigned", "%u", -1);
    TEST("Multiple unsigned", "%u %u %u", 0, 100, UINT_MAX);
    TEST("INT_MIN as unsigned", "%u", INT_MIN);
    TEST("Large unsigned", "%u", 3000000000U);
    
    // ========== %x TESTS ==========
    printf("\n========== HEX LOWERCASE (%%x) TESTS ==========\n");
    TEST("Zero hex", "%x", 0);
    TEST("Small hex", "%x", 42);
    TEST("Large hex", "%x", 255);
    TEST("UINT_MAX hex", "%x", UINT_MAX);
    TEST("Negative as hex", "%x", -1);
    TEST("Multiple hex", "%x %x %x", 10, 255, 4096);
    TEST("Powers of 16", "%x %x %x", 16, 256, 4096);
    TEST("Single digit hex", "%x", 15);
    TEST("Large number hex", "%x", 0xDEADBEEF);
    
    // ========== %X TESTS ==========
    printf("\n========== HEX UPPERCASE (%%X) TESTS ==========\n");
    TEST("Zero HEX", "%X", 0);
    TEST("Small HEX", "%X", 42);
    TEST("Large HEX", "%X", 255);
    TEST("UINT_MAX HEX", "%X", UINT_MAX);
    TEST("Mixed case test", "%x %X", 255, 255);
    TEST("Multiple HEX", "%X %X %X", 10, 255, 4096);
    TEST("Large number HEX", "%X", 0xDEADBEEF);
    
    // ========== %p TESTS ==========
    printf("\n========== POINTER (%%p) TESTS ==========\n");
    int var = 42;
    char str[] = "test";
    TEST("Valid pointer", "%p", &var);
    TEST("NULL pointer", "%p", NULL);
    TEST("Multiple pointers", "%p %p", &var, &test_num);
    TEST("Pointer with text", "Address: %p", &var);
    TEST("Zero pointer value", "%p", (void *)0);
    TEST("String pointer", "%p", str);
    TEST("Max pointer", "%p", (void *)-1);
    
    // ========== %% TESTS ==========
    printf("\n========== PERCENT (%%%%) TESTS ==========\n");
    TEST("Single percent", "%%");
    TEST("Multiple percent", "%%%%");
    TEST("Percent with text", "100%% complete");
    TEST("Mixed percent", "%%d %%s %%c");
    TEST("Triple percent", "%%%%%%");
    
    // ========== MIXED FORMAT TESTS ==========
    printf("\n========== MIXED FORMAT TESTS ==========\n");
    TEST("All formats", "%c %s %d %i %u %x %X %p %%", 'A', "test", 42, -42, 100, 255, 255, &var);
    TEST("Complex mix", "Char: %c, String: %s, Int: %d", 'X', "Hello", -123);
    TEST("Repeated formats", "%d %d %d %d %d", 1, 2, 3, 4, 5);
    TEST("No format specifiers", "Just plain text");
    TEST("Empty format", "");
    TEST("All specifiers once", "%c%s%d%i%u%x%X%p%%", 'Z', "A", 1, 2, 3, 4, 5, &var);
    
    // ========== EDGE CASES ==========
    printf("\n========== EDGE CASES ==========\n");
    TEST("Only format specifiers", "%d%d%d", 1, 2, 3);
    TEST("Trailing text", "%d done", 42);
    TEST("Leading text", "Result: %d", 42);
    TEST("Format at boundaries", "A%cB%sC%dD", 'X', "Y", 99);
    TEST("Consecutive specifiers", "%s%s%s", "A", "B", "C");
    TEST("Long mixed format", 
        "Test: %s, Num: %d, Hex: %x, Char: %c, Ptr: %p, Percent: %%",
        "string", -42, 255, '!', &var);
    TEST("Format in middle", "start %d middle %s end", 100, "text");
    TEST("Many spaces", "%d    %s    %c", 1, "test", 'x');
    
    // ========== BOUNDARY TESTS ==========
    printf("\n========== BOUNDARY TESTS ==========\n");
    TEST("All zeros", "%d %u %x %X", 0, 0, 0, 0);
    TEST("All max values", "%d %u %x %X", INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
    TEST("All min values", "%d", INT_MIN);
    TEST("Alternating pos/neg", "%d %d %d %d", 1, -1, 100, -100);
    TEST("Boundary signed", "%d %d", INT_MAX, INT_MIN);
    TEST("Boundary unsigned", "%u %u", 0, UINT_MAX);
    
    // ========== STRESS TESTS ==========
    printf("\n========== STRESS TESTS ==========\n");
    char long_str[500];
    memset(long_str, 'A', 499);
    long_str[499] = '\0';
    TEST("Very long string", "%s", long_str);
    
    TEST("Many arguments", 
        "%d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    
    TEST("Complex nesting",
        "a%cb%sc%dd%ie%uf%xg%Xh%pi%%j",
        '1', "2", 3, 4, 5, 6, 7, &var);
    
    TEST("Very long format string",
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    
    // ========== SPECIAL COMBINATIONS ==========
    printf("\n========== SPECIAL COMBINATIONS ==========\n");
    TEST("Null and empty", "%s %s %s", NULL, "", "text");
    TEST("Zero in all formats", "%d %i %u %x %X", 0, 0, 0, 0, 0);
    TEST("Negative in all numeric", "%d %i", -42, -42);
    TEST("Same value different formats", "%d %u %x %X", 255, 255, 255, 255);
    TEST("Mix null and values", "%s %d %s", NULL, 42, "test");
    TEST("Consecutive NULL", "%s%s%s", NULL, NULL, NULL);
    
    // ========== TRICKY CASES ==========
    printf("\n========== TRICKY CASES ==========\n");
    TEST("Percent before format", "%%before %d", 42);
    TEST("Percent after format", "%d after%%", 42);
    TEST("Only percents", "%%%%%%%%");
    TEST("Null with other formats", "%s and %d and %c", NULL, 0, 'A');
    TEST("Negative zero variations", "%d %i %u", 0, -0, 0);
    TEST("Hex of zero", "%x %X", 0, 0);
    TEST("Pointer variations", "%p %p %p", NULL, (void*)0, (void*)1);
    
    // ========== WIDTH EDGE CASES (if you implement width) ==========
    printf("\n========== ADDITIONAL INTEGER TESTS ==========\n");
    TEST("Max and min together", "%d %d %d", INT_MIN, 0, INT_MAX);
    TEST("Unsigned boundaries", "%u %u %u", 0, INT_MAX, UINT_MAX);
    TEST("Hex boundaries", "%x %X", 0, UINT_MAX);
    TEST("All negative", "%d %d %d", -1, -100, -1000);
    TEST("All positive", "%d %d %d", 1, 100, 1000);
    
    // ========== FINAL RESULTS ==========
    printf("\n" YELLOW "================================" RESET "\n");
    printf("Total tests: %d\n", test_num);
    printf(GREEN "Passed: %d\n" RESET, passed);
    printf(RED "Failed: %d\n" RESET, failed);
    printf("Pass rate: %.1f%%\n", (passed * 100.0) / test_num);
    
    if (failed == 0)
        printf(GREEN "\n🎉 ALL TESTS PASSED! 🎉\n" RESET);
    else
        printf(RED "\n⚠️  SOME TESTS FAILED ⚠️\n" RESET);
    
    printf("\nNote: Visual comparison is also important!\n");
    printf("Check that the actual output matches between printf and ft_printf.\n");
    
    return (failed > 0);
}
