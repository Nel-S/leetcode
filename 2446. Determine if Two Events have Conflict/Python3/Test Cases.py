from Solution import Solution

class TestCase:
    event1: list[str]
    event2: list[str]
    expected_output: bool

    def __init__(self, event1: list[str], event2: list[str], expected_output: bool) -> None:
        self.event1 = event1
        self.event2 = event2
        self.expected_output = expected_output


TEST_CASES: list[TestCase] = [
    TestCase(["01:15","02:00"], ["02:00","03:00"], True),
    TestCase(["01:00","02:00"], ["01:20","03:00"], True),
    TestCase(["10:00","11:00"], ["14:00","15:00"], False)
]

def main() -> None:
    for i, test_case in enumerate(TEST_CASES):
        output = Solution().haveConflict(test_case.event1, test_case.event2)
        if output == test_case.expected_output:
            print(f"Test case {i + 1} passed.", flush=True)
        else:
            print(f"!!! TEST CASE {i + 1} FAILED. !!!", flush=True)
            # Event1
            print(f"\tEvent1: {test_case.event1}", flush=True)
            # Event2
            print(f"\tEvent2: {test_case.event2}", flush=True)
            # Actual output
            print(f"\tActual output: {output}", flush=True)
            # Expected output
            print(f"\tExpected output: {test_case.expected_output}", flush=True)
            break

if __name__ == "__main__":
    main()