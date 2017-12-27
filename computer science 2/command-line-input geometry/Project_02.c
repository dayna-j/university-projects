#define _USE_MATH_DEFINES

#ifndef M_PI
#define M_PI acos(-1.0)
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>

// declares _Bool type var, bHasError and assigns false to it.
_Bool bHasError = false;
// note the use of the const specifier on these four strings
// these are literals that should not change during the lifetime of the program execution
const char *assignmentID = "Project 02";                                        // pointer to a constant string.
const char *classId = "CSC-250 Computer Science II (a.k.a. C II) Spring 2017";  // pointer to a constant string.
const char *programmerName = "Dayna Blackwell";                                        // pointer to a constant string.
const char *dueDate = "Monday AM, February 6, 2017";                            // pointer to a constant string.
char *completionStatus = "Success";     // set this to Success here.  on error we will reset it to appropriate messaging
// PrintExitBanner function prototype. returns void.  2 formal parameters:  pointer to a constant char and pointer to a constant char.
void PrintExitBanner(const char *, const char *);
// PrintEntryBanner functino prototype.  returns void.  4 formal param.  All 4 are pointers to constant strings
void PrintEntryBanner(const char *sAssignID, const char *sClassID, const char *sDate, const char *sDeveloper);
// function prototypes for shapes
void square(const char *side);
void circle(const char *rad);
void annulus(const char *inRad , const char *outRad);
void squarePrism(const char *s , const char *h);
void cylinder(const char *rad, const char *h);
void torus(const char *minRad, const char *majRad);
// function prototype for findShape.  returns nothing.  2 formal param: integer-type and pointer to constant char
void findShape(int, const char*);

