// In computer graphics, colors are often stored as three numbers. representing red, green, and
// blue intensities. Suppose that each number requires eight bits, and we'd like to store all three
// values in a single long integer. Write a macro named MK_COLOR with three parameters (the
// red, green, and blue intensities) MK_COLOR should return a long in which the last three
// bytes contain the red, green, and blue intensities, with the red value as the last byte and the 
// green value as the next-to-last byte.

#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))

