import java.io.IOException;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeoutException;
import java.util.Random;
import java.net.URISyntaxException;

import io.github.amithkoujalgi.ollama4j.core.OllamaAPI;
import io.github.amithkoujalgi.ollama4j.core.models.OllamaResult;
import io.github.amithkoujalgi.ollama4j.core.types.OllamaModelType;
import io.github.amithkoujalgi.ollama4j.core.utils.PromptBuilder;
import io.github.amithkoujalgi.ollama4j.core.utils.OptionsBuilder;
import io.github.amithkoujalgi.ollama4j.core.exceptions.OllamaBaseException;

class ProgramGenerator {
    private static final Random random = new Random();

    public final String[] m_compilerOpt = {
	"Scalar Optimizations", "Dead Code Elimination", "Constant Folding", "Common Subexpression Elimination",
	"Loop Optimizations", "Loop Optimizations", "Loop Fusion", "Loop-Invariant Code Motion",
 	"Memory Optimizations", "Memory-to-Register Promotion", "Sparse Conditional Constant Propagation",
	"Inlining", "Function Inlining", "Inliner Heuristics",
	"Target-Specific Optimizations", "Instruction Scheduling", "Register Allocation",
	"Interprocedural Optimizations", "Whole Program Analysis", "Function Specialization",
	"Profile-Guided Optimizations", "Profile-Guided Instrumentation", "Profile-Guided Optimization",
	"Vectorization", "Automatic Vectorization", "Loop Vectorization"
	};
    public final String[] m_compilerParts = {
	"Code Generation", "Handles code generation", "Supports execution of generated code", "Handles machine code generation",
		"Deals with object file manipulation", "Targets specific architectures",
	"Assembly and Bitcode", "Parses assembly files", "Handles LLVM bitcode",
	"Support", "Provides various utility functions",
	"Analysis", "Static analysis in Clang", "General LLVM analysis passes",
	"IR Manipulation", "Core LLVM Intermediate Representation (IR) manipulation", "Reads LLVM IR",
	"Object and Binary Format", "Deals with binary formats",
	"Passes and Transformations", "Collection of optimization passes", "Framework for LLVM transformations",
	"Frontend", "Header files for Clang frontend", "Handles Abstract Syntax Tree (AST)", "Implements Clang frontend",
	"Support Libraries",
	"Backend", "Middle-End", "Frontend", "StaticAnalyzer", "Sema", "Serialization", "Parse", "Lex", "AST"
	};
    public final String[] m_PL = {
	"Integer", "Floating-Point Numbers", "ASCII Value of a Character", "Print", "Compute Quotient and Remainder",
	"int, float, double and char", "sizeof", "Keyword long", "Swap Two Numbers", "Number is Even or Odd",
	"a Character is a Vowel or Consonant", "Largest Number Among Three Numbers", "binary operators",
	"short circuting rule", "short circuit", "Roots of a Quadratic Equation", "logic expression", "expression",
	"expression not zero", "expression positive", "expression negative", "expression negative or positive",
	"Leap Year", "a Number is Positive or Negative", "a Character is an Alphabet or not", "the Sum of Natural Numbers",
	"calculate two numbers resutl", "Factorial of a Number", "Generate Multiplication Table", "Generate",
	"Fibonacci Sequence", "GCD of two Numbers", "LCM of two Numbers", "Characters from A to Z Using Loop", "Loop", "For loop",
	"Case switch", "Count Number of Digits in an Integer", "Reverse a Number", "Calculate the Power of a Number",
	"a Number is Palindrome or Not", "Number is Prime or Not", "Prime Numbers Between Two Intervals", "Armstrong Number",
	"Armstrong Number Between Two Intervals", "Factors of a Number", "Simple Calculator Using switch...case",
	"Prime Numbers Between Intervals Using Function", "Prime or Armstrong Number Using User-defined Function", "User-defined Function",
	"Macros", "function", "foo function", "Recursion", "logical", "logic", "time in AM-PM format", "Digital Clock with the Current Time",
	"Calendar Year in Different Formats", "Dates", "Time", "Structure in C", "Structures and Sort them by Age or ID",
	"Passing Structure to a Function", "Complex numbers", "N Distances Given in inch-feet System using Structures",
	"Structures and Sort them by Name", "Students Using Structure", "Union", "int32", "Singly Linked List using Recursion",
	"List", "array", "heap", "Array of Strings", "regex", "null", "null pointer check", "check before dividing",
	"Number of Sub-Strings ", "Array Rotation ", "Two Arrays", "merge", "element in array", "min", "max", "const",
	"C Program to Sort an Array using Bubble Sort",
	"C Program to Sort an Array using Merge Sort",
	"C Program to Sort an Array Using Selection Sort",
	"C Program to Sort an Array Using Insertion Sort",
	"C Program For Boolean to String Conversion",
	"C Program For Float to String Conversion",
	"C Program For Double to String Conversion",
	"C Program For String to Long Conversion",
	"C Program For Long to String Conversion",
	"C Program For Int to Char Conversion",
	"C Program For Char to Int Conversion",
	"C Program For Octal to Decimal Conversion",
	"C Program For Decimal to Octal Conversion",
	"C Program For Hexadecimal to Decimal Conversion",
	"C Program For Decimal to Hexadecimal Conversion",
	"C Program For Decimal to Binary Conversion",
	"C Program For Binary to Decimal Conversion",
    	"C Program to Print an Integer (Entered by the User)",
    	"C Program to Add Two Integers",
    	"C Program to Multiply Two Floating-Point Numbers",
    	"C Program to Find ASCII Value of a Character",
    	"C Program to Compute Quotient and Remainder",
    	"C Program to Find the Size of int, float, double and char",
    	"C Program to Demonstrate the Working of Keyword long",
    	"C Program to Swap Two Numbers",
    	"C Program to Check Whether a Number is Even or Odd",
    	"C Program to Check Whether a Character is a Vowel or Consonant",
    	"C Program to Find the Largest Number Among Three Numbers",
    	"C Program to Find the Roots of a Quadratic Equation",
    	"C Program to Check Leap Year",
    	"C Program to Check Whether a Number is Positive or Negative",
    	"C Program to Check Whether a Character is an Alphabet or not",
    	"C Program to Calculate the Sum of Natural Numbers",
    	"C Program to Find Factorial of a Number",
    	"C Program to Generate Multiplication Table",
    	"C Program to Display Fibonacci Sequence",
    	"C Program to Find GCD of two Numbers",
    	"C Program to Find LCM of two Numbers",
    	"C Program to Display Characters from A to Z Using Loop",
    	"C Program to Count Number of Digits in an Integer",
    	"C Program to Reverse a Number",
    	"C Program to Calculate the Power of a Number",
    	"C Program to Check Whether a Number is Palindrome or Not",
    	"C Program to Check Whether a Number is Prime or Not",
    	"C Program to Display Prime Numbers Between Two Intervals",
    	"C Program to Check Armstrong Number",
    	"C Program to Display Armstrong Number Between Two Intervals",
    	"C Program to Display Factors of a Number",
    	"C Program to Make a Simple Calculator Using switch...case",
    	"C Program to Display Prime Numbers Between Intervals Using Function",
    	"C Program to Check Prime or Armstrong Number Using User-defined Function",
    	"C Program to Check Whether a Number can be Expressed as Sum of Two Prime Numbers",
    	"C Program to Find the Sum of Natural Numbers using Recursion",
    	"C Program to Find Factorial of a Number Using Recursion",
    	"C Program to Find G.C.D Using Recursion",
    	"C Program to Convert Binary Number to Decimal and vice-versa",
    	"C Program to Convert Octal Number to Decimal and vice-versa",
    	"C Program to Convert Binary Number to Octal and vice-versa",
    	"C Program to Reverse a Sentence Using Recursion",
    	"C program to calculate the power using recursion",
    	"C Program to Calculate Average Using Arrays",
    	"C Program to Find Largest Element in an Array",
    	"C Program to Calculate Standard Deviation",
    	"C Program to Add Two Matrices Using Multi-dimensional Arrays",
    	"C Program to Multiply Two Matrices Using Multi-dimensional Arrays",
    	"C Program to Find Transpose of a Matrix",
    	"C Program to Multiply two Matrices by Passing Matrix to a Function",
    	"C Program to Access Array Elements Using Pointer",
    	"C Program Swap Numbers in Cyclic Order Using Call by Reference",
    	"C Program to Find Largest Number Using Dynamic Memory Allocation",
    	"C Program to Find the Frequency of Characters in a String",
    	"C Program to Count the Number of Vowels, Consonants and so on",
    	"C Program to Remove all Characters in a String Except Alphabets",
    	"C Program to Find the Length of a String",
    	"C Program to Concatenate Two Strings",
    	"C Program to Copy String Without Using strcpy()",
    	"C Program to Sort Elements in Lexicographical Order (Dictionary Order)",
    	"C Program to Store Information of a Student Using Structure",
    	"C Program to Add Two Distances (in inch-feet system) using Structures",
    	"C Program to Add Two Complex Numbers by Passing Structure to a Function",
    	"C Program to Calculate Difference Between Two Time Periods",
    	"C Program to Store Information of Students Using Structure",
    	"C Program to Store Data in Structures Dynamically",
    	"C Program to Write a Sentence to a File",
    	"C Program to Read the First Line From a File",
    	"C Program to Display its own Source Code as Output",
    	"C Program to Print Pyramids and Patterns"
	};