void findShape(int argc, const char *argv[])
{
    if (0 == strcmp(argv[1], "square") && (argc >= 3))
    {
        square(argv[2]);
    }
    else if (0 == strcmp(argv[1], "circle") && (argc >= 3))
    {
        circle(argv[2]);
    }
    else if (0 == strcmp(argv[1], "annulus") && (argc >= 4))
    {
        annulus(argv[2], argv[3]);
    }
    else if (0 == strcmp(argv[1], "square_prism") && (argc >= 4))
    {
        squarePrism(argv[2],argv[3]);
    }
    else if (0 == strcmp(argv[1], "cylinder") && (argc >= 4))
    {
        cylinder(argv[2],argv[3]);
    }
    else if (0 == strcmp(argv[1], "torus") && (argc >= 4))
    {
        torus(argv[2],argv[3]);
    }
    else
    {
        printf(" unknown or unhandled shape: %s\n", argv[1]);
        bHasError = true;
        completionStatus = "***> error <***  unknown shape";
    }
}
// side will be passed in as argv[2]
void square(const char *side)
{
//  atof(argv[2] parses the C string str, interpreting its content as a floating point number and returns its value as a double.
    double base = atof(side);
        if (base >= 0.0)
        {
            double area = base * base;
            printf("%18s: base: %.2lf  area: %.2f\n", "square", base, area);
        }
        else
        {
            printf("%18s: base: %.2lf      ***> error <***      Bad Data\n", "square", base);
            bHasError = true;
            completionStatus = "***> error <***  square(bad data)";
        }
}
void circle(const char *rad)
{
    double radius = atof(rad);
        if (radius >= 0.0)
        {
            double area = radius * radius * M_PI;
            printf("%18s: radius: %.2lf  area: %.2f\n", "circle", radius, area);
        }
        else
        {
            printf("%18s: radius: %.2lf      ***> error <***      Bad Data\n", "circle", radius);
            bHasError = true;
            completionStatus = "***> error <***  circle(bad data)";
        }
}
void annulus(const char *inRad , const char *outRad)
{
    double inner_radius = atof(inRad);
    double outer_radius = atof(outRad);
        if ((inner_radius >= 0.0) && (outer_radius >= 0.0) && (inner_radius <= outer_radius))
        {
            double area = (outer_radius*outer_radius - inner_radius*inner_radius) * M_PI;
            printf("%18s: inner radius: %.2lf  outer radius: %.2lf  area: %.2f\n", "annulus", inner_radius, outer_radius, area);
        }
        else
        {
            printf("%18s: inner_radius: %.2lf  outer_radius: %.2lf     ***> error <***      Bad Data\n", "annulus", inner_radius, outer_radius);
            bHasError = true;
            completionStatus = "***> error <***  annulus(bad data)";
        }

}
void squarePrism(const char *s , const char *h)
{
    double width = atof(s);
    double height = atof(h);
        if ((width >= 0.0) && (height >= 0.0))
        {
            double volume = (width*width) * height;
            printf("%18s: width: %.2lf  height: %.2lf  volume: %.2f\n", "square_prism", width, height, volume);
        }
        else
        {
            printf("%18s: width: %.2lf  height: %.2lf     ***> error <***      Bad Data\n", "square_prism", width, height);
            bHasError = true;
            completionStatus = "***> error <***  square_prism(bad data)";
        }
}
void cylinder(const char *rad, const char *h)
{
    double radius = atof(rad);
    double height = atof(h);
        if ((radius >= 0.0) && (height >= 0.0))
        {
            double volume = height * radius * radius * M_PI;
            printf("%18s: radius: %.2lf  height: %.2lf  volume: %.2f\n", "cylinder", radius, height, volume);
        }
        else
        {
            printf(" cylinder: radius: %.2lf  height: %.2lf     ***> error <***      Bad Data\n", radius, height);
            bHasError = true;
            completionStatus = "***> error <***  cylinder(bad data)";
        }

}
void torus(const char *minRad, const char *majRad)
{
    double minor_radius = atof(minRad);
    double major_radius = atof(majRad);
        if (minor_radius <= major_radius)
        {
            if ((minor_radius >= 0.0) && (major_radius >= 0.0))
            {
                double volume = (minor_radius*minor_radius * major_radius) * M_PI * M_PI * 2;
                printf("%18s: minor radius: %.2lf  major radius: %.2lf  volume: %.2f\n", "torus", minor_radius, major_radius, volume);
            }
            else
            {
                printf("%18s: minor radius: %.2lf  major radius: %.2lf     ***> error <***      Bad Data(negative data)\n", "torus", minor_radius, major_radius);
                bHasError = true;
                completionStatus = "***> error <***  torus(bad data)";
            }
        }
        else
        {
            printf(" torus: minor radius: %.2lf  major radius: %.2lf     ***> error <***      Bad Data(invalid radii)\n", minor_radius, major_radius);
            bHasError = true;
            completionStatus = "***> error <***  torus(bad data)";
        }

}
void print_usage(void)
{
        printf("usage:\n"
        "  Project 02 compute area/volume for common geometric shapes\n"
        "    area calcualtors:\n"
           "        square  width\n"
           "        circle  radius\n"
           "        annulus inner_radius  outer_radius\n"
           "    volume calculators:\n"
           "        square_prism width  height\n"
           "        cylinder  radius  height\n"
           "        torus   minor_radius  major_radius\n"
           "     example:\n"
        "        square_prism 4  12\n"
        "        cylinder  32  320\n"
        "        torus   17   45\n");
}
// HasSilentFlag returns _Bool.  2 formal parameters:  argc and *argv[]
// argc: argument count. The number of arguments passed from command line.  
// argv: argument vector.  an array containing the strings passed to main as arguments from the command line.
_Bool HasSilentFlag(int argc, char *argv[])
{
    for (size_t n = 1; n < (unsigned int)argc; n++)
    {
// strcmp(str1, str2) returns 0 if str1 and str2 are the same.
        if (0 == strcmp("-quiet", argv[n]))
            return true;
    }
// return false if "-quiet" cannot be found in argv    
    return false;
}
void PrintEntryBanner(const char *sAssignID, const char *sClassID, const char *sDate, const char *sDeveloper)
{
    // Is the multiline C string literal a new form?  
    // Adjacent string literal tokens are concatenated (during phase 6) into a single literal token
    // See 6.4.5 String literals, paragraph 5 (Semantics) of C 2011 Language Standard  (N1570.pdf draft)
    
    // It is not until compilation phase 6 that the C string null terminator char is appended, 
    // and that is why the following produces one C string and not 5...
    printf("\n--------------------------------------------------------------------------\n"
           "Project ID: %s\n"
           "Class ID: %s\n"
           "Program Due Date: %s\n"
           "Programmer ID: %s\n\n", sAssignID, sClassID, sDate, sDeveloper);
}
void PrintExitBanner(const char * sAssignID, const char * sComplStatus)
{
    printf("\nProject ID: %s\n"
        "Compeletion Status: %s\n", sAssignID, sComplStatus);
}
// ===============================================================
// main - this is where all of the action occurs...
// ===============================================================
int main(int argc, char *argv[])
{   
    if (argc < 2)
    {
        print_usage();  // if no args, then show usage and quit early
        return 0;
    }
    // if "-quiet" is NOT found in argv, call PrintEntryBanner()
    if (!HasSilentFlag(argc, argv))
    {
        PrintEntryBanner(assignmentID, classId, dueDate, programmerName);
    }
    // C is missing the case insensitive compare - so we coerce input arg to lower case, and compare on that
    // OH MY - we are modifying a string that we do not have ownership of.  In general, that is a very very very bad thing to do
    // If the modifying of arguments stings would result in either undefined or unspecified behavior as covered in Annex J of C 2011 Language Standard (draft as of N1570), then you must fix this
    // Hint -- check Section 5.1.2.2.1, paragraph 2 of C 2011 Language Standard  (N1570.pdf draft)

    // *p is a pointer to char type pointer.  points to the 1st index position in argv array.
    // p will point to the first char of the first arg. string.  Loop continuation: *p is nonzero.  incrementing p gives p the address of the next char.
    for (char *p = argv[1]; *p; p++)
    {
// if p is alphanumeric and uppercase, then assign char of tolower of p to p. 
        if (isalpha(*p) && isupper(*p))
        {
            printf("%c\n",*p);//!!!!!!!!!!!DEBUG LINE!!!!!!
            *p = (char)tolower(*p);
        }
    }
///////DEBUG LINES//////////////////////////////////
//    for (int n=0; n<=argc; n++)
//    {
//        printf("argument[%d]: %s\n",n,argv[n]);
//    }
////////////////////////////////////////////////////
    findShape(argc,argv);
    if (!HasSilentFlag(argc, argv) || bHasError)
        PrintExitBanner(assignmentID, completionStatus);

    return 0;
}

