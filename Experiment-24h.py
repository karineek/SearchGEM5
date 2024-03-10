import subprocess
import sys

def run_bash_script(script_number):
    script_filename = f"./run_AFL_loop_v{script_number}.sh"
    try:
        subprocess.run([script_filename], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running the bash script {script_filename}: {e}")

def main():
    # Check if the script is called with the correct number of parameters
    if len(sys.argv) != 2:
        print("Usage: python script.py <script_number>")
        sys.exit(1)

    # Get the script number from the command line argument
    script_number = int(sys.argv[1])

    # Check if the script number is within the valid range (1 to 8)
    if 1 <= script_number <= 8:
        # Run the bash script
        run_bash_script(script_number)
    else:
        print("Script number should be between 1 and 8 inclusive.")

if __name__ == "__main__":
    main()
