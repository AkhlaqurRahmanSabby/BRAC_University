/* # represents pre-processor directive. It happens before normal compilation of the code. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void data_types()
{
    //square brackets represents an array that can store a string
    char oneCharacterOnly = 'S';
    char name [] = "Sabby";

    //double is more precise than floating point numbers
    int date = 13;
    double cgpa = 1.99;
    float a = 3.99;

    //%s for text and %d for numbers are place holders for the variables
    printf("My name is %s. \n", name);
    printf("My birth date is %d. \n", date);
    printf("My cgpa is %f. \n", cgpa);
    printf("My name starts with %c. \n", oneCharacterOnly);

    //how to print a quotation mark
    printf("\"Whoami\"\n");
}

void arithmetic_operations()
{
    int a = 5;
    double b = 2.4;
    double c = a + b;
    printf("%f \n", c);

    //using built-in functions
    printf("%f \n", pow(2, 3)); //pow gives decimal number
    printf("%f \n", sqrt(16));
    printf("%f \n", ceil(19.2777));
    printf("%f \n", floor(19.2777));

    //how to update the value within a variable
    a = 2.68;
    printf("%f \n", a + b);

    //creating a read-only variable
    //it is best practice to capitalize these variable names
    const int READ_ONLY = 13; //"int const d" also works
    //d = 16 fails to update d
}

void user_input()
{
    //variable definition but no initialization
    int num1;
    double num2;
    char a;

    //taking an integer input
    printf("Please enter first number: ");
    //scanf function reads input from the standard input stream stdin
    scanf("%d", &num1);
    printf("You entered the numbers: %d.\n", num1);

    //taking a double input
    printf("Please enter second number: ");
    scanf("%lf", &num2);
    printf("You entered the numbers: %f.\n", num2);

    //taking character input
    printf("Please enter a character: ");
    //add a space before %c to prevent new line from interfering when enter is pressed in previous scanf
    scanf(" %c", &a);
    printf("You have entered %c.\n", a);

    //taking character input using getchar()
    printf("Please enter a character: ");
    //the getchar() consumes the dangling newline from previous scanf
    getchar();
    char d = getchar();
    printf("You have entered ");
    putchar(d);

    //taking string input
    char name [100];
    printf("\nPlease enter a string: ");
    /*
    try using scanf
    scanf cannot be used as it considers space as string ending
    fgets take three arguments (variable, input length, input type- in our case "standard input" which is the console
    as we press enter, it is also stored inside the string
    & is not required while storing string using &s
    */
    getchar();
    fgets(name, 100, stdin);
    printf("You have entered %s", name);
}

void arrays_in_C()
{
    //arrays are used to hold a bunch of same type of data
    int sample_array [] = {1, 2, 3, 4, 5};
    printf("%d \n", sample_array[0]);
    sample_array [0] = 100;
    printf("%d \n", sample_array[0]);

    //multidimensional arrays
    int a[3][2] = {{1, 4}, {2, 5}, {3, 6}};

    //while just defining an array, we must tell C how many elements it can hold
    char sample_array2 [10];
    sample_array2 [9] = 'S';
    printf("%c\n", sample_array2[9]);
    printf("%c\n", sample_array2[0]);

}
void strings_in_C()
{
    //strings are arrays consisting of characters and ending with null
    char s1 [] = {'O', 'p', 'e', 'r', '\0'};
    printf("%s\n", s1);

    char s2 [] = "ating";
    printf("Concatenated string is %s\n", strcat(s1, s2));
    printf("s1 now is %s\n", s1);
    printf("s2 now is %s\n", s2);

    printf("Length is %d\n", strlen(s1));
    //returns 0 if s1 = s2, <0 if s1<s2, >0 is s1>s2
    printf("%d\n", strcmp(s1, s2));
    printf("%s\n", strchr(s1, 'r'));
    printf("%s\n", strstr(s1, s2));
}

//functions cannot have an array return type
int f_w_return_type(int user_input)
{
    int sum = 5 + user_input;

    return sum;
}

void test_function(char input_A [], int input_B)
{
    /* void is the return type of the function
    a function must be called
    input_A and input_B are parameters


    A parameter is a variable in a function definition.
    It is a placeholder and hence does not have a concrete value.
    An argument is a value passed during function declaration.
    */

    printf("Input_A is %s and Input_B is %d. \n", input_A, input_B);

    printf("The function returned %d.", f_w_return_type(5));
}


void loops_in_C()
{
    int sample_array [5];
    for (int i = 0; i < 5; i++)
    {
        sample_array [i] = i + 20;
        printf("Element at %d index of sample_array is %d\n", i, sample_array[i]);
    }

    //printing elements in a multidimensional array
    int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            printf("a[%d][%d] = [%d]\n", r, c, a[r][c]);
        }
    }

    //while loops
    int i = 1;
    while (i <=5)
    {
        printf("%d\n", i);
        i++;
    }

    //conditions
    if (2>3)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}

void pointers_in_C()
{
    //physical memory address locations
    int age = 26;
    printf("%p\n", &age);

    //pointers is a data type that is a physical memory address

    //defining pointer variables
    int fav_num = 13;
    int *ip = &fav_num;

    double cgpa = 1.99;
    double *dp = &cgpa;

    float *fp;

    char name [] = "Sabby";
    char *ch = &name;

    printf("The pointer ip contains memory address of %d, which is %x. \n", *ip, ip);
    printf("The pointer dp contains memory address of %f, which is %x. \n", *dp, dp);

    //show them that %s gives error. Pointer points at first character of a string.
    printf("The pointer ch contains memory address of %c, which is %x. \n", *ch, ch);

    //incrementing pointer
    int var [] = {1, 2, 3};
    ip = &var;

    for (int i = 0; i < 3; i++)
    {
        printf("Pointer value for var[%d] is %x, which is holding %d.\n", i, ip, *ip);
        ip++;
    }
}

/* struct is a data structure where we can store a group of data types
We can use it  to define a new data type
*/
struct Books
{
    char title [50];
    char author [50];
    char subject [100];
    int book_id;
};

void structs_in_C()
{
    //creating an instance or container called Book1

    struct Books Book1;

    strcpy(Book1.title, "Harry Potter");
    strcpy(Book1.author, "J.K. Rowling");
    strcpy(Book1.subject, "Literature");
    Book1.book_id = 12345;

    printf("%s [%d], which is of type %s, written by %s is the best series of fantasy novels I ever read in my life.", Book1.title, Book1.book_id, Book1.subject, Book1.author);
}

int main()
{
    //data_types();

    //arithmetic_operations();

    //user_input();

    //arrays_in_C();

    //strings_in_C();

    //test_function("Operating Systems", 13);

    //loops_in_C();

    //pointers_in_C();

    //structs_in_C();

    return 0;
}
