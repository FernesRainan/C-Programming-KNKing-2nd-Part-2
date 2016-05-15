// Replace the test condition in the following if statement by a single call of strstr:
// if (strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0 ||
//     strcmp(str, "baz") == 0) 
// Hint: Combine the string literals into a single string. separating them with a special 
// character. Does your solution assume anything about the contents of str?

if (strstr("foo#bar#baz", str) != NULL) ...