    public String getRandomCompilerOpt() {
        return getRandomEntry(m_compilerOpt);
    }

    public String getRandomCompilerParts() {
        return getRandomEntry(m_compilerParts);
    }

    public String getRandomPL() {
        return getRandomEntry(m_PL);
    }

    private String getRandomEntry(String[] array) {
        // Check if the array is not empty
        if (array.length == 0) {
            return "Array is empty"; // or some appropriate value
        }

        int randomIndex = random.nextInt(array.length);
        return array[randomIndex];
    }

    public void loadModel(OllamaAPI ollamaAPI, String modelType, String prompt) {
    	try {
        	// code that might throw OllamaBaseException
                ollamaAPI.pullModel(modelType);
     	} catch (OllamaBaseException e) {
                // handle the exception
                e.printStackTrace();
        } catch (IOException | InterruptedException | URISyntaxException e) {
     		// handle the IOException
                e.printStackTrace();
        }
    }

    public String askModel(OllamaAPI ollamaAPI, String modelType, String prompt) {
        try {
                // code that might throw OllamaBaseException
                OllamaResult result =
                ollamaAPI.ask(modelType, prompt, new OptionsBuilder().build());
                //System.out.println(result.getResponse());
                return result.getResponse();
        } catch (OllamaBaseException e) {
                // handle the exception
                e.printStackTrace();
        } catch (IOException | InterruptedException e) {
                // handle the IOException
                e.printStackTrace();
        }
        return "";
    }

