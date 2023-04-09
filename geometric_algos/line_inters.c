#include <stdio.h>
#include <stdbool.h>

// Structure to represent a point
typedef struct Point {
    int x;
    int y;
} Point;

// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) &&
        q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y))
        return true;
    return false;
}

// Function to find the orientation of ordered triplet (p, q, r)
// The function returns the following values:
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// The function that returns true if line segment 'p1q1' and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false; // Doesn't fall in any of the above cases
}

// The main function for user input and testing
int main()
{
    Point p1, q1, p2, q2;
    printf("Enter the first line segment: ");
    scanf("%d%d%d%d", &p1.x, &p1.y, &q1.x, &q1.y);
    printf("Enter the second line segment: ");
    scanf("%d%d%d%d", &p2.x, &p2.y, &q2.x, &q2.y);

    if (doIntersect(p1,q1,p2,q2)){
        printf("intersect");
    } else {
        printf("dont");
    } 
    return 0;
}
