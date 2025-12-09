#include <math.h>
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <algorithm>

typedef uint64_t u64;
typedef struct {
    long x;
    long y;
} v2;


/*
    Theoretical solution for part 2

    Basics is to check if current rect goes past a border point
    aka if rectangle 2,3 to 4,5 crosses 3,3 its not inside of the grids

    some edge cases: points inside of a border created by other 4 points?
    it is not garunteed that it creates a perfect house shape?

    Though the problem description seems to indicate that all points are on 
    given such that it can create a perfect house shape with no internal points.

    So we will first try to use the if no other points inside of rectangle then the area is valid theory.
    Though does that mean O(n3) is enforced? Is there a less brute force algorithm?
    Because we will have to loop through all pairs of points for rectangles and all points to check if there is
    an point inside of it.

*/

using namespace std;
int main() {
    vector<v2> vs;
    v2 v;
    long m = -1;
    while (scanf("%li,%li\n", &v.x, &v.y) == 2) {
        for (auto u : vs) {
            m = max((abs(u.x - v.x) + 1) * (abs(u.y - v.y) + 1), m);
        } 
        vs.push_back(v);
    }

    printf("%li\n", m);
}