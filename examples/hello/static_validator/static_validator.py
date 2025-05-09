import sys
import os

def main():
    if len(sys.argv) < 4:
        print(f'Correst invocation is: static_validator_program.py <language> <entry_point> <feedback_dir> [additional_arguments]')
        sys.exit(1)
    with open (sys.argv[2], 'rt') as f:
        for line in f:
            if 'print(' in line:
                print("Success!")
                print(f'line is {line}')
                sys.exit(42)
            print(f' not success but line is {line}')
    sys.exit(43)
                
if __name__ == '__main__':
    main()