#include<stdio.h>
/* test_comments.c
   A collection of test cases for Exercise 1-23 (comment removal).
   Save this file and run: ./your_comment_remover test_comments.c out.c
*/
void main()
{
/* 1) Simple line comment */
int a = 1; // initialize a to one
a++;

/* 2) Simple inline block comment */
int x = 10; /* inline block comment */ int y = 20;

/* 3) Multi-line block comment */
int z = 0;
/* This is a
   multi-line block comment
   that spans several lines and should be removed */
z = z + 1;

/* 4) Block comment that contains "*/" like tokens in strings inside it
   (still part of comment and should be removed)
   Example: "not code /* even if it looks like it */"
*/

/* 5) String literals containing comment-like sequences (should remain) */
char *s1 = "This is not /* a comment */";
char *s2 = "He said \"// not a comment\" and left.";

/* 6) Escaped quotes and backslashes inside strings */
char *s3 = "Quote: \\\" /* not a comment */ \\\" end";
char *s4 = "Backslash then star: \\* then slash: \\/";

/* 7) Character constants containing comment-like characters */
char c1 = '/';
char c2 = '*';
char c3 = '\'';   /* escaped single quote */
char c4 = '\\';   /* backslash */

/* 8) Division operator and lone slash cases — should not be removed */
int quotient = a / y;
int div_by_expr = x / (y + 1); // division in expression

/* 9) Nested-looking comments: comments do NOT nest.
   The first '*/' should close the comment.
*/
int before = 1;
/* outer comment start
   /* inner-looking comment */
   after inner text
*/
int after = 2;

/* 10) Line comment in the middle of a line followed by code on next line */
int p = 5; // comment to end-of-line
p += 1;

/* 11) Unterminated block comment at EOF (should trigger a warning from your program).
   The comment begins here and never ends:
   /* UNTERMINATED COMMENT */
int will_not_run = 42;
}
