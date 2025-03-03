import subprocess

def run_test(input_str, expected_output, expect_error=False):
    try:
        result = subprocess.run(['./RPN', input_str], capture_output=True, text=True)
        output = result.stdout.strip()
        exit_code = result.returncode

        print("="*40)
        print(f"Input: {input_str}")
        print("-"*40)
        print("Output:")
        print(output)
        print("Expected Output:")
        print(expected_output)
        print("Exit Code:")
        print(exit_code)
        if expect_error:
            assert exit_code != 0, f"Test failed: {input_str} -> Expected error but got exit code {exit_code}"
        else:
            assert exit_code == 0, f"Test failed: {input_str} -> Expected success but got exit code {exit_code}"
            assert output == expected_output, f"Test failed: {input_str} -> {output} != {expected_output}"
        if result.stderr:
            print("Errors:")
            print(result.stderr.strip())
        print("="*40)
    except Exception as e:
        print(f"An error occurred: {e}")

def main():
    test_cases = [
        ("3 4 +", "7"),
        ("8 2 /", "4"),
        ("2 3 *", "6"),
        ("5 1 2 + 4 * + 3 -", "14"),
        ("9 3 /", "3"),
        ("4 2 + 3 -", "3"),
        ("2 3 4 * +", "14"),
        ("7 8 + 3 2 + /", "3"),
        ("5 9 8 + 4 6 * * 7 + *", "2075"),
        ("3 4 5 * -", "-17"),
        # Edge cases
        ("", "", True),
        ("3 4 + +", "", True),
        ("10 2 3 +", "", True),
        ("3 4 5 + - *", "", True),
        ("3 4 + 5", "", True),
        ("10 0 /", "", True),
        # Additional test cases
        ("5", "5"),
        ("3 4 + 2 * 7 /", "2"),
        ("-3 -4 +", "-7"),
        ("2.5 3.5 +", "6.0", True),  # Assuming floating point numbers are not supported
        ("3    4 +", "7"),
        ("3 4 a +", "", True),
        ("9 9 +", "18"),
        ("10 9 -", "", True),
        ("9 10 -", "", True),
        ("10 10 *", "", True),
        ("10 10 /", "", True),
        ("10 1 /", "", True),
        ("1 10 /", "", True),
        ("10 0 /", "", True),
    ]

    for test_case in test_cases:
        if len(test_case) == 2:
            run_test(test_case[0], test_case[1])
        else:
            run_test(test_case[0], test_case[1], test_case[2])

if __name__ == "__main__":
    main()