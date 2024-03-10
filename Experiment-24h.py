import subprocess
import time

def run_bash_script():
    try:
        # Change the path to the actual location of your bash script
        subprocess.run(["./run_me.sh"], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running the bash script: {e}")

def main():
    # Run the bash script initially
    run_bash_script()

    # Run the bash script every hour for 24 hours
    for _ in range(24):
        time.sleep(3600)  # Sleep for 1 hour (3600 seconds)
        run_bash_script()

if __name__ == "__main__":
    main()
