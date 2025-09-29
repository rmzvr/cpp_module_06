#include <string>

#include "ScalarConverter.hpp"

#ifdef DEBUG
	void run_tests() {
		std::cout << "========== Running Full Coverage Test Suite ==========\n\n";

		// Array of test cases to cover all branches
		std::string test_cases[] = {
			// 1. Character Literal Tests (Covers isCharacterLiteral: true, non-digit)
			"a",    // Printable char
			"Z",    // Uppercase printable char
			"@",    // Symbol printable char

			// Added character-like inputs
			"'a'",  // Quoted character literal (3 chars long)
			"'1'",  // Quoted digit literal (3 chars long)
			
			// 2. Integer Literal Tests (Covers isIntegerLiteral: true)
			"0",    // Zero
			"42",   // Positive
			"-42",  // Negative
			"10",   // Integer leading to a non-displayable character (newline, ASCII 10)
			"127",  // Max value for signed char
			
			// 3. Float Literal Tests (Covers isFloatLiteral: true, isDoubleLiteral: false)
			"42.0f",    // Basic float (integer value)
			"42.42f",   // Float with fractional part
			"nanf",     // Special float: Not a Number (Covers handleFloatLiteral: impossible int)
			"+inff",    // Special float: Positive infinity (Covers handleFloatLiteral: impossible int)
			"-inff",    // Special float: Negative infinity (Covers handleFloatLiteral: impossible int)
			"3.0e40f",  // Float too large for int (Covers handleFloatLiteral: impossible int)
			
			// 4. Double Literal Tests (Covers isDoubleLiteral: true)
			"42.0",     // Basic double (integer value)
			"42.42",    // Double with fractional part
			"nan",      // Special double: Not a Number (Covers handleDoubleLiteral: impossible int)
			"+inf",     // Special double: Positive infinity (Covers handleDoubleLiteral: impossible int)
			"-inf",     // Special double: Negative infinity (Covers handleDoubleLiteral: impossible int)
			"3.0e400",  // Double too large for int (Covers handleDoubleLiteral: impossible int)
			
			// 5. Unknown/Edge Cases (Covers is*Literal: false, getType: Unknown, convert: default)
			
			// isCharacterLiteral: false branches
			"",         // Empty string (length != 1)
			"ab",       // Multi-character string (length != 1)
			"5",        // Single digit (isCharacterLiteral: isdigit branch)
			
			// isIntegerLiteral: false branches
			"123a",     // Partial conversion (pos != length)
			"hello",    // Not a number (stoi exception: invalid_argument)
			"2147483648", // Int overflow (stoi exception: out_of_range)
			
			// isFloatLiteral: false branches
			"42.0",     // Missing 'f' (already covered as double, but hits isFloatLiteral: false branch)
			"42.0fa",   // Extra character after 'f' (pos + 1 != length)
			
			// isDoubleLiteral: false branch
			"123a",     // Partial conversion (already used for int test)
			"notadouble",// Not a double
			
			// Overlap/Precedence Check (Ensuring correct getType ordering)
			"5", // Should be Integer (not Character)
			"42.0f", // Should be Float (not Double)
			
			// Character conversion checks:
			// Integer input resulting in non-displayable char
			"130",      // 130 maps to a non-printable char on most systems (covers printCharacterValue: non-displayable)
			
			// Integer input resulting in displayable char
			"65"       // 65 maps to 'A' (covers printCharacterValue: displayable)
		};

		for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i) {
			std::cout << "--- TEST " << i + 1 << " (Input: " << test_cases[i] << ") ---\n";
			ScalarConverter::convert(test_cases[i]);
			std::cout << "------------------------------------------\n";
		}

		std::cout << "========== Test Suite Complete ==========\n";
	}
#endif
int main(int argc, char **argv)
{
	#ifndef DEBUG
		if (argc != 2)
		{
			std::cout << "Invalid amount of arguments." << std::endl;
			return 1;
		}
		ScalarConverter::convert(argv[1]);
	#endif

	#ifdef DEBUG
		(void) argc;
		(void) argv;

		try
		{
			run_tests();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Caught exception in main: " << e.what() << '\n';
		}
	#endif

	return 0;
}