    public static void main(String[] args) {
        System.out.println("Hello, Starting Generating Programs!");

	// Uoload model
        String host = "http://localhost:11434/";
	OllamaAPI ollamaAPI = new OllamaAPI(host);
        ollamaAPI.setRequestTimeoutSeconds(100);
        ollamaAPI.setVerbose(true);
        boolean isOllamaServerReachable = ollamaAPI.ping();
        System.out.println("Is Ollama server alive: " + isOllamaServerReachable);

	// Model type: https://github.com/amithkoujalgi/ollama4j/blob/816bbd9bbf5550bacdfeef7252bfcdf53c8697a5/src/main/java/io/github/amithkoujalgi/ollama4j/core/types/OllamaModelType.java#L10
        String modelType = OllamaModelType.MAGICODER;

	ProgramGenerator compilerStrings = new ProgramGenerator();

    	for (int i = 0; i < 1000; i++) {
        	// Get a random entry from each array
       		String randomCompilerOpt = compilerStrings.getRandomCompilerOpt();
        	String randomCompilerParts = compilerStrings.getRandomCompilerParts();
        	String randomPL = compilerStrings.getRandomPL();

        	// Combine the random entries into a prompt string
        	String promptString = "Prompt: " + randomCompilerOpt + ", " + randomCompilerParts + ", " + randomPL;

		// program
		String prompt = "Give me a program in C with all includes. Code only please. Input taken via argv only. Please return code and example of input in the format ``` ``` and input:." +
			"The program will focus on the following: the code triggers " + randomCompilerOpt + " optimization, and covers this part of the compiler " +
			randomCompilerParts + ", and excersise this idea of syntax of C: " + randomPL;

		// PROMPT
		System.out.println(compilerStrings.askModel(ollamaAPI, modelType, prompt));

		// Input
		// Type
    	}
    }
}
