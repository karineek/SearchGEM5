
import java.io.IOException;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeoutException;
import java.util.Random;
import java.net.URISyntaxException;
import java.util.regex.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;

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
    	"C Program to Print Pyramids and Patterns",
	"Short circuit and operator precedence", "using scalars with short-circuiting or",
	"Order of evaluation between logical and assignment operators", "a function call",
	"input include several arguments", "Checking dictionary key existence and boolean condition",
	"Short Circuit Evaluation", "Something cool!", "Anything popular in C", "recursion",
	"short circuiting operations", "conditions of short circuit", "use a value without computing it twice",
	"Ternary operator", "Ternary operator use with short circuiting operations",
	"Character sets", "Character display semantics", "limits of integers",
	"Types", "while", "For and While loops", "size_t", "Complex numbers", "malloc", "EOF", "STDC",
	"struct, union or enum, tv_sec", "sqrt", "! (exclamation-mark punctuator),",
	"! (logical negation operator)", "!= (inequality operator)", "!= (not-equal punctuator)",
	"# (hash punctuator)", "# preprocessing directive", "# punctuator", "#define preprocessing directive",
	"#elif preprocessing directive", "#else preprocessing directive", "#endif preprocessing directive",
	"#error preprocessing directive", "#if preprocessing directive", "#if preprocessing directive",
	"#ifdef preprocessing directive", "#ifndef preprocessing directive", "#include preprocessing directive",
	"#line preprocessing directive", "#pragma preprocessing directive", "#undef preprocessing directive",
	"& (bitwise AND operator)", "&& (logical AND operator)", "&= (bitwise AND assignment operator)",
	"’ ’ (space character)", "( (opening parenthesis punctuator)", "() (cast operator)",
	"() (function-call operator)", "() (parentheses punctuator)", "(){} (compound-literal operator)",
	") (closing parenthesis punctuator)", "* (asterisk punctuator)", "* (indirection operator)",
	"* (multiplication operator)", "*= (asterisk-equal punctuator)", "*= (multiplication assignment operator)",
	"+ (addition operator)", "+ (plus punctuator)", "+ (unary plus operator)", "++ (plus-plus punctuator)",
	"++ (postfix increment operator)", "++ (prefix increment operator)", "+= (addition assignment operator)",
	"+= (plus-equal punctuator)", ", (comma operator)", ", (comma punctuator)",
	"- (minus punctuator)", "- (subtraction operator)", "- (unary minus operator)", "- format flag",
	"-- (minus-minus punctuator)", "-- (postfix decrement operator)", "-- (prefix decrement operator)",
	"-= (minus-equal punctuator)", "-= (subtraction assignment operator)", "-> (minus-greater punctuator)",
	"-> (structure/union pointer operator)", ". (dot punctuator)", ". (structure/union member operator)",
	"... (ellipsis punctuator)", "/ (division operator)", "/ (slash punctuator)", "/= (division assignment operator)",
	"/= (slash-equal punctuator)", ": (colon punctuator)", ":> (colon greater punctuator)", "; (semicolon punctuator)",
	"< (less punctuator)", "< (less-than operator)", "<: (alternative spelling of [)", "<: (less-colon punctuator)",
	"<< (left-shift operator)", "<< (less-less punctuator)", "<<= (left-shift assignment operator)",
	"<<= (less-less equal punctuator)", "<= (less-equal punctuator)", "<= (less-than-or-equal-to operator)",
	"<% (alternative spelling of {)", "<% (less-percent punctuator)", "<assert.h> header", "<complex.h> header",
	"<ctype.h> header", "<errno.h> header", "<fenv.h> header", "<float.h> header", "<inttypes.h> header",
	"<iso646.h> header" ,"<limits.h> header" ,"<locale.h> header", "<math.h>", "<setjmp.h> header,",
	"<signal.h> header,",
	"<stdalign.h> header,",
	"<stdarg.h> header,",
	"<stdatomic.h> header,",
	"<stdbool.h> header,",
	"<stddef.h> header,",
	"<stdint.h> header,",
	"<stdio.h> header,",
	"<stdlib.h> header,",
	"<stdnoreturn.h> header,",
	"<string.h> header,",
	"<tgmath.h> header,",
	"<threads.h> header,",
	"<time.h> header,",
	"<uchar.h> header,",
	"<wchar.h> header,",
	"<wctype.h> header,",
	"= (equal-sign punctuator),",
	"= (simple assignment operator),",
	"== (equal-equal punctuator),",
	"== (equality operator),",
	"> (greater punctuator),",
	"> (greater-than operator),",
	">= (greater-equal punctuator),",
	">= (greater-than-or-equal-to operator),",
	">> (greater greater punctuator),",
	">> (right-shift operator),",
	">>= (greater-greater-equal punctuator),",
	">>= (right-shift assignment operator),",
	"? (question-mark punctuator),",
	"?: (conditional operator),",
	"?? (trigraph sequences),",
	"[ (opening bracket punctuator),",
	"[ ] (array subscript operator),",
	"[ ] (brackets punctuator),",
	"# format flag,",
	"% (percent punctuator),",
	"% (remainder operator),",
	"%: (percent-colon punctuator),",
	"%:%: (percent-percent punctuator),",
	"%= (percent-equal punctuator),",
	"%= (remainder assignment operator),",
	"%> (alternative spelling of }),",
	"%> (percent-greater punctuator),",
	"%A conversion specifier,",
	"%B conversion specifier,",
	"%C conversion specifier,",
	"%D conversion specifier,",
	"%E conversion specifier,",
	"%F conversion specifier,",
	"%G conversion specifier,",
	"%H conversion specifier,",
	"%I conversion specifier,",
	"%M conversion specifier,",
	"%R conversion specifier,",
	"%S conversion specifier,",
	"%T conversion specifier,",
	"%U conversion specifier,",
	"%V conversion specifier,",
	"%W conversion specifier,",
	"%X conversion specifier,",
	"%Y conversion specifier,",
	"%Z conversion specifier,",
	"& (address operator),",
	"& (ampersand punctuator),",
	"&= (ampersand-equal punctuator),",
	"&& (ampersand-ampersand punctuator),",
	"(backslash character),",
	"(backslash escape sequence),",
	"(single-quote escape sequence)",
	"(null character)",
	"padding of binary stream,",
	"(question-mark escape sequence)",
	" (universal character names)",
	"(alert escape sequence)",
	" (backspace escape sequence)",
	"(escape character)",
	"(form-feed escape sequence)",
	"(new-line escape sequence)", 
	"octal digits (octal-character escape sequence),", 
	"(carriage-return escape sequence)", 
	"(horizontal-tab escape sequence)", 
	"(universal character names),", 
	"(vertical-tab escape sequence),", 
	"{} (braces punctuator),", 
	"{ (opening brace punctuator),", 
	"} (closing brace punctuator),", 
	"] (closing bracket punctuator),", 
	"^ (bitwise exclusive OR operator),", 
	"^ (caret punctuator),", 
	"^= (bitwise exclusive OR assignment operator),", 
	"^= (caret-equal punctuator),", 
	"_Alignas,",
	"_Alignof operator,", 
	"_Atomic type qualifier,", 
	"_Atomic type specifier,", 
	"_Bool type,", 
	"_Bool type conversions,", 
	"_C identifier suffix,", 
	"_Complex type,", 
	"_Complex types,", 
	"_Complex_I macro,", 
	"_Exit function,", 
	"_Generic,", 
	"_IOFBF macro,", 
	"_IOLBF macro,", 
	"_IONBF macro,", 
	"_Imaginary keyword,", 
	"_Imaginary type,", 
	"_Imaginary types,", 
	"_Imaginary_I macro,", 
	"_MAX identifier suffix,", 
	"_MIN identifier suffix,", 
	"_Noreturn,", 
	"_Pragma operator,", 
	"_Static_assert,", 
	"_Thread_local storage-class specifier,", 
	"__STDC_ identifier prefix,", 
	"__DATE__ macro,", 
	"__FILE__ macro,", 
	"__LINE__ macro,", 
	"__STDC_ANALYZABLE__ macro,", 
	"__STDC_HOSTED__ macro,", 
	"__STDC_IEC_559_COMPLEX__ macro,", 
	"__STDC_IEC_559__ macro,", 
	"__STDC_ISO_10646__ macro,", 
	"__STDC_LIB_EXT1__ macro,", 
	"__STDC_MB_MIGHT_NEQ_WC__ macro,", 
	"__STDC_NO_ATOMICS__ macro,", 
	"__STDC_NO_COMPLEX__ macro,", 
	"__STDC_NO_THREADS__ macro,", 
	"__STDC_NO_VLA__ macro,", 
	"__STDC_UTF_16__ macro,", 
	"__STDC_UTF_32__ macro,", 
	"__STDC_VERSION__ macro,", 
	"__STDC_WANT_LIB_EXT1__ macro,", 
	"__STDC__ macro,", 
	"__TIME__ macro,", 
	"__VA_ARGS__ identifier,", 
	"__alignas_is_defined macro,", 
	"__alignof_is_defined macro,", 
	"__bool_true_false_are_defined macro,", 
	"__cplusplus macro,", 
	"__func__ identifier,", 
	"_explicit identifier suffix,", 
	"_t identifier suffix,", 
	"| (bitwise inclusive OR operator),", 
	"| (vertical-line punctuator),", 
	"|= (bitwise inclusive OR assignment operator),", 
	"|= (vertical-line-equal punctuator),", 
	"|| (logical OR operator),", 
	"|| (vertical-vertical punctuator),", 
	"~ (bitwise complement operator),", 
	"~ (tilde punctuator),", 
	"0 format flag,", 
	"abort function,", 
	"abort_handler_s function,", 
	"abs function,",
	"abs macro,",
	"absolute-value functions",
	"complex,",
	"integer,",
	"real,",
	"abstract declarator,",
	"abstract machine,",
	"access",
	"accuracy, see floating-point accuracy",
	"acos function",
	"acos type-generic macro",
	"acosf function",
	"acosh function",
	"acosh type-generic macro",
	"acoshf function",
	"acoshl function",
	"acosl function",
	"acquire fence",
	"acquire operation",
	"active position",
	"addition assignment operator (+=)",
	"addition operator (+)",
	"additive expressions",
	"address constant",
	"address operator (&)",
	"address-free",
	"aggregate initialization",
	"aggregate types",
	"alert",
	"alert escape sequence (a)",
	"aliasing",
	"alignas macro",
	"aligned_alloc function",
	"alignment",
	"pointer",
	"structure/union member",
	"alignment header",
	"alignment specifier",
	"alignof macro",
	"allocated storage, order and contiguity",
	"alternative spellings header",
	"and macro",
	"AND operators",
	"bitwise (&)",
	"bitwise (&)",
	"bitwise assignment",
	"logical (&&)",
	"AND operators",
	"logical (&&)",
	"and_eq macro",
	"anonymous structure",
	"anonymous union",
	"ANSIEE 754",
	"ANSIEE 854",
	"argc (main function parameter)",
	"argument",
	"array",
	"default promotions",
	"function",
	"macro",
	"argument, complex",
	"argv (main function parameter)",
	"arithmetic constant expression",
	"arithmetic conversions",
	"arithmetic operators",
	"additive",
	"bitwise",
	"increment and decrement",
	"multiplicative",
	"shift",
	"unary",
	"arithmetic types",
	"arithmetic, pointer",
	"array",
	"argument",
	"declarator",
	"initialization",
	"multidimensional",
	"parameter",
	"storage order",
	"subscript operator ([ ])",
	"subscripting",
	"type",
	"type conversion",
	"variable length",
	"arrow operator (->)",
	"as–if rule",
	"ASCII code set",
	"asctime function",
	"asctime_s function",
	"asin function",
	"asin type-generic macro",
	"asinf function",
	"asinh function",
	"asinh type-generic macro",
	"asinhf function",
	"asinhl function",
	"asinl function",
	"assert macro",
	"assignment",
	"compound",
	"conversion",
	"expression",
	"operators",
	"simple",
	"associativity of operators",
	"asterisk punctuator (*)",
	"at_quick_exit function",
	"atan function",
	"atan type-generic macro",
	"atan2 function",
	"atan2 type-generic macro",
	"atan2f function",
	"atan2l function",
	"atanf function"
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

    public String getCode(String input, String cCodeRegex) {
	String lines[] = input.split("\\r?\\n");
	if (1 > lines.length) return "";
	try {
	    Pattern cPattern = Pattern.compile(cCodeRegex, Pattern.DOTALL);

	    // Get the block
            int i = 0;
	    Matcher cMatcher = cPattern.matcher(lines[0]);
	    // Print C code blocks
            while (!cMatcher.find()) {
	        i++;
	        if (i > lines.length) return "";
	        cMatcher = cPattern.matcher(lines[i]);
            }
	    // Yeah! we found it!
	    // Jump to the start (we do not need the first i matched
	    i++;

	    // Pattern and Matcher for end of Code code
	    if (i > lines.length) return "";
	    String cCodeRegexEnd = "```*";
            Pattern cPatternEnd = Pattern.compile(cCodeRegexEnd, Pattern.DOTALL);
	    Matcher cMatcherEnd = cPatternEnd.matcher(lines[i]);
	    String program = "";
	    while (!cMatcherEnd.find()) {
	        program += "\n" + lines[i];
	        i++;
	        if (i > lines.length) return "";
	        cMatcherEnd = cPatternEnd.matcher(lines[i]);
	    }
	    return program;
	} catch (PatternSyntaxException | ArrayIndexOutOfBoundsException e) {
	    return "";
	}
    }

    public String getParams(String input) {
	// Define regular expressions for BASH code blocks
	String bashCodeRegex = "\\$.*?(?:\\n|$)";
	// Pattern and Matcher for BASH code
        Pattern bashPattern = Pattern.compile(bashCodeRegex);
        Matcher bashMatcher = bashPattern.matcher(input);
        // Print BASH code blocks
        while (bashMatcher.find()) {
            String bashBlock=(bashMatcher.group().trim());
	    if (!bashBlock.contains("gcc") && !bashBlock.contains("clang")) {
		return bashBlock;
	    }
        }
	return "0";
    }

    public static int getMaxArgvNumber(String input) {
	if (input.isEmpty())  return -1;

        Pattern pattern = Pattern.compile("argv\\[(\\d+)]");
        Matcher matcher = pattern.matcher(input);

        int maxArgvNumber = -1;

        while (matcher.find()) {
            int argvNumber = Integer.parseInt(matcher.group(1));
            maxArgvNumber = Math.max(maxArgvNumber, argvNumber);
        }

        return maxArgvNumber;
    }

    public static String generateFilename(String prefix) {
        return prefix + System.nanoTime() + ".c";
    }

    public boolean writeFile(String filename, String content) {
	// Writing content to the specified file
        try {
            // Using java.nio.file to write to the file
            byte[] contentBytes = content.getBytes("UTF-8");
            Files.write(Path.of(filename), contentBytes, StandardOpenOption.CREATE, StandardOpenOption.WRITE);
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
	    return false;
        }
	return true;
    }

    // input_test_bit_binary : inpupt_test_bit
    public boolean generateBinary(String filename) {
	try {
            String[] compilationCommand = {"gcc", "-O3", filename, "-o", filename + ".o"};
	    ProcessBuilder processBuilder = new ProcessBuilder(compilationCommand);
 	    processBuilder.redirectErrorStream(true);
	    Process process = processBuilder.start();
	    return (0 == process.waitFor());
	} catch (IOException | InterruptedException e) {
	    e.printStackTrace();
	    return false;
	}
    }

    // Util
    public static String stringLeft(String input, String substring, int offset) {
        // Find the index of "./" in the input string
        int index = input.indexOf(substring);
        // If "./" is found, extract the substring after it
	return ((index != -1) && (index + offset < input.length())) ?
        	input.substring(index + offset) : "";
    }

    public static String formatText(String inputText) {
        if (inputText.contains("bash")) {
            return "bash";
        } else if (inputText.contains("BASH")) {
            return "BASH";
        } else if (inputText.contains("Bash")) {
            return "Bash";
        } else {
            // Default case: return the original text
            return inputText;
        }
    }

    private static String determineType(String input) {
	if (input.isEmpty()) return "string";

	// Check if it ends with "f," "l," or "u"
        if (input.endsWith("f")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 1);
            try {
                Float.parseFloat(withoutSuffix);
                return "FLOAT";
            } catch (NumberFormatException eFloat) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("ll") || input.endsWith("LL")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 2);
            try {
                Long.parseLong(withoutSuffix);
                return "LONG";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("ul") || input.endsWith("UL")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 2);
            try {
                return (Long.parseLong(withoutSuffix) >= 0) ? "ULONG" : "STRING";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("l") || input.endsWith("L")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 1);
            try {
                Long.parseLong(withoutSuffix);
                return "LONG";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("u") || input.endsWith("U")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 1);
            try {
                return (Long.parseLong(withoutSuffix) >= 0) ? "UINT32" : "STRING";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        try {
            // Attempt to parse as Integer
            Integer.parseInt(input);
            return "INT32";
        } catch (NumberFormatException eInt) {
            // Not an Integer, check if it's a Double
            try {
                Double.parseDouble(input);
                return "DOUBLE";
            } catch (NumberFormatException eDouble) {
                // Not a Double mst be String
                return "STRING";
            }
        }
    }

    public static String getArgumentsTypes(String argsValue, int argsSize) {
    	String returnTypesList = "";
    	int currentListSize = 0;

	if (!argsValue.isEmpty()) {
		String[] args = argsValue.split(" ");
    		for (String arg : args) {
        		String type = determineType(arg);
        		returnTypesList += type + " ";
        		currentListSize++;
    		}
	}

    	// Fill remaining slots with INT32 if needed
    	for (int i = currentListSize + 1; i <= argsSize; i++) {
        	returnTypesList += "INT32 ";
    	}

    	return returnTypesList.trim(); // Trim to remove trailing space
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
		String prompt = "Give me a program in C with all includes. Code only and short answer. Input taken via argv only. Please return program (in C) and example of input (BASH). " +
			"The C program will with code triggers " + randomCompilerOpt + " optimizatios, covers this part of the compiler " +
			randomCompilerParts + ", and excersises this idea in C: " + randomPL + ".";

		// PROMPT
		String res = compilerStrings.askModel(ollamaAPI, modelType, prompt);
		System.out.println(res);

		// Program
		System.out.println("======================= Program: =======================");
		String program = compilerStrings.getCode(res, "```C*");
		System.out.println(program);
		// Input
		System.out.println("======================= Input: ======================="); // Solve problem with "./" in second bash tags
		String bashForm = compilerStrings.formatText(res);
		String inputCleaned = compilerStrings.stringLeft(compilerStrings.getCode(res, "```" + bashForm + "*"),"./",2);
		if (inputCleaned.isEmpty()) {
			inputCleaned = compilerStrings.getCode(res, "```\n" + bashForm + "./*");
			if (inputCleaned.isEmpty()) {
				inputCleaned = compilerStrings.getCode(res, "```\n./*");
				if (inputCleaned.isEmpty()) {
					inputCleaned = compilerStrings.getCode(res, "`./*");
				}
			}
		}
		String lines[] = inputCleaned.split("\\r?\\n");
		String callLine = compilerStrings.stringLeft(lines[0]," ",1);
		System.out.println(callLine);
		// Type
		System.out.println("======================= Type: =======================");
		int maxArgs = compilerStrings.getMaxArgvNumber(program);
                System.out.println(maxArgs);
		String argsType = "";
		if (program.contains("argv[i]") || program.contains("argv[j]") || (maxArgs >=1)) {
			// set argsType
			argsType = compilerStrings.getArgumentsTypes(callLine, maxArgs);
		}


		// Type string generatee
		if (argsType.isEmpty() || callLine.isEmpty() || program.isEmpty()) {
		    	System.out.println(">>> Bad program. Skip this test input.");
			// Check if the case of argv[i and then get it from input size
		} else {
		    	// GOOD Program - Write the files
		    	String testName = compilerStrings.generateFilename("test_input_");
		    	if (compilerStrings.writeFile(testName, program)) {
				if (compilerStrings.generateBinary(testName)) {
					String testArgs = testName + ".o\n" + callLine;
					if (compilerStrings.writeFile(testName + ".txt", testArgs)) {
						// Write type
						if (compilerStrings.writeFile(testName + ".type", argsType)) {
			    				System.out.println(">>>>>> Generate the test input " + testName);
						}
					}
				}
		    	}
		}
		System.out.println("===========================================================================");
	}
    }
}
