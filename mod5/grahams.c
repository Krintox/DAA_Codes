#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure for a 2D point
typedef struct {
    int x, y;
} Point;

// Helper function to swap two points
void swap(Point *p1, Point *p2) {
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Helper function to find the square of distance between two points
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Helper function to find the orientation of ordered triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) {
        return 0; // collinear
    } else {
        return (val > 0) ? 1 : 2; // clockwise or counterclockwise
    }
}

Point p0;
// Comparator function to sort points based on polar angle
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    
    // Find orientation of triplet (p, q, r)
    int o = orientation(p0, *p1, *p2);
    if (o == 0) {
        // If collinear, select the point that is farther from p0
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    } else {
        // Sort in counterclockwise direction
        return (o == 2) ? -1 : 1;
    }
}

// Main function to find the convex hull of a set of n points
void convexHull(Point points[], int n) {
    // Find the point with the smallest y-coordinate (ties broken by smallest x-coordinate)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }
    
    // Place the bottom-most point at first position
    swap(&points[0], &points[min]);
    
    // Sort points based on polar angle with respect to the first point
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);
    
    // Initialize stack for Graham Scan
    int stack[n];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = 1;
    stack[++top] = 2;
    
    // Process remaining n-3 points
    for (int i = 3; i < n; i++) {
        // Keep removing top while the angle formed by points next-to-top, top, and points[i] makes a non-left turn
        while (top >= 1 && orientation(points[stack[top-1]], points[stack[top]], points[i]) != 2){
            top--;
        }
        stack[++top] = i;

        for(int i=0; i<=top;i++){
            printf("(%d,%d)\n", points[stack[i]].x,points[stack[i]].y);
        }
    }
}
        
int main() {
    Point points[] = {{0,3}, {1,1}, {2,2}, {4,4}, {0,0}, {1,2}, {3,1}, {3,3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points,n);
    return 0;
}
    
    
        