# Console Statistics and Frequency Analyzer

## Overview

A Windows console application written in C++ that reads numeric input, sorts a dataset, and produces a statistical report with a frequency table and text-based chart. The project demonstrates recursive sorting, dynamic collections, numeric processing, and formatted console output. The current implementation contains calculation and grouping defects described below; its statistical results require correction and verification before practical use.

## Key Features

- Reads whitespace-separated input until `end` or the end of the input stream.
- Converts input tokens to floating-point values, silently skipping tokens that cause conversion exceptions.
- Sorts stored values using a custom recursive quicksort implementation.
- Tracks the input count, total, minimum, and maximum, and includes calculations for summary statistics.
- Applies the natural logarithm to positive values before frequency grouping; nonpositive values remain unchanged.
- Produces ten frequency groups labelled A–J, with interval boundaries, counts, percentages, and horizontal console bars.

## Technologies Used

- **Programming language:** C++; the supplied project selects C++20.
- **Standard library:** `std::vector`, `std::string`, stream input/output, `std::stod`, `std::swap`, and mathematical functions.
- **Windows API:** `GetConsoleOutputCP` and `SetConsoleOutputCP` for console character encoding.
- **Build configuration:** Visual Studio C++ project and solution files, MSVC platform toolset `v145`, and Windows SDK target `10.0`.

## Technical Concepts Demonstrated

- **Recursive algorithms:** Quicksort selects a middle-element pivot, partitions values using two moving indices, and recursively sorts the resulting sections.
- **Dynamic collections:** A `std::vector<double>` stores numeric input, while a vector of `buckets` structures holds frequency-group metadata.
- **Structured data:** Each bucket combines a label, interval boundaries, count, and percentage.
- **References and in-place processing:** Sorting modifies the dataset through a reference, and the logarithmic transformation updates elements through reference-based iteration.
- **Modular organization:** Sorting has a separate declaration and implementation; dedicated functions format frequency-table and chart rows.
- **Conversion exception handling:** Input conversion is wrapped in a `try`/`catch` block, although validation and user feedback remain limited.

## How the Program Works

1. Read input tokens and attempt to convert each token to a `double`.
2. Store accepted values and accumulate summary data.
3. Sort the dataset using the custom quicksort function.
4. Calculate median, mean, variance, and standard deviation.
5. Replace positive values with their natural logarithms.
6. Construct ten intervals and attempt to count the transformed values in each group.
7. Print the summary report, frequency table, and chart, then restore the original console output code page.

The summary calculations precede the logarithmic transformation. The frequency table and chart use the modified dataset.

## Project Structure

- `Project2.slnx` — Visual Studio solution referencing the C++ project.
- `Project2/Project2.cpp` — Input processing, summary calculations, transformation, grouping, and console output.
- `Project2/Sort.cpp` — Recursive quicksort implementation.
- `Project2/Sort.h` — Quicksort function declaration.
- `Project2/Project2.vcxproj` — Compiler, platform, and build settings.
- `Project2/Project2.vcxproj.filters` — Visual Studio file organization.

## How to Run

### Requirements

- Windows, because the application includes `Windows.h` and uses Windows console APIs.
- Visual Studio with C++ build support and the configured MSVC `v145` toolset.
- A compatible Windows SDK; the project specifies target version `10.0`.

### Build and execute

1. Open `Project2.slnx` in a Visual Studio version that supports this solution format, or open `Project2/Project2.vcxproj` directly.
2. Select a configuration such as **Debug / x64** and build the project.
3. Run the generated `Project2.exe` from a Windows console.
4. Enter whitespace-separated numbers, followed by `end`.

The application also accepts redirected standard input. From Windows Command Prompt, in the executable's directory:

```bat
Project2.exe < numbers.txt
```

`numbers.txt` is a user-provided input file; no dataset is included in the submitted project.

These steps are derived from the supplied project configuration and source. A successful build and execution have not been verified as part of this review. Review the limitations below before interpreting output.

## Known Limitations

- Median calculations use incorrect indices and can access elements outside the vector.
- The variance calculation adds squared values a second time and incorrectly uses input values as vector indices. This can produce invalid results or undefined behavior.
- Empty input is not handled before element access and division.
- Frequency grouping can skip values and stop before all values are counted.
- Leaving nonpositive values unchanged during the logarithmic transformation can disrupt the sorted order assumed by grouping.
- Numeric conversion does not enforce whole-token consumption or reject non-finite values.
- Minimum and maximum initialization uses integer limits despite storing floating-point data.

## What This Project Demonstrates

- Combining input processing, sorting, calculations, and reporting in a console application.
- Implementing a recursive sorting algorithm with in-place partitioning.
- Organizing related values into structures and dynamic collections.
- Separating a reusable algorithm from application logic and output functions.

## Potential Enhancements

- Correct the statistical calculations and bucket assignment, then add automated tests with independently verified expected results.
- Validate complete input tokens, reject non-finite values, and report invalid input clearly.
- Define a consistent policy for logarithmic transformation and nonpositive values.
- Extract calculation and grouping functions from `main` to support focused testing and reuse.
- Scale the chart to the observed percentages and offer portable text output.

## Academic Context

This project was developed as part of coursework in the Computer Programming and Analysis program at Fanshawe College. It is included in this portfolio to demonstrate programming concepts, software-development techniques, and practical problem-solving skills.

## Author

Joshua Otto  
Computer Programming and Analysis  
Fanshawe College