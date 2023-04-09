#include <stdio.h>

// define a point struct to hold x and y coordinates
typedef struct {
    int x;
    int y;
} point;

// determine the orientation of three points
int orientation(point p, point q, point r) {
    // compute the cross product of two vectors
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// compute the convex hull of a set of points
void convexHull(point points[], int n) {
    if (n < 3) return; // the convex hull of less than three points is undefined

    // initialize an array to store the indices of the points on the convex hull
    int hull[n];
    for (int i = 0; i < n; i++)
        hull[i] = -1;

    // find the leftmost point in the set of points
    int leftmost = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftmost].x)
            leftmost = i;

    int p = leftmost, q;
    int i;
    do {
        // mark the current point as part of the convex hull
        hull[p] = 1;
        q = (p + 1) % n;

        // find the next point on the convex hull by checking the orientation of all other points
        for (i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != leftmost);

    // print out the points on the convex hull
    for (int i = 0; i < n; i++) {
        if (hull[i] == 1)
            printf("(%d,%d)\n", points[i].x, points[i].y);
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // initialize an array of points and read in their values from standard input
    point points[n];
    printf("Enter the points in the format (x,y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d,%d", &points[i].x, &points[i].y);
    }

    // compute and print out the convex hull
    printf("The convex hull is:\n");
    convexHull(points, n);

    return 0;
}
