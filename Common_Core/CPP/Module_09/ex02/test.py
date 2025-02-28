import subprocess

def run_test(input_str):
    try:
        result = subprocess.run(['./PmergeMe', input_str], capture_output=True, text=True)
        print("="*40)
        print(f"Input: {input_str}")
        print("-"*40)
        print("Output:")
        print(result.stdout.strip())
        if result.stderr:
            print("Errors:")
            print(result.stderr.strip())
        print("="*40)
    except Exception as e:
        print(f"An error occurred: {e}")

def main():
    test_inputs = [
        "8 9 10 11 12 13 14 15 1 2 3 4 5 6 7",
        "1 2 3",
        "-1",
        "",
        "100 7 42 45",
        "100 7 42 45 100",
        "1 1 1 1"
        "39 59 69 58 72 84 72 77 48 58 76 61 69 16 19 10 79 62 25 6 96 10 52 73 61 32 31 5 60 95 90 44 99 7 29 24 71 72 43 93 34 66 23 4 54 59 24 100 5 38"
    ]

    for input_str in test_inputs:
        run_test(input_str)

if __name__ == "__main__":
    main()