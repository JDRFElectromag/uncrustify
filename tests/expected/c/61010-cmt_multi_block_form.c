/* One-line comment stays. */
int a; /* trailing stays */

/**
 * First line of text
 * second line of text
 */
int b;

/**
 * Already block form, plain opener
 */
int c;

/**
 * Already correct
 */
int c2;

/**
 * Doxygen opener with text
 * continues here
 */
int d;

/**
 * text then
 * star cont
 */
int e;

/**
 * Paragraph one
 *
 * Paragraph two
 *   - indented bullet
 */
int f;

/*! Qt style stays
 * as is
 */
int g;

/*****************************
* Banner stays
*****************************/
int h;

/* comment then code */ int i;

int j; /* trailing multi
        * line */

#define M(x) /* in a macro \
              * stays */(x)

void fn(void)
{
    /**
     * inside a function
     * wrapped
     */
    g();
    if (a) {
        /**
         * deeper
         *    keep relative indent
         */
        h();
    }
}

/**
 ******************************************************************************
 * @file    divider.h
 ******************************************************************************
 */
int k;

/**
 * Code sample
 *<pre>
 * int x = f(
 *            a,
 *            b
 *          );</pre>
 */
int l;

/**
 * Tip: text on the opener
 *  ===  and a star at the margin
 */
int m;
