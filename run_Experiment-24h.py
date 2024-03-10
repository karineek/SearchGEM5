import subprocess
import sys

def run_bash_script(script_number, param1, param2, param3, param4):
    script_filename = f"./run_AFL_loop_v{script_number}.sh"
    try:
        subprocess.run([script_filename, param1, param2, param3, param4, 0], check=True)  # RUN AFL
        while True:
            subprocess.run([script_filename, param1, param2, param3, param4, 1], check=True) # Resume if not stopped
    except subprocess.CalledProcessError as e:
        print(f"Error running the bash script {script_filename}: {e}")

def main():
    # Check if the script is called with the correct number of parameters
    if len(sys.argv) != 6:
        print("Usage: python script.py <script_number> <param1> <param2> <param3> <param4> <param5>")
        sys.exit(1)

    # Get the script number and parameters from the command line arguments
    script_number = int(sys.argv[1])
    param1 = sys.argv[2]
    param2 = sys.argv[3]
    param3 = sys.argv[4]
    param4 = sys.argv[5]

    # Check if the script number is within the valid range (1 to 8)
    if 1 <= script_number <= 8:
        # Run the bash script with additional parameters
        run_bash_script(script_number, param1, param2, param3, param4)
        # TODO: stop after 24 hours.
    else:
        print("Script number should be between 1 and 8 inclusive.")

if __name__ == "__main__":
    main()
