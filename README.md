# 342-Project1
When comparing C and Haskell, there are both similarities and differences in how they handle sorting algorithms like Quick Sort and Merge Sort.

In C, which is a procedural language, you have to control everything step by step. For sorting, this means you use loops, manage memory, and manually swap values. C requires you to handle memory allocation yourself, like using malloc() to create temporary space during sorting. You also use pointers to swap values, which can be tricky but gives you a lot of control over how things are done.

Haskell, on the other hand, is a functional language. Instead of manually managing everything, Haskell relies on recursion—where a function calls itself to break down problems into smaller parts. In Haskell, sorting is done using simple and clean code. For example, its Quick Sort uses list comprehensions, which automatically divide the list into smaller pieces without needing you to manually swap values or manage memory. Everything is more abstract in Haskell, meaning it hides the complex details.

The main similarity between C and Haskell is that both can implement sorting algorithms and follow the same logic: divide the list, sort it, and merge it back. However, the way they do this is very different—C gives you control over every detail, while Haskell does more work for you in the background, using higher-level concepts like recursion and immutability.

The following tools and websites were used to complete this assignment:
Tools and Websites used for Sorting in C: 
Tools: Visual Studio Code (to write and run the code), GHC (to run Haskell programs), GCC (to run C programs).
Websites: GeeksForGeeks.org (for reference), Discord (for asking questions), GitHub (for saving and sharing code), Haskell.org (for learning Haskell), and ChatGPT (for getting help and advice).
