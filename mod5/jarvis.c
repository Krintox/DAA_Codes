#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

int orientation(point p, point q, point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(point points[], int n) {
    if (n < 3) return;

    int hull[n];
    for (int i = 0; i < n; i++)
        hull[i] = -1;

    int leftmost = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftmost].x)
            leftmost = i;

    int p = leftmost, q;
    int i;
    do {
        hull[p] = 1;
        q = (p + 1) % n;

        for (i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != leftmost);

    for (int i = 0; i < n; i++) {
        if (hull[i] == 1)
            printf("(%d,%d)\n", points[i].x, points[i].y);
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    point points[n];
    printf("Enter the points in the format (x,y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d,%d", &points[i].x, &points[i].y);
    }

    printf("The convex hull is:\n");
    convexHull(points, n);

    return 0;
}